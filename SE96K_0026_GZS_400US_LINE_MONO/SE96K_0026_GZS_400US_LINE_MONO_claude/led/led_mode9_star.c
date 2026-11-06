/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
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
unsigned int                    lfsr_value;
unsigned char                   start_dec_count;

//-----------------------------------------------------------------------------;
// 表格定义区
//
unsigned char       const   start_dec_delay[8]={
    4,
    8,
    13,
    20,
    30,
    30,
    30,
    30,
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/******************************************************************************
* 函数名称: led_mode_snake
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_star(void)
{
    unsigned char i;

    delay_time_count++;
    i = start_dec_delay[led_speed_lev&0x07];
    if(i > delay_time_count)
    {
        start_dec_count++;
        if((led_speed_lev<<1)>start_dec_count)
        {
            start_dec_count++;
            return;
        }
        start_dec_count = 0;
        for(i=0; i<iLED_ALL_MAX; i++)
        {
            if(0 != pwm_duty_array[i])
                pwm_duty_array[i]--;
        }
        return;
    }

    delay_time_count = 0;

    lfsr_value = lfsr_value>>1;
    if(lfsr_value & 0x01)
        lfsr_value ^= iLFSR_MULTINOMIAL;

    i = ((lfsr_value+(lfsr_value>>8))&0x7F);
    if(iLED_ALL_MAX <= i)
        i -= iLED_ALL_MAX;

    pwm_duty_array[i] = iPWM_MAX;
}

