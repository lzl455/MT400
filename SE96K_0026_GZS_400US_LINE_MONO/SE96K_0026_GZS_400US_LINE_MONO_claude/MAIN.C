/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.c
*
* 功能说明: 主函数处理程序
* 修改说明:
*******************************************************************************/
#include "defines.h"

//----------------------------------------------------------------------------;
//变量定义
//

//----------------------------------------------------------------------------;
//变量定义
//
USBD_U8                     usys_ctrl_reg;
USBD_U8                     utemp_bit;

unsigned char               sof_count;
unsigned char               SwBusTimer;

unsigned char               gtemp_i;     //@ 0X058;
unsigned char               gtemp_j;     //@ 0X059;
unsigned char               mac_win_hint_time;

unsigned char               matrix_status_bak[iMATRIX_COL_NUM+2];

unsigned char               my_led_flag;     //灯光模式，0是关闭灯光，1是开启灯光

//-----------------------------------------------------------------------------;

//-----------------------------------------------------------------------------;
// 表格定义区
//

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/*******************************************************************************
* 函数名称: sys_init()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void sys_init(void)
{
    unsigned char i;

    GIEH = 0;
//----------------------------------------------------
//Init IO
//IOA
    ANSA = 0x00;
    IOAODS0 = 0xFC;
    IOAODS1 = 0xFC;
    PUA = 0x03;                                 //0:上拉关闭 1:上拉使能
    PDA = 0x00;                                 //0:下拉关闭 1:下拉使能
    OEA = 0xFC;                                 //0:输入 1:输出
    IOA = 0xFF;                                 //IO口数据
//IOB
    ANSB = 0x00;
    IOBODS0 = 0x00;
    IOBODS1 = 0x00;
    PUB = 0x00;                                 //0:上拉关闭 1:上拉使能
    PDB = 0x00;                                 //0:下拉关闭 1:下拉使能
    OEB = 0xFF;                                 //0:输入 1:输出
    IOB = 0xFF;                                 //IO口数据
//IOC
    ANSC = 0x00;
    IOCODS0 = 0x00;
    IOCODS1 = 0x00;
    PUC = 0x00;                                 //0:上拉关闭 1:上拉使能
    PDC = 0x00;                                 //0:下拉关闭 1:下拉使能
    OEC = 0xFF;                                 //0:输入 1:输出
    IOC = 0xFF;                                 //IO口数据
//IOD
    ANSD = 0x00;
    IODODS0 = 0x00;
    IODODS1 = 0x00;
    PUD = 0x00;                                 //0:上拉关闭 1:上拉使能
    PDD = 0x00;                                 //0:下拉关闭 1:下拉使能
    OED = 0xFF;                                 //0:输入 1:输出
    IOD = 0xFF;                                 //IO口数据
//IOE
    ANSE = 0x00;
    IOEODS0 = 0x00;
    IOEODS1 = 0x00;
    PUE = 0xFF;                                 //0:上拉关闭 1:上拉使能
    PDE = 0x00;                                 //0:下拉关闭 1:下拉使能
    OEE = 0x00;                                 //0:输入 1:输出
    IOE = 0xFF;                                 //IO口数据
//IOF
    ANSF = 0x00;
    IOFODS0 = 0x03;
    IOFODS1 = 0x03;
    PUF = 0x00;                                 //0:上拉关闭 1:上拉使能
    PDF = 0x0E;                                 //0:下拉关闭 1:下拉使能
    OEF = 0xF0;                                 //0:输入 1:输出
    IOF = 0xFF;                                 //IO口数据

    INTCR0 = 0x00;
    INTCR1 = 0x00;
    INTCR2 = 0x00;

    // PF7=0;
    timer0_init();
    pwm2_init();
    e2_config_load();

	memset(std_key, 0x00, 22);
	memset(key_fn_status, 0x00, iMATRIX_NUM_MAX);
	memset(define_key_fifo, 0x00, iMATRIX_NUM_MAX);

    for(i=0; i<iMATRIX_COL_NUM; i++)
    {
        matrix_status[i] = 0;
        matrix_status_bak[i] = 0;
        gKeyScan_bak[i] = 0;
        gKey_delay[i] = 0xFF;
    }

    clr_led_data();
    bsave_flash = 0;
    bwin_mac_sataus =1;
    usb_data_flag = 0;
    busb_boot = 1;

    int_iob_dat = 0xFF;
    int_ioc_dat = 0xFF;
    int_iod_dat = 0xFF;
    led_scan_count = 0x00;
    led_index_value = 0;

    //led_cur_mode = iMODE_LED_BREATH;
	//led_cur_mode = iMODE_LED_SNAKE;
}

/******************************************************************************
* 函数名称: led_mode_snake
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void power_on_self(void)
{
    unsigned char i, j;

    TC1PRH = 0x00;
    TC1PRL = iPWM_MAX;
    j = iLED_BACK_MAX;
    for(i=0; i<=iLED_BACK_MAX/2; i++)
    {
        pwm_duty_array[led_to_matrix_tab_3[i]] = iPWM_MAX;
        pwm_duty_array[led_to_matrix_tab_3[--j]] = iPWM_MAX;
		delayms(35);
	}
	delayms(200);
    clr_led_data();
	pwm2_init();
}

/******************************************************************************
* 函数名称: main()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void main(void)
{
    sys_init();
    GIEH = 1;
    power_on_self();

    USBD_Init();

    while(1)
    {
        if(bkey_scan)
        {
            bkey_scan = 0;
            sof_count++;
            if(0 == (sof_count&0x03))
            {                                    // 周期10.31ms
			    if(0 != mac_win_hint_time)
				    mac_win_hint_time--;
            }

            if(PF2)
            {
                if(my_led_flag)
                {
                     my_led_flag=0;
                }
            }
            else if(PF3)
            {
               if(!my_led_flag)
               {
                    my_led_flag=1;
               }
            }
            if(MY_SIRI_TIME)
            MY_SIRI_TIME--;
            
            led_process();
            // wheel_scan();
			// wheel_led_process();
            matrixkey_scan();

            hid_process();
            usb_data_process();
        }

        system_sleep();
    }
}

/******************************************************************************
* 函数名称: none()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void none_int(void)
{
}

/******************************************************************************
* 函数名称: high_priority()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void interrupt high_priority HP_Intr(void)    //高优先级中断入口
{
    #asm
    call _none_int ,f        //高优先级中断务必添加该汇编
    #endasm
//----------------------------------------------
// 总线中断处理
//
    if(UBRST)
    {
        UBRST = 0;

        USBEnumState = USBE_Default;
        usb_ctrl_flag = 0;
        usb_status_reg = 0;
        EpState = 0;
        USBEpBusy = 0;

        USBSwState = 0;

        UDADR = 0x00;
        UE0CON = 0x02;
        UE0IOPS = 0x00;
    
        UE1CON = UE1CON_RSET;
        UE1IOPS = 0x00;
    
        UE2CON = UE2CON_RSET;
        UE2IOPS = 0x00;
    
        UE3CON = UE3CON_RSET;
        UE3IOPS = 0x00;
		USBD_CalibrationInit();
    }
    if(UBSPD)
    {
        UBSPD = 0;
    }

    if(UBRSM)
    {
        UBRSM = 0;
        busb_suspend_en = 0;
    }
//----------------------------------------------
// 端点0中断处理
//
    if(UE0STL)
    {
        unsigned char t = 100;    //不同运行速度下,可能需要修改t
        while(t--)
        {
            if(!UE0STL)
                break;
            if(TC0IF)
            {
                TC0IF = 0;
                timer_int_process();
            }
        }
        UE0STL = 0;    
    }
    if(UE0SDF)
        USBD_EP0_Handler();

//----------------------------------------------
// 端点1中断处理
//
    if(UE1INF)
    {
        busb_suspend_en = 0;
        UE1INF = 0;
        UE1IOPS = 0;
        bEp1Busy = 0;
    }
//----------------------------------------------
// 端点2中断处理
//
    if(UE2INF)
    {
        busb_suspend_en = 0;
        UE2INF = 0;
        UE2IOPS = 0;
        bEp2Busy = 0;
    }

    if(IOFCHIE&&IOFCHIF)
    {
        IOFCHIF = 0;
        if(0!=(IOFICR&0X03))
        {
            IOFICR &= ~0X03;         // 翻转后关闭F0、F1中断,等待一定时间后再开启,避免频繁进入该中断
            SwBusTimer = 0;             // 清除定时器
            busb_suspend_en = 0;
        }
    }
    if(IOACHIE && IOACHIF)
        IOACHIF = 0;

    INTF1 = 0;

    if(TC0IF)
    {
        TC0IF = 0;                              // 中断标志位清零
        timer_int_process();
    }
}

/*
void interrupt low_priority LP_Intr(void)    //低优先级中断入口
{

}
*/

