/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: wheel.c
*
* 功能说明: 滚轮扫描处理
* 修改说明:
*******************************************************************************/
#include "..\defines.h"
#include "key_code_define.h"

//-----------------------------------------------------------------------------;
// 常量定义区
//

//-----------------------------------------------------------------------------;
// 变量定义区
//
USBD_U8                         uwheel_status_1;

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/*******************************************************************************
* 函数名称: wheel_scan()
* 功能描述: 滚轮扫描处理
* 输入参数：无
* 输出参数：无
* 说    明:
*******************************************************************************/
void wheel_scan(void)
{
    bcurr_a_status_1 = WHEEL_A_1;
    bcurr_b_status_1 = WHEEL_B_1;

    if(bcurr_a_status_1 != bcurr_b_status_1)
    {                                           //  设置不稳定状态有效位
        bno_status_valid_1 = 1;
        bpre_ab_no_status_1 = bcurr_a_status_1;
        return;
    }

    if(bpre_ab_status_1 == bcurr_a_status_1)
    {
   	    return;                                 // 前后状态没有变化
    }

    if(bno_status_valid_1)
    {
        bno_status_valid_1 = 0;

        if(bpre_ab_no_status_1)
        {
            bwheel_data_status_1 = bpre_ab_status_1;
        }
        else
        {
            bwheel_data_status_1 = !bpre_ab_status_1;
        }
        if(bwheel_data_status_1)
        {
            multi_key[0] = iMMK_VOLUMEDOWN_L;
            multi_key[1] = iMMK_VOLUMEDOWN_H;
        }
        else
        {
            multi_key[0] = iMMK_VOLUMEUP_L;
            multi_key[1] = iMMK_VOLUMEUP_H;
        }
        bmmk_data_send = 1;
    }

    bpre_ab_status_1 = bcurr_a_status_1;
}
