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
unsigned char       const       led_liuguang_l_r_tbl[]={
    128, 96, 64, 32,  0, 32, 64, 96,128, 96, 64, 32,  0, 32, 64, 96,128, 96, 64, 32,
};

unsigned char       const       led_liuguang_u_d_tbl[]=
{
    0, 32, 64, 96, 128,  96,
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;
void led_mode_liuguang_l_r_w(void)
{
    unsigned char j;

    j = led_to_matrix_tab_1[gtemp_i++];
    pwm_duty_array[j] = gtemp_j;
}

/******************************************************************************
* 函数名称: led_mode_snake
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_liuguang_l_r(void)
{
    unsigned char i, k;
    unsigned int x;

    if(led_speed_lev > delay_time_count)
    {
        delay_time_count++;
	    return;
	}
    delay_time_count = 0;

    x = 0x0001;
    for(i=0; i<16; i++)
    {
        if(led_status_reg & x)
        {
            pwm_duty_array_0[i]++;
            if(iPWM_MAX <= pwm_duty_array_0[i])
            {
                led_status_reg &= ~x;
            }
        }
        else
        {
            pwm_duty_array_0[i]--;
            if(0 == pwm_duty_array_0[i])
            {
                led_status_reg |= x;
            }
        }
        x <<= 1;
    }

    k = 0x01;
    for(i=16; i<iLED_COL_NUM; i++)
    {
        if(led_status_reg_ex & k)
        {
            pwm_duty_array_0[i]++;
            if(iPWM_MAX <= pwm_duty_array_0[i])
            {
                led_status_reg_ex &= ~k;
            }
        }
        else
        {
            pwm_duty_array_0[i]--;
            if(0 == pwm_duty_array_0[i])
            {
                led_status_reg_ex |= k;
            }
        }
        k <<= 1;
    }

    gtemp_i = 0;
    for(k=0; k<iLED_COL_NUM; k++)
	{
        gtemp_j = pwm_duty_array_0[iLED_COL_NUM-1-k];

        led_mode_liuguang_l_r_w();
        led_mode_liuguang_l_r_w();
        led_mode_liuguang_l_r_w();
        led_mode_liuguang_l_r_w();
        led_mode_liuguang_l_r_w();
        led_mode_liuguang_l_r_w();
    }
}

/******************************************************************************
* 函数名称: led_mode_snake
* 功能描述:
* 输入参数: 无`
* 输出参数: 无
* 说    明:
******************************************************************************/
void led_mode_liuguang_u_d(void)
{
    unsigned char i, k;
    unsigned int x;

    if(led_speed_lev > delay_time_count)
    {
        delay_time_count++;
	    return;
	}
    delay_time_count = 0;

    x = 0x01;
    for(i=0; i<iLED_ROW_NUM; i++)
    {
        if(led_status_reg & x)
        {
            pwm_duty_array_0[i]++;
            if(iPWM_MAX <= pwm_duty_array_0[i])
            {
                led_status_reg &= ~x;
            }
        }
        else
        {
            pwm_duty_array_0[i]--;
            if(0 == pwm_duty_array_0[i])
            {
                led_status_reg |= x;
            }
        }
        x <<= 1;
    }

    gtemp_i = 0;
    for(i=0; i<iLED_ROW_NUM; i++)
	{
        gtemp_j = pwm_duty_array_0[iLED_ROW_NUM-1-i];

        for(k=0; k<iLED_COL_NUM; k++)
        {
            pwm_duty_array[led_to_matrix_tab_3[gtemp_i++]] = gtemp_j;
        }
    }
}

