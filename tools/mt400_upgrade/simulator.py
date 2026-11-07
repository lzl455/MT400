# -*- coding: utf-8 -*-
"""
模拟键盘: 在没有硬件时验证驱动流程

按固件源码逐条模拟:
    Boot   : SE93T_BootLoader  MAIN.C / hid_process.c / flash.c
             旧 Boot (版本 1) 与新 Boot (版本 >=2) 的行为差异也一并模拟
    App    : SE96K App  hal/hid_process.c (MODE_INFO / ISP)
    Updater: SE96K_BootUpdater MAIN.C 的写入顺序、断点续写、停机

故障注入:
    write_protect_boot   0x0000-0x0FFF 写保护 (烧录选项), IAP 写入无效
    updater_powerloss_at Updater 第 N 次页擦写时掉电 (从 1 计数)
    corrupt_fifo_once    下一次 W_FIFO 数据出错一次 (模拟传输错误)
    unsolicited_info     App 启动时主动上报一次 MODE_INFO (验证驱动会清空旧报文)
"""
from collections import deque

FLASH_SIZE = 0x8000
PAGE = 128
APP_BASE = 0x1000
CODE_LENGTH = 28 * 1024
BOOT_FLAG = bytes([0x3C, 0xC3, 0x55, 0xAA])
STUB = {0x00: b'\x00\xDF\x08\xF0', 0x08: b'\x04\xDF\x08\xF0', 0x18: b'\x0C\xDF\x08\xF0'}


def stub_page():
    p = bytearray(b'\xFF' * PAGE)
    for a, v in STUB.items():
        p[a:a + 4] = v
    return bytes(p)


class PowerLoss(Exception):
    pass


class SimKeyboard(object):
    def __init__(self, boot_image, app_bin=None, write_protect_boot=False,
                 updater_powerloss_at=None, unsolicited_info=True):
        self.flash = bytearray(b'\xFF' * FLASH_SIZE)
        self.flash[0:0x1000] = boot_image
        if app_bin is not None:
            self.flash[APP_BASE:APP_BASE + len(app_bin)] = app_bin
        self.ram_flag = bytes(4)
        self.state = 'off'           # off / app / boot / halted / bricked
        self.gen = 0                 # USB 连接代号, 复位后旧连接失效
        self.tx = deque()            # 设备待发报文
        self.fifo = bytearray(PAGE)
        self.after_reply = None      # 应答被主机取走后执行 (APP / ISP 复位)
        self.write_protect_boot = write_protect_boot
        self.updater_powerloss_at = updater_powerloss_at
        self.updater_page_writes = 0
        self.corrupt_fifo_once = False
        self.unsolicited_info = unsolicited_info
        self.events = []             # 日志, 便于测试断言

    # ================================================================ 硬件
    def flash_write_page(self, addr, data):
        """IAP 整页擦写 (ERASE+WRITE)"""
        addr &= ~(PAGE - 1)
        if self.write_protect_boot and addr < 0x1000:
            return                   # 写保护: 静默无效, 回读校验会失败
        self.flash[addr:addr + PAGE] = data

    def boot_version(self):
        return self.flash[0xFFC]

    def boot_is_new(self):
        return self.boot_version() >= 2

    def _set_state(self, st):
        self.state = st
        self.gen += 1
        self.tx.clear()
        self.after_reply = None
        self.events.append(st)

    # ================================================================ 复位
    def power_on(self, keys=False):
        """上电; keys=True 表示按住 左Ctrl+左Win"""
        self.ram_flag = bytes(4)     # 上电 RAM 内容不定, 视为无标志
        self._reset(soft=False, keys=keys)

    def power_off(self):
        self._set_state('off')

    def _reset(self, soft, keys=False):
        page0 = bytes(self.flash[0:PAGE])
        if page0 == stub_page():
            return self._run_0x1000()            # 跳转桩: 直接运行 0x1000
        if self.flash[0xFFD:0x1000] != b'\xAA\x55\x5A' or page0[0:4] == b'\xFF\xFF\xFF\xFF':
            return self._set_state('bricked')    # Boot 区不完整, 无法启动
        self._boot_main(soft, keys)

    def _boot_main(self, soft, keys):
        app_present = self.flash[APP_BASE:APP_BASE + 2] != b'\xFF\xFF'
        if app_present:
            if not soft:
                if not keys:
                    return self._run_0x1000()
            elif self.ram_flag != BOOT_FLAG:
                return self._run_0x1000()
        self.ram_flag = bytes(4)
        self._set_state('boot')

    def _run_0x1000(self):
        if self.flash[APP_BASE:APP_BASE + 2] == b'\xFF\xFF':
            return self._set_state('bricked')    # 跳到空白区, 跑飞
        if self.flash[0x6FF8:0x6FFB] == b'UPD':
            return self._run_updater()
        self._set_state('app')
        if self.unsolicited_info:
            self.tx.append(self._app_info_reply())

    def _soft_reset(self):
        self._reset(soft=True)

    # ================================================================ 主机接口
    def present(self, kind):
        return self.state == kind

    def host_send(self, gen, out):
        if gen != self.gen:
            raise IOError('设备已断开')
        out = bytes(out)
        if self.state == 'boot':
            self._boot_cmd(out)
        elif self.state == 'app':
            self._app_cmd(out)

    def host_recv(self, gen):
        if gen != self.gen:
            raise IOError('设备已断开')
        if not self.tx:
            return None
        pkt = self.tx.popleft()
        if not self.tx and self.after_reply:
            act, self.after_reply = self.after_reply, None
            act()
        return pkt

    def host_flush(self, gen):
        if gen == self.gen:
            self.tx.clear()

    # ================================================================ App
    def _app_info_reply(self):
        r = bytearray(32)
        r[0], r[1] = 0x0F, 0x20
        r[14:30] = self.flash[0x6FF0:0x7000]
        return bytes(r)

    def _app_cmd(self, o):
        if o[0] != 0x0F:
            return
        if o[1] == 0x20:
            self.tx.append(self._app_info_reply())
        elif o[1] == 0x1E and o[2:6] == b'\x55\xAA\x00\xFF':
            r = bytearray(32)
            r[0], r[1], r[2] = 0x0F, 0x1E, 0x01
            self.tx.append(bytes(r))

            def jump():
                self.ram_flag = BOOT_FLAG
                self._soft_reset()
            self.after_reply = jump

    # ================================================================ Boot
    def _boot_cmd(self, o):
        if o[0] != 0x0E:
            return
        if (o[1] & 0xF0) == 0x10:
            sub = o[1] & 0x0F
            if sub == 0x00:
                self._boot_w_flash(o)
            elif sub == 0x01:
                self._boot_w_fifo(o)
            elif sub == 0x02:
                self._boot_r_flash(o)
            elif sub == 0x0E:
                self._boot_run_app()
        elif o[1] == 0x20:
            r = bytearray(32)
            r[0], r[1] = 0x0E, 0x20
            r[2:6] = bytes([self.flash[0xFFB], self.flash[0xFFA], self.flash[0xFF9], self.flash[0xFF8]])
            r[6] = self.flash[0xFFC]
            r[7:15] = bytes([0x00, 0x96, 0x00, 0x09, 0x01]) + b'YiQ'
            self.tx.append(bytes(r))

    def _boot_w_fifo(self, o):
        r = bytearray(32)
        r[0], r[1], r[2], r[3] = 0x0E, 0x11, o[2], o[3]
        if o[3] <= 28 and o[2] + o[3] <= PAGE:
            data = bytearray(o[4:4 + o[3]])
            if self.corrupt_fifo_once and data:
                data[0] ^= 0xFF
                self.corrupt_fifo_once = False
            self.fifo[o[2]:o[2] + o[3]] = data
            r[4:4 + o[3]] = self.fifo[o[2]:o[2] + o[3]]
            if bytes(r[4:4 + o[3]]) != o[4:4 + o[3]]:
                r[3] |= 0x80
        else:
            r[3] |= 0x80
        self.tx.append(bytes(r))

    def _boot_w_flash(self, o):
        err_id, cmd_err = 0, False
        length = o[4]
        if length > PAGE or o[5] > 0xA5:
            err_id, cmd_err = 1, True
        else:
            if length & 1:
                cmd_err = True                 # checksum_check 置错, check_sum 沿用旧值
            cs = 0xFA21
            for k in range(0, length - (length & 1), 2):
                cs = (cs + (self.fifo[k] | (self.fifo[k + 1] << 8))) & 0xFFFF
            if (length & 1) or o[6] != (cs & 0xFF) or o[7] != (cs >> 8):
                err_id, cmd_err = 2, True
        addr = o[2] | (o[3] << 8)
        if addr > CODE_LENGTH:
            err_id, cmd_err = 3, True
        if not cmd_err and not self._flash_program(addr, length):
            err_id, cmd_err = 4, True
        r = bytearray(32)
        r[0], r[1], r[2], r[3], r[4] = 0x0E, 0x10, o[2], o[3], length
        r[5] = 0x00 if cmd_err else 0x01
        r[7] = err_id
        self.tx.append(bytes(r))

    def _flash_program(self, addr, length):
        """flash.c flash_program; 返回 False 表示 bhid_cmd_err"""
        new = self.boot_is_new()
        if addr >= CODE_LENGTH:
            return False
        if new and (addr & 0x7F) + length > PAGE:
            return False                       # 新 Boot: 不允许跨页
        if not new and length > PAGE:
            return False
        a = addr + APP_BASE
        j = a & 0x7F
        cmp_base = a if new else (a & ~0x7F)   # 旧 Boot 比较页首 (缺陷)
        if bytes(self.flash[cmp_base:cmp_base + length]) == bytes(self.fifo[:length]):
            return True                        # 内容一致, 不擦写
        page_addr = a & ~0x7F
        buf = bytearray(self.flash[page_addr:page_addr + PAGE])
        for i in range(length):
            if j + i < PAGE:                   # 旧 Boot 越界部分写到 RAM 其它地方, 不进 Flash
                buf[j + i] = self.fifo[i]
        self.flash_write_page(page_addr, bytes(buf))
        for i in range(length):                # 写后校验
            ref = self.fifo[i] if new else (self.fifo[j + i] if j + i < PAGE else 0)
            if ref != self.flash[a + i]:
                return False
        return True

    def _boot_r_flash(self, o):
        addr = o[2] | (o[3] << 8)
        length = o[4] | (o[5] << 8)
        p = APP_BASE + addr
        i = 0
        while i < length:
            y = min(28, length - i)
            r = bytearray(32)
            r[0], r[1], r[2], r[3] = 0x0E, 0x12, i & 0xFF, i >> 8
            x = 0
            while x < y:                       # 固件每次取 2 字节
                r[4 + x] = self.flash[p] if p < FLASH_SIZE else 0xFF
                r[5 + x] = self.flash[p + 1] if p + 1 < FLASH_SIZE else 0xFF
                x += 2
                p += 2
                i += 2
            self.tx.append(bytes(r))

    def _boot_run_app(self):
        r = bytearray(32)
        r[0], r[1] = 0x0E, 0x1E
        ok = self.flash[APP_BASE:APP_BASE + 2] != b'\xFF\xFF'
        r[2] = 0x01 if ok else 0x00
        self.tx.append(bytes(r))
        if ok:
            self.after_reply = self._soft_reset

    # ================================================================ Updater
    def _find_boot_image(self):
        """在 Updater 程序区里找内嵌的 boot_image[4096] (尾标记 AA 55 5A, 开头 'Bo')"""
        area = bytes(self.flash[APP_BASE:0x7F80])
        for off in range(0, len(area) - 0x1000 + 1):
            if area[off + 0xFFD:off + 0x1000] == b'\xAA\x55\x5A' and area[off + 0xFF0:off + 0xFF2] == b'Bo':
                return area[off:off + 0x1000]
        return None

    def _upd_write(self, addr, data):
        """Updater flash_page_write: 一致则跳过, 否则擦写并校验, 重试 3 次"""
        if bytes(self.flash[addr:addr + PAGE]) == data:
            return True
        for _ in range(3):
            self.updater_page_writes += 1
            if self.updater_powerloss_at and self.updater_page_writes == self.updater_powerloss_at:
                self.flash[addr:addr + PAGE] = b'\xFF' * PAGE      # 擦除后掉电
                raise PowerLoss()
            self.flash_write_page(addr, data)
            if bytes(self.flash[addr:addr + PAGE]) == data:
                return True
        return False

    def _run_updater(self):
        self.events.append('updater')
        img = self._find_boot_image()
        resume = bytes(self.flash[0:PAGE]) == stub_page()
        try:
            if img is None:
                if resume:
                    return self._set_state('halted')
                self.ram_flag = BOOT_FLAG
                return self._soft_reset()
            if bytes(self.flash[0:0x1000]) == img:
                self.ram_flag = BOOT_FLAG
                return self._soft_reset()
            if not resume:
                if (self.flash[0xFFD:0x1000] != b'\xAA\x55\x5A'
                        or self.flash[0xFF8:0xFFA] != img[0xFF8:0xFFA]):
                    self.ram_flag = BOOT_FLAG
                    return self._soft_reset()      # 非本产品 Boot
                if not self._upd_write(0, stub_page()):
                    return self._set_state('halted')
            for a in range(PAGE, 0x1000, PAGE):
                if not self._upd_write(a, img[a:a + PAGE]):
                    return self._set_state('halted')
            if not self._upd_write(0, img[0:PAGE]):
                self._upd_write(0, stub_page())
                return self._set_state('halted')
            self.ram_flag = BOOT_FLAG
            self._soft_reset()
        except PowerLoss:
            self.updater_powerloss_at = None       # 只掉电一次
            self._set_state('off')


# ==================================================================== 传输层适配
class SimLink(object):
    def __init__(self, kb, kind):
        self.kb = kb
        self.kind = kind
        self.gen = kb.gen

    def send(self, out):
        self.kb.host_send(self.gen, out)

    def recv(self, timeout_s):
        return self.kb.host_recv(self.gen)     # 模拟器应答是即时的, 无数据即视为超时

    def flush(self):
        self.kb.host_flush(self.gen)

    def close(self):
        pass


class SimBus(object):
    def __init__(self, kb):
        self.kb = kb

    def find(self, kind):
        return self.kb.present(kind)

    def open(self, kind):
        if not self.kb.present(kind):
            raise IOError('未找到 %s 设备' % kind)
        return SimLink(self.kb, kind)


# ==================================================================== 测试用固件
def make_new_boot(old_boot, pid=(0x00, 0x96, 0x00, 0x28), ver=2):
    """用旧 Boot 镜像改出一个"新 Boot" (只改版本信息), 仅供模拟"""
    b = bytearray(old_boot)
    b[0xFF8:0xFFC] = bytes(pid)
    b[0xFFC] = ver
    return bytes(b)


def make_sim_updater(new_boot, code_offset=0x0100):
    """
    构造一个 Updater bin (仅供模拟): 0x1000 处放占位代码, 内嵌 new_boot,
    0x6FF0 放 updater_info (与 SE96K_BootUpdater/MAIN.C 相同格式)
    """
    from protocol import BIN_SIZE, INFO_OFFSET
    b = bytearray(b'\xFF' * BIN_SIZE)
    b[0:4] = b'\x8B\xDF\x08\xF0'
    b[code_offset:code_offset + 0x1000] = new_boot
    pid = new_boot[0xFF8:0xFFC]                   # ID0..ID3
    b[INFO_OFFSET:INFO_OFFSET + 16] = bytes([pid[3], pid[2], pid[1], pid[0], new_boot[0xFFC],
                                              0, 0, 0]) + b'UPD-BOOT'
    return bytes(b)
