/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: System_Sleep.c
*
* 功能说明: 
* 修改说明:
*******************************************************************************/
#include "defines.h"

//-----------------------------------------------------------------------------;
// 变量定义
//

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void off_led(void)
{
    IOA |= 0xFC;
    IOB = 0x00;
    IOC = 0x00;
    IOD = 0x00;
    IOF &= 0xF3;
    pwm2_init();
} 

/******************************************************************************
* 函数名称: in_sleep_init()
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明: 
******************************************************************************/
void in_sleep_init(void)
{
    GIEH = 0;
//----------------------------------------------
// 关背光灯,矩阵输出低
    off_led();

//----------------------------------------------
// 设置IO唤醒使能
    IOAICR = 0x03;
    IOACHIE = 1;
    IOACHIF = 0;
    IOEICR = 0x30;
    IOECHIE = 1;
    IOECHIF = 0;
    IOFICR = 0xC3;
    IOFCHIE = 1;
    IOFCHIF = 0;

    INTF0 = 0;
    INTF1 = 0;
    INTF2 = 0;
    
//----------------------------------------------
// 关闭timer
    TC0IF = 0;
    TC0EN = 0;
	TC0IE = 0;
}

/******************************************************************************
* 函数名称: system_sleep()
* 功能描述: 系统休眠处理
* 输入参数: 无
* 输出参数: 无
* 说    明: 
******************************************************************************/
void out_sleep_init(void)
{
    IOACHIE = 0;
    IOECHIE = 0;
    IOFCHIE = 0;

    timer0_init();

    led_pre_mode = iMODE_LED_INVALID;
    GIEH = 1;
}

/******************************************************************************
* 函数名称: system_sleep()
* 功能描述: 系统休眠处理
* 输入参数: 无
* 输出参数: 无
* 说    明: 
******************************************************************************/
void system_sleep(void)
{
    if(!busb_suspend_en)
       return;
    
    if(busb_boot)
    {
        busb_suspend_en = 0;
        return;
    }
    in_sleep_init();

    if(!bwakeup_usb_enable)                 // USB不能唤醒PC.
    {
        IOAICR = 0x00;                      // usb休眠下，只允许FN + 1\2\3唤醒
        IOACHIE = 0;
        IOEICR = 0x00;
        IOECHIE = 0;
        IOFICR = 0x03;
        IOFCHIE = 1;

        GIEH = 1;

    	INTF0 = 0;
    	INTF1 = 0;
    	INTF2 = 0;
    
        STPH = 1;
        STPL = 1;
        STOP = 1;
        nop;
    }
    else                                    // USB可唤醒PC.
    {
        key_temp_flag = (IOF&0xC0);
        key_temp_flag |= (IOA&0x03);
        key_temp_flag |= (IOE&0x30);
        gtemp_i = key_temp_flag;

        GIEH = 1;
        STPH = 1;
        STPL = 1;
        STOP = 1;
    	nop;
    
        delayms(1);
        key_temp_flag = (IOF&0xC0);
        key_temp_flag |= (IOA&0x03);
        key_temp_flag |= (IOE&0x30);
        if(gtemp_i != key_temp_flag)
        {
    		USRSM = 1;                      // 远程唤醒
    		delayms(10);
    		USRSM = 0;
        }
    }
    delayms(10);

    busb_suspend_bak = 1;
    clr_led_data();
    
    USBSwState = 0;
    out_sleep_init();
    USBD_SwBusInit();
}
