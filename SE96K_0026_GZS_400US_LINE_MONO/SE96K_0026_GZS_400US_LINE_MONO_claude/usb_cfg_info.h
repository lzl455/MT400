/*******************************************************************************
* Copyright (c) 2012, SHENZHEN BEIHAI Co.,LTD.
* All rights reserved.
*
* 文件名称: USB_Cfg_Info.h
* 文件描述: USB库文件配置头文件
* 版    本: V1.0.0
* 作    者: 易谦
* 日    期: 2013-1-8
*******************************************************************************/
#ifndef _USB_CFG_INFO_
#define _USB_CFG_INFO_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//-----------------------------------------------------------------------------;
//配置常量定义区
//
#define     iREPORT_ID_MOUSE                    0x02
#define     iREPORT_ID_MULTIM_KEY               0x01
#define     iREPORT_ID_SYSTEM_KEY               0x03
#define     iREPORT_ID_KB_KEY                   0x05
#define     iREPORT_ID_CUSTOMER_DATA            0x0F

//-----------------------------------------------------------------------------;
//配置区
//
//USB EndPoint Size Config
#define MAX_EP0_SIZE 32

#define MAX_EP1_SIZE 32
#define MAX_EP2_SIZE 32
#define MAX_EP3_SIZE 16
#define MAX_EP4_SIZE 64
#define MAX_EP5_SIZE 64

//---------------------------------------------------------------------------
//Register Config(User can ignore this part)
//---------------------------------------------------------------------------
#define	BIT_UE		0X01
#define BIT_USHC	0X08
#define BIT_UFS		0X04

#define BIT_INTBUS	0X01
#define	BIT_INTEP0	0X02

#define	BIT_INTEP1	0X04
#define EP1SIZE     MAX_EP1_SIZE
#define	BIT_INTEP2	0X08
#define EP2SIZE     MAX_EP2_SIZE
#define	BIT_INTEP3	0X10
#define EP3SIZE     MAX_EP3_SIZE
#define BIT_INTEP4	0X00
#define EP4SIZE     MAX_EP4_SIZE
#define BIT_INTEP5	0X00
#define EP5SIZE 0

#define UE1CON_RSET 0X0C
#define UE2CON_RSET 0X0C
#define UE3CON_RSET 0X0C
#define UE4CON_RSET 0X0C
#define UE5CON_RSET 0X0C

//=============================================================================;
// 外部定义内部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 外部寄存器引用
//

//=============================================================================;
// 内部定义外部部引用区                                                        ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 寄存器引用
//
extern unsigned char	        USBEnumState;

extern USBD_U8                  uusb_data_flag;
//{
    #define usb_data_flag       uusb_data_flag.u8

    #define bhid_data_send      uusb_data_flag.BIT.b6
    #define bfn_data_send       uusb_data_flag.BIT.b5
    #define bstd_exdata_send    uusb_data_flag.BIT.b4
    #define bmmk_data_send      uusb_data_flag.BIT.b2
    #define bstd_data_send      uusb_data_flag.BIT.b1
    #define bmouse_data_send    uusb_data_flag.BIT.b0
//}

extern unsigned char            std_kb_data[8];
//{
    #define std_kb_data_key0    std_kb_data[0]
    #define std_kb_data_key1    std_kb_data[2]
    #define std_kb_data_key2    std_kb_data[3]
    #define std_kb_data_key3    std_kb_data[4]
    #define std_kb_data_key4    std_kb_data[5]
    #define std_kb_data_key5    std_kb_data[6]
    #define std_kb_data_key6    std_kb_data[7]
//}

extern unsigned char            out_report_data[];
extern unsigned char            in_report_data[];

//-----------------------------------------------------------------------------;
// 函数引用
//
extern void USBD_CalibrationInit(void);
extern void USBD_Init(void);
extern void USBD_SwBusInit(void);
extern void USBD_disable(void);
extern void usb_data_process(void);

extern void USBD_EP0_Handler(void);
//
//----------------------------------------------------------------------------;

#endif

