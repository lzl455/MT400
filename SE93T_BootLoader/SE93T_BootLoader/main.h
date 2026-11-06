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
#define iDEVICE_TYPE_OFF        0xFF

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

    #define bkey_press          usys_ctrl_reg.BIT.b5
    #define bi2c_error     	    usys_ctrl_reg.BIT.b4
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

//-----------------------------------------------------------------------------;
// 函数引用
//
extern void none(void);
extern void memcpy(unsigned char  *ptr_d, unsigned char *ptr_s, unsigned char lenght);
extern void memset(unsigned char  *ptr_d, unsigned char const dat, unsigned char lenght);
//
//-----------------------------------------------------------------------------;
#endif
