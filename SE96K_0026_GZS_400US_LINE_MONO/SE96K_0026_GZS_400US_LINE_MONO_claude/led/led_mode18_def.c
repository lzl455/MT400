 /*******************************************************************************
* Copyright (c) 2013  SHENZHEN SEMITEK Co. LTD.
* All rights reserved.
*
* 文件名称: uart.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "..\defines.h"

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;
unsigned char                   led_def_index;
unsigned char                   led_def_dat_tbl[16*8];

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;
unsigned char       const       led_def_mode_0_4_tbl[]=
{
//  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x01,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x07,0x00,0x00,0x00,0x10,0x00,0x00,0x0E,  // mode0

    0x0E,0x00,0xC0,0x07,0x30,0x7C,0x00,0x06,0x17,0x00,0x10,0x04,0x00,0x2A,0x00,0x00,  // mode1

    0x00,0x00,0xC0,0x1F,0x00,0xF8,0x00,0x00,0x1F,0x00,0x10,0x03,0x00,0x02,0x00,0x00,  // mode2

    0x00,0x00,0xC0,0x1F,0x00,0x78,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // mode3

    0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x07,0x00,0x10,0x00,0x10,0x0A,0x00,0x0E,  // mode4
};

/******************************************************************************
* 函数名称: led_mode_bhqf
* 功能描述: 百花齐放
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_def(void)
{
    unsigned char i, j;

    j = 0;
    for(i=0; i<16; i++)
    {
         if(5>led_def_index)
            key_temp_delay = led_def_mode_0_4_tbl[16*led_def_index+i];
        else
            key_temp_delay = led_def_dat_tbl[16*(led_def_index-5)+i];

        if(bkey_delay0)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay1)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay2)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay3)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay4)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay5)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay6)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
        if(bkey_delay7)
            pwm_duty_array[j] = iPWM_MAX;
        else
            pwm_duty_array[j] = 0;
        j++;
    }
    pwm_duty_array[iR*1+1+led_def_index] = iPWM_MAX;

}
