#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
把 BootLoader 工程编译出的 Intel HEX 转成 Updater 工程使用的 boot_image.c

用法:
    python hex2c.py <Boot 的 output/SE95K.hex> [输出 boot_image.c]

检查项:
    * 数据只能落在 0x0000-0x0FFF (Boot 区), 否则报错
    * 0x0FFD-0x0FFF 必须是 Boot 版本信息尾标记 AA 55 5A
    * 0x0FF8-0x0FFB 为项目 ID, 打印出来供人工核对
生成:
    boot_image[4096]       Boot 区完整镜像 (未使用字节填 0xFF)
    BOOT_IMAGE_SUM         镜像 16 位累加和, Updater 运行时校验
"""
import sys
import os

BOOT_SIZE = 0x1000
PAGE = 128


def parse_hex(path):
    img = bytearray([0xFF] * BOOT_SIZE)
    used = bytearray(BOOT_SIZE)
    base = 0
    with open(path, 'r') as f:
        for n, line in enumerate(f, 1):
            line = line.strip()
            if not line:
                continue
            if line[0] != ':':
                raise ValueError('第 %d 行不是 Intel HEX 记录' % n)
            raw = bytes.fromhex(line[1:])
            if (sum(raw) & 0xFF) != 0:
                raise ValueError('第 %d 行校验和错误' % n)
            cnt, addr, rtype = raw[0], (raw[1] << 8) | raw[2], raw[3]
            data = raw[4:4 + cnt]
            if rtype == 0x00:
                a = base + addr
                if a + cnt > BOOT_SIZE:
                    raise ValueError('第 %d 行地址 0x%04X 超出 Boot 区 0x0000-0x0FFF' % (n, a))
                img[a:a + cnt] = data
                for i in range(cnt):
                    used[a + i] = 1
            elif rtype == 0x01:
                break
            elif rtype == 0x02:
                base = ((data[0] << 8) | data[1]) << 4
            elif rtype == 0x04:
                base = ((data[0] << 8) | data[1]) << 16
            elif rtype in (0x03, 0x05):
                pass
            else:
                raise ValueError('第 %d 行未知记录类型 0x%02X' % (n, rtype))
    return img, used


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)
    src = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), '..', 'boot_image.c')

    try:
        img, used = parse_hex(src)
    except (ValueError, OSError) as e:
        sys.exit('错误: %s' % e)

    if img[0xFFD:0x1000] != b'\xAA\x55\x5A':
        sys.exit('错误: 0x0FFD-0x0FFF 不是 AA 55 5A, 这不像是 Boot 镜像')
    if img[0x0000:0x0004] == b'\xFF\xFF\xFF\xFF':
        sys.exit('错误: 0x0000 复位向量为空')

    pid = img[0xFF8:0xFFC]
    ver = img[0xFFC]
    total = sum(img) & 0xFFFF
    pages = sum(1 for p in range(0, BOOT_SIZE, PAGE) if any(used[p:p + PAGE]))

    lines = []
    lines.append('/' + '*' * 79)
    lines.append('* 文件名称: boot_image.c')
    lines.append('*')
    lines.append('* 功能说明: 新 BootLoader 镜像 (0x0000-0x0FFF)')
    lines.append('*           本文件由 tools/hex2c.py 自动生成, 请勿手工修改')
    lines.append('*           来源: %s' % os.path.basename(src))
    lines.append('*           项目ID: %02X %02X %02X %02X  Boot版本: %d  使用页数: %d/32'
                 % (pid[0], pid[1], pid[2], pid[3], ver, pages))
    lines.append('*' * 79 + '/')
    lines.append('#include "defines.h"')
    lines.append('')
    lines.append('unsigned int const boot_image_sum = 0x%04X;' % total)
    lines.append('')
    lines.append('unsigned char const boot_image[%d] =' % BOOT_SIZE)
    lines.append('{')
    for p in range(0, BOOT_SIZE, 16):
        if p % 0x100 == 0:
            lines.append('//---------------------------------------------- 0x%04X' % p)
        lines.append('    ' + ' '.join('0x%02X,' % b for b in img[p:p + 16]))
    lines.append('};')
    lines.append('')

    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines))

    print('输出: %s' % os.path.abspath(out))
    print('项目ID: %02X %02X %02X %02X  Boot版本: %d  累加和: 0x%04X  使用页数: %d/32'
          % (pid[0], pid[1], pid[2], pid[3], ver, total, pages))


if __name__ == '__main__':
    main()
