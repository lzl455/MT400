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
void led_mode_xilabianhuan(void)
{
    unsigned char x, k;

    if(led_speed_lev>delay_time_count)
    {
		delay_time_count++;
        return;
	}
    delay_time_count = 0;

	if(!bled_dir_status)
    {
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

	    if(33 <= snake_led_index)
	    {
	        snake_led_index = 33;
            memset(pwm_duty_array_0, 0x00, 40);
	        pwm_duty_array_0[33] = iPWM_MAX;
		    bled_dir_status = 1;
			goto bled_run_dir_0;
	    }
    }
    else
    {
	    k = snake_led_index;
	    x = --pwm_duty_array_0[k];

	    if(((iPWM_MAX*5)/6)>=x)
        {
	    	snake_led_index--;
            pwm_duty_array_0[k] = ((iPWM_MAX*5)/6);
            pwm_duty_array_0[snake_led_index] = iPWM_MAX;
        }
	    x = pwm_duty_array_0[k];
	    k++;
	    pwm_duty_array_0[k] = x-((iPWM_MAX*1)/6);
	    k++;
	    pwm_duty_array_0[k] = x-((iPWM_MAX*2)/6);
	    k++;
	    pwm_duty_array_0[k] = x-((iPWM_MAX*3)/6);
	    k++;
	    pwm_duty_array_0[k] = x-((iPWM_MAX*4)/6);
	    k++;
	    pwm_duty_array_0[k] = x-((iPWM_MAX*5)/6);

	    if(0 == snake_led_index)
	    {
            if(1>=pwm_duty_array_0[5])
		    {
	            snake_led_index = 5;
                memset(pwm_duty_array_0, 0x00, 40);
	            pwm_duty_array_0[5] = iPWM_MAX;
		        bled_dir_status = 0;
			    goto bled_run_dir_1;
			}
	    }
    }

    for(x=0; x<33; x++)
    {
	    if(!bled_dir_status)
        {
bled_run_dir_0:
            gtemp_j = led_to_matrix_tab_14_14[x+40*0+5];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*1+4];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*2+3];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*3+2];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*4+1];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*5+0];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        }
        else
        {
bled_run_dir_1:
            gtemp_j = led_to_matrix_tab_14_14[x+40*0+0];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*1+1];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*2+2];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*3+3];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*4+4];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
            gtemp_j = led_to_matrix_tab_14_14[x+40*5+5];
		    pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        }
    }
}
