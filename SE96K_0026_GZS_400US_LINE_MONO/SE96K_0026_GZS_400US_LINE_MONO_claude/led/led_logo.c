/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: led.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "..\defines.h"

//-----------------------------------------------------------------------------;
// 常量定义区
//

//-----------------------------------------------------------------------------;
// 变量定义区
//
USBD_U16                        uled_ctrl_reg;
USBD_U16                        uled_status_reg;
USBD_U8                         uled_status_reg_ex;
USBD_U8                         uint_temp0;
//{
    #define int_temp0           uint_temp0.u8

    #define bint_temp7          uint_temp0.BIT.b7
    #define bint_temp6          uint_temp0.BIT.b6
    #define bint_temp5          uint_temp0.BIT.b5
    #define bint_temp4          uint_temp0.BIT.b4
    #define bint_temp3          uint_temp0.BIT.b3
    #define bint_temp2          uint_temp0.BIT.b2
    #define bint_temp1          uint_temp0.BIT.b1
    #define bint_temp0          uint_temp0.BIT.b0
//}

enum led_mod                    led_cur_mode;
enum led_mod                    led_pre_mode;
enum speed_level                led_speed_lev;
unsigned char                   led_scan_count;

unsigned char                   pwm_time_count;
unsigned int                    delay_time_count;
//unsigned int                    hint_time_count;

unsigned char                   scan_index;
unsigned char                   back_led_off_delay;

unsigned char                   pwm_duty_array_0[0x80];
unsigned char                   pwm_duty_array_1[0x80];
unsigned char                   pwm_duty_array_2[0x80];
unsigned char                   pwm_duty_array_3[0x80];

//-----------------------------------------------------------------------------;
// 表格定义区
//

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/******************************************************************************
* 函数名称: pwm2_init
* 功能描述:
* 输入参数:
* 输出参数:
* 说    明:
******************************************************************************/
void pwm2_init(void)
{
 //1、时钟源设置
    T1CR = 0x88;                                 // 递增模式，系统高频时钟，1:64分频
    TC1CL = 0X00;                                // 将TC1CL清零    
    TC1CH = 0x00;                                // 将TC1CH清零
    TC1PRH = 0x00;
    TC1PRL = 0x00;
    if(4==led_light_lev)
        TC1PRL = iPWM_MAX;
    else if(3==led_light_lev)
        TC1PRH = 0x01;
    else if(2==led_light_lev)
        TC1PRH = 0x02;
    else //if(1==led_light_lev)
        TC1PRH = 0x04;

//PWM100设置
    PWM100CR = 0x00;
    PWM100DH = 0x00;
    PWM100DL = 0x00;

    PWM101CR = 0x00;
    PWM101DH = 0x00;
    PWM101DL = 0x00;

    PWM102CR = 0x00;
    PWM102DH = 0x00;
    PWM102DL = 0x00;

    PWM103CR = 0x00;
    PWM103DH = 0x00;
    PWM103DL = 0x00;

    PWM104CR = 0x00;
    PWM104DH = 0x00;
    PWM104DL = 0x00;

    PWM105CR = 0x00;
    PWM105DH = 0x00;
    PWM105DL = 0x00;

    PWM106CR = 0x00;
    PWM106DH = 0x00;
    PWM106DL = 0x00;

    PWM107CR = 0x00;
    PWM107DH = 0x00;
    PWM107DL = 0x00;

    PWM108CR = 0x00;
    PWM108DH = 0x00;
    PWM108DL = 0x00;

    PWM109CR = 0x00;
    PWM109DH = 0x00;
    PWM109DL = 0x00;

    PWM110CR = 0x00;
    PWM110DH = 0x00;
    PWM110DL = 0x00;

    PWM111CR = 0x00;
    PWM111DH = 0x00;
    PWM111DL = 0x00;

    PWM112CR = 0x00;
    PWM112DH = 0x00;
    PWM112DL = 0x00;

    PWM113CR = 0x00;
    PWM113DH = 0x00;
    PWM113DL = 0x00;

    PWM114CR = 0x00;
    PWM114DH = 0x00;
    PWM114DL = 0x00;

    PWM115CR = 0x00;
    PWM115DH = 0x00;
    PWM115DL = 0x00;

    PWM116CR = 0x00;
    PWM116DH = 0x00;
    PWM116DL = 0x00;

    PWM117CR = 0x00;
    PWM117DH = 0x00;
    PWM117DL = 0x00;

    PWM118CR = 0x00;
    PWM118DH = 0x00;
    PWM118DL = 0x00;

    PWM119CR = 0x00;
    PWM119DH = 0x00;
    PWM119DL = 0x00;

    PWM120CR = 0x00;
    PWM120DH = 0x00;
    PWM120DL = 0x00;
}

void clr_led(void)
{
    memset(pwm_duty_array, 0x00, iLED_ALL_MAX);
}

void set_led(void)
{
    memset(pwm_duty_array, iPWM_MAX, iLED_ALL_MAX);
}

void led_hint(void)
{
    for(unsigned char i=0; i<3; i++)
    {
        LED_NUM_PIN = 1;
        LED_CAPS_PIN = 1;
        LED_SCROLL_PIN = 1;
        delayms(50);
        LED_NUM_PIN = 0;
        LED_CAPS_PIN = 0;
        LED_SCROLL_PIN = 0;
        delayms(50);
    }
}

void clr_led_data(void)
{
    memset(pwm_duty_array, 0x00, iLED_ALL_MAX);
}

/******************************************************************************
* 函数名称: led_process
* 功能描述:
* 输入参数:
* 输出参数:
* 说    明:
******************************************************************************/
void led_process(void)
{
    unsigned char i;

    LED_NUM_PIN = ~bnum_lock;
    LED_CAPS_PIN = ~bcaps_lock;
    LED_SCROLL_PIN = ~bscroll_lock;
    LED_WIN_LOCK_PIN = ~bwin_lock_status;

    if(bsave_flash)
    {
        cfg_mode_save();
        bsave_flash = 0;
    }
    if(bsave_led)
    {
        led_def_save();
        bsave_led = 0;
    }

    if(busb_suspend_en || !busb_enum_finish)
    {
        if(bled_hint_ing)
        {
            if(200 < back_led_off_delay)
            {
                busb_suspend_bak = 1;
                clr_led_data();

                bled_hint_ing = 0;
                return;
            }
            if(0 == (sof_count&0x03))
                back_led_off_delay++;
        }
        else
        {
            return;
        }
    }
    else
    {
        if(busb_suspend_bak)
        {
            busb_suspend_bak = 0;

            back_led_off_delay = 0;
            led_pre_mode = iMODE_LED_INVALID;
        }
    }

    if((0==led_light_lev)||!bled_bright_en)
    {
        clr_led_data();
        return;
    }
	
	if(bled_mode_def)
	{
	    led_mode_def();
        return;
	}

    // if(!my_led_flag)
    // {
    //     clr_led();
    //     return;
    // }

    if(led_pre_mode != led_cur_mode)
    {
        led_pre_mode = led_cur_mode;
        led_scan_count = 0;
        led_index_value = 0;

        delay_time_count = 0;
        bdevice_status_change = 1;
        bled_mode_single = 0;
        bled_mode_jg = 0;

        clr_led_data();
	    memset(pwm_duty_array_0, 0x00, iLED_ALL_MAX);
	    memset(pwm_duty_array_1, 0x00, iLED_ALL_MAX);
	    memset(pwm_duty_array_2, 0x00, iLED_ALL_MAX);
	    memset(pwm_duty_array_3, 0x00, iLED_ALL_MAX);

        switch(led_cur_mode)
        {
            case iMODE_LED_OFF:

                break;
            case iMODE_LED_ON:

                break;
            case iMODE_LED_BREATH:
                pwm_time_count = 0;
                delay_time_count = 0xFF;

                break;
            case iMODE_LED_SNAKE:
                snake_led_index = 5;
                pwm_duty_array_0[5] = ((iPWM_MAX*6)/6);

                break;
            case iMODE_LED_SNAKE_1:
                snake_led_index = 5;
                pwm_duty_array_0[5] = ((iPWM_MAX*6)/6);
                break;
            case iMODE_LED_SNAKE_2:
                delay_time_count = 0;

                pwm_duty_array_1[0] = 0;
                pwm_duty_array_0[0*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[1] = 0;
                pwm_duty_array_0[1*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[2] = 0;
                pwm_duty_array_0[2*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[3] = 0;
                pwm_duty_array_0[3*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[4] = 0;
                pwm_duty_array_0[4*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[5] = 0;
                pwm_duty_array_0[5*iLED_COL_NUM+0] = ((iPWM_MAX*6)/6);

                break;
            case iMODE_LED_XLBH:
                snake_led_index = 5;
                pwm_duty_array_0[5] = ((iPWM_MAX*6)/6);

                break;
            case iMODE_LED_ROLLING:
                rolling_led_index = 0;
                pwm_duty_array[led_to_matrix_tab_1[rolling_led_index]] = iPWM_MAX;

                break;
            case iMODE_LED_SINGLE:
                bled_mode_single = 1;
                for(i=0; i<iMATRIX_NUM_MAX; i++)
                    pwm_duty_array[i] = iPWM_MAX;

                break;
            case iMODE_LED_LG_L_R:
                delay_time_count = 0;
                led_status_reg = 0xF0F0;
                led_status_reg_ex = 0;

                for(i=0; i<iLED_COL_NUM; i++)
                    pwm_duty_array_0[i] = led_liuguang_l_r_tbl[i];

                break;
            case iMODE_LED_LG_U_D:
                led_status_reg = 0x0007;
                for(i=0; i<iLED_COL_NUM; i++)
                    pwm_duty_array_0[i] = led_liuguang_u_d_tbl[i];

                break;
            case iMODE_LED_STAR:
                snake_led_index = 0xFF;
                lfsr_value = 0x55AA;
                break;

            case iMODE_LED_ZXB:
                led_status_reg = 0;
                bled0_status = 1;

                break; 
            case iMODE_LED_YZMB:

                break; 
            case iMODE_LED_CHLP:
                memcpy_const(pwm_duty_array_0, chlp_r_tbl, iLED_COL_NUM*2);
                memcpy_const(pwm_duty_array_1, chlp_g_tbl, iLED_COL_NUM*2);
                memcpy_const(pwm_duty_array_2, chlp_b_tbl, iLED_COL_NUM*2);
                memcpy_const(pwm_duty_array_3, chlp_ctrl_tbl, iLED_COL_NUM*2);

                break; 
            case iMODE_LED_BHQF:
                pwm_duty_array_0[0] = 53;
                for(i=1; i<iLED_BACK_MAX; i++)
                {
                    pwm_duty_array_0[i] = (pwm_duty_array_0[i-1]+(i<<4)+50);
                    if(iPWM_MAX < pwm_duty_array_0[i])
                        pwm_duty_array_0[i] -= iPWM_MAX;
                    pwm_duty_array_1[i] = (i&0x01);
                }
            case iMODE_LED_17:
                snake_led_index0 = 0;

                break; 
            case iMODE_LED_ARROW:
                delay_time_count = 0;

                pwm_duty_array_1[0] = 5;
                pwm_duty_array_0[0*iLED_COL_NUM+5] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[1] = 6;
                pwm_duty_array_0[1*iLED_COL_NUM+6] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[2] = 7;
                pwm_duty_array_0[2*iLED_COL_NUM+7] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[3] = 7;
                pwm_duty_array_0[3*iLED_COL_NUM+7] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[4] = 6;
                pwm_duty_array_0[4*iLED_COL_NUM+6] = ((iPWM_MAX*6)/6);
                pwm_duty_array_1[5] = 5;
                pwm_duty_array_0[5*iLED_COL_NUM+5] = ((iPWM_MAX*6)/6);

                break; 
            case iMODE_LED_CENTRE:
                snake_led_index = 5;
                pwm_duty_array_0[5] = ((iPWM_MAX*6)/6);

                break;
        }
    }
    else
    {
        bled_hint_ing = 1;
        switch(led_cur_mode)
        {
            case iMODE_LED_OFF:
                break;
            case iMODE_LED_ON:                
                led_mode_on();
                break;
            case iMODE_LED_BREATH:
                led_mode_breath();
                break;
            case iMODE_LED_SNAKE:
                led_mode_snake();
                break;

            case iMODE_LED_SNAKE_1:
			    led_mode_snake_1();
                break;

            case iMODE_LED_SNAKE_2:
			    led_mode_snake_2();
                break;

            case iMODE_LED_XLBH:
			    led_mode_xilabianhuan();
                break;
            case iMODE_LED_ROLLING:
                led_mode_roling();
                break;
            case iMODE_LED_SINGLE:
                led_mode_single();
                break;
            case iMODE_LED_LG_L_R:
                led_mode_liuguang_l_r();
                break;
            case iMODE_LED_LG_U_D:
                led_mode_liuguang_u_d();
                break;
            case iMODE_LED_STAR:
                led_mode_star();
                break;
            case iMODE_LED_ZXB:
                led_mode_zxb();
                break;
            case iMODE_LED_YZMB:
                led_mode_yzmb();
                break;
            case iMODE_LED_CHLP:
                led_mode_chlp();
                break;
            case iMODE_LED_BHQF:
                led_mode_bhqf();
                break;
            case iMODE_LED_17:
                led_mode_17();
                break;
            case iMODE_LED_ARROW:
                led_mode_arrow();
                break;
            case iMODE_LED_CENTRE:
                led_mode_centre();
                break;
        }
    }
}

/******************************************************************************
* 函数名称: timer_int_process
* 功能描述:
* 输入参数:
* 输出参数:
* 说    明:
******************************************************************************/
void timer_int_process(void)
{
    IOA |= 0xFC;

    PWM114CR = 0x00;
    PWM115CR = 0x00;
    PWM116CR = 0x00;
    PWM117CR = 0x00;
    PWM118CR = 0x00;
    PWM119CR = 0x00;
    PWM120CR = 0x00;
    PWM100CR = 0x00;
    PWM101CR = 0x00;
    PWM102CR = 0x00;
    PWM103CR = 0x00;
    PWM104CR = 0x00;
    PWM105CR = 0x00;
    PWM106CR = 0x00;
    PWM107CR = 0x00;
    PWM108CR = 0x00;
    PWM109CR = 0x00;
    PWM110CR = 0x00;
    PWM111CR = 0x00;
    PWM112CR = 0x00;
    PWM113CR = 0x00;

    led_scan_count++;
    if((iMATRIX_COL_NUM+1) < led_scan_count)
    {
        int_iob_dat = 0xFE;
        int_ioc_dat = 0xFE;
        int_iod_dat = 0xFE;
        led_scan_count = 0;
        bkey_scan = 1;
    }

    if(8>led_scan_count)
    {
        IOB = int_iob_dat;
        IOC = 0xFF;
        IOD = 0xFF;
#asm
    rlncr   _int_iob_dat, f, c
#endasm
    }
    else if(16>led_scan_count)
    {
        IOC = int_ioc_dat;
        IOB = 0xFF;
        IOD = 0xFF;
#asm
    rlncr   _int_ioc_dat, f, c
#endasm
    }
    else
    {
        IOD = int_iod_dat;
        IOB = 0xFF;
        IOC = 0xFF;
#asm
    rlncr   _int_iod_dat, f, c
#endasm
    }

#asm
    bankbsr 0x0E

    ldfsr   2, _pwm_duty_array
    movr    _led_index_value, w, c
    addar   0xD9, f, c
    movrr   POSTINC2, _PWM100DL
    movrr   POSTINC2, _PWM101DL
    movrr   POSTINC2, _PWM102DL
    movrr   POSTINC2, _PWM103DL
    movrr   POSTINC2, _PWM104DL
    movrr   POSTINC2, _PWM105DL

    movrr   POSTINC2, _PWM106DL
    movrr   POSTINC2, _PWM107DL
    movrr   POSTINC2, _PWM108DL
    movrr   POSTINC2, _PWM109DL
    movrr   POSTINC2, _PWM110DL
    movrr   POSTINC2, _PWM111DL
    movrr   POSTINC2, _PWM112DL
    movrr   POSTINC2, _PWM113DL

    movrr   POSTINC2, _PWM114DL
    movrr   POSTINC2, _PWM115DL
    movrr   POSTINC2, _PWM116DL
    movrr   POSTINC2, _PWM117DL
    movrr   POSTINC2, _PWM118DL
    movrr   POSTINC2, _PWM119DL
    movrr   POSTINC2, _PWM120DL
#endasm

    if(0 == led_index_value)
    {
        // PWM120DL = wheel_led_array[0];
        // PWM106DL = wheel_led_array[1];
        // PWM102DL = wheel_led_array[2];
        // PWM101DL = wheel_led_array[3];
    }

    int_temp0 = 0;
    if(!IOE5)
        bint_temp7 = 1;
    if(!IOE4)
        bint_temp6 = 1;
    if(!IOE3)
        bint_temp5 = 1;
    if(!IOE0)
        bint_temp4 = 1;
    if(!IOA1)
        bint_temp3 = 1;
    if(!IOA0)
        bint_temp2 = 1;

    if(3 == led_scan_count)
    {
        if(matrix_status[20]&0x08)
            bint_temp2 = 1;
    }
    else if(4 == led_scan_count)
    {
        if(matrix_status[20]&0x20)
            bint_temp2 = 1;
    }
    else if(5 == led_scan_count)
    {
        if(matrix_status[20]&0x40)
            bint_temp2 = 1;
    }
    
    if(int_temp0 == matrix_status_bak[led_scan_count])
        matrix_status[led_scan_count] = int_temp0;
    else
        matrix_status_bak[led_scan_count] = int_temp0;
    IOB = 0x00;
    IOC = 0x00;
    IOD = 0x00;

    // if((0==led_index_value)&&bkey_lock_status)
	//     PWM119DL = 0xFF;
    // else 
    
    if(((iMATRIX_COL_NUM*2)==led_index_value)&&bdir_wasd_status)
	    PWM102DL = 0xFF;

    // if((0==led_index_value)&&bwin_lock_status)
	//     PWM101DL = 0xFF;

    // if((0==led_index_value)&&bfn_fn_lock_status)
	//     PWM105DL = 0xFF;

    PWM114CR = 0xC0;
    PWM115CR = 0xC0;
    PWM116CR = 0xC0;
    PWM117CR = 0xC0;
    PWM118CR = 0xC0;
    PWM119CR = 0xC0;
    PWM120CR = 0xC0;
    PWM100CR = 0xC0;
    PWM101CR = 0xC0;
    PWM102CR = 0xC0;
    PWM103CR = 0xC0;
    PWM104CR = 0xC0;
    PWM105CR = 0xC0;
    PWM106CR = 0xC0;
    PWM107CR = 0xC0;
    PWM108CR = 0xC0;
    PWM109CR = 0xC0;
    PWM110CR = 0xC0;
    PWM111CR = 0xC0;
    PWM112CR = 0xC0;
    PWM113CR = 0xC0;

    if(++SwBusTimer>=50)    //判定间隔时间
    {
        SwBusTimer = 0;

        if(IOFICR&0X03)        //一定时间后F0、F1电平未翻转认定总线进入挂起状态
        {
            if(USBEnumState==USBE_Configured)
            {
                if(!busb_suspend_en_bak)
                {
                    if((IOF0==1)&&(IOF1==0)) //全速模式挂起时为J状态
                    {
                        busb_suspend_en_bak = 1;
                        busb_suspend_en = 1;
                    }
                }
            }
        }
        else
        {
            IOFICR |= 0X03;        //F0、F1中断关闭后一定时间后再开启中断检测电平
            IOFCHIF = 0;
        }
    }

    IOA = int_ioa_dat;
#asm
    rlncr   _int_ioa_dat, f, c
#endasm
    led_index_value += iMATRIX_COL_NUM;
    if(iMATRIX_COL_NUM*6 <= led_index_value)
    {
        int_ioa_dat = 0xFB;
        led_index_value = 0;
    }
}
