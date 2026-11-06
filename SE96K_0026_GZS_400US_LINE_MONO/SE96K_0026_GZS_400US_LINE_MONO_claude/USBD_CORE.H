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
#ifndef _USBD_CORE_H
#define _USBD_CORE_H

#include "types.h"

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//bmRequesetType
#define Direction	0X80		                // D7,传输方向
#define Re_Type		0X60		                // D6-D5请求类型
#define Recipient	0X1F		                // D4-D0 接收对象

#define	EP0BUFF_ADDR        (unsigned char*)0X800
#define	EP1BUFF_ADDR        (unsigned char*)0X822
#define	EP2BUFF_ADDR        (unsigned char*)0X844
#define	EP3BUFF_ADDR        (unsigned char*)0X866
#define	EP4BUFF_ADDR        (unsigned char*)0X878
#define	EP5BUFF_ADDR        (unsigned char*)0X8BA

#define EP0CON_ADDR	        (unsigned char*)0XF77
#define EP1CON_ADDR	        (unsigned char*)0XF75
#define EP2CON_ADDR	        (unsigned char*)0XF73
#define EP3CON_ADDR	        (unsigned char*)0XF71
#define EP4CON_ADDR	        (unsigned char*)0XF6F
#define EP5CON_ADDR	        (unsigned char*)0XF6D

#define EP0IOPS_ADDR        (unsigned char*)0XF76
#define EP1IOPS_ADDR        (unsigned char*)0XF74
#define EP2IOPS_ADDR        (unsigned char*)0XF72
#define EP3IOPS_ADDR        (unsigned char*)0XF70
#define EP4IOPS_ADDR        (unsigned char*)0XF6E
#define EP5IOPS_ADDR        (unsigned char*)0XF6C

//-----------------------------------------------------------------------------;
//配置区
//

//=============================================================================;
// 外部定义内部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 外部寄存器引用
//
typedef enum
{
	Dir_HostToSlave = 0X00,		                // 主机到设备
	Dir_SlaveToHost = 0X80,		                // 设备到主机
}DIRECTION_ENUM;

typedef enum
{
	ReType_Standard=0X00,		                //标准请求
	ReType_Class=0X20,			                //类请求
	ReType_Manufacturer=0X40,                   //厂商请求
}RETYPE_ENUM;

typedef enum
{
	Rec_Device=0,		                        // 设备
	Rec_Interface=1,	                        // 接口
	Rec_EndPoint=2,		                        // 端点
	Rec_Other = 3,		                        // 其它
}RECIPIENT_ENUM;

typedef enum
{
	GET_STATUS=0,
	CLEAR_FEATURE=1,
	SET_FEATURE=3,
	SET_ADDRESS=5,
	GET_DESCRIPTOR=6,
	SET_DESCRIPTOR=7,
	GET_CONFIGURATION=8,
	SET_CONFIGURATION=9,
	GET_INTERFACE=10,
	SET_INTERFACE=11,
	SYNCH_FRAME=12,
}STANDARD_REQUEST;

typedef enum
{
	GET_REPORT=0x01,
	GET_IDLE=0x02,
	GET_PROTOCOL=0x03,
	SET_REPORT=0x09,
	SET_IDLE=0x0A,
	SET_PROTOCOL=0x0B,
}CLASS_REQUEST;

typedef enum
{
	GET_DEV_DES=0x01,
	GET_CONFIG_DES=0x02,
	GET_STR_DES=0x03,
	GET_BOS_DES=0X0F,
	GET_CLASS_HID_DES=0x21,
	GET_CLASS_HID_REPORT=0x22,
}DESCRIPTOR_REQUEST;

typedef enum
{
	USBE_Default,
	USBE_Address,
	USBE_Configured,
}USBENUM_STATE;

//=============================================================================;
// 内部定义外部部引用区                                                        ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 寄存器引用
//
unsigned char               USBEnumState;

USBD_U8                     uUSBSwState;
//{
    #define USBSwState          uUSBSwState.u8
    #define busb_suspend_en     uUSBSwState.BIT.b0
    #define busb_suspend_en_bak uUSBSwState.BIT.b2
//}

USBD_U8                     uusb_ctrl_flag;
//{
    #define usb_ctrl_flag       uusb_ctrl_flag.u8
    #define bwakeup_usb_enable  uusb_ctrl_flag.BIT.b5
    #define bep1_ep2_enable     uusb_ctrl_flag.BIT.b4
    #define busb_report_set     uusb_ctrl_flag.BIT.b3
    #define bUSBRemoteSleep     uusb_ctrl_flag.BIT.b1
//}

USBD_U8                     uusb_status_reg;
//{
    #define usb_status_reg      uusb_status_reg.u8

    #define bkb_led_valid       uusb_status_reg.BIT.b7
    #define busb_enum_finish    uusb_status_reg.BIT.b5
    #define busb_boot           uusb_status_reg.BIT.b4
    #define busb_reset          uusb_status_reg.BIT.b3
    #define bscroll_lock        uusb_status_reg.BIT.b2
    #define bcaps_lock          uusb_status_reg.BIT.b1
    #define bnum_lock           uusb_status_reg.BIT.b0
//}

USBD_U8                     uEpState;
//{
    #define EpState             uEpState.u8
    #define bEp0Stall           uEpState.BIT.b0
    #define bEp1InStall         uEpState.BIT.b1
    #define bEp1OutStall        uEpState.BIT.b2
    #define bEp2InStall         uEpState.BIT.b3
    #define bEp2OutStall        uEpState.BIT.b4
    #define bEp3InStall         uEpState.BIT.b5
    #define bEp3OutStall        uEpState.BIT.b6
//}

unsigned char               IdleRate;
unsigned char               usb_report_lenght;

USBD_U8                     uUSBEpBusy;
//{
    #define USBEpBusy           uUSBEpBusy.u8
    #define bEp1Busy            uUSBEpBusy.BIT.b0
    #define bEp2Busy            uUSBEpBusy.BIT.b1
    #define bEp3Busy            uUSBEpBusy.BIT.b2
    #define bEp4Busy            uUSBEpBusy.BIT.b3
    #define bEp5Busy            uUSBEpBusy.BIT.b4
//}

unsigned char               UsbEp0Buffer[32+2] @(0X800);	//端点1缓存起始地址
//{
    #define bmRequestType       UsbEp0Buffer[0]
    #define bRequest            UsbEp0Buffer[1]
    #define wValuel             UsbEp0Buffer[2]
    #define wValueh             UsbEp0Buffer[3]
    #define wIndexl             UsbEp0Buffer[4]
    #define wIndexh             UsbEp0Buffer[5]
    #define wLengthl            UsbEp0Buffer[6]
    #define wLengthh            UsbEp0Buffer[7]
//}
unsigned char               UsbEp1Buffer[32+2] @(0X822);	//端点1缓存起始地址
unsigned char               UsbEp2Buffer[32+2] @(0X844);	//端点2缓存起始地址
unsigned char               UsbEp3Buffer[16+2] @(0X866);	//端点3缓存起始地址
unsigned char               UsbEp4Buffer[64+2] @(0X878);	//端点4缓存起始地址
unsigned char               UsbEp5Buffer[64+2] @(0X8BA);	//端点5缓存起始地址

//-----------------------------------------------------------------------------;
// 函数引用
//
//
//-----------------------------------------------------------------------------;
#endif


