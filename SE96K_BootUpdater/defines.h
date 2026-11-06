/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: defines.h
*
* 功能说明: Boot 更新程序 (Updater) 公共定义
* 修改说明:
*******************************************************************************/
#ifndef _DEFINES_H_
#define _DEFINES_H_

//----------------------------------------------------------------------------;
// 外部头文件引用
//
#include <zc.h>

//----------------------------------------------------------------------------;
// 地址定义 (与 BootLoader / App 工程保持一致)
//
#define iBOOT_START_ADDR        0x0000      // Boot 区起始
#define iBOOT_SIZE              0x1000      // Boot 区大小 4KB
#define iPAGE_SIZE              128         // Flash 页大小
#define iBOOT_PAGE_NUM          (iBOOT_SIZE/iPAGE_SIZE)

#define iBOOT_INFO_ADDR         0x0FF0      // Boot 版本信息 boot_fw_vs[]
#define iBOOT_PID_OFFSET        0x08        // 项目ID 在版本信息中的偏移
#define iBOOT_TAG_OFFSET        0x0D        // 尾标记 AA 55 5A 的偏移

#define iUPD_INFO_ADDR          0x6FF0      // Updater 标识信息, 与 App fw_info 同址

//----------------------------------------------------------------------------;
// 跳转 Boot 标志, 与 App usb_user_process.c / Boot MAIN.C 一致
//
#define iBOOT_FLAG_0            0x3C
#define iBOOT_FLAG_1            0xC3
#define iBOOT_FLAG_2            0x55
#define iBOOT_FLAG_3            0xAA

//----------------------------------------------------------------------------;
// 每页写入失败重试次数
//
#define iWRITE_RETRY            3

//----------------------------------------------------------------------------;
// 外部引用
//
extern unsigned char const      boot_image[iBOOT_SIZE];
extern unsigned int const       boot_image_sum;

extern unsigned char            page_buf[iPAGE_SIZE];

extern unsigned char flash_page_write(unsigned int addr);
extern unsigned char flash_page_compare(unsigned int addr);

#endif
