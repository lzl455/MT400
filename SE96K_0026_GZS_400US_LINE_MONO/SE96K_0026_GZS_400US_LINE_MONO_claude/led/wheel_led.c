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

enum RGB_MODE_Enum              wheel_led_cur_mode;
enum RGB_MODE_Enum              wheel_led_pre_mode;

unsigned char                   hclg_ctrl_tbl[4];
unsigned char                   wheel_led_array[4];

//-----------------------------------------------------------------------------;
// 表格定义区
//
unsigned char       const   wheel_hclg_tbl[]={
  128, 64,  0,  64,
};

unsigned char       const   wheel_hclg_ctrl_tbl[]={
    0,  0,  1,  1,
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void wheel_led_off(void)
{
    wheel_led_array[0] = 0;
    wheel_led_array[1] = 0;
    wheel_led_array[2] = 0;
    wheel_led_array[3] = 0;
}

/*******************************************************************************
* 函数名称: led_process()
* 功能描述:
* 输入参数： 无
* 输出参数： 无
* 说    明:
*******************************************************************************/
void wheel_led_process(void)
{
    unsigned char temp_i;

    if(wheel_led_pre_mode != wheel_led_cur_mode)
    {
        wheel_led_pre_mode = wheel_led_cur_mode;

        wheel_led_off();

        switch(wheel_led_cur_mode)
        {
            case iMODE_WHEEL_OFF:
                break;
            case iMODE_WHEEL_HCLG:
                for(temp_i=0; temp_i<iBACK_COUNT; temp_i++)
                {
                    wheel_led_array[temp_i] = wheel_hclg_tbl[temp_i];
                    hclg_ctrl_tbl[temp_i] = wheel_hclg_ctrl_tbl[temp_i];
                }
                break;
            case iMODE_WHEEL_BREATH:
                break;
            case iMODE_WHEEL_ON:
                break;

        }
    }
    else
    {
        if(0==led_light_lev)
	    {
            wheel_led_off();
            return;
	    }

	    if(iMODE_WHEEL_HCLG == wheel_led_cur_mode)
        {
            for(temp_i=0; temp_i<4; temp_i++)
            {
                if(0 == hclg_ctrl_tbl[temp_i])
                {
                    wheel_led_array[temp_i]--;
                    if(0 == wheel_led_array[temp_i])
                        hclg_ctrl_tbl[temp_i]++;
                }
                else
                {
                    wheel_led_array[temp_i]++;
                    if(iPWM_MAX <= wheel_led_array[temp_i])
                        hclg_ctrl_tbl[temp_i]=0;
                }
            }
		}
        else if(iMODE_WHEEL_BREATH == wheel_led_cur_mode)
		{

		}
		else if(iMODE_WHEEL_ON == wheel_led_cur_mode)
		{
             wheel_led_array[0] = iPWM_MAX;
             wheel_led_array[1] = iPWM_MAX;
             wheel_led_array[2] = iPWM_MAX;
             wheel_led_array[3] = iPWM_MAX;

		}
    }
}
