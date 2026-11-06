/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.c
*
* 功能说明: 主函数处理程序
* 修改说明:
*******************************************************************************/
#include <zc.h>
#include <stdio.h>
#include "USBD_CORE.H"
#include "usb_cfg_info.h"
#include ".\hal\hid_process.h"
#include "usb_descriptor.h"

//-----------------------------------------------------------------------------;
// 常量定义
//
extern unsigned char const      HID_ReportDescriptor_Define[];
extern unsigned char const      HID_ReportDescriptor_Keyboard[];

extern unsigned char const      DeviceDesc[];

extern unsigned char const      ManuStringDesc[];
extern unsigned char const      SerialNumberStringDesc[];
extern unsigned char const      StringDescSerialNum[];

extern unsigned char const      ConfigurationDesc[];
extern unsigned char const      DeviceHidDescriptor_KB[];
extern unsigned char const      DeviceHidDescriptor_DEF[];
extern unsigned char const      LanguageIDDesc[];

extern unsigned char            DeviceDescSize;
extern unsigned char            LanguageIDDescSize;
extern unsigned char            ManuStringDescSize;
extern unsigned char            SerialNumStringDescSize;
extern unsigned char            SerialNumberStringDescSize;
extern unsigned char            ConfigurationDescSize;

extern unsigned char            KeyboardReportDescSize;
extern unsigned char            DefReportDescSize;

extern unsigned char            sof_count;
extern unsigned char            SwBusTimer;

extern USBD_U8                  ukb_led_bak;
//{
    #define kb_led_bak          ukb_led_bak.u8
//}

unsigned int                    usbcalisum;
unsigned char                   usbcalimax,usbcalimin,usbcalisimplecnt;

//-----------------------------------------------------------------------------;
// 变量定义
//
extern void timer_int_process(void);

#define USBCaliCnt              10

//----------------------------------------------------------------------------—;
//表格定义区
//

void USBD_CalibrationInit(void)
{
	usbcalisum = 0;
	usbcalimax = 0;
	usbcalimin = 0XFF;
	usbcalisimplecnt = 0;
	USHC = 1;

	unsigned char flag = 0;
	unsigned char Count = 0;
	if(USHC)
	{
		if(UCLKCON>=0X20)
		{
			Count = (UCLKCON - 0X20)/2;
		}
		else
		{
			Count = (0X20-UCLKCON)/2;
			flag=1;
		}
		CALLOCK = 0x55;
		CALLOCK = 0xAA;
		if(flag)
		    IRCCAL-=Count;
		else
			IRCCAL+=Count;

        USHC = 0;
		USHC = 1;
	}
}

void USBD_Calibration(void)
{
	if(USHC)	//USB校准打开时
	{
		unsigned char uclk = UCLKCON;
		
		if(uclk>usbcalimax)
			usbcalimax = uclk;	//最大值
		if(uclk<usbcalimin)
			usbcalimin = uclk; //最小值
			
		usbcalisum += uclk;
		
		if(++usbcalisimplecnt>=USBCaliCnt)
		{
			usbcalisum = (usbcalisum-usbcalimax-usbcalimin)/(USBCaliCnt-2); //去除最大值最小值后取平均

			unsigned char curoffset;
			unsigned char signal=0;
			if(usbcalisum>=0X20)
			{
				curoffset = (usbcalisum - 0X20)/2;
			}
			else
			{
				curoffset = (0X20-usbcalisum)/2;
				signal=1;
			}

			if(signal && curoffset<=1)
			{
				curoffset +=1;
			}
			if(curoffset!=0)
			{
				CALLOCK = 0x55;
				CALLOCK = 0xAA;
				if(signal)
				{	
					if((curoffset/2)>=1)	//每2个值补1个值
					{
						curoffset += curoffset/2;
					}
					IRCCAL-=curoffset;
				}
				else
				{
					if(curoffset <= 4)
						curoffset -= 1;
					IRCCAL+=curoffset;
				}
			}
			
			USHC = 0; //关闭校准
		}
	}
}

void __delayus(unsigned char time)
{
    while(--time);
}
//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;
static void USBD_Ep0_Stall(void)
{
    UE0CON = 0x1F;
    bEp0Stall = 1;
}

//EP0设为输入状态
static void USBD_Ep0_StatusIn(void)
{
	unsigned char overtime = 120;
	//发送状态过程前先等待其它端点传输完成
	while(UE1INS || UE2INS)	
	{
		if(TC0IF)
		{
			TC0IF = 0;                              // 中断标志位清零
			timer_int_process();
		}

		if(--overtime==0)
			break;
		else
			__delayus(10);
	}
    UE0IOPS = 0x00;
    UE0CON = 0x06;
	overtime = 120;
	while(UE0SINS)
	{
		if(TC0IF)
		{
			TC0IF = 0;                              // 中断标志位清零
			timer_int_process();
		}
		if(--overtime==0)
			break;
		else
			__delayus(10);
	}
}

//EP0设为输出状态
static void USBD_Ep0_StatusOut(void)
{
	unsigned char overtime = 120;
	//发送状态过程前先等待其它端点传输完成
	while(UE1INS || UE2INS)
	{
		if(TC0IF)
		{
			TC0IF = 0;                              // 中断标志位清零
			timer_int_process();
		}
		if(--overtime==0)
			break;
		else
			__delayus(10);
	}
	UE0IOPS = 0x00;
	UE0CON = 0x0A;
	overtime = 120;
	while(UE0SOUTS)
	{
		if(TC0IF)
		{
			TC0IF = 0;                              // 中断标志位清零
			timer_int_process();
		}
		if(--overtime==0)
			break;
		else
			__delayus(10);
	}
}

/***********************************************************************************************************
*** 函数名称：void USBD_Ep0_Write(unsigned char len)
*** 功能描述：从端点0发送数据
*** 参数：len:发送长度
*** 返回值：无
*** 创建者:GJN
*** 创建时间：2020.08.30
*** 最后更新:
*** 说明: 发送的数据包需放在RAM 0X800为起始的地址中
************************************************************************************************************/
static void USBD_Ep0_Write(unsigned char len)
{
    UE0IOPS = len;
    UE0CON = 0x01;   

    while( !UE0SDF );

	USBD_Ep0_StatusOut();
}

/***********************************************************************************************************
*** 函数名称：void USBD_Ep0_WriteTable(unsigned char* dat, unsigned char len)
*** 功能描述：从端点0发送数据
*** 参数：*dat:数据地址 len:数据长度
*** 返回值：无
************************************************************************************************************/
static void USBD_Ep0_WriteTable(const unsigned char* dat, unsigned char len)
{
    unsigned char ZPacket,j;

    if((wLengthl>len)||(0!=wLengthh))
    {
        ZPacket = 1;
    }
    else
    {
        ZPacket = 0;
        len = wLengthl;
    }

    unsigned char i;
    
    while(len)
    {
        i = len > MAX_EP0_SIZE ? MAX_EP0_SIZE : len;
        len -= i;
        for(j=0; j<i; j++)
        {
            UsbEp0Buffer[j] = dat[j];
        }
        dat += i;

        UE0IOPS = i;
        UE0CON = 0x01;    

        while( !UE0SDF);
        UE0SDF = 0;
    }

    if((i==MAX_EP0_SIZE)&&(ZPacket))    //发送0长度的包
    {
        USBD_Ep0_Write(0);
    }
    else
    {
		USBD_Ep0_StatusOut();
    }
}

static void USBD_GetStatus(void)
{
    if(USBEnumState==USBE_Default)
    {
        USBD_Ep0_Stall();
        return;
    }

    unsigned char temp = bmRequestType;

    bmRequestType = 0;
    bRequest = 0;
    switch(temp & Recipient)
    {
        case Rec_Device:                /* device status */
            if(bwakeup_usb_enable)
                bmRequestType = 0x02;
            USBD_Ep0_Write(2);
            break;
        case Rec_Interface:             /* interface status */
            if(USBEnumState == USBE_Address)
            {
                USBD_Ep0_Stall();
            }
            else
            {
                USBD_Ep0_Write(2);
            }
            break;
        case Rec_EndPoint: /* ep status */
            switch(wIndexl)
            {
                case 0x00:
                    if(!bEp0Stall)
                        bmRequestType = 1;
                    USBD_Ep0_Write(2);

                    break;

                case 0x81:    /* ep1 state */
                    if( USBEnumState == USBE_Address)
                    {
                        USBD_Ep0_Stall();
                        break;
                    }
                    if(bEp1InStall)
                        bmRequestType = 0x01;           
                    USBD_Ep0_Write(2);

                    break;
                case 0x82: /* ep2 state */
                    if( USBEnumState == USBE_Address)
                    {
                        USBD_Ep0_Stall();
                        break;
                    }
                    if(bEp2InStall)
                        bmRequestType = 0x01;
                    USBD_Ep0_Write(2);

                    break;
                case 0x83: /* ep3 state */
                    if( USBEnumState == USBE_Address)
                    {
                        USBD_Ep0_Stall();
                        break;
                    }
                    if(bEp3InStall)
                        bmRequestType = 0x01;
                    USBD_Ep0_Write(2);

                    break;
                default:
                    USBD_Ep0_Stall();
                break;
            }
            break;

        default:
            USBD_Ep0_Stall();
            break;
    }
}

static void USBD_ClearFeature(void)
{
    if(USBEnumState!=USBE_Configured)
    {
        USBD_Ep0_Stall();
        return;
    }

    if(bmRequestType == Rec_EndPoint)
    {
        if( wValuel || wValueh || wLengthh || wLengthl )
        {
            USBD_Ep0_Stall();
            return;
        }

        switch (wIndexl)
        {
            case 0x81:
                bEp1InStall = 0;
                UE1INSTL = 0;
                USBD_Ep0_StatusIn();
                break;
            case 0x82:
                bEp2InStall = 0;
                UE2INSTL = 0;
                USBD_Ep0_StatusIn();
                break;
            case 0x83:
                bEp3InStall = 0;
                UE3INSTL = 0;
                USBD_Ep0_StatusIn();
                break;

            default:
                USBD_Ep0_Stall();
            break;
        }
    }
    else if(bmRequestType==Rec_Device)
    {
        bwakeup_usb_enable = 0;
        USBD_Ep0_StatusIn();
    }
    else
    {
        USBD_Ep0_Stall();
    }
}

static void USBD_SetFeature(void)
{
    if( USBEnumState != USBE_Configured)
    {
        USBD_Ep0_Stall();
        return;
    }
    if(bmRequestType==Rec_Device)
    {
        if( ( wValuel | wLengthl | wLengthh | wValueh ) != 0x01 )
        {
            USBD_Ep0_Stall();
            return;
        }
        bwakeup_usb_enable = 1;
        USBD_Ep0_StatusIn();
        return;
    }
    else if(bmRequestType != Rec_EndPoint)
    {
        USBD_Ep0_Stall();
        return;
    }

    if( wValuel || wLengthl || wLengthh || wValueh )
    {
        USBD_Ep0_Stall();
        return;
    }

    switch(wIndexl)
    {
        case 0x81:
            UE1INSTL = 1;
            bEp1InStall = 1;
            USBD_Ep0_StatusIn();    

            break;
        case 0x82:
            UE2INSTL = 1;
            bEp2InStall = 1;
            USBD_Ep0_StatusIn();    

            break;
        case 0x83:
            UE3INSTL = 1;
            bEp3InStall = 1;
            USBD_Ep0_StatusIn();      
            break;
        default:
            USBD_Ep0_Stall();
        return;
    }
}

//设置地址
static void USBD_SetAddress(void)
{
    if( wIndexl || wIndexh || wLengthl || wLengthh || (USBEnumState == USBE_Configured))
    {
        USBD_Ep0_Stall();
        return;
    }
    
    if(wValuel)
        USBEnumState = USBE_Address;
    else
        USBEnumState = USBE_Default;
        
    UDADR = wValuel;
    USBD_Ep0_StatusIn();
}

//获取字符串描述符
static void USBD_GetDevStrDescriptor(void)
{
    switch(wValuel)
    {
        case 0x00:
            USBD_Ep0_WriteTable( LanguageIDDesc, LanguageIDDescSize);
            break;
        case 0X01:
            USBD_Ep0_WriteTable( ManuStringDesc, ManuStringDescSize);
            break;
        case 0x02:
            USBD_Ep0_WriteTable( SerialNumberStringDesc, SerialNumberStringDescSize);
            break;
        case 0x03:
            USBD_Ep0_WriteTable( StringDescSerialNum, SerialNumStringDescSize);
            break;
        default:
            USBD_Ep0_Write(0);
            break;
    }
}

//获取HID接口描述符
static void USBD_ClassGetHidDes(void)
{
//每多一个HID接口描述符，switch多加一个case进行传输
    switch(wIndexl)
    {
        case 0x00:        //键盘接口
            USBD_Ep0_WriteTable(DeviceHidDescriptor_KB, 9);
            break;
        case 0x01:        //鼠标接口
            USBD_Ep0_WriteTable(DeviceHidDescriptor_DEF, 9);
            break;                      
        default:
            USBD_Ep0_Write(0);
            break;
    }
}

//获取HID报告描述符
static void USBD_ClassGetHidReport(void)
{
//每多一个报告描述符，switch多加一个case进行传输
    switch( wIndexl )
    {
        case 0x00: 
            USBD_Ep0_WriteTable( HID_ReportDescriptor_Keyboard, KeyboardReportDescSize);
            break;
        case 0x01:
            USBD_Ep0_WriteTable( HID_ReportDescriptor_Define, DefReportDescSize);
            break;
        default:
            USBD_Ep0_Stall();
        break;
    }
}

static void USBD_GetConfig(void)
{
    if( wLengthl != 0x01 || wLengthh || wIndexh || wIndexl || wValueh || wValuel || (USBEnumState == USBE_Default))
    {
        USBD_Ep0_Stall();
        return;
    }
    if( USBEnumState == USBE_Address)
    {
        bmRequestType = 0x00;
    }
    else if(USBEnumState == USBE_Configured)
    {
        bmRequestType = 0x01;
    }
    else
    {
        USBD_Ep0_Stall();
        return;
    }
    USBD_Ep0_Write(1);
}

static void USBD_SetConfig(void)
{
    if( wLengthh || wIndexh || wValueh || (USBEnumState == USBE_Default))
    {
        USBD_Ep0_Stall();
        return;
    }

    if(wValuel==0)
    {
        USBEnumState = USBE_Address;
        USBD_Ep0_StatusIn();
    }
    else if(wValuel==1)
    {
        USBEnumState = USBE_Configured;
        bep1_ep2_enable = 1;
        sof_count = 0;
        USBD_Ep0_StatusIn();
    }
    else
    {
        USBD_Ep0_Stall();    
    }
}

static void USBD_GetInterface(void)
{
    if( wLengthl != 0x01  || wValuel || wValueh || wLengthh )
    {
        USBD_Ep0_Stall();
        return;
    }
    
    if( USBEnumState != USBE_Configured)
    {
        USBD_Ep0_Stall();
        return;
    }

    bmRequestType = 0X00;
    USBD_Ep0_Write(1);
}

static void USBD_SetInterface(void)
{
    if( wLengthl || wLengthh || wValuel || wValueh || wIndexh )
    {
        USBD_Ep0_Stall();
        return;
    }
    
    if(USBEnumState != USBE_Configured)
    {
        USBD_Ep0_Stall();
        return;
    }
        
    USBD_Ep0_StatusIn();
}

static void USBD_ClassGetProtocol(void)
{
    if( wLengthl != 0x01 )
    {
        USBD_Ep0_Stall();
        return;
    }

    if(busb_boot)
        bmRequestType = 0x00;
    else
        bmRequestType = 0x01;

    USBD_Ep0_Write(1);
}

//获取描述符
static void USBD_GetDescriptor(void)
{
    switch(wValueh)
    {
        case GET_DEV_DES:        //设备描述符
            busb_boot = 0;
            USBD_Ep0_WriteTable(DeviceDesc, DeviceDescSize);
            break;
        case GET_CONFIG_DES:    //配置描述符
            USBD_Ep0_WriteTable( ConfigurationDesc, ConfigurationDescSize);

            break;
        case GET_STR_DES:
            USBD_GetDevStrDescriptor();

            break;
        case GET_CLASS_HID_DES:
            USBD_ClassGetHidDes();    

            break;
        case GET_CLASS_HID_REPORT:
            USBD_ClassGetHidReport();

            break;
        default:
            USBD_Ep0_Stall();
            break;
    }
}

/******************************************************************************
* 函数名称: USB_ISR()
* 功能描述:
* 说    明:
******************************************************************************/
void USBD_EP0_Handler(void)
{
    unsigned char i;

    USBD_Calibration();

    UE0SDF = 0;

    busb_suspend_en = 0;

    if(busb_report_set)
    {
        busb_report_set = 0;

        if(1 == usb_report_lenght)
        {
            usb_status_reg &= 0xF8;
            usb_status_reg |= (UsbEp0Buffer[0]&0x07);
            if(!bkb_led_valid)
            {
                bkb_led_valid = 1;
                //kb_led_bak = (usb_status_reg&0x07);
            }
        }
        else
        {
		    for(i=0; i<usb_report_lenght; i++)
		    {
				out_report_data[i] = UsbEp0Buffer[i];
			}
            if(0x20 == usb_report_lenght)
                bhid_data_process = 1;
        }

        USBD_Ep0_StatusIn();
        usb_report_lenght = 0;
		return;
    }

    if((bmRequestType & Direction)==Dir_SlaveToHost)
    {
        switch(bmRequestType&Re_Type)
        {
            case ReType_Standard:                    //标准输入请求
                switch(bRequest)
                {
                    case GET_STATUS:
                        USBD_GetStatus();
                    break;

                    case GET_DESCRIPTOR:
                        USBD_GetDescriptor();
                    break;
                    case GET_CONFIGURATION:
                        USBD_GetConfig();
                    break;
                    case GET_INTERFACE:
                        USBD_GetInterface();
                    break;   
                    default:
                        USBD_Ep0_Stall();
                    break;
                }
                break;

            case ReType_Class:                        //类输入请求
                 switch(bRequest)
                 {
                     case GET_REPORT:
                        //USBD_ClassGetReport();
                        USBD_Ep0_Write(0);
                     break;
                     case GET_IDLE:
                        //USBD_ClassGetIdle();
                        bmRequestType = IdleRate;
                        USBD_Ep0_Write(1);

                     break;
                     case GET_PROTOCOL:
                         USBD_ClassGetProtocol();
                     break;
                     default:
                        USBD_Ep0_Stall();
                     break;
                 }

                 break;
             case ReType_Manufacturer:            //厂商输入请求
                 USBD_Ep0_Stall();

                break;
             default:
                 USBD_Ep0_Stall();
                 break;
        }
    }
    else
    {
        switch(bmRequestType&Re_Type)
        {
            case ReType_Standard:  //标准输出请求
                switch(bRequest)
                {
                    case CLEAR_FEATURE:
                        USBD_ClearFeature();

                        break;
                    case SET_FEATURE:
                        USBD_SetFeature();

                        break;
                    case SET_ADDRESS:
                        USBD_SetAddress();

                        break;
                    case SET_DESCRIPTOR:
                        USBD_Ep0_StatusIn();

                        break;
                    case SET_CONFIGURATION:
                        USBD_SetConfig();

                        break;
                    case SET_INTERFACE:
                        USBD_SetInterface();

                        break;
                    default:
                        USBD_Ep0_Stall();
                        break;
                }

                break;
            case ReType_Class:  //类输出请求
                 switch(bRequest)
                 {
                     case SET_REPORT:

                        if(wLengthl!=0)
                        {
                            busb_report_set = 1;
                            usb_report_lenght = UsbEp0Buffer[6];
                            UE0CON = 0X02;
                        }
                        else
                            USBD_Ep0_StatusIn();

                         break;
                     case SET_IDLE:
                        //USBD_ClassSetIdle();
                        IdleRate = wValueh;
                        USBD_Ep0_StatusIn();

                         break;
                     case SET_PROTOCOL:
                        busb_boot = 0;
                        if( wValuel == 0x00 )
                        {
                            busb_boot = 1;
                        }
                        USBD_Ep0_StatusIn();    

                        break;
                     default:
                        USBD_Ep0_Stall();
                         break;
                 }

                break;
            case ReType_Manufacturer:  //厂商输出请求
                USBD_Ep0_Stall();

                break;
            default: //未定义的请求。这里只显示一个报错信息。
                 USBD_Ep0_Stall();
                break;
           }
    }
}

/******************************************************************************
* 函数名称: USBD_Init
* 功能描述: 对USB系统进行初始化
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void USBD_Init(void)
{
    UINTCR0 = BIT_INTEP2+BIT_INTEP1+BIT_INTEP0+BIT_INTBUS; //中断使能
    USBCON  = BIT_UFS+BIT_USHC+BIT_UE;
    USBEnumState = USBE_Default;
    usb_ctrl_flag = 0;
    usb_status_reg = 0;
    EpState = 0;
    USBEpBusy = 0;

    busb_boot = 0;
    bep1_ep2_enable = 0;

    USBSwState = 0;

    USBD_SwBusInit();
}

void USBD_SwBusInit(void)
{
    IOFICR |= 0X03;
    IOFCHIE = 1;
    IOFCHIF = 0;
    SwBusTimer = 0;
}
/******************************************************************************
* 函数名称: USBD_Init
* 功能描述: 对USB系统进行初始化
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void USBD_disable(void)
{
    UINTCR0 = 0x00;
    USBCON  = 0x00;

    IOFICR &= ~0X03;
    SwBusTimer = 0;
}



