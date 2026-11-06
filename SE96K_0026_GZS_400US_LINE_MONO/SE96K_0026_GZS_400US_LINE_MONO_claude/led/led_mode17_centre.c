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
void led_mode_centre(void)
{
    unsigned char i, x, k;

    if(led_speed_lev>delay_time_count)
    {
		delay_time_count++;
        return;
	}
    delay_time_count = 0;

	k = snake_led_index;
	x = --pwm_duty_array_0[k];

	if(((iPWM_MAX*5)/6)>=x)
    {
		snake_led_index++;
        pwm_duty_array_0[k] = ((iPWM_MAX*5)/6);
        pwm_duty_array_0[snake_led_index] = iPWM_MAX;
    }
	x = pwm_duty_array_0[k];
	k--;
	pwm_duty_array_0[k] = x-((iPWM_MAX*1)/6);
	k--;
	pwm_duty_array_0[k] = x-((iPWM_MAX*2)/6);
	k--;
	pwm_duty_array_0[k] = x-((iPWM_MAX*3)/6);
	k--;
	pwm_duty_array_0[k] = x-((iPWM_MAX*4)/6);
	k--;
	pwm_duty_array_0[k] = x-((iPWM_MAX*5)/6);

	if((iLED_COL_NUM+2) <= snake_led_index)
	{
	    snake_led_index = 5;
        memset(pwm_duty_array_0, 0x00, 34);
	    pwm_duty_array_0[5] = iPWM_MAX;
	}

    if(!bled_run_dir)
        x = 5;
    else
        x = iLED_COL_NUM;
    for(i=0; i<((iLED_COL_NUM+1)/2); i++)
    {
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*0];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*1];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*2];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*3];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*4];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[i+iLED_COL_NUM*5];
        pwm_duty_array[k] = pwm_duty_array_0[x];

        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*0];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*1];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*2];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*3];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*4];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        k = led_to_matrix_tab_3[iLED_COL_NUM-i+iLED_COL_NUM*5];
        pwm_duty_array[k] = pwm_duty_array_0[x];
        if(!bled_run_dir)
            x++;
        else
            x--;
    }
}

