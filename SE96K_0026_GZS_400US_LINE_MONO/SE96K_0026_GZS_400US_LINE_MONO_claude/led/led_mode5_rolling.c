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

#define iROLLING_PWM_SWITCH     ((iPWM_MAX*2)/3)

unsigned char                   rolling_led_index;

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
void led_mode_roling(void)
{
    unsigned char i;

    if(led_speed_lev > delay_time_count)
    {
        delay_time_count++;
	    return;
	}
    delay_time_count = 0;

	if((iLED_BACK_MAX) <= rolling_led_index)
    	rolling_led_index = 0;

	i = --pwm_duty_array[led_to_matrix_tab_1[rolling_led_index]];
	if(iROLLING_PWM_SWITCH>=i)
    {
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index++]] = 0;

        if((iLED_BACK_MAX-iLED_ROW_NUM)<rolling_led_index)
            rolling_led_index = 0;

        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+0]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+1]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+2]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+3]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+4]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+5]] = iPWM_MAX;
    }
    else
    {
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+0]] = i;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+1]] = i;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+2]] = i;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+3]] = i;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+4]] = i;
        pwm_duty_array[led_to_matrix_tab_1[rolling_led_index+5]] = i;
    }
}


