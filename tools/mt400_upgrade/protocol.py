# -*- coding: utf-8 -*-
"""
SE96K 升级协议 (上位机侧)

与 docs/驱动升级协议.md 一一对应, 所有报文按固件编号书写:
    out[0..31]  主机下发, out[0] 为命令头 (App 0x0F / Boot 0x0E)
    in[0..31]   设备应答
App / Boot 的 Report ID 差异由传输层 (hid_transport.py / simulator.py) 处理。
"""
import time

# ---------------------------------------------------------------------------
# 设备标识
#
APP_VID, APP_PID, APP_USAGE_PAGE, APP_INTERFACE = 0x331A, 0x101D, 0xFF0F, 1
BOOT_VID, BOOT_PID, BOOT_USAGE_PAGE, BOOT_INTERFACE = 0x32C2, 0x001B, 0xFF0E, 0

APP_HANDLE = 0x0F
BOOT_HANDLE = 0x0E

# ---------------------------------------------------------------------------
# 固件文件
#
BIN_SIZE = 0x6F80           # 0x1000 - 0x7F7F
BIN_BASE = 0x1000
INFO_OFFSET = 0x5FF0        # 0x6FF0 - 0x1000, App fw_info / Updater updater_info
PAGE = 128

CMD_W_FLASH = 0x10
CMD_W_FIFO = 0x11
CMD_R_FLASH = 0x12
CMD_RUN_APP = 0x1E          # Boot: 运行 App
CMD_ISP = 0x1E              # App : 跳 Boot (参数 55 AA 00 FF)
CMD_INFO = 0x20

ERR_TEXT = {0: '无', 1: '长度错误', 2: '校验错误', 3: '地址错误', 4: '写入后回读不一致'}


class UpgradeError(Exception):
    pass


def hexs(b):
    return ' '.join('%02X' % x for x in b)


def page_checksum(data):
    """W_FLASH 校验: 0xFA21 + 16 位小端字累加"""
    if len(data) & 1:
        raise ValueError('长度必须为偶数')
    cs = 0xFA21
    for k in range(0, len(data), 2):
        cs = (cs + (data[k] | (data[k + 1] << 8))) & 0xFFFF
    return cs


def cmd(*args):
    """拼 32 字节命令"""
    b = bytearray(32)
    b[:len(args)] = bytes(args)
    return b


# ---------------------------------------------------------------------------
# 固件文件解析
#
class FwFile(object):
    def __init__(self, data, name=''):
        self.name = name
        self.bin = bytes(data)
        if len(self.bin) != BIN_SIZE:
            raise UpgradeError('%s: 大小 %d 字节, 应为 %d (0x6F80)' % (name, len(self.bin), BIN_SIZE))
        m = self.bin[INFO_OFFSET:INFO_OFFSET + 16]
        self.info = m
        self.pid = bytes([m[3], m[2], m[1], m[0]])        # ID0..ID3
        self.ver = m[4]
        self.tag = m[8:16]
        self.is_updater = m[8:11] == b'UPD'
        if self.pid[0:2] != b'\x00\x96':
            raise UpgradeError('%s: 项目ID %s 不是本产品 (00 96 ..)' % (name, hexs(self.pid)))

    @classmethod
    def load(cls, path):
        with open(path, 'rb') as f:
            return cls(f.read(), path)

    def describe(self):
        kind = 'Updater (目标 Boot 版本 %d)' % self.ver if self.is_updater else 'App (版本 %d)' % self.ver
        return '%s  项目ID %s  标识 %r' % (kind, hexs(self.pid), bytes(self.tag))

    def embedded_boot(self):
        """Updater 内嵌的 boot_image[4096]; 返回 (偏移, 镜像) 或 (None, None)"""
        return find_embedded_boot(self.bin)

    def check(self):
        """
        发送前检查, 返回 (错误列表, 提示列表)。
        Updater: 必须能找到内嵌 Boot, 且其项目ID/版本与 0x5FF0 标识一致;
                 内嵌 Boot 版本 <= 1 说明还是占位文件 (旧 Boot)。
        """
        errors, notes = [], []
        if self.is_updater:
            off, img = self.embedded_boot()
            if img is None:
                errors.append('找不到内嵌的 Boot 镜像 (结尾 AA 55 5A、开头 "Bo")')
            else:
                ipid, iver = bytes(img[0xFF8:0xFFC]), img[0xFFC]
                notes.append('内嵌 Boot 位于 bin 偏移 0x%04X (Flash 0x%04X): 项目ID %s 版本 %d'
                             % (off, BIN_BASE + off, hexs(ipid), iver))
                if ipid != self.pid or iver != self.ver:
                    errors.append('内嵌 Boot (项目ID %s 版本 %d) 与标识 (项目ID %s 版本 %d) 不一致'
                                  % (hexs(ipid), iver, hexs(self.pid), self.ver))
                if iver <= 1:
                    errors.append('内嵌 Boot 版本为 %d, 这是用旧 Boot 生成的占位 Updater, '
                                  '请用新 Boot 重新运行 hex2c.py 后再编译 Updater' % iver)
                if img[0:4] == b'\xFF\xFF\xFF\xFF':
                    errors.append('内嵌 Boot 的复位向量为空')
        else:
            if self.bin[0:2] == b'\xFF\xFF':
                errors.append('0x1000 处为空白, 不是有效的 App')
            if find_embedded_boot(self.bin)[1] is not None and self.tag[0:4] != b'BYKC':
                notes.append('文件里含有 Boot 镜像, 请确认不是 Updater')
        return errors, notes


def find_embedded_boot(data):
    data = bytes(data)
    for off in range(0, len(data) - 0x1000 + 1):
        if data[off + 0xFFD:off + 0x1000] == b'\xAA\x55\x5A' and data[off + 0xFF0:off + 0xFF2] == b'Bo':
            return off, data[off:off + 0x1000]
    return None, None


# ---------------------------------------------------------------------------
# 会话: 命令封装 + 升级流程
#
class Session(object):
    """
    bus 需提供:
        bus.find(kind) -> bool            kind = 'app' / 'boot'
        bus.open(kind) -> link
    link 需提供:
        link.kind                         'app' / 'boot'
        link.send(out32)                  失败抛 IOError
        link.recv(timeout_s) -> bytes32 或 None
        link.flush()
        link.close()
    """

    def __init__(self, bus, log=print, verbose=False,
                 reply_timeout=0.5, appear_timeout=5.0, gone_timeout=3.0, poll=0.05):
        self.bus = bus
        self.log = log
        self.verbose = verbose
        self.reply_timeout = reply_timeout
        self.appear_timeout = appear_timeout
        self.gone_timeout = gone_timeout
        self.poll = poll
        self.link = None
        self.progress = None            # 回调 progress(stage, done, total)
        self.confirm = None             # 回调 confirm(提示) -> bool, 分步模式用; None 表示不停

    # ---------------- 连接 ----------------
    def close(self):
        if self.link:
            try:
                self.link.close()
            finally:
                self.link = None

    def open(self, kind):
        self.close()
        self.link = self.bus.open(kind)
        return self.link

    def open_any(self):
        """优先打开 Boot, 否则 App; 都没有返回 None"""
        for kind in ('boot', 'app'):
            if self.bus.find(kind):
                return self.open(kind)
        return None

    def wait_gone(self, kind, timeout=None):
        t0 = time.time()
        timeout = self.gone_timeout if timeout is None else timeout
        while time.time() - t0 < timeout:
            if not self.bus.find(kind):
                return True
            time.sleep(self.poll)
        return False

    def wait_appear(self, kind, timeout=None):
        t0 = time.time()
        timeout = self.appear_timeout if timeout is None else timeout
        while True:
            if self.bus.find(kind):
                return True
            if time.time() - t0 >= timeout:
                return False
            time.sleep(self.poll)

    # ---------------- 收发 ----------------
    def transact(self, out, timeout=None, retries=1):
        """一问一答: 清旧报文 -> 发送 -> 等 in[0..1] 匹配的应答"""
        timeout = self.reply_timeout if timeout is None else timeout
        out = bytes(out)
        for attempt in range(retries + 1):
            self.link.flush()
            if self.verbose:
                self.log('  TX %s' % hexs(out))
            self.link.send(out)
            t0 = time.time()
            while True:
                left = timeout - (time.time() - t0)
                if left <= 0:
                    break
                rx = self.link.recv(left)
                if rx is None:
                    break
                if self.verbose:
                    self.log('  RX %s' % hexs(rx))
                if rx[0] == out[0] and rx[1] == out[1]:
                    return bytes(rx)
            if self.verbose:
                self.log('  (应答超时, 第 %d 次)' % (attempt + 1))
        raise UpgradeError('命令 %02X %02X 无应答' % (out[0], out[1]))

    def send_raw(self, out, timeout=None, max_packets=64):
        """调试用: 发任意命令, 返回超时前收到的所有报文"""
        timeout = self.reply_timeout if timeout is None else timeout
        self.link.flush()
        if self.verbose:
            self.log('  TX %s' % hexs(out))
        self.link.send(bytes(out))
        pkts = []
        while len(pkts) < max_packets:
            rx = self.link.recv(timeout)
            if rx is None:
                break
            if self.verbose:
                self.log('  RX %s' % hexs(rx))
            pkts.append(bytes(rx))
        return pkts

    def _need(self, kind):
        if not self.link or self.link.kind != kind:
            raise UpgradeError('需要先连接 %s 设备' % ('App' if kind == 'app' else 'Boot'))

    # ---------------- App 命令 ----------------
    def app_read_info(self):
        self._need('app')
        rx = self.transact(cmd(APP_HANDLE, CMD_INFO))      # out[8]/out[10] 为 0, 只查询
        return rx[14:30]

    def app_jump_boot(self):
        self._need('app')
        rx = self.transact(cmd(APP_HANDLE, CMD_ISP, 0x55, 0xAA, 0x00, 0xFF))
        if rx[2] != 0x01:
            raise UpgradeError('App 拒绝跳 Boot: %s' % hexs(rx[:4]))
        # 发出后不要再发任何命令, 直接等待断开

    # ---------------- Boot 命令 ----------------
    def boot_read_info(self):
        """返回 (pid ID0..ID3, 版本)"""
        self._need('boot')
        rx = self.transact(cmd(BOOT_HANDLE, CMD_INFO))
        return bytes([rx[5], rx[4], rx[3], rx[2]]), rx[6]

    def boot_write_fifo(self, offset, data):
        self._need('boot')
        n = len(data)
        if n > 28 or offset + n > PAGE:
            raise ValueError('W_FIFO 越界')
        o = cmd(BOOT_HANDLE, CMD_W_FIFO, offset, n)
        o[4:4 + n] = data
        rx = self.transact(o)
        return not (rx[3] & 0x80) and rx[4:4 + n] == bytes(data)

    def boot_write_flash(self, addr, length, cs):
        """返回 (ack, 错误码)"""
        self._need('boot')
        rx = self.transact(cmd(BOOT_HANDLE, CMD_W_FLASH, addr & 0xFF, addr >> 8, length, 0xA5,
                               cs & 0xFF, cs >> 8), timeout=max(1.0, self.reply_timeout))
        return rx[5] == 0x01, rx[7]

    def boot_write_page(self, addr, page, retries=3):
        """写一整页 (128 字节, addr 为 bin 偏移, 128 对齐)"""
        if addr % PAGE or len(page) != PAGE:
            raise ValueError('必须 128 字节对齐整页')
        cs = page_checksum(page)
        for attempt in range(retries):
            ok = True
            for off in range(0, PAGE, 28):
                if not self.boot_write_fifo(off, page[off:off + 28]):
                    self.log('  W_FIFO 回读不符 addr=%04X off=%d' % (addr, off))
                    ok = False
                    break
            if not ok:
                continue
            ack, err = self.boot_write_flash(addr, PAGE, cs)
            if ack:
                return
            self.log('  W_FLASH NAK addr=%04X 错误码=%d(%s)' % (addr, err, ERR_TEXT.get(err, '?')))
        raise UpgradeError('页 %04X 写入失败' % addr)

    def boot_write_image(self, data, stage='写入'):
        """首页最后写: 首页空白 -> 第 1..末页 -> 首页"""
        data = bytes(data)
        pages = len(data) // PAGE
        self.boot_write_page(0, b'\xFF' * PAGE)
        for p in range(1, pages):
            self.boot_write_page(p * PAGE, data[p * PAGE:(p + 1) * PAGE])
            if self.progress:
                self.progress(stage, p, pages)
        self.boot_write_page(0, data[:PAGE])
        if self.progress:
            self.progress(stage, pages, pages)

    def boot_read_flash(self, addr, length):
        """R_FLASH: addr 为 bin 偏移; 需连续收包"""
        self._need('boot')
        if length & 1:
            length += 1
        self.link.flush()
        out = cmd(BOOT_HANDLE, CMD_R_FLASH, addr & 0xFF, addr >> 8, length & 0xFF, length >> 8)
        if self.verbose:
            self.log('  TX %s' % hexs(out))
        self.link.send(bytes(out))
        buf = bytearray(b'\xFF' * length)
        got = 0
        while got < length:
            rx = self.link.recv(self.reply_timeout)
            if rx is None:
                raise UpgradeError('R_FLASH 读到 %d/%d 字节后超时' % (got, length))
            if rx[0] != BOOT_HANDLE or rx[1] != CMD_R_FLASH:
                continue
            off = rx[2] | (rx[3] << 8)
            n = min(28, length - off)
            buf[off:off + n] = rx[4:4 + n]
            got = off + n
        return bytes(buf)

    def boot_run_app(self):
        self._need('boot')
        rx = self.transact(cmd(BOOT_HANDLE, CMD_RUN_APP))
        if rx[2] != 0x01:
            raise UpgradeError('Boot 回 NAK: 0x1000 处为空白, 没有 App')

    # ---------------- 流程 ----------------
    def step(self, text):
        """分步模式: 每个阶段前停下来等确认"""
        if self.confirm and not self.confirm(text):
            raise UpgradeError('用户取消: %s' % text)

    def precheck(self, fw):
        errors, notes = fw.check()
        for n in notes:
            self.log('  ' + n)
        if errors:
            raise UpgradeError('%s 检查未通过:\n  - %s' % (fw.name, '\n  - '.join(errors)))

    def enter_boot(self):
        if self.bus.find('boot'):
            self.open('boot')
            return
        if not self.bus.find('app'):
            raise UpgradeError('没有找到键盘 (App 或 Boot)')
        self.open('app')
        self.log('App -> 跳 Boot')
        self.app_jump_boot()
        self.close()
        self.wait_gone('app')
        if not self.wait_appear('boot'):
            raise UpgradeError('Boot 未出现: 请按住 左Ctrl+左Win 重新插拔键盘后重试')
        self.open('boot')

    def check_boot_product(self):
        pid, ver = self.boot_read_info()
        self.log('Boot: 项目ID %s  版本 %d' % (hexs(pid), ver))
        if pid[0:2] != b'\x00\x96':
            raise UpgradeError('设备型号不匹配')
        return pid, ver

    def finish_to_app(self, expect_ver=None):
        self.log('运行 App')
        self.boot_run_app()
        self.close()
        self.wait_gone('boot')
        if not self.wait_appear('app'):
            raise UpgradeError('App 未启动')
        self.open('app')
        info = self.app_read_info()
        self.log('App: 项目ID %s  版本 %d  %r' % (hexs(info[3::-1]), info[4], bytes(info[8:16])))
        if expect_ver is not None and info[4] != expect_ver:
            raise UpgradeError('App 版本 %d, 期望 %d' % (info[4], expect_ver))
        return info

    def upgrade_app(self, fw):
        if fw.is_updater:
            raise UpgradeError('这是 Boot 升级文件 (UPD), 请选择 App 固件')
        self.precheck(fw)
        self.step('跳进 Boot')
        self.enter_boot()
        self.check_boot_product()
        self.step('写入 App (%s)' % fw.name)
        self.log('写入 App: %s' % fw.describe())
        self.boot_write_image(fw.bin, '写 App')
        return self.finish_to_app(fw.ver)

    def upgrade_boot(self, upd, app):
        if not upd.is_updater:
            raise UpgradeError('%s 不是 Updater (偏移 0x5FF8 不是 UPD)' % upd.name)
        if app.is_updater:
            raise UpgradeError('%s 是 Updater, 请选择正式 App' % app.name)
        self.log('检查 %s' % upd.name)
        self.precheck(upd)
        self.log('检查 %s' % app.name)
        self.precheck(app)
        self.step('跳进 Boot')
        self.enter_boot()
        _, ver = self.check_boot_product()
        boot_ok = True
        if ver == upd.ver:
            self.log('Boot 已是版本 %d, 跳过 Updater' % ver)
        else:
            self.step('写入 Updater (%s)' % upd.name)
            self.log('写入 Updater: %s' % upd.describe())
            self.boot_write_image(upd.bin, '写 Updater')
            self.step('运行 Updater 改写 Boot 区 (约 0.2 秒, 期间不要拔线)')
            self.log('运行 Updater')
            self.boot_run_app()
            self.close()
            self.wait_gone('boot')
            if not self.wait_appear('boot'):
                raise UpgradeError('Updater 后 Boot 未出现: 请重新插拔键盘, '
                                   '上电后 Updater 会继续, 然后再次执行本命令')
            self.open('boot')
            _, ver = self.boot_read_info()
            if ver == upd.ver:
                self.log('Boot 已更新为版本 %d' % ver)
            else:
                boot_ok = False
                self.log('警告: Boot 版本仍为 %d (Updater 未改动 Boot), 继续恢复 App' % ver)
        self.step('写回 App (%s)' % app.name)
        self.log('写回 App: %s' % app.describe())
        self.boot_write_image(app.bin, '写 App')
        self.step('运行 App')
        self.finish_to_app(app.ver)
        if not boot_ok:
            raise UpgradeError('Boot 未更新, App 已恢复')
