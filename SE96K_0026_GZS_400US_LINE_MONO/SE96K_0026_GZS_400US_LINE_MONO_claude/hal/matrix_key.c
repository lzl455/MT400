/*******************************************************************************
* Copyright (c) 2012, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: matrix_key.c
* 文件描述: 矩阵处理程序
*
*******************************************************************************/
#include "..\defines.h"

//----------------------------------------------------------------------------;
//常量定义
//
extern void key_decode(void);

//----------------------------------------------------------------------------;
//变量定义
//
USBD_U16                        ukey_ctrl;
USBD_U16                        ukey_ctrl_ex;

USBD_U8                         ukey_temp_flag;
USBD_U8                         ukey_temp_flag_1;
//{
    #define key_temp_flag_1     ukey_temp_flag_1.u8

    #define bkey_temp15         ukey_temp_flag_1.BIT.b7
    #define bkey_temp14         ukey_temp_flag_1.BIT.b6
    #define bkey_temp13         ukey_temp_flag_1.BIT.b5
    #define bkey_temp12         ukey_temp_flag_1.BIT.b4
    #define bkey_temp11         ukey_temp_flag_1.BIT.b3
    #define bkey_temp10         ukey_temp_flag_1.BIT.b2
//}
USBD_U8                         ukey_temp_delay;

//unsigned char                   std_key_count;  // 按下按键的个数
unsigned char                   matrix_status[iMATRIX_COL_NUM+2];
unsigned char                   key_fn_status[iMATRIX_NUM_MAX];

unsigned char                   mouse_data_key;
unsigned int                    mouse_data_x;
unsigned int                    mouse_data_y;
unsigned char                   mouse_data_z;

unsigned char                   std_key[22];
unsigned char                   multi_key[2];

unsigned char                   gKeyScan_bak[iMATRIX_COL_NUM+2];
unsigned char                   gKey_delay[21];

unsigned int                    press_default_led_time_count;

unsigned char                   led_index;
unsigned char                   col_index;

/******************************************************************************
* 函数名称: void key_process(void)
* 功能描述:
* 输入参数:
* 输出参数:
* 说    明:
******************************************************************************/
void key_process(void)
{
    unsigned char i;

    if(bkey_lock_status||bled_def_rec)
	{
	    memset(tmp_std_key, 0x00, 22);
		multi_data_tmp_l = 0;
		multi_data_tmp_h = 0;
	}

    if(!bwin_mac_sataus)
    {                                           // mac系统，按键交换
        temp_bit = modifier_key_tmp;
        modifier_key_tmp &= 0x33;
        if(btemp_bit7)
            modifier_key_tmp |= 0x40;
        if(btemp_bit6)
            modifier_key_tmp |= 0x80;
        if(btemp_bit2)
            modifier_key_tmp |= 0x08;
        if(btemp_bit3)
            modifier_key_tmp |= 0x04;
    }


    if(MY_SIRI_TIME)
    {
        modifier_key_tmp |= (iLEFT_GUI&0x0F); 
        key_data_tmp[1] = iSTD_SPACE;
    }

    for(i=0; i<6; i++)
    {
        if(key_data_tmp[i] != std_key[i])
        {
			memcpy(std_key, tmp_std_key, 6);
            std_key[6] = 0;

            bstd_data_send = 1;
            return;
        }
    }

    for(i=7; i<22; i++)
    {
        if(tmp_std_key[i] != std_key[i])
        {
		    memcpy(std_key+7, tmp_std_key+7, 15);

            bstd_exdata_send = 1;
            return;
        }
    }

    if(multi_data_tmp_l != multi_key[0])
    {
	    if(!bmmk_data_send)
        {
		    multi_key[0] = multi_data_tmp_l;
            multi_key[1] = multi_data_tmp_h;
            bmmk_data_send = 1;
	    }
    }
}

unsigned char const matrix_index_tbl[] =
{
    0,  1,  2,  3, 4, 5,
   6, 7,  8, 9, 10, 11,
   12, 13,   14,  15,  16,  17,
    18,  19,   20, 21, 21, 21,
};

/******************************************************************************
* 函数名称: matrixkey_value
* 功能描述: 矩阵按键扫描
* 输入参数:
* 输出参数:
* 说    明: 为提高时间效率,赋值等操作不采用循环模式
******************************************************************************/
void matrixkey_value(void)
{
    unsigned char i, j;
    unsigned char x, y;

    special_key = 0;
    key_ctrl &= 0xFFF0;

    modifier_key_tmp = 0;
    multi_data_tmp_l = 0;
    multi_data_tmp_h = 0;

    bkey_press_status = 0;

    led_index = 0;
    for(col_index=0; col_index<iMATRIX_COL_NUM; col_index++)
    {
GIEH = 0;
        j = matrix_index_tbl[col_index];
        key_temp_flag_1 = (gKeyScan_bak[j] ^ matrix_status[j]);
        gKeyScan_bak[j] = matrix_status[j];
GIEH = 1;
        key_temp_flag = gKeyScan_bak[j];
// 0
        for(i=0; i<6; i++)
        {
            if(bkey_temp0)
			{
                define_key_flag_n |= bdefine_key_press;
                bkey_press_status = 1;
			}
		    else
		    {
		        define_key_flag_n &= ~bdefine_key_press;
		    	key_fn_status[led_index] = iNULL_MATRIX;
            }
            if(0 == (define_key_flag_n&bkey_decode))
            {
                if(bkey_temp10)
                {                                   // 按键有变化
                    if(bkey_temp0)
                    {                               // 按下到松开,延时发送状态
                        define_key_flag_n = (bdefine_key_press|bkey_decode);
                        if(define_key_ctrl & bcom_key_break)
                        {                                           // 按键可打断
                            define_key_ctrl &= ~bcom_key_break;
                            bkey_status_change = 1;
                        }

                        if(bled_mode_single)
                        {
                            pwm_duty_array[matrix_single_tab[led_index]] = iPWM_MAX;
                        }
                    }
                    goto define_key_process;
                }
                else
                {
		    	    if(led_index == com_key_index)
		    		    com_key_index = 0xFF;
                }
            }
            else
            {
                if(bkey_temp10)
                {                                   // 有变化
                    if(bkey_temp0)
                    {
                        if(define_key_ctrl & bcom_key_break)
                        {                                           // 按键可打断
                            define_key_ctrl &= ~bcom_key_break;
                            bkey_status_change = 1;
                        }
                        if(bled_mode_single)
                        {
                            pwm_duty_array[matrix_to_led_tab[led_index]] = iPWM_MAX;
                        }
                    }
                }
define_key_process:
                key_decode();
                if(bled_def_rec)
                {
                    if((5<=led_def_index) && bkey_temp10 && !bkey_temp0)
                    {
					    if(!brec_press_status)
						{
							j = matrix_to_led_tab[led_index];
							x = (16*(led_def_index-5)+(j>>3));
							y = (0x01<<(j&0x07));
							if(0 ==(led_def_dat_tbl[x]&y))
							{
								led_def_dat_tbl[x] |= y;
                            }
                            else
                            {
                                led_def_dat_tbl[x] &= ~y;
                            }
						}
                    }
                }
                if(bkey_decode_valid)
                {
                    if((define_key_flag&bkey_decode_end)
			    	    && (0==(define_key_flag&bdefine_key_press)))
                    {
                        define_key_flag = 0;
                    }
                    define_key_flag_n = define_key_flag;
                    if(define_key_flag&bdefine_key_com)
                    {
                        decode_data_l_n = decode_data_l;
                        decode_data_h_n = decode_data_h;
                    }
                }
                if(!bkey_temp0)
			        key_fn_status[led_index] = iNULL_MATRIX;
            }
            
            key_temp_flag>>=1;
			key_temp_flag_1>>=1;
            led_index++;     
        }
    }

    if(bkey_break_or_realse)
    {
        bkey_break_or_realse = 0;

	    memset(key_data_tmp, 0x00, 22);
    }
	else
	{
	    if(!bkey_press_status && (0 == (define_key_ctrl&bcom_decode_ing)))
		{
	        memset(key_data_tmp, 0x00, 22);
		}
	}

// 按键去抖处理_END
    special_key_bak &= special_key;
    if(bfn_press != bfn_key_status)
    {
        bfn_key_status = bfn_press;
		if(!bfn_press&&bfn_save_flash)
		{
		    bfn_save_flash = 0;
            bsave_flash = 1;
		}
    }

	if((0 == (matrix_status[iKEY_FN_C]&iKEY_FN_R))
	    &&(0 == (matrix_status[iKEY_HOME_C]&iKEY_HOME_R)))
	    brec_press_status = 0;
}

/******************************************************************************
* 函数名称: matrixkey_scan
* 功能描述: 矩阵按键扫描
* 输入参数:
* 输出参数:
* 说    明: 为提高时间效率,赋值等操作不采用循环模式
******************************************************************************/
void matrixkey_scan(void)
{
    unsigned char i;

    ///  bwin_mac_sataus = LED_WIN_PIN;


    if(matrix_status[20]&0x08)
    {
        matrix_status[3] |= 0x04;
    }
    else
    {
        matrix_status[3] &= ~0x04;
    }

    if(matrix_status[20]&0x20)
    {
        matrix_status[4] |= 0x04;
    }
    else
    {
        matrix_status[4] &= ~0x04;
    }


    if(matrix_status[20]&0x40)
    {
        matrix_status[5] |= 0x04;
    }
    else
    {
        matrix_status[5] &= ~0x04;
    }
    

    matrixkey_value();
    key_process();
	if(iKEY_FN_R == matrix_status[iKEY_FN_C])
	{
	    if(iCLEAR_INFO_R == matrix_status[iCLEAR_INFO_C])
	    {
	        if(!bdefault_led_press)
	        {
	            bdefault_led_press = 1;
	            press_default_led_time_count = 0;
	        }
	        else
	        {
	            if(600 == press_default_led_time_count)
	            {
                        clr_led_data();
                        for(i=0; i<4; i++)
                        {
                            set_led();
                            delayms(250);
                            clr_led();
                            delayms(250);
                        }
                        flash_clear(0);
                        flash_clear(15);
	                    memset(led_def_dat_tbl, 0x00, 128);
						led_def_save();

                        cfg_load();
                        bcfg_reset = 1;
                        bdevice_status_change = 1;
                        led_cur_mode = iMODE_LED_DEF;
                        led_speed_lev = iSPEED_LEV_3;
                        led_light_lev = iLED_LEV_MAX;
                        led_pre_mode = iMODE_LED_INVALID;

                        press_default_led_time_count++;
	            }
	            else if(600 > press_default_led_time_count)
	            {
	                press_default_led_time_count++;
	            }
	        }
	    }
	}
	else
	{
        bdefault_led_press = 0;
	}
}
