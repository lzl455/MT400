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
* 函数名称: led_mode_breath
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_breath(void)
{
    unsigned char i;

    if(led_speed_lev > delay_time_count)
    {
        delay_time_count++;
	    return;
	}
    delay_time_count = 0;

    i = pwm_time_count;
    if(!bback_led_status)
    {
		if(pwm_time_count >= iPWM_MAX)
			pwm_duty_array[0] = 0;
		else
        	pwm_duty_array[0] = (iPWM_MAX - i);
    }
    else
    {
		if(pwm_time_count >= iPWM_MAX)
			pwm_duty_array[0] = iPWM_MAX;
		else
        	pwm_duty_array[0] = i;
    }

    if(pwm_time_count == iPWM_MAX)
    {
        pwm_time_count = 0;
        bback_led_status = ~bback_led_status;
    }

    for(i=1; i<iLED_ALL_MAX; i++)
        pwm_duty_array[i] = pwm_duty_array[0];

    pwm_time_count++;
	//if(0==led_speed_lev)
    //    pwm_time_count++;
}
