/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: UserDefined_Key.h
*
* 功能说明: 
* 修改说明:
*******************************************************************************/
#ifndef _USERDEFINED_KEY_H_
#define _USERDEFINED_KEY_H_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//-----------------------------------------------------------------------------;
//配置常量定义区
//

//-----------------------------------------------------------------------------;
//配置区
//

//=============================================================================;
// 外部定义内部引用区
//=============================================================================;

//=============================================================================;
// 外部寄存器引用
//
USBD_U8                         udefine_key_status;
//{
    #define define_key_status   udefine_key_status.u8

    #define bkey_break_or_realse udefine_key_status.BIT.b1
    #define bkey_status_change  udefine_key_status.BIT.b0
//}

extern unsigned char        define_key_ctrl;
//{
    #define bdefine_key_send    (1<<7)
    #define bdpi_fast_change    (1<<6)
    #define bmouse_key_press    (1<<5)
    #define bcom_decode_ing     (1<<4)
    #define bcom_key_break      (1<<3)
//}

extern USBD_U8                  udecode_data_l;
//{
    #define decode_data_l       udecode_data_l.u8

    #define bkey_code_b7        udecode_data_l.BIT.b7
    #define bkey_code_b6        udecode_data_l.BIT.b6
    #define bkey_code_b5        udecode_data_l.BIT.b5
    #define bkey_code_b4        udecode_data_l.BIT.b4
    #define bkey_code_b3        udecode_data_l.BIT.b3
    #define bkey_code_b2        udecode_data_l.BIT.b2
    #define bkey_code_b1        udecode_data_l.BIT.b1
    #define bkey_code_b0        udecode_data_l.BIT.b0
//}
extern USBD_U8                  udecode_data_h;
//{
    #define decode_data_h       udecode_data_h.u8

    #define bkey_code_b15       udecode_data_h.BIT.b7
    #define bkey_code_b14       udecode_data_h.BIT.b6
    #define bkey_code_b13       udecode_data_h.BIT.b5
    #define bkey_code_b12       udecode_data_h.BIT.b4
    #define bkey_code_b11       udecode_data_h.BIT.b3
    #define bkey_code_b10       udecode_data_h.BIT.b2
    #define bkey_code_b9        udecode_data_h.BIT.b1
    #define bkey_code_b8        udecode_data_h.BIT.b0
//}

extern unsigned char            com_key_index;

extern unsigned char                   MY_SIRI_TIME;

#define define_key_flag_n       define_key_fifo[led_index]

extern unsigned char            define_key_flag;
//{
    #define bcom_key_realse_did (1<<6)
    #define bdefine_delay_flag  (1<<5)
    #define bdefine_key_com     (1<<4)
    #define bkb_led_back        (1<<3)
    #define bdefine_key_press   (1<<2)
    #define bkey_decode_end     (1<<1)
    #define bkey_decode         (1<<0)
//}
//=============================================================================;
// 外部函数引用
//

//=============================================================================;
// 内部定义外部引用区
//=============================================================================;

//=============================================================================;
// 寄存器引用
//

//=============================================================================;
// 函数引用
//
extern void define_key_process(void);

#endif
