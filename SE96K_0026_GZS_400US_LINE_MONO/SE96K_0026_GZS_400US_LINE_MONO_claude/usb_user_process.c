/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: usb_user_process.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "defines.h"
#include ".\hal\key_code_define.h"

//----------------------------------------------------------------------------;
//外部变量定义
//
USBD_U8                     uusb_data_flag;
//unsigned char               mouse_data[7];
//
//----------------------------------------------------------------------------;
//寄存器定义

/******************************************************************************
* 函数名称: usb_data_process()
* 功能描述: USB数据发送处理
* 输入参数: 无
* 输出参数: 无
* 说    明: USB数据发送处理
******************************************************************************/
void usb_data_process(void)
{
    unsigned char* pReg;

    if(!busb_enum_finish && bep1_ep2_enable)
    {
        if(0x20<sof_count)
        {
            busb_enum_finish = 1;
        }
        return;
    }

    if((0 == (usb_data_flag&0x5F))|| !busb_enum_finish)
    {
        return;
    }

    UE5OUTS = 1;

//PE4 = ~PE4;
//----------------------------------------------
// EP0 键盘数据
    if(bstd_data_send && !bEp1Busy)
    {
GIEH = 0;
        bEp1Busy = 1;
        pReg = EP1IOPS_ADDR;                    // EPxIOPS地址

        *pReg++ = 8;                            // 包大小
        UsbEp1Buffer[0] = std_key[0];
        UsbEp1Buffer[1] = 0;
        memcpy(UsbEp1Buffer+2, std_key+1, 6);

        *pReg = 1;                              // 开始传输
        bstd_data_send = 0;
GIEH = 1;
    }
//
//----------------------------------------------
// EP1 键盘数据
//
    if(!bEp2Busy)
    {
        if(bstd_exdata_send)
        {
GIEH = 0;
            bEp2Busy = 1;
            pReg = EP2IOPS_ADDR;                // EPxIOPS地址
            *pReg++ = 16;                       // 包大小

            UsbEp2Buffer[0] = iREPORT_ID_KB_KEY;
            memcpy(UsbEp2Buffer+1, std_key+7, 15);

            *pReg = 1;                          // 开始传输
            bstd_exdata_send = 0;
GIEH = 1;
        }
        else if(bmmk_data_send)
        {
GIEH = 0;
            bEp2Busy = 1;
            pReg = EP2IOPS_ADDR;                // EPxIOPS地址
            *pReg++ = 3;                        //包大小

            UsbEp2Buffer[0] = iREPORT_ID_MULTIM_KEY;
            UsbEp2Buffer[1] = multi_key[0];
            UsbEp2Buffer[2] = multi_key[1];
    
            *pReg = 1;                          // 开始传输
            bmmk_data_send = 0;
GIEH = 1;
        }
        else if(bhid_data_send)
        {
GIEH = 0;
            bEp2Busy = 1;
            pReg = EP2IOPS_ADDR;                // EPxIOPS地址
            *pReg++ = 32;                       //包大小

			in_report_data[0] = iHID_CMD_HANDLE;
			memcpy(UsbEp2Buffer, in_report_data, 32);

            *pReg = 1;                          // 开始传输
            bhid_data_send = 0;
			
            if(bjump_boot
				&&(0x55 == out_report_data[2])
                && (0xAA == out_report_data[3])
                && (0x00 == out_report_data[4])
                && (0xFF == out_report_data[5]))
            {
				clr_led();
		        delayms(2);
				USBD_disable();
		        delayms(200);

			    bootloader_val[0] = 0x3C;
			    bootloader_val[1] = 0xC3;
			    bootloader_val[2] = 0x55;
			    bootloader_val[3] = 0xAA;
                Reset();
		        delayms(5);
            }
GIEH = 1;
        }
        else if(bmouse_data_send)
        {
GIEH = 0;
            bEp2Busy = 1;
            pReg = EP2IOPS_ADDR;                // EPxIOPS地址
            *pReg++ = 7;                        //包大小

            UsbEp2Buffer[0] = iREPORT_ID_MOUSE;
            UsbEp2Buffer[1] = (mouse_data_key&0x1F);
            UsbEp2Buffer[2] = (mouse_data_x&0xFF);
            UsbEp2Buffer[3] = (((mouse_data_x>>8)&0x0f)|((mouse_data_y<<4)&0xf0));
            UsbEp2Buffer[4] = ((mouse_data_y>>4)&0xFF);
            UsbEp2Buffer[5] = mouse_data_z;
            UsbEp2Buffer[6] = 0;

            mouse_data_x = 0;
            mouse_data_y = 0;
            mouse_data_z = 0;

            *pReg = 1;                          // 开始传输
            bmouse_data_send = 0;
GIEH = 1;
        }
    }
}
