/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: UserDefined_Key.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "..\defines.h"
#include "matrix_key_tbl_win.h"
// #include "matrix_key_tbl_mac.h"
#include "matrix_key_tbl_win_fn.h"
// #include "matrix_key_tbl_mac_fn.h"
#include "matrix_key_tbl_win_fn_lock.h"
#include "matrix_key_tbl_win_lock.h"

//-----------------------------------------------------------------------------;
//常量定义区
//

//----------------------------------------------------------------------------
//变量定义区
//
USBD_U16                        uspecial_key;
USBD_U16                        uspecial_key_bak;

USBD_U8                         udefine_key_status;

USBD_U8                         udecode_data_l;
USBD_U8                         udecode_data_h;

unsigned char                   define_key_ctrl;

unsigned char                   define_key_fifo[120];
unsigned char                   define_key_flag;

unsigned char                   decode_data_l_n;
unsigned char                   decode_data_h_n;

unsigned int                    com_key_length;
unsigned int                    com_key_addr_back;
unsigned int                    com_key_addr;
unsigned char                   cmd_hong_count;
unsigned char                   com_key_index;

unsigned char                   key_delay_count_l; 
unsigned char                   key_delay_count_h;

unsigned char                   multi_data_tmp_l;
unsigned char                   multi_data_tmp_h;
unsigned char                   tmp_std_key[22];

unsigned char                   MY_SIRI_TIME;
unsigned char                   MY_FN_WIN_LOCK_flag;    //FN锁下，不锁多媒体


//-----------------------------------------------------------------------------
//表格定义区
//

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/******************************************************************************
* 函数名称: key_decode
* 功能描述:
* 输入参数:
* 输出参数:
* 说    明:
******************************************************************************/
void key_decode(void)
{
    unsigned char i, j, key_index;
    unsigned int length;
	unsigned char const *pRom;
    unsigned char loop_count = 0;

    bkey_decode_valid = 1;

    MY_FN_WIN_LOCK_flag=1;

    define_key_flag = define_key_flag_n;
    define_key_ctrl &= ~bdefine_key_send;

    key_index = (led_index<<1);
    if(bfn_key_status)
    {
		if(iKEY_INDEX_FN != led_index)
	    {
		    if(iNORMAL_MATRIX == key_fn_status[led_index])
			    goto normal_matrix_tbl;
            key_fn_status[led_index] = iFN_MATRIX;
	    }
fn_matrix_tbl:

        // LED_SCROLL_PIN = 1;

        // if(bwin_mac_sataus)
        // {
            if (bfn_fn_lock_status)   // bfn_fn_lock_status
            {
                decode_data_l = matrixkey_win_fn_lock_tbl[key_index++];
                decode_data_h = matrixkey_win_fn_lock_tbl[key_index];
            }
            else
            {
                decode_data_l = matrixkey_win_fn_tbl[key_index++];
                decode_data_h = matrixkey_win_fn_tbl[key_index];
            }
                
        // }
        // else
        // {
		//     decode_data_l = matrixkey_mac_fn_tbl[key_index++];
        //     decode_data_h = matrixkey_mac_fn_tbl[key_index];
        // }
    }
    else
    {
		if(iKEY_INDEX_FN != led_index)
	    {
            if(iFN_MATRIX == key_fn_status[led_index])
				goto fn_matrix_tbl;
            key_fn_status[led_index] = iNORMAL_MATRIX;
		}
normal_matrix_tbl:
        if(bdir_wasd_status)
        {
            if(iKEY_INDEX_UP == led_index)
                key_index = (iKEY_INDEX_W*2);
            else if(iKEY_INDEX_DOWN == led_index)
                key_index = (iKEY_INDEX_S*2);
            else if(iKEY_INDEX_LEFT == led_index)
                key_index = (iKEY_INDEX_A*2);
            else if(iKEY_INDEX_RIGHT == led_index)
                key_index = (iKEY_INDEX_D*2);
            else if(iKEY_INDEX_W == led_index)
                key_index = (iKEY_INDEX_UP*2);
            else if(iKEY_INDEX_S == led_index)
                key_index = (iKEY_INDEX_DOWN*2);
            else if(iKEY_INDEX_A == led_index)
                key_index = (iKEY_INDEX_LEFT*2);
            else if(iKEY_INDEX_D == led_index)
                key_index = (iKEY_INDEX_RIGHT*2);
        }

        

        // if(bwin_mac_sataus)
        // {
            if (bfn_fn_lock_status)  
            {
                // LED_SCROLL_PIN = 1;
                decode_data_l = matrix_key_tbl_win_lock[key_index++];
                decode_data_h = matrix_key_tbl_win_lock[key_index];
            }
            else
            {
                // LED_SCROLL_PIN = 0;
                // flash 0xF0~0xFF 是校验和区, C20 不能从flash取
                pRom = (key_index < 0xF0) ? flash_key_win_tbl : matrixkey_win_tbl;
                decode_data_l = pRom[key_index++];
                decode_data_h = pRom[key_index];
            }
                
        // }
        // else
        // {
        //     decode_data_l = matrixkey_mac_tbl[key_index++];
        //     decode_data_h = matrixkey_mac_tbl[key_index];
        // }
    }

    if(iKEY_INDEX_FN == led_index)
    {

        decode_data_h = iKEY_TYPE_SPECIAL;
        decode_data_l = iMODE_KEY_FN;
    }
    else if((0==decode_data_l)&&(0==decode_data_h))
    {
        key_index &= 0xFE;                      // 上面已 key_index++, 回到偶地址
        pRom = (key_index < 0xF0) ? flash_key_win_tbl : matrixkey_win_tbl;
        decode_data_l = pRom[key_index++];
        decode_data_h = pRom[key_index];
    }

    if(iDEF_COM == (decode_data_h&iDEF_COM_MASK))
    {
        if((0 == (define_key_ctrl&bcom_decode_ing))
		    ||(0xFF == com_key_index))
        {
            define_key_ctrl |= bcom_decode_ing;
            com_key_index = led_index;
        }
        else
        {
            if(led_index !=com_key_index)
            {
                bkey_decode_valid = 0;
                return;
            }
            else
            {
                if(0==(define_key_flag & bkey_decode_end))
			    {
                    decode_data_l = decode_data_l_n;
                    decode_data_h = decode_data_h_n;
				}
            }
        }
    }
    //decode_dat_l = decode_data_l;
    //decode_dat_h = decode_data_h;

define_key_decode_begin:
    if(iKEY_TYPE_INVALID == decode_data_h)
    {
        if(define_key_flag&bdefine_key_com)
        {
            bkey_break_or_realse = 1;
            define_key_ctrl &= ~bcom_decode_ing;
        }
        define_key_flag &= ~bkey_decode;
        return;
    }

    if(iKEY_TYPE_MY == decode_data_h)
    {
        if(iKEY_TYPE_MY_SIRI == decode_data_l)
        {
            MY_SIRI_TIME =200;
        }
    }


        if(bwin_mac_sataus)
        {                      
            if((iKEY_TYPE_STD|iKEY_PRESS|iLEFT_GUI|iLEFT_SHIFT) == decode_data_h)
            {
                if(iSTD_F23 == decode_data_l)
                {
                    MY_FN_WIN_LOCK_flag = 0;
                }
            }         
        }

    if(iKEY_TYPE_STD == (decode_data_h & iKEY_STD_MASK))
    {                                           // 标准按键
		if(define_key_flag & bkey_decode_end)
        {
            if(0==(define_key_flag&bdefine_key_press))
            {
                if(define_key_flag&bdefine_key_com)
                {
				
				}
				else
				{
					bkey_press = 0;
					goto std_key_decode_1;
				}
			}
            else
                goto std_key_decode_0;
        }
        else
        {
std_key_decode_0:
            if(bkey_code_b13)
                bkey_press = 1;
            else
                bkey_press = 0;

std_key_decode_1:
            if(bkey_press)
            {
                if(bkey_code_b12)
                    modifier_key_tmp |= (decode_data_h&0x0F);
                else
                    modifier_key_tmp |= ((decode_data_h&0x0F)<<4);
            }

            if(bwin_mac_sataus && bwin_lock_status && MY_FN_WIN_LOCK_flag)
            {
                modifier_key_tmp&= 0x77;
                if(iSTD_APP == decode_data_l)
                    bkey_press = 0;
            }
    
            if(0 != decode_data_l)
            {
                i = ((decode_data_l>>3)+7);
                j = (0x01<<(decode_data_l&0x07));
                if(bkey_press)
                {                                   // 按下
//PB2 = 1;
                    if(key_data_tmp[i] & j)
                        goto define_decode_end;
                    if(decode_data_l == key_data_tmp[1])
                        goto define_decode_end;
                    if(decode_data_l == key_data_tmp[2])
                        goto define_decode_end;
                    if(decode_data_l == key_data_tmp[3])
                        goto define_decode_end;
                    if(decode_data_l == key_data_tmp[4])
                        goto define_decode_end;
                    if(decode_data_l == key_data_tmp[5])
                        goto define_decode_end;

                    if(0 == key_data_tmp[1])
                        key_data_tmp[1] = decode_data_l;
                    else if(0 == key_data_tmp[2])
                        key_data_tmp[2] = decode_data_l;
                    else if(0 == key_data_tmp[3])
                        key_data_tmp[3] = decode_data_l;
                    else if(0 == key_data_tmp[4])
                        key_data_tmp[4] = decode_data_l;
                    else if(0 == key_data_tmp[5])
                        key_data_tmp[5] = decode_data_l;
                    else
                        key_data_tmp[i] |= j;
                }
                else
                {                                   // 松开
//PB2 = 0;
                    if(decode_data_l == key_data_tmp[1])
                        key_data_tmp[1] = 0;
                    if(decode_data_l == key_data_tmp[2])
                        key_data_tmp[2] = 0;
                    if(decode_data_l == key_data_tmp[3])
                        key_data_tmp[3] = 0;
                    if(decode_data_l == key_data_tmp[4])
                        key_data_tmp[4] = 0;
                    if(decode_data_l == key_data_tmp[5])
                        key_data_tmp[5] = 0;
                    else
                        key_data_tmp[i] &= ~j;
                }
            }
        }
        define_key_ctrl |= bdefine_key_send;
    }
    else if(iKEY_TYPE_MMK == (decode_data_h & iKEY_TYPE_MASK))
    {                                           // 多媒体按键
        if(define_key_flag & bkey_decode_end)
        {
            if(0==(define_key_flag&bdefine_key_press))
            {
                multi_data_tmp_l = 0;
                multi_data_tmp_h = 0;
            }
            else
            {
                multi_data_tmp_l = decode_data_l;
                multi_data_tmp_h = (decode_data_h & (~iKEY_MMK_MASK));
                return;
            }
        }
        else
        {
            multi_data_tmp_l = decode_data_l;
            multi_data_tmp_h = (decode_data_h & (~iKEY_MMK_MASK));
        }
        define_key_ctrl |= bdefine_key_send;
    }
    else if(iKEY_TYPE_EX == (decode_data_h & iKEY_TYPE_MASK))
    { // 0x4X
        if(!bkey_code_b11)
        { // 0x40~0x47
            switch(decode_data_h&0x0F)
            {
                case iKEY_TYPE_SYS&0x07:        // 0x40 系统按键

                    break;
                case iKEY_TYPE_MOUSE&0x07:      // 0x41 鼠标按键
                    if(define_key_flag & bkey_decode_end)
                    {
                        if(0==(define_key_flag&bdefine_key_press))
                        {
                            mouse_data_key &= (~(decode_data_l&0x7F));
                        }
                        else
                            return;
                    }
                    else
                    {
                        if(bkey_code_b7)
                            mouse_data_key |= (decode_data_l&0x7F);
                        else
                            mouse_data_key &= (~(decode_data_l&0x7F));
                    }

                    bmouse_data_send = 1;
                    define_key_flag |= bdefine_key_send;
                    break;
                case iKEY_TYPE_WHEEL&0x07:      // 0x42 鼠标滚轮
                    break;
                case iDELAY_1MS&0x07:           // 0x44 不处理松开
                case iDELAY_1MS_RELEASE&0x07:   // 0x45 处理松开
                case iDELAY_250MS&0x07:         // 0x46 不处理松开
                case iDELAY_250MS_RELEASE&0x07: // 0x47 处理松开
                    if(0==(define_key_flag&bdefine_key_com))
                    {
                        define_key_flag &= ~bkey_decode;
                        return;                 // 延时只会出现在组合按键中
                    }

                    if(define_key_flag&bdefine_delay_flag)
                    {
                        key_delay_count_l++;
                        if(0 == key_delay_count_l)
                        {
                            key_delay_count_h++;
                        }

                        i = key_delay_count_l;
                        if(decode_data_h&(1<<1))
                        {                       // 250ms延时
                            i = key_delay_count_h;
                        }

                        if(i >= ((decode_data_l+3)>>2))
                        {                       // 延时完毕
                            define_key_flag &= ~bdefine_delay_flag;
                        }
                        else
                        {
                            if((define_key_flag&bcom_key_realse_did) && (0==(define_key_flag&bdefine_key_press)))
                            {                   // 延时时间内按键可松开, 加载松开处理
                                bkey_break_or_realse = 1;

                                define_key_flag &= ~bdefine_delay_flag;
                                cmd_hong_count = 1;
                                define_key_flag &= ~bcom_key_realse_did;
                                com_key_addr = ((com_key_addr_back + com_key_length)-2);
                                goto define_key_get_data;
                            }
                            else if(bkey_status_change)
                            {
                                bkey_status_change = 0;
                                bkey_break_or_realse = 1;
                                cmd_hong_count = 1;
                                com_key_addr = ((com_key_addr_back + com_key_length)-2);
                                goto define_key_get_data;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    else
                    {
                        define_key_flag |= bdefine_delay_flag;
                        key_delay_count_l = 0;
                        key_delay_count_h = 0;
                        return;
                    }

                    break;
            }
        }
        else
        { // 0x48~0x4F
            switch(decode_data_h&0x07)
            {
// 0x48 特殊按键
                case iKEY_TYPE_SPECIAL&0x07: 
                    if(define_key_flag&bdefine_key_com)
                    {
                        define_key_flag &= ~bkey_decode;
                        define_key_ctrl &= ~bcom_decode_ing;
                        return;
                    }

                    if(0==(define_key_flag&bdefine_key_press))
                        return;

                    bkey_all_realse = 0;
                    /*if(iDEF_SYS_CTRL == (decode_data_l & iKEY_SPECIAL_MASK))
                    {

                    }
                    else*/ if(iLED_CTRL == (decode_data_l & iKEY_SPECIAL_MASK))
                    {
                        switch(decode_data_l&0x0F)
                        {
                            case iLED_BRIGHT_SUB&0x0F:
                                bkey_light_dn = 1;
                                if(!bkey_light_dn_bak&&bled_bright_en)
                                {
                                    bkey_light_dn_bak = 1;
                                    if(led_light_lev > iLED_LEV_MIN)
                                    {
                                        led_light_lev--;
                                        pwm2_init();

                                        bfn_save_flash = 1;
                                    }
                                    else
                                    {
                                        led_hint();
                                    }
                                }
                                break;
                            case iLED_BRIGHT_ADD&0x0F:
                                bkey_light_up = 1;
                                if(!bkey_light_up_bak&&bled_bright_en)
                                {
                                    bkey_light_up_bak = 1;
                                    if(led_light_lev < iLED_LEV_MAX)
                                    {
                                        led_light_lev++;
                                        pwm2_init();

                                        bfn_save_flash = 1;
                                    }
                                    else
                                    {
                                        led_light_lev = iLED_LEV_MAX;
                                        led_hint();
                                    }
                                }
                                break;

                            case iLED_MODE_CYC_ADD&0x0F:
                                bkey_mode_cyc = 1;
                                if(!bkey_mode_cyc_bak && bled_bright_en)
                                {
                                    bkey_mode_cyc_bak = 1;
                                    if(!bled_mode_def)
                                    {
                                        led_cur_mode++;
                                        if(iMODE_LED_MAX<=led_cur_mode)
                                            led_cur_mode = iMODE_LED_OFF;
                                    }
                                    else
                                    {
                                        bled_mode_def = 0;
                                    }
                                    bled_def_rec = 0;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_RST&0x0F:
                                bkey_mode_cyc = 1;
                                if(!bkey_mode_cyc_bak && bled_bright_en)
                                {
                                    bkey_mode_cyc_bak = 1;
                                    if(!bled_mode_def)
                                    {
                                        led_cur_mode = iMODE_LED_DEF;
                                        led_speed_lev = iSPEED_LEV_3;
                                        led_light_lev = iLED_LEV_MAX;
                                    }
                                    else
                                    {
                                        bled_mode_def = 0;
                                    }
                                    bled_def_rec = 0;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_01&0x0F:
                                if (led_cur_mode != iMODE_LED_17)
                                {
                                    led_cur_mode = iMODE_LED_17;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_02&0x0F:
                                if (led_cur_mode != iMODE_LED_SNAKE)
                                {
                                    led_cur_mode = iMODE_LED_SNAKE;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_03&0x0F:
                                if (led_cur_mode != iMODE_LED_LG_L_R)
                                {
                                    led_cur_mode = iMODE_LED_LG_L_R;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_04&0x0F:
                                if (led_cur_mode != iMODE_LED_ON)
                                {
                                    led_cur_mode = iMODE_LED_ON;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_05&0x0F:
                                if (led_cur_mode != iMODE_LED_BREATH)
                                {
                                    led_cur_mode = iMODE_LED_BREATH;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_06&0x0F:
                                if (led_cur_mode != iMODE_LED_CHLP)
                                {
                                    led_cur_mode = iMODE_LED_CHLP;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_07&0x0F:
                                if (led_cur_mode != iMODE_LED_BHQF)
                                {
                                    led_cur_mode = iMODE_LED_BHQF;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_08&0x0F:
                                if (led_cur_mode != iMODE_LED_STAR)
                                {
                                    led_cur_mode = iMODE_LED_STAR;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_09&0x0F:
                                if (led_cur_mode != iMODE_LED_ARROW)
                                {
                                    led_cur_mode = iMODE_LED_ARROW;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iLED_MODE_0&0x0F:
                                if (led_cur_mode != iMODE_LED_SINGLE)
                                {
                                    led_cur_mode = iMODE_LED_SINGLE;
                                    bfn_save_flash = 1;
                                }
                                break;
                                
                            case iLED_SPEED_SUB&0x0F:
                                bkey_speed_dn = 1;
                                if(!bkey_speed_dn_bak&&bled_bright_en)
                                {
                                    bkey_speed_dn_bak = 1;
                                    if(iSPEED_LEV_MAX > led_speed_lev)
                                    {
                                        led_speed_lev++;
                                        bfn_save_flash = 1;
                                    }
                                    else
                                    {
                                        led_hint();
                                    }
                                }
                                break;
                            case iLED_SPEED_ADD&0x0F:
                                bkey_speed_up = 1;
                                if(!bkey_speed_up_bak&&bled_bright_en)
                                {
                                    bkey_speed_up_bak = 1;
                                    if(led_speed_lev > iSPEED_LEV_MIN)
                                    {
                                        led_speed_lev--;
                                        bfn_save_flash = 1;
                                    }
                                    else
                                    {
                                        led_hint();
                                    }
                                }
                                break; 
                            // case iLED_DIR_L_R&0x0F:
                            //     if(bled_run_dir)
                            //     {
                            //         bled_run_dir = 0;

                            //         bfn_save_flash = 1;
                            //     }
                            //     break;
                            // case iLED_DIR_R_L&0x0F:
                            //     if(!bled_run_dir)
                            //     {
                            //         bled_run_dir = 1;
                            //         bfn_save_flash = 1;
                            //     }
                            //     break;
                        }
                    }
                    else if(iKEY_MODE_SWITCH == (decode_data_l & iKEY_SPECIAL_MASK))
                    {
					    if(iMODE_KEY_FN == decode_data_l)
						{
                            bfn_press = 1;
							return;
						}
						if(bled_def_rec)
							return;

                        switch(decode_data_l&0x0F)
                        {
/*
                            case iKEY_WIN&0x0F:
                                if(!bwin_mac_sataus)
                                {
                                    bwin_mac_sataus = 1;
                                    bsave_flash = 1;
									bwin_mac_hint = 1;
					            	hint_time_count = 0;
                                }
                                break;
                            case iKEY_MAC&0x0F:
                                if(bwin_mac_sataus)
                                {
                                    bwin_mac_sataus = 0;
                                    bfn_save_flash = 1;
									bwin_mac_hint = 1;
					            	hint_time_count = 0;
                                }
                                break;
*/
                            case iKEY_WIN_LOCK&0x0F:
                                bwin_lock = 1;
                                if(!bwin_lock_bak && bwin_mac_sataus)
                                {
                                    bwin_lock_bak = 1;
                                    bwin_lock_status = ~bwin_lock_status;
                                    bfn_save_flash = 1;
                                }
                                break;

                            case iKEY_FN_LOCK&0x0F:
                                bkey_fn_lock = 1;
                                if(!bkey_fn_lock_bak)
                                {
                                    bkey_fn_lock_bak = 1;
                                    bfn_fn_lock_status = ~bfn_fn_lock_status;
                                    bfn_save_flash = 1;
                                    // if (bfn_fn_lock_status)
                                    //     LED_SCROLL_PIN = 1;
                                    // else
                                    //     LED_SCROLL_PIN = 0;
                                }
                                break;

                            case iKEY_DIR_WASD&0x0F:
                                bkey_dir_wasd = 1;
                                if(!bkey_dir_wasd_bak)
                                {
                                    bkey_dir_wasd_bak = 1;
                                    bdir_wasd_status = ~bdir_wasd_status;
                                    bfn_save_flash = 1;
                                }
                                break;
                                
                            case iKEY_LOCK&0x0F:
                                bkey_lock = 1;
                                if(!bkey_lock_bak)
                                {
                                    bkey_lock_bak = 1;
                                    bkey_lock_status = ~bkey_lock_status;
                                }
                                break;
                        }
                    }
                    else if(iLED_DEF_CTRL == (decode_data_l & iKEY_SPECIAL_MASK))
                    {
                        if(iLED_DEF_REC > decode_data_l)
                        {
                            bled_mode_def = 1;
                            led_def_index = (decode_data_l&0x0F);
                            bfn_save_flash = 1;
                            bled_def_rec = 0;
                        }
                        else
                        {
                            if(bled_mode_def)
                            {
                                if(iLED_DEF_REC == (decode_data_l))
                                {
                                    bsave_led = 0;
									brec_press_status = 1;
                                    bled_def_rec = 1;
                                }
                                else if(iLED_DEF_SAVE == (decode_data_l))
                                {
                                    bsave_led = 1;
                                    bled_def_rec = 0;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    else if(iDEFINE_CMD_TRANSFER == (decode_data_h&iKEY_TRANSFER_MASK))
    {
		if(bled_def_rec)
			return;

        length = ((decode_data_l&0xFE) | ((decode_data_h&0x07)<<8));
		length += 2;

        i = (decode_data_h&iTRANSFER_MASK);
        if(iTRANSFER_KEY_STATUS == i)
        {                                   // 按键状态转移
            if(define_key_flag&bdefine_key_press)
            {
                if(decode_data_l&(1<<0))    // 负向偏移
                    com_key_addr -= length;
                else                        // 正向偏移
                    com_key_addr += length;
            }
        }
        else if(iTRANSFER_TIMES == i)
        {                                   // 次数转移                
            if(0 == cmd_hong_count)
            {
                if(decode_data_l&(1<<0))    // 负向偏移
                    com_key_addr -= length;
                else                        // 正向偏移
                    com_key_addr += length;
            }
            else if(1 != cmd_hong_count)
            {
                if(decode_data_l&(1<<0))    // 负向偏移
                    com_key_addr -= length;
                else                        // 正向偏移
                    com_key_addr += length;
                cmd_hong_count--;
            }
        }
        else
        {
            define_key_ctrl &= ~bdefine_key_send;
        }
    }
    else if(iDEF_COM == (decode_data_h&iDEF_COM_MASK))
    {
		if(bled_def_rec)
			return;
        if(0 != (define_key_flag&bkey_decode_end)) 
            return;

        com_key_addr = (((decode_data_h&0x3F)<<8) | (decode_data_l&0xFE));
        com_key_addr |= iKEY_CFG_BASE_ADDR;
        com_key_addr_back =  (com_key_addr+0x10);

        pRom = (unsigned char const *)com_key_addr;

        if(0x5A != *pRom)
            return;

        define_key_flag |= bdefine_key_com;
        pRom++;
        cmd_hong_count = *pRom++;

        i = *pRom++;
        j = *pRom++;
        com_key_length = ((i&0xFE)|(j<<8));

        define_key_ctrl &= ~bcom_key_break;
        if(i&(1<<0))                            // 按键操作可打断
            define_key_ctrl |= bcom_key_break;            

        define_key_flag &= ~bcom_key_realse_did;
        if(decode_data_l&(1<<0))                // 松开处理
            define_key_flag |= bcom_key_realse_did;

        com_key_addr += 0x10;
    }
define_decode_end:

    if(define_key_flag&bdefine_key_com)         // 组合按键
    {
        if(com_key_addr >= (com_key_length + com_key_addr_back))
        {
            define_key_flag |= bkey_decode_end;
            define_key_ctrl &= ~bcom_decode_ing;
            define_key_ctrl &= ~bcom_key_break;
            bkey_break_or_realse = 1;
        }
        else
        {
            if((define_key_flag&bcom_key_realse_did) && (0==(define_key_flag&bdefine_key_press)))
            {                                   // 松开处理, 加载松开处理
                define_key_flag &= ~bdefine_delay_flag;
                cmd_hong_count = 1;
                define_key_flag &= ~bcom_key_realse_did;
                com_key_addr = ((com_key_addr_back+com_key_length)-2);
                bkey_break_or_realse = 1;
            }

            if(bkey_status_change)
            {                                   // 状态变化
                com_key_addr = ((com_key_addr_back + com_key_length)-2);            
                bkey_status_change = 0;
                bkey_break_or_realse = 1;
                cmd_hong_count = 1;
            }
define_key_get_data:
            pRom = (unsigned char const *)com_key_addr;

            decode_data_l = *pRom++;
            decode_data_h = *pRom++;
            com_key_addr += 2;

            if(0==(define_key_ctrl&bdefine_key_send))
            {
                loop_count++;
                if(8 <= loop_count)
                {                               // 防止按键解码死循环
                    define_key_flag = 0;
                    define_key_flag |= bkey_decode_end;
                    define_key_ctrl &= ~bcom_decode_ing;
                    define_key_ctrl &= ~bcom_key_break;
                }
                else
                {
                    goto define_key_decode_begin;   //组合按键模式下，解码新的数据
                }
            }
        }
    }
    else
    {
        define_key_flag |= bkey_decode_end;
    }
}
