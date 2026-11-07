#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
把 BootLoader 工程编译出的 Intel HEX 转成 C 源文件

用法:
    python hex2c.py <Boot 的 output/SE95K.hex> [输出 boot_image.c]
        生成 Updater 用的 boot_image.c / boot_image.h (默认 ../boot_image.c)

    python hex2c.py <Boot hex> --app-bootloader [BootLoader_bin.c]
        同时更新 App 工程 driver/BootLoader_bin.c 中的 bootloader_0[] 数组
        (不给路径时使用仓库内 SE96K App 工程的该文件)

    python hex2c.py <Boot hex> --app-bootloader --no-updater
        只更新 BootLoader_bin.c, 不动 boot_image.c / .h

检查项:
    * 数据只能落在 0x0000-0x0FFF (Boot 区), 否则报错
    * 0x0FFD-0x0FFF 必须是 Boot 版本信息尾标记 AA 55 5A
    * 0x0FF8-0x0FFB 为项目 ID, 打印出来供人工核对
生成:
    boot_image.c       boot_image[4096] Boot 区完整镜像 (未使用字节填 0xFF)
                       boot_image_sum   镜像 16 位累加和, Updater 运行时校验
    boot_image.h       BOOT_IMAGE_VER / BOOT_IMAGE_PID0~3, 供 Updater 标识信息使用
    BootLoader_bin.c   只替换 bootloader_0[] 大括号内的数据和上方一行说明,
                       文件其余内容 (含 debug / bootloader 开关状态) 保持不变;
                       文件不存在时按原有结构新建 (两个开关均为注释状态)
"""
import argparse
import os
import sys

BOOT_SIZE = 0x1000
PAGE = 128

HERE = os.path.dirname(os.path.abspath(__file__))
DEF_BOOT_IMAGE = os.path.join(HERE, '..', 'boot_image.c')
DEF_APP_BOOTLOADER = os.path.join(HERE, '..', '..', 'SE96K_0026_GZS_400US_LINE_MONO',
                                  'SE96K_0026_GZS_400US_LINE_MONO_claude', 'driver', 'BootLoader_bin.c')

ARRAY_DECL = 'static const unsigned char bootloader_0[0x1000] @0x0000 ='
INFO_TAG = '// hex2c:'


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


# ============================================================================
# Updater: boot_image.c / boot_image.h
#
def write_updater_files(out, src, img, pid, ver, total, pages):
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

    hdr = os.path.join(os.path.dirname(os.path.abspath(out)), 'boot_image.h')
    h = []
    h.append('/' + '*' * 79)
    h.append('* 文件名称: boot_image.h')
    h.append('*')
    h.append('* 功能说明: 新 BootLoader 镜像信息')
    h.append('*           本文件由 tools/hex2c.py 自动生成, 请勿手工修改')
    h.append('*' * 79 + '/')
    h.append('#ifndef _BOOT_IMAGE_H_')
    h.append('#define _BOOT_IMAGE_H_')
    h.append('')
    h.append('#define BOOT_IMAGE_PID0         0x%02X' % pid[0])
    h.append('#define BOOT_IMAGE_PID1         0x%02X' % pid[1])
    h.append('#define BOOT_IMAGE_PID2         0x%02X' % pid[2])
    h.append('#define BOOT_IMAGE_PID3         0x%02X' % pid[3])
    h.append('#define BOOT_IMAGE_VER          %d' % ver)
    h.append('')
    h.append('#endif')
    h.append('')
    with open(hdr, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(h))

    print('输出: %s' % os.path.abspath(out))
    print('输出: %s' % os.path.abspath(hdr))


# ============================================================================
# App: driver/BootLoader_bin.c
#
def array_body(img):
    """与原 BootLoader_bin.c 相同的格式: 两空格缩进, 每行 16 字节, 最后一个无逗号"""
    rows = []
    for p in range(0, BOOT_SIZE, 16):
        rows.append('  ' + ', '.join('0x%02X' % b for b in img[p:p + 16]))
    return ',\n'.join(rows)


NEW_FILE_TEMPLATE = """/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: BootLoader_bin.c
*
* 功能说明: Boot 区 (0x0000-0x0FFF) 数据
*           debug      : 只放复位/中断跳转, 无 Boot 时仿真调试 App
*           bootloader : 放完整 Boot, 编出整片量产烧录镜像
*           两者都不定义: 编出给驱动升级用的 App (0x1000 起)
* 修改说明:
*******************************************************************************/

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;
//#define debug
//#define bootloader

#ifdef debug

const unsigned int start[2] @0x0000 =
{
    0xDF00, 0xF008,                     // goto 0x1000
};
const unsigned int low_int[2] @0x0008 =
{
    0xDF04, 0xF008,                     // goto 0x1008
};
const unsigned int high_int[2] @0x0018 =
{
    0xDF0C, 0xF008,                     // goto 0x1018
};
#endif

#ifdef bootloader

%(info)s
%(decl)s
{
%(body)s
};

/*** end of file ***/

#endif
"""


def write_app_bootloader(path, src, img, pid, ver):
    info = ('%s 由 hex2c.py 生成, 来源 %s, 项目ID %02X %02X %02X %02X, Boot版本 %d'
            % (INFO_TAG, os.path.basename(src), pid[0], pid[1], pid[2], pid[3], ver))
    body = array_body(img)

    if not os.path.exists(path):
        text = NEW_FILE_TEMPLATE % {'info': info, 'decl': ARRAY_DECL, 'body': body}
        newline = '\n'
        action = '新建'
    else:
        with open(path, 'r', encoding='utf-8', newline='') as f:
            raw = f.read()
        newline = '\r\n' if '\r\n' in raw else '\n'
        t = raw.replace('\r\n', '\n')

        k = t.find(ARRAY_DECL)
        if k < 0 or t.find(ARRAY_DECL, k + 1) >= 0:
            sys.exit('错误: %s 中应恰好有一处 "%s"' % (path, ARRAY_DECL))
        lb = t.find('{', k)
        rb = t.find('};', lb)
        if lb < 0 or rb < 0:
            sys.exit('错误: %s 中 bootloader_0[] 的大括号不完整' % path)

        decl_line = t.rfind('\n', 0, k) + 1             # 声明所在行的行首
        prev_line = t.rfind('\n', 0, decl_line - 1) + 1 if decl_line > 0 else 0
        if decl_line > 0 and t[prev_line:decl_line].startswith(INFO_TAG):
            head = t[:prev_line]                         # 替换旧的说明行
        else:
            head = t[:decl_line]                         # 插入说明行
        text = head + info + '\n' + t[decl_line:lb + 1] + '\n' + body + '\n' + t[rb:]
        action = '更新'

    with open(path, 'w', encoding='utf-8', newline='') as f:
        f.write(text.replace('\n', newline))
    print('%s: %s' % (action, os.path.abspath(path)))


# ============================================================================
def main():
    ap = argparse.ArgumentParser(description='Boot hex -> C 源文件',
                                 formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument('hex', help='Boot 工程编译出的 output/SE95K.hex')
    ap.add_argument('out', nargs='?', default=DEF_BOOT_IMAGE, help='Updater 的 boot_image.c 路径')
    ap.add_argument('--app-bootloader', nargs='?', const=DEF_APP_BOOTLOADER, metavar='BootLoader_bin.c',
                    help='同时更新 App 工程的 BootLoader_bin.c (省略路径则用仓库内 SE96K App 工程)')
    ap.add_argument('--no-updater', action='store_true', help='不生成 boot_image.c / .h')
    args = ap.parse_args()
    if args.no_updater and not args.app_bootloader:
        sys.exit('错误: --no-updater 需要与 --app-bootloader 一起使用')

    src = args.hex
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

    if not args.no_updater:
        write_updater_files(args.out, src, img, pid, ver, total, pages)
    if args.app_bootloader:
        write_app_bootloader(args.app_bootloader, src, img, pid, ver)

    print('项目ID: %02X %02X %02X %02X  Boot版本: %d  累加和: 0x%04X  使用页数: %d/32'
          % (pid[0], pid[1], pid[2], pid[3], ver, total, pages))


if __name__ == '__main__':
    main()
