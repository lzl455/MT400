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

unsigned char               snake_led_index0;
    
/******************************************************************************
* 函数名称: led_mode_snake
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_17(void)
{
    unsigned char i, j;

    if(led_speed_lev > delay_time_count)
    {
        delay_time_count++;
	    return;
	}
    delay_time_count = 0;

	if(iLED_ROW_NUM <= snake_led_index0)
		snake_led_index0 = 0;

	i = --pwm_duty_array_0[snake_led_index0];
	if(0==led_speed_lev)
	{
	    if(0 != i)
	        i = --pwm_duty_array_0[snake_led_index0];
	}
	j = snake_led_index0;
	if(160>=i)
    {
		snake_led_index0++;
        if(iLED_ROW_NUM <= snake_led_index0)
            snake_led_index0 = 0;
        pwm_duty_array_0[j] = 160;
        pwm_duty_array_0[snake_led_index0] = 240;
    }
	i = pwm_duty_array_0[j];

	if(0!=j)
		j--;
	else
	    j = (iLED_ROW_NUM-1);
	pwm_duty_array_0[j] = i-80;

	if(0!=j)
		j--;
	else
	    j = (iLED_ROW_NUM-1);
	pwm_duty_array_0[j] = i-160;

    j=0;
    for(i=0; i<iLED_COL_NUM; i++)
    {
        if(iMODE_LED_17 == led_cur_mode)
        {
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[0];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[1];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[2];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[3];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[4];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[5];
        }
        else //if(iMODE_LED_18 == led_cur_mode)
        {
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[5];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[4];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[3];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[2];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[1];
            pwm_duty_array[led_to_matrix_tab_1[j++]] = pwm_duty_array_0[0];
        }
    }
}

