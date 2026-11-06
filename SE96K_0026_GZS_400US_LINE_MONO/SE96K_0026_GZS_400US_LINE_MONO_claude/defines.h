/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
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
#include "system_sleep.h"
#include "main.h"

#include ".\driver\time.h"

#include ".\hal\hid_process.h"
#include ".\hal\matrix_key.h"
#include ".\hal\userdefined_key.h"
#include ".\hal\key_code_define.h"
#include ".\hal\flash_process.h"
#include ".\hal\wheel.h"

#include ".\led\led_logo.h"
#include ".\led\led_logo_tbl.h"
#include ".\led\wheel_led.h"

//----------------------------------------------------------------------------;
// 函数声明
//

//----------------------------------------------------------------------------;
// 通用类型定义
//
unsigned char                   led_index_value @ 0X0050;
enum led_level                  led_light_lev   @ 0X0051;
unsigned char                   int_temp0       @ 0X0052;
unsigned char                   led_index       @ 0X0054;
unsigned char                   int_ioa_dat     @ 0X0055;
unsigned char                   int_iob_dat     @ 0X0056;
unsigned char                   int_ioc_dat     @ 0X0057;
unsigned char                   int_iod_dat     @ 0X0058;

unsigned char                   pwm_duty_array[0x80] @ 0X0100;

unsigned char                   bootloader_val[4] @ 0X0280;

//-----------------------------------------------------------------------------;
// IO定义区
//
#define                 PF0     IOF0
#define                 PF1     IOF1
#define                 PF2     IOF2
#define                 PF3     IOF3
#define                 PF4     IOF4
#define                 PF5     IOF5
#define                 PF6     IOF6
#define                 PF7     IOF7

#define                 PE0     IOE0
#define                 PE1     IOE1
#define                 PE2     IOE2
#define                 PE3     IOE3
#define                 PE4     IOE4
#define                 PE5     IOE5
#define                 PE6     IOE6
#define                 PE7     IOE7

#define                 PD0     IOD0
#define                 PD1     IOD1
#define                 PD2     IOD2
#define                 PD3     IOD3
#define                 PD4     IOD4
#define                 PD5     IOD5
#define                 PD6     IOD6
#define                 PD7     IOD7

#define                 PC0     IOC0
#define                 PC1     IOC1
#define                 PC2     IOC2
#define                 PC3     IOC3
#define                 PC4     IOC4
#define                 PC5     IOC5
#define                 PC6     IOC6
#define                 PC7     IOC7

#define                 PB0     IOB0
#define                 PB1     IOB1
#define                 PB2     IOB2
#define                 PB3     IOB3
#define                 PB4     IOB4
#define                 PB5     IOB5
#define                 PB6     IOB6
#define                 PB7     IOB7

#define                 PA0     IOA0
#define                 PA1     IOA1
#define                 PA2     IOA2
#define                 PA3     IOA3
#define                 PA4     IOA4
#define                 PA5     IOA5
#define                 PA6     IOA6
#define                 PA7     IOA7
//
//----------------------------------------------------------------------------;

//----------------------------------------------------------------------------;
// 通用宏定义
//

//
//----------------------------------------------------------------------------;

//----------------------------------------------------------------------------;
// 项目ID定义区 项目立项的时候分配的项目ID
//
// #define iPROJECT_ID_0           0x00
// #define iPROJECT_ID_1           0x91
// #define iPROJECT_ID_2           0x00
// #define iPROJECT_ID_3           0x15
#define iPROJECT_ID_0           0x00
#define iPROJECT_ID_1           0x96
#define iPROJECT_ID_2           0x00
#define iPROJECT_ID_3           0x28
//----------------------------------------------------------------------------;
// 程序版本定义区 程序版本升级编号
//
// #define iVERSION_ID             2
// #define iUSB_STR_ID             '2'
// #define iHID_VS_ID              iSTD_2

#define iVERSION_ID             3
#define iUSB_STR_ID             '1'
#define iHID_VS_ID              iSTD_1

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
//
extern void flash_save_info(unsigned int addr);
extern void flash_program(unsigned int addr, unsigned char length);
extern void flash_read(unsigned int addr);
extern void flash_clear(unsigned char bank);
extern void flash_clear_info(void);
extern void fcc_test_process(void);
//
//----------------------------------------------------------------------------;

#endif

