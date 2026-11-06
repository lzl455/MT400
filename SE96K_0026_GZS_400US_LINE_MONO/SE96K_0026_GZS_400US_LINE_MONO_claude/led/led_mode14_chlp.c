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
unsigned char       const   chlp_r_tbl[]={                 // 16                                                              32                                      42
 128,112, 96, 80, 64, 48, 32, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 48, 64, 80, 96,112,128,112, 96, 80, 64, 48, 32, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,};
unsigned char       const   chlp_g_tbl[]={
   0, 16, 32, 48, 64, 80, 96,112,128,112, 96, 80, 64, 48, 32, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 48, 64, 80, 96,112,128,112, 96, 80, 64, 48, 32, 16,  0,  0,};
unsigned char       const   chlp_b_tbl[]={
   0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 48, 64, 80, 96,112,128,112, 96, 80, 64, 48, 32, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 48, 64, 80, 96,112,128,112,};
unsigned char       const   chlp_ctrl_tbl[]={
   0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,};

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
void led_mode_chlp(void)
{
    unsigned char i, gtemp_x;

    if(led_speed_lev>delay_time_count)
    {
        delay_time_count++;
        return;
    }
    delay_time_count = 0;

    for(i=0; i<iLED_COL_NUM*2; i++)
    {
        if(0 == pwm_duty_array_3[i])
        {
            pwm_duty_array_0[i]--;
            pwm_duty_array_1[i]=iPWM_MAX-pwm_duty_array_0[i];
            if(0 == pwm_duty_array_0[i])
                pwm_duty_array_3[i]++;
        }
        else if(1 == pwm_duty_array_3[i])
        {
            pwm_duty_array_1[i]--;
            pwm_duty_array_2[i]=iPWM_MAX-pwm_duty_array_1[i];
            if(0 == pwm_duty_array_1[i])
                pwm_duty_array_3[i]++;
        }
        else //if(2 == pwm_duty_array_3[i])
        {
            pwm_duty_array_2[i]--;
            pwm_duty_array_0[i]=iPWM_MAX-pwm_duty_array_2[i];
            if(0 == pwm_duty_array_2[i])
                pwm_duty_array_3[i]=0;
        }
    }

    if(0==scan_index)
    {
        scan_index = 1;
        gtemp_i = 0;
        for(i=0; i<((iLED_ROW_NUM+1)/2); i++)
        {
            for(gtemp_x=0; gtemp_x<iLED_COL_NUM; gtemp_x++)
            {
                if(!bled_run_dir)
                    gtemp_j = led_to_matrix_tab_3[gtemp_i++];
                else
                    gtemp_j = led_to_matrix_tab_4[gtemp_i++];
                pwm_duty_array[gtemp_j]=pwm_duty_array_0[gtemp_x];
            }
        }
    }
    else
    {
        scan_index = 0;
        gtemp_i = (iLED_COL_NUM*((iLED_ROW_NUM+1)/2));
        for(i=((iLED_ROW_NUM+1)/2); i<iLED_ROW_NUM; i++)
        {
            for(gtemp_x=(iLED_COL_NUM*2-1); gtemp_x>=iLED_COL_NUM; gtemp_x--)
            {
                if(!bled_run_dir)
                    gtemp_j = led_to_matrix_tab_3[gtemp_i++];
                else
                    gtemp_j = led_to_matrix_tab_4[gtemp_i++];
                pwm_duty_array[gtemp_j]=pwm_duty_array_0[gtemp_x];
            }
        }
    }
}
