/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.c
*
* 功能说明: 主函数处理程序
* 修改说明:
*******************************************************************************/
#include "defines.h"

//----------------------------------------------------------------------------;
//变量定义
//
extern void USBD_CalibrationInit(void);

//----------------------------------------------------------------------------;
//变量定义
//
unsigned char               bootloader_val[4] @ 0X0280;

//-----------------------------------------------------------------------------;
#define iPORT_A            0
#define iPORT_B            1 
#define iPORT_C            2
#define iPORT_D            3
#define iPORT_E            4

#define iDIR_IN            0
#define iDIR_OUT           1

//-----------------------------------------------------------------------------;
// 表格定义区
//
const unsigned int low_int[2] @0x0008 =
{
    0xDF04, 0xF008,                     // goto 0x1008
};
const unsigned int high_int[2] @0x0018 =
{
    0xDF0C, 0xF008,                     // goto 0x1018
};

const unsigned char boot_fw_vs[] @0x0FF0 =
{
    'B',  'o',  'o'-0x60,  't'-0x60,  '-', 'V'-0x60,  '2', '0',
    iPROJECT_ID_0,
    iPROJECT_ID_1,
    iPROJECT_ID_2,
    iPROJECT_ID_3,
    iVERSION_ID,
	0xAA,
	0x55,
	0x5A,
};

const unsigned char boot_key_tbl[] @0x0FE8 =
{												// ESC PB0 PE5
    iPORT_B,									// port
    (1<<0),										// pin
    (1<<0),										// check
    0xAA,										//
												// WIN PB1 PE0
    iPORT_B,									// port
    (1<<1),										// pin
    (1<<0),										// check
    0x55,										//
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void port_set(unsigned char port, unsigned char pin, unsigned char dir)
{
    if(iPORT_B==port)
	{
	    ANSB &= ~pin;
	    if(iDIR_IN==dir)
	    {										// 输入
            PUB |= pin;
            OEB &= ~pin;
		}
	    else
	    {										// 输出低
            OEB |= pin;
			IOB &= ~pin;
	    }
	}
	else if(iPORT_C==port)
	{
	    ANSC &= ~pin;
	    if(iDIR_IN==dir)
	    {										// 输入
            PUC |= pin;
            OEC &= ~pin;
		}
	    else
	    {										// 输出低
            OEC |= pin;
			IOC &= ~pin;
	    }
	}
	else if(iPORT_D==port)
	{
	    ANSD &= ~pin;
	    if(iDIR_IN==dir)
	    {										// 输入
            PUD |= pin;
            OED &= ~pin;
		}
	    else
	    {										// 输出低
            OED |= pin;
			IOD &= ~pin;
	    }
	}
}
void memcpy(unsigned char  *ptr_d, unsigned char *ptr_s, unsigned char lenght)
{
	for(unsigned char i=0; i<lenght; i++)
    {
        *ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
    }
}

/******************************************************************************
* 函数名称: main()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void main(void)
{
    unsigned char matrix_status[2] = {0};

    GIEL = 0;
    GIEH = 0;                                    // 关中断
    USBCON = 0X00;                                // 失能USB

    const unsigned char *pRom = (const unsigned char *)APP_StartAddr;    //查询升级标志
    if((*pRom != 0XFF) || (*(pRom+1) != 0XFF))
    {
       if(!SOFTRST)
        {                                        // 非软复位
//上电外部IO状态强制停留Boot区
            delayms(5);
            ANSA = 0x00;
            PUA = 0x03;                         //0:上拉关闭 1:上拉使能
            PDA = 0x00;                         //0:下拉关闭 1:下拉使能
			IOA = 0xFF;
            OEA = 0xFC;                         //0:输入 1:输出

            ANSE = 0x00;
            PUE = 0xFF;                         //0:上拉关闭 1:上拉使能
            PDE = 0x00;                         //0:下拉关闭 1:下拉使能
			IOE = 0xFF;
            OEE = 0x00;                         //0:输入 1:输出

            ANSB = 0x00;
            PUB = 0x00;                         //0:上拉关闭 1:上拉使能
            PDB = 0x00;                         //0:下拉关闭 1:下拉使能
			IOB = 0xFF;
            OEB = 0xFF;                         //0:输入 1:输出
		
			ANSF = 0x00;
			IOFODS0 = 0x03;
			IOFODS1 = 0x03;
			PUF = 0x00;                                 //0:上拉关闭 1:上拉使能
			PDF = 0x0E;                                 //0:下拉关闭 1:下拉使能
			OEF = 0xF0;                                 //0:输入 1:输出
			IOF = 0xFF;                                 //IO口数据

			IOB0 = 0;
            delayms(1);
            matrix_status[0] = (~IOA)&0x03;

			IOB0 = 1;
			IOB1 = 0;
            delayms(1);
            matrix_status[1] |= (~IOA)&0x03;

	        if((0x01 != matrix_status[0]) 
	            || (0x01 != matrix_status[1]))
            {
                #asm 
                goto APP_StartAddr
                #endasm
            }
            goto into_bootloader;
        }

        if((0x3C != bootloader_val[0])
            ||(0xC3 != bootloader_val[1])
            ||(0x55 != bootloader_val[2])
            ||(0xAA != bootloader_val[3]))
        {
            #asm
            goto APP_StartAddr    //无升级标志且用户区不为空跳转用户区
            #endasm
        }

        bootloader_val[0] = 0;
        bootloader_val[1] = 0;
        bootloader_val[2] = 0;
        bootloader_val[3] = 0;
    }

into_bootloader:
	ANSF &= ~0X03;	//DP、DN端口设为数字模式
    UINTCR0 = BIT_INTEP1+BIT_INTEP0+BIT_INTBUS; //中断使能
    USBCON  = BIT_UFS+BIT_USHC+BIT_UE;
    USBEnumState = USBE_Default;
    usb_ctrl_flag = 0;
    usb_status_reg = 0;
    EpState = 0;
    USBEpBusy = 0;

    while(1)
    {
        if(UBRST)
        {
            UBRST = 0;

            USBEnumState = USBE_Default;
            usb_ctrl_flag = 0;
            usb_status_reg = 0;
            EpState = 0;
            USBEpBusy = 0;

            UDADR = 0x00;
            UE0CON = 0x02;
            UE0IOPS = 0x00;

            UE1CON = UE1CON_RSET;
            UE1IOPS = 0x00;
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
        if(UBSPD)
            UBSPD = 0;

        if(UBRSM)
            UBRSM = 0;
//----------------------------------------------
// 端点0中断处理
//
        if(UE0STL)
        {
            unsigned char t = 100;    //不同运行速度下,可能需要修改t
            while(t--)
            {
                if(!UE0STL)
                    break;
            }
            UE0STL = 0;    
        }
        if(UE0SDF)
            USBD_EP0_Handler();

//----------------------------------------------
// 端点1中断处理
//
        if(UE1INF)
        {
            UE1INF = 0;
            UE1IOPS = 0;
            bEp1Busy = 0;
        }

        hid_process();
        usb_data_process(); 
    }
}
