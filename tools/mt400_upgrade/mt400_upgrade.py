#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
SE96K 升级工具 —— 用软件模拟驱动发命令

真实键盘 (需要 pip install hidapi):
    python mt400_upgrade.py list
    python mt400_upgrade.py info
    python mt400_upgrade.py inspect Updater.bin App.bin  # 发送前检查文件
    python mt400_upgrade.py write-app  App.bin
    python mt400_upgrade.py upgrade-boot  Updater.bin  App.bin
    python mt400_upgrade.py --step --log boot.log upgrade-boot Updater.bin App.bin  # 分步+记录
    python mt400_upgrade.py shell                     # 交互式手动发命令

模拟键盘 (不需要硬件, 加 --sim):
    python mt400_upgrade.py --sim info
    python mt400_upgrade.py --sim -v write-app  App.bin
    python mt400_upgrade.py --sim upgrade-boot  --sim-make-updater  App.bin
    python mt400_upgrade.py --sim shell

通用选项: -v 打印每条 TX/RX 报文; --step 每个阶段前暂停确认; --log FILE 同时写入日志文件
"""
import argparse
import os
import shlex
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from protocol import (Session, FwFile, UpgradeError, hexs, cmd, page_checksum,  # noqa: E402
                      APP_HANDLE, BOOT_HANDLE, BIN_SIZE)

REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
DEF_SIM_BOOT = os.path.join(REPO, 'SE93T_BootLoader', 'SE93T_BootLoader', 'output', '20250331', 'SE95K.bin')
DEF_SIM_APP = os.path.join(REPO, 'SE96K_0026_GZS_400US_LINE_MONO',
                           'SE96K_0026_GZS_400US_LINE_MONO_claude', 'output', 'SE95K.bin')


def read_file(p):
    with open(p, 'rb') as f:
        return f.read()


# ============================================================================ 总线
def make_bus(args):
    if not args.sim:
        from hid_transport import HidBus
        return HidBus(args.index), None
    from simulator import SimKeyboard, SimBus
    boot = read_file(args.sim_boot)
    if len(boot) != 0x1000:
        sys.exit('--sim-boot 必须是 4096 字节的 Boot bin')
    app = read_file(args.sim_app) if args.sim_app else None
    kb = SimKeyboard(boot, app, write_protect_boot=args.sim_write_protect,
                     updater_powerloss_at=args.sim_powerloss_at)
    kb.power_on(keys=args.sim_keys)
    print('[模拟] 上电 -> %s  (Boot 版本 %d%s)' % (kb.state, kb.boot_version(),
                                                ', 写保护' if args.sim_write_protect else ''))
    return SimBus(kb), kb


def progress_printer():
    last = {'stage': None, 'pct': -1}

    def cb(stage, done, total):
        pct = done * 100 // total
        if stage != last['stage'] or pct // 10 != last['pct'] // 10 or done == total:
            sys.stdout.write('\r  %s: %3d%% (%d/%d 页)' % (stage, pct, done, total))
            if done == total:
                sys.stdout.write('\n')
            sys.stdout.flush()
            last['stage'], last['pct'] = stage, pct
    return cb


# ============================================================================ 命令
def do_list(s, args):
    if args.sim:
        print('App : %s' % ('在线' if s.bus.find('app') else '-'))
        print('Boot: %s' % ('在线' if s.bus.find('boot') else '-'))
        return
    from hid_transport import list_all
    rows = list_all()
    if not rows:
        print('没有找到 App (331A:101D) 或 Boot (32C2:001B)')
    for kind, d in rows:
        print('%-4s %04X:%04X  接口%-2d UsagePage=%04X Usage=%04X  %s'
              % (kind, d['vendor_id'], d['product_id'], d.get('interface_number', -1),
                 d.get('usage_page') or 0, d.get('usage') or 0, d['path']))


def print_app_info(info):
    print('App : 项目ID %s  版本 %d  %r' % (hexs(info[3::-1]), info[4], bytes(info[8:16])))


def do_info(s, args):
    link = s.open_any()
    if link is None:
        raise UpgradeError('没有找到键盘')
    if link.kind == 'app':
        print_app_info(s.app_read_info())
    else:
        pid, ver = s.boot_read_info()
        print('Boot: 项目ID %s  版本 %d' % (hexs(pid), ver))


def inspect_file(path, log=print):
    """打印文件类型、标识, 并做发送前检查; 返回是否通过"""
    try:
        fw = FwFile.load(path)
    except (UpgradeError, IOError) as e:
        log('%s: 错误 %s' % (path, e))
        return False
    log('%s' % path)
    log('  %s' % fw.describe())
    errors, notes = fw.check()
    for n in notes:
        log('  ' + n)
    for e in errors:
        log('  [错误] ' + e)
    log('  %s' % ('检查通过' if not errors else '检查未通过, 不要发送此文件'))
    return not errors


def do_inspect(s, args):
    ok = all([inspect_file(p) for p in args.files])
    if not ok:
        raise UpgradeError('文件检查未通过')


def do_jump_boot(s, args):
    s.enter_boot()
    pid, ver = s.boot_read_info()
    print('已进入 Boot: 项目ID %s  版本 %d' % (hexs(pid), ver))


def do_run_app(s, args):
    s.open('boot')
    s.finish_to_app()


def do_read(s, args):
    s.open('boot')
    addr, length = int(args.addr, 0), int(args.length, 0)
    data = s.boot_read_flash(addr, length)
    if args.output:
        with open(args.output, 'wb') as f:
            f.write(data)
        print('已保存 %d 字节到 %s' % (len(data), args.output))
    else:
        for k in range(0, len(data), 16):
            print('%04X: %s' % (0x1000 + addr + k, hexs(data[k:k + 16])))


def do_verify(s, args):
    fw = FwFile.load(args.bin)
    s.enter_boot()
    data = s.boot_read_flash(0, BIN_SIZE)
    bad = [a for a in range(0, BIN_SIZE, 128) if data[a:a + 128] != fw.bin[a:a + 128]]
    if bad:
        raise UpgradeError('%d 页不一致, 首个 0x%04X' % (len(bad), 0x1000 + bad[0]))
    print('校验通过: Flash 0x1000-0x7F7F 与 %s 一致' % args.bin)


def do_write_app(s, args):
    fw = FwFile.load(args.app)
    print('文件: %s' % fw.describe())
    s.upgrade_app(fw)
    print('App 升级完成')


def do_upgrade_boot(s, args):
    if args.sim_make_updater:
        if not args.sim:
            sys.exit('--sim-make-updater 只能和 --sim 一起用')
        from simulator import make_new_boot, make_sim_updater
        new_boot = make_new_boot(read_file(args.sim_boot))
        upd = FwFile(make_sim_updater(new_boot), '<模拟 Updater>')
        app_path = args.updater           # 此时唯一的位置参数是 App
    else:
        if not args.app:
            sys.exit('用法: upgrade-boot Updater.bin App.bin')
        upd = FwFile.load(args.updater)
        app_path = args.app
    app = FwFile.load(app_path)
    print('Updater: %s' % upd.describe())
    print('App    : %s' % app.describe())
    s.upgrade_boot(upd, app)
    print('Boot 升级完成')


# ============================================================================ 交互
SHELL_HELP = """\
命令 (数字可写 0x..):
  find                      查看 App / Boot 是否在线
  open app|boot             打开设备
  info                      读版本 (App: 0F 20 / Boot: 0E 20)
  jump                      App 跳 Boot (0F 1E 55 AA 00 FF), 并等待 Boot 出现
  fifo OFF HEX..            Boot 写缓存, 例: fifo 0 01 02 03 04
  flash ADDR LEN            Boot 写 Flash (自动计算缓存前 LEN 字节的校验)
  page ADDR HEX..|ff        整页写入 (自动分包+校验), ff 表示全 0xFF
  read ADDR LEN             Boot 读 Flash (地址为 bin 偏移)
  run                       Boot 运行 App (0E 1E), 并等待设备出现
  inspect FILE              检查 bin 文件 (类型/标识/内嵌 Boot)
  write FILE                Boot 写入整个 bin (首页最后写, 每页 5×W_FIFO + W_FLASH)
  verify FILE               Boot 回读整片与 bin 比对
  raw HEX..                 发送任意报文 (按固件编号, 首字节为命令头), 打印全部应答
  sim power [keys]          [模拟] 断电再上电, keys 表示按住 左Ctrl+左Win
  sim state                 [模拟] 查看状态
  help / quit"""


def wait_any(s, timeout):
    """同时等 App 或 Boot 出现"""
    import time
    t0 = time.time()
    while time.time() - t0 < timeout:
        for kind in ('boot', 'app'):
            if s.bus.find(kind):
                return kind
        time.sleep(s.poll)
    return None


def shell(s, args, kb):
    fifo_shadow = bytearray(b'\xFF' * 128)
    print('输入 help 查看命令')
    s.verbose = True
    while True:
        try:
            line = input('%s> ' % (s.link.kind if s.link else '-'))
        except (EOFError, KeyboardInterrupt):
            print()
            break
        try:
            a = shlex.split(line)
        except ValueError as e:
            print('解析失败: %s' % e)
            continue
        if not a:
            continue
        c, p = a[0], a[1:]
        num = lambda x: int(x, 16) if len(x) == 2 and not x.startswith('0x') else int(x, 0)   # noqa: E731
        try:
            if c in ('quit', 'exit', 'q'):
                break
            elif c == 'help':
                print(SHELL_HELP)
            elif c == 'find':
                print('App: %s  Boot: %s' % (s.bus.find('app'), s.bus.find('boot')))
            elif c == 'open':
                s.open(p[0])
            elif c == 'info':
                if not s.link:
                    s.open_any()
                if s.link.kind == 'app':
                    print_app_info(s.app_read_info())
                else:
                    pid, ver = s.boot_read_info()
                    print('Boot: 项目ID %s  版本 %d' % (hexs(pid), ver))
            elif c == 'jump':
                s.enter_boot()
            elif c == 'fifo':
                off = int(p[0], 0)
                data = bytes(int(x, 16) for x in p[1:])
                fifo_shadow[off:off + len(data)] = data
                print('OK' if s.boot_write_fifo(off, data) else '失败 (in[3] bit7=1 或回读不符)')
            elif c == 'flash':
                addr, n = int(p[0], 0), int(p[1], 0)
                ack, err = s.boot_write_flash(addr, n, page_checksum(fifo_shadow[:n]))
                print('ACK' if ack else 'NAK 错误码 %d' % err)
            elif c == 'page':
                addr = int(p[0], 0)
                data = b'\xFF' * 128 if p[1:] == ['ff'] else bytes(int(x, 16) for x in p[1:]).ljust(128, b'\xFF')
                s.boot_write_page(addr, data[:128])
                print('OK')
            elif c == 'read':
                data = s.boot_read_flash(int(p[0], 0), int(p[1], 0))
                for k in range(0, len(data), 16):
                    print('%04X: %s' % (0x1000 + int(p[0], 0) + k, hexs(data[k:k + 16])))
            elif c == 'run':
                s.boot_run_app()
                s.close()
                s.wait_gone('boot', 1.0)
                kind = wait_any(s, 5.0)
                if kind:
                    s.open(kind)
                    print('设备: %s' % kind)
                else:
                    print('超时: 5 秒内没有设备出现 (Updater 可能停机, 请重新插拔)')
            elif c == 'inspect':
                inspect_file(p[0])
            elif c == 'write':
                fw = FwFile.load(p[0])
                print(fw.describe())
                s.precheck(fw)
                v, s.verbose = s.verbose, False      # 整片写入不逐条打印
                try:
                    s.boot_write_image(fw.bin, '写入')
                finally:
                    s.verbose = v
                print('写入完成, 输入 run 运行')
            elif c == 'verify':
                fw = FwFile.load(p[0])
                v, s.verbose = s.verbose, False
                try:
                    data = s.boot_read_flash(0, BIN_SIZE)
                finally:
                    s.verbose = v
                bad = [x for x in range(0, BIN_SIZE, 128) if data[x:x + 128] != fw.bin[x:x + 128]]
                print('一致' if not bad else '%d 页不一致, 首个 Flash 0x%04X' % (len(bad), 0x1000 + bad[0]))
            elif c == 'raw':
                if not s.link:
                    s.open_any()
                out = cmd(*[num(x) for x in p])
                pkts = s.send_raw(out)
                if not pkts:
                    print('(无应答)')
            elif c == 'sim':
                if kb is None:
                    print('只在 --sim 下可用')
                elif p and p[0] == 'power':
                    s.close()
                    kb.power_off()
                    kb.power_on(keys='keys' in p)
                    print('上电 -> %s' % kb.state)
                else:
                    print('状态 %s  Boot 版本 %d  0x1000=%s' % (kb.state, kb.boot_version(),
                                                            hexs(kb.flash[0x1000:0x1004])))
            else:
                print('未知命令, 输入 help')
        except (UpgradeError, IOError, ValueError, IndexError) as e:
            print('错误: %s' % e)
            if isinstance(e, IOError):
                s.close()


# ============================================================================ main
class Tee(object):
    """stdout 同时写日志文件 (带时间)"""
    def __init__(self, path):
        import datetime
        self.f = open(path, 'a', encoding='utf-8')
        self.out = sys.__stdout__
        self.f.write('\n===== %s  %s\n' % (datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
                                           ' '.join(sys.argv[1:])))

    def write(self, s):
        self.out.write(s)
        self.f.write(s)
        self.f.flush()

    def flush(self):
        self.out.flush()
        self.f.flush()


def confirm_step(text):
    try:
        ans = input('\n>>> 下一步: %s  [回车继续 / q 取消] ' % text)
    except EOFError:
        return True
    return ans.strip().lower() not in ('q', 'n', 'quit')


def main(argv=None):
    ap = argparse.ArgumentParser(description='SE96K 升级工具 (模拟驱动)',
                                 formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument('-v', '--verbose', action='store_true', help='打印每条 TX/RX 报文')
    ap.add_argument('--index', type=int, default=0, help='多把键盘时选第几把 App (从 0 起)')
    ap.add_argument('--step', action='store_true', help='升级流程中每个阶段前暂停, 按回车继续')
    ap.add_argument('--wait', type=float, default=20.0, metavar='秒',
                    help='运行 Updater 后等待新 Boot 枚举的最长时间 (默认 20)')
    ap.add_argument('--log', metavar='FILE', help='把输出同时写入日志文件')
    g = ap.add_argument_group('模拟器')
    g.add_argument('--sim', action='store_true', help='使用模拟键盘, 不需要硬件')
    g.add_argument('--sim-boot', default=DEF_SIM_BOOT, help='模拟器 Boot 区镜像 (4096 字节 bin)')
    g.add_argument('--sim-app', default=DEF_SIM_APP, help='模拟器初始 App (bin); 传空串表示无 App')
    g.add_argument('--sim-keys', action='store_true', help='上电时按住 左Ctrl+左Win')
    g.add_argument('--sim-write-protect', action='store_true', help='Boot 区写保护')
    g.add_argument('--sim-powerloss-at', type=int, help='Updater 第 N 次页擦写时掉电')

    sub = ap.add_subparsers(dest='cmd')
    sub.add_parser('list', help='列出设备')
    sub.add_parser('info', help='读版本')
    ins = sub.add_parser('inspect', help='检查 bin 文件 (不连设备)')
    ins.add_argument('files', nargs='+')
    sub.add_parser('jump-boot', help='App 跳 Boot')
    sub.add_parser('run-app', help='Boot 运行 App')
    r = sub.add_parser('read', help='Boot 读 Flash (地址为 bin 偏移)')
    r.add_argument('addr')
    r.add_argument('length')
    r.add_argument('-o', '--output')
    v = sub.add_parser('verify', help='回读整片并与 bin 比对')
    v.add_argument('bin')
    w = sub.add_parser('write-app', help='升级 App')
    w.add_argument('app')
    u = sub.add_parser('upgrade-boot', help='通过 Updater 升级 Boot')
    u.add_argument('updater', help='Updater.bin (用 --sim-make-updater 时此处填 App.bin)')
    u.add_argument('app', nargs='?')
    u.add_argument('--sim-make-updater', action='store_true',
                   help='[模拟] 自动生成 Updater (内嵌版本 2 的 Boot)')
    sub.add_parser('shell', help='交互式发命令')

    args = ap.parse_args(argv)
    if not args.cmd:
        ap.print_help()
        return 1
    if args.sim_app == '':
        args.sim_app = None

    if args.log:
        tee = Tee(args.log)
        sys.stdout = tee
    if args.cmd == 'inspect':
        try:
            do_inspect(None, args)
            return 0
        except UpgradeError:
            return 2
        finally:
            if args.log:
                sys.stdout = sys.__stdout__

    bus, kb = make_bus(args)
    s = Session(bus, verbose=args.verbose, updater_timeout=args.wait)
    s.progress = progress_printer()
    if args.step:
        s.confirm = confirm_step
    try:
        if args.cmd == 'shell':
            shell(s, args, kb)
        else:
            {'list': do_list, 'info': do_info, 'jump-boot': do_jump_boot, 'run-app': do_run_app,
             'read': do_read, 'verify': do_verify, 'write-app': do_write_app,
             'upgrade-boot': do_upgrade_boot}[args.cmd](s, args)
    except (UpgradeError, IOError) as e:
        print('\n失败: %s' % e)
        return 2
    finally:
        s.close()
        if kb is not None:
            print('[模拟] 结束状态: %s  Boot 版本 %d' % (kb.state, kb.boot_version()))
        if args.log:
            sys.stdout = sys.__stdout__
    return 0


if __name__ == '__main__':
    sys.exit(main())
