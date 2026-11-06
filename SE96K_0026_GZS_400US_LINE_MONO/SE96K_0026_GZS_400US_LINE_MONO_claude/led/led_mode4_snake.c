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

unsigned char                   snake_led_index;

//-----------------------------------------------------------------------------;
// 表格定义区
//
#define iPWM_SNAKE_MAX          126

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
void led_mode_snake(void)
{
    unsigned char x, y ,k;
    if(led_speed_lev>delay_time_count)
    {
		delay_time_count++;
        return;
	}
    delay_time_count = 0;

	if(iLED_BACK_MAX <= snake_led_index)
		snake_led_index = 0;

	k = snake_led_index;
	y = led_snake_table[k];
	x = --pwm_duty_array_0[y];
	if(((iPWM_SNAKE_MAX*5)/6)>=x)
    {
		snake_led_index++;
        if(iLED_BACK_MAX<=snake_led_index)
            snake_led_index = 0;
        pwm_duty_array_0[y] = ((iPWM_SNAKE_MAX*5)/6);
        y = led_snake_table[snake_led_index];
        pwm_duty_array_0[y] = iPWM_SNAKE_MAX;
    }
	x = pwm_duty_array_0[led_snake_table[k]];

	if(0!=k)
		k--;
	else
	    k = (iLED_BACK_MAX-1);
	y = led_snake_table[k];
	pwm_duty_array_0[y] = x-((iPWM_SNAKE_MAX*1)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_BACK_MAX-1);
	y = led_snake_table[k];
	pwm_duty_array_0[y] = x-((iPWM_SNAKE_MAX*2)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_BACK_MAX-1);
	y = led_snake_table[k];
	pwm_duty_array_0[y] = x-((iPWM_SNAKE_MAX*3)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_BACK_MAX-1);
	y = led_snake_table[k];
	pwm_duty_array_0[y] = x-((iPWM_SNAKE_MAX*4)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_BACK_MAX-1);
	y = led_snake_table[k];
	pwm_duty_array_0[y] = x-((iPWM_SNAKE_MAX*5)/6);
	
    for(x=0; x<iLED_ALL_MAX; x++)
    {
		pwm_duty_array[x] = pwm_duty_array_0[x];
    }
}
		
#define iLED_SNAKE_1            17
void led_mode_snake_1(void)
{
    unsigned char x, k;

    if(led_speed_lev>delay_time_count)
    {
		delay_time_count++;
        return;
	}
    delay_time_count = 0;

    if(iLED_COL_NUM <= snake_led_index)
		snake_led_index = 0;

	k = snake_led_index;
	x = --pwm_duty_array_0[k];

	if(((iPWM_SNAKE_MAX*5)/6)>=x)
    {
		snake_led_index++;
        if(iLED_SNAKE_1<=snake_led_index)
            snake_led_index = 0;
        pwm_duty_array_0[k] = ((iPWM_SNAKE_MAX*5)/6);
        k = snake_led_index;
        pwm_duty_array_0[k] = iPWM_SNAKE_MAX;
    }
	x = pwm_duty_array_0[k];

	if(0!=k)
		k--;
	else
	    k = (iLED_SNAKE_1-1);
	pwm_duty_array_0[k] = x-((iPWM_SNAKE_MAX*1)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_SNAKE_1-1);
	pwm_duty_array_0[k] = x-((iPWM_SNAKE_MAX*2)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_SNAKE_1-1);
	pwm_duty_array_0[k] = x-((iPWM_SNAKE_MAX*3)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_SNAKE_1-1);
	pwm_duty_array_0[k] = x-((iPWM_SNAKE_MAX*4)/6);

	if(0!=k)
		k--;
	else
	    k = (iLED_SNAKE_1-1);
	pwm_duty_array_0[k] = x-((iPWM_SNAKE_MAX*5)/6);

    for(x=0; x<iLED_COL_NUM; x++)
    {
        gtemp_j = led_snake_table[x+iLED_COL_NUM*0];
        pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        gtemp_j = led_snake_table[x+iLED_COL_NUM*1];
        pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        gtemp_j = led_snake_table[x+iLED_COL_NUM*2];
        pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        gtemp_j = led_snake_table[x+iLED_COL_NUM*3];
        pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        gtemp_j = led_snake_table[x+iLED_COL_NUM*4];
        pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
        // gtemp_j = led_snake_table[x+iLED_COL_NUM*5];
        // pwm_duty_array[gtemp_j] = pwm_duty_array_0[x];
    }
}

void led_mode_snake_2(void)
{
    unsigned char i, x, k;

    if(led_speed_lev>delay_time_count)
    {
		delay_time_count++;
        return;
	}
    delay_time_count = 0;

    for(i=0; i<iLED_ROW_NUM; i++)
    {
        if(pwm_duty_array_3[i]>pwm_duty_array_2[i])
        {
		    pwm_duty_array_2[i]++;
            continue;
	    }
        pwm_duty_array_2[i] = 0;
        pwm_duty_array_3[i] = i;

        if(iLED_COL_NUM <= pwm_duty_array_1[i])
		    pwm_duty_array_1[i] = 0;

        k = pwm_duty_array_1[i];
        pwm_duty_array_0[i*iLED_COL_NUM+k]--;
		if(0!=pwm_duty_array_0[i*iLED_COL_NUM+k])
            pwm_duty_array_0[i*iLED_COL_NUM+k]--;
		if(0!=pwm_duty_array_0[i*iLED_COL_NUM+k])
            pwm_duty_array_0[i*iLED_COL_NUM+k]--;
		if(0!=pwm_duty_array_0[i*iLED_COL_NUM+k])
            pwm_duty_array_0[i*iLED_COL_NUM+k]--;
        x = pwm_duty_array_0[i*iLED_COL_NUM+k];

	    if(((iPWM_SNAKE_MAX*5)/6) >= x)
        {
	    	pwm_duty_array_1[i]++;
            if(iLED_COL_NUM<=pwm_duty_array_1[i])
                pwm_duty_array_1[i] = 0;

            k = pwm_duty_array_1[i];
            pwm_duty_array_0[i*iLED_COL_NUM+k] = iPWM_SNAKE_MAX;
            x = iPWM_SNAKE_MAX;
        }

	    if(0!=k)
		    k--;
	    else
	        k = (iLED_COL_NUM-1);
	    pwm_duty_array_0[i*iLED_COL_NUM+k] = x-((iPWM_SNAKE_MAX*1)/6);

	    if(0!=k)
		    k--;
	    else
	        k = (iLED_COL_NUM-1);
	    pwm_duty_array_0[i*iLED_COL_NUM+k] = x-((iPWM_SNAKE_MAX*2)/6);

	    if(0!=k)
		    k--;
	    else
	        k = (iLED_COL_NUM-1);
	    pwm_duty_array_0[i*iLED_COL_NUM+k] = x-((iPWM_SNAKE_MAX*3)/6);

	    if(0!=k)
		    k--;
	    else
	        k = (iLED_COL_NUM-1);
	    pwm_duty_array_0[i*iLED_COL_NUM+k] = x-((iPWM_SNAKE_MAX*4)/6);

	    if(0!=k)
		    k--;
	    else
	        k = (iLED_COL_NUM-1);
	    pwm_duty_array_0[i*iLED_COL_NUM+k] = x-((iPWM_SNAKE_MAX*5)/6);
    }

    i = 0;
    for(x=0; x<iLED_BACK_MAX; x++)
    {
        i = led_to_matrix_tab_3[x]; 
        pwm_duty_array[i] = pwm_duty_array_0[x];
    }
}
