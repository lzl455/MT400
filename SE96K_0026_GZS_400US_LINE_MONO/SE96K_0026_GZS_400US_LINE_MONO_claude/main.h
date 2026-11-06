/*******************************************************************************
* Copyright (c) 2013, SHENZHEN BEIHAI Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.h
*
* 功能说明: 主函数头文件
* 修改说明:
*******************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 配置常量定义区
//
#define nop                     NOP()

#define iDEVICE_TYPE_USB        0x08
#define iDEVICE_TYPE_BT0        0x00
#define iDEVICE_TYPE_BT1        0x01
#define iDEVICE_TYPE_BT2        0x02
#define iDEVICE_TYPE_BT3        0x03
#define iDEVICE_TYPE_BT4        0x04
#define iDEVICE_TYPE_24G        0x05
#define iDEVICE_TYPE_VALID      0x0F

//=============================================================================;
// 外部定义内部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 外部寄存器引用
//

//-----------------------------------------------------------------------------;
// 外部函数引用
//

//=============================================================================;
// 内部定义外部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 寄存器引用
//
extern USBD_U8                  usys_ctrl_reg;
//{
    #define sys_ctrl_reg        usys_ctrl_reg.u8

    #define bwrite_flash        usys_ctrl_reg.BIT.b7
    #define bkey_scan           usys_ctrl_reg.BIT.b6
    #define bwin_mac_sataus     usys_ctrl_reg.BIT.b4 // 1 WIN; 0 MAC

    #define bconn_type_usb      usys_ctrl_reg.BIT.b3
    //#define bconn_type_bt       usys_ctrl_reg.BIT.b1
    //#define bconn_type_24g      usys_ctrl_reg.BIT.b0
//}

extern USBD_U8                  utemp_bit;
//{
    #define temp_bit            utemp_bit.u8

    #define btemp_bit7          utemp_bit.BIT.b7
    #define btemp_bit6          utemp_bit.BIT.b6
    #define btemp_bit5          utemp_bit.BIT.b5
    #define btemp_bit4          utemp_bit.BIT.b4
    #define btemp_bit3          utemp_bit.BIT.b3
    #define btemp_bit2          utemp_bit.BIT.b2
    #define btemp_bit1          utemp_bit.BIT.b1
    #define btemp_bit0          utemp_bit.BIT.b0
//}

extern unsigned char            sof_count;
extern unsigned char            gtemp_i;
extern unsigned char            gtemp_j;

extern unsigned char            SwBusTimer;

extern unsigned char            led_index;
extern unsigned char            led_index_value;
extern unsigned char            led_scan_count;

extern unsigned char               my_led_flag;     //灯光模式，0是关闭灯光，1是开启灯光

extern unsigned char            matrix_status_bak[];

//-----------------------------------------------------------------------------;
// 函数引用
//
extern void none(void);

//
//-----------------------------------------------------------------------------;
#endif
