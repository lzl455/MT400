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

//-----------------------------------------------------------------------------;
// 表格定义区
//
unsigned char       const   yzmb_time_delay[8]={
    20,
    30,
    45,
    60,
    80,
    60,
    60,
    60,
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/******************************************************************************
* 函数名称: led_mode_yzmb
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_yzmb(void)
{
    unsigned char i, j, k;

    delay_time_count++;
    i = yzmb_time_delay[led_speed_lev&0x07];
    if(i>delay_time_count)
        return;
    delay_time_count = 0;

    k = 0;
    for(i=0; i<10; i++)
    {
        lfsr_value >>= 1;
        if(lfsr_value & 1)
            lfsr_value ^= iLFSR_MULTINOMIAL;
        j = ((lfsr_value+(lfsr_value>>8))&0x1F);
        if(iLED_COL_NUM<j)
            j >>= 1;

        if(0 == pwm_duty_array_0[j])
        {
            pwm_duty_array_0[j] = (iLED_ROW_NUM-1);
            k++;
            if(4<k)
                break;
        }
    }

    for(i=0; i<iLED_ALL_MAX; i++)
    {
        pwm_duty_array[i] = 0;
    }

    k = 0;
    for(i=0; i<iLED_COL_NUM; i++)
    {
        if(0 != pwm_duty_array_0[i])
        {
            j = led_to_matrix_tab_down_up[k+pwm_duty_array_0[i]];
            pwm_duty_array_0[i]--;
            pwm_duty_array[j] = iPWM_MAX;

            j = led_to_matrix_tab_down_up[k+pwm_duty_array_0[i]];
            pwm_duty_array[j] = iPWM_MAX;
        }
        k += 5;
    }
}

