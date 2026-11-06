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

unsigned char       const   zxb_time_delay[8]={
    15,
    25,
    35,
    60,
    80,
    80,
    80,
    80,
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
void led_mode_zxb(void)
{
    unsigned char i, j;

    delay_time_count++;
    i = zxb_time_delay[led_speed_lev&0x07];
    if(i>delay_time_count)
        return;
    delay_time_count = 0;

    bled1_status = bled0_status;
    for(i=0; i<(iLED_COL_NUM+1)/2; i++)
    {
        if(bled1_status)
        {
            pwm_duty_array_0[i]++;
            pwm_duty_array_0[i+1] =  pwm_duty_array_0[i];
            if((iLED_ROW_NUM-1) <= pwm_duty_array_0[i])
            {
                pwm_duty_array_0[i] = (iLED_ROW_NUM-1);
                bled1_status = 0;
                pwm_duty_array_0[i+1] = (iLED_ROW_NUM-1);

                if(0 == i)
                    bled0_status = 0;
            }
        }
        else
        {
            pwm_duty_array_0[i]--;
            pwm_duty_array_0[i+1] =  pwm_duty_array_0[i];
            if(0 == pwm_duty_array_0[i])
            {
                pwm_duty_array_0[i+1] = 0;

                bled1_status = 1;
                if(0 == i)
                    bled0_status = 1;
            }
        }
    }

    for(i=0; i<iLED_ALL_MAX; i++)
    {
        pwm_duty_array[i] = 0;
    }

    for(i=0; i<(iLED_COL_NUM+1)/2; i++)
    {
        j = led_to_matrix_tab_2[i][pwm_duty_array_0[i]];
        pwm_duty_array[j] = iPWM_MAX;

        j = led_to_matrix_tab_2[(iLED_COL_NUM-1)-i][pwm_duty_array_0[i]];
        pwm_duty_array[j] = iPWM_MAX;

        if((iLED_ROW_NUM-1) > pwm_duty_array_0[i])
        {                                       // 每列上面亮两个灯
            j = led_to_matrix_tab_2[i][pwm_duty_array_0[i]+1];
            pwm_duty_array[j] = iPWM_MAX;

            j = led_to_matrix_tab_2[(iLED_COL_NUM-1)-i][pwm_duty_array_0[i]+1];
            pwm_duty_array[j] = iPWM_MAX;
        }
    }
}

