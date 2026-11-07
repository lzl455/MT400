# -*- coding: utf-8 -*-
"""
真实设备传输层 (hidapi: pip install hidapi)

处理 App / Boot 报文差异:
    App : 有 Report ID 0x0F, out[0]=0x0F 本身就是 Report ID, 直接写 32 字节
    Boot: 无 Report ID, 写入时前面补 0x00 (33 字节)
    读  : hidapi 读回的数据不含 Report ID 0, 两者都直接对应 in[0..31]
"""
from protocol import (APP_VID, APP_PID, APP_USAGE_PAGE, APP_INTERFACE,
                      BOOT_VID, BOOT_PID, BOOT_USAGE_PAGE, BOOT_INTERFACE)

try:
    import hid
except ImportError:          # 允许无 hidapi 时使用模拟器
    hid = None

TARGETS = {
    'app': (APP_VID, APP_PID, APP_USAGE_PAGE, APP_INTERFACE),
    'boot': (BOOT_VID, BOOT_PID, BOOT_USAGE_PAGE, BOOT_INTERFACE),
}


def _require():
    if hid is None:
        raise RuntimeError('未安装 hidapi: pip install hidapi')


def find_paths(kind):
    """
    按 VID/PID + UsagePage 找升级用的 HID 路径。
    App 是复合设备, 必须筛 UsagePage; 个别平台 (旧版 Linux hidraw) 取不到
    UsagePage 时退回按接口号匹配。
    """
    _require()
    vid, pid, up, ifn = TARGETS[kind]
    paths = []
    for d in hid.enumerate(vid, pid):
        dup = d.get('usage_page') or 0
        if dup == up or (dup == 0 and d.get('interface_number') == ifn):
            if d['path'] not in paths:
                paths.append(d['path'])
    return paths


def list_all():
    """列出所有相关 HID 路径, 便于排查"""
    _require()
    out = []
    for kind, (vid, pid, _, _) in TARGETS.items():
        for d in hid.enumerate(vid, pid):
            out.append((kind, d))
    return out


class HidLink(object):
    def __init__(self, kind, path):
        _require()
        self.kind = kind
        self.dev = hid.device()
        self.dev.open_path(path)

    def send(self, out):
        out = bytes(out)
        buf = (b'\x00' + out) if self.kind == 'boot' else out
        try:
            n = self.dev.write(list(buf))
        except (IOError, OSError, ValueError) as e:
            raise IOError('写入失败: %s' % e)
        if n < 0:
            raise IOError('写入失败 (设备可能已断开)')

    def recv(self, timeout_s):
        try:
            data = self.dev.read(64, max(1, int(timeout_s * 1000)))
        except (IOError, OSError, ValueError):
            return None
        if not data:
            return None
        data = bytes(data)
        if self.kind == 'boot' and len(data) == 33 and data[0] == 0x00:
            data = data[1:]                    # 个别平台会带上 Report ID 0
        return data[:32].ljust(32, b'\x00')

    def flush(self):
        try:
            while self.dev.read(64, 1):
                pass
        except (IOError, OSError, ValueError):
            pass

    def close(self):
        try:
            self.dev.close()
        except Exception:
            pass


class HidBus(object):
    def __init__(self, index=0):
        self.index = index        # 同时插多把时选第几把 (仅对 App 有意义)

    def find(self, kind):
        return len(find_paths(kind)) > 0

    def open(self, kind):
        paths = find_paths(kind)
        if not paths:
            raise IOError('未找到 %s 设备' % kind)
        if len(paths) > 1 and kind == 'boot':
            raise IOError('发现 %d 个 Boot 设备, 无法区分, 请只保留一把键盘' % len(paths))
        return HidLink(kind, paths[min(self.index, len(paths) - 1)])
