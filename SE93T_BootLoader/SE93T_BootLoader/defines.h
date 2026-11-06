/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: defines.h
*
* 功能说明: 
* 修改说明:
*******************************************************************************/
#ifndef _DEFINES_H_
#define _DEFINES_H_

//----------------------------------------------------------------------------;
// 外部头文件引用
//
#include <zc.h>
#include "types.h"

#include "usb_cfg_info.h"
#include "USBD_CORE.H"
#include "main.h"

#include "time.h"
#include "hid_process.h"

//----------------------------------------------------------------------------;
// 函数声明
//

//----------------------------------------------------------------------------;
// 通用类型定义
//
#define UpdateFlagAddr              0X7FFF
#define APP_StartAddr               0X1000      //用户工程编译起始地址

#define AppStartAddr_Word 			(APP_StartAddr>>1)
#define HB_AppStartAddr 			((AppStartAddr_Word&0XFF00)>>8)
#define LB_AppStartAddr             ((AppStartAddr_Word&0XFF)>>0)

#define ReMapLIntAddr               (AppStartAddr_Word+0X04)
#define HB_ReMapLIntAddr            ((ReMapLIntAddr&0XFF00)>>8)
#define LB_ReMapLIntAddr            ((ReMapLIntAddr&0XFF)>>0)

#define ReMapHIntAddr               (AppStartAddr_Word+0X0C)
#define HB_ReMapHIntAddr            ((ReMapHIntAddr&0XFF00)>>8)
#define LB_ReMapHIntAddr            ((ReMapHIntAddr&0XFF)>>0)

//----------------------------------------------------------------------------;
// 通用宏定义
//

//----------------------------------------------------------------------------;
// 项目ID定义区 项目立项的时候分配的项目ID
//

#define iPROJECT_ID_0           0x00
#define iPROJECT_ID_1           0x96
#define iPROJECT_ID_2           0x00    // 与 App 工程(SE96K_0026) defines.h 一致
#define iPROJECT_ID_3           0x28

//----------------------------------------------------------------------------;
// 程序版本定义区 程序版本升级编号
//
#define iVERSION_ID             2

//-----------------------------------------------------------------------------;
// 配置区
//

/*******************************************************************************

*******************************************************************************/

//=============================================================================;
// 外部定义内部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 外部寄存器引用
extern void flash_program(unsigned int addr, unsigned char length);

#endif


