/*******************************************************************************
* Copyright (c) 2022, SHENZHEN BEIHAI Co.,LTD.
* All rights reserved.
*
* 文件名称: Flash_process.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "..\defines.h"

extern unsigned char    const   matrixkey_win_tbl[];

//-----------------------------------------------------------------------------;
// 常量定义区
//
unsigned char                   device_para_tbl[4];
//-----------------------------------------------------------------------------;
// 变量定义区
//
unsigned char                   cfg_base;

//-----------------------------------------------------------------------------;
// 内部宏定义区
//

void led_default_load(void)
{
    s_mode = iPARA_TYPE;
    s_led_mode =  iMODE_LED_LG_L_R|iLED_ENABLE;
    s_led_para = iLED_LEV_4|(iSPEED_LEV_3<<4);
    s_cfg_para = iWIN_MODE|iMODE_WHEEL_HCLG;
}

/*******************************************************************************
* 函数名称: checksum_check()
* 功能描述:
* 输入参数:无
* 输出参数:无
* 说    明:
*******************************************************************************/
unsigned char checksum_flash(unsigned char lenght, unsigned char const *ptr)
{
    unsigned char i, check;

    check = 0x5A;
    for(i=0; i<lenght; i++)
    {
        check ^= ptr[i];
    }

    return check;
}

void memcpy_const(unsigned char  *ptr_d, unsigned char const *ptr_s, unsigned char lenght)
{
    for(unsigned char i=0; i<lenght; i++)
    {
        *ptr_d = *ptr_s;
        ptr_d++;
        ptr_s++;
    }
}

void memcpy(unsigned char  *ptr_d, unsigned char *ptr_s, unsigned char lenght)
{
    for(unsigned char i=0; i<lenght; i++)
    {
        *ptr_d = *ptr_s;
        ptr_d++;
        ptr_s++;
    }
}

void memset(unsigned char  *ptr_d, unsigned char const dat, unsigned char lenght)
{
    for(unsigned char i=0; i<lenght; i++)
    {
        *ptr_d = dat;
        ptr_d++;
    }
}

/*******************************************************************************
* 函数名称: cfg_load
* 功能描述:
* 输入参数: 无
* 输出参数:
* 说    明:
*******************************************************************************/
void cfg_load(void)
{
    unsigned char i,j,k;
//----------------------------------------------------------------------------
// KEY MODE0  KEY0~KEY63
//
    bwrite_flash = 0;
    j = 0xF0;
    k = 0;
    for(i=0x00; i<0x80;)
    {
        gtemp[k] = checksum_flash(16, flash_key_win_tbl + i);
        if(flash_key_win_tbl[j++] != gtemp[k])
        {
            bwrite_flash = 1;
            memcpy_const(flash_dat+i, matrixkey_win_tbl+i, 16);
        }
        else
        {
            memcpy_const(flash_dat+i, flash_key_win_tbl+i, 16);
        }
        k++;
        i += 16;
    }

    if(bwrite_flash)
    {
        flash_program(0x00, 128);
        memcpy(flash_dat, gtemp, 8);
        flash_program(0xF0, 8);
    }
//----------------------------------------------------------------------------
// KEY MODE0  KEY64~KEY119
//
    bwrite_flash = 0;
    j = 0xF8;
    k = 0;
    for(i=0x80; i<0xF0;)
    {
        gtemp[k] = checksum_flash(16, flash_key_win_tbl + i);
        if(flash_key_win_tbl[j++] != gtemp[k])
        {
            bwrite_flash = 1;
            memcpy_const(flash_dat+(i&0x7F), matrixkey_win_tbl+i, 16);
        }
        else
        {
            memcpy_const(flash_dat+(i&0x7F), flash_key_win_tbl+i, 16);
        }
        k++;
        i += 16;
    }

    if(bwrite_flash)
    {
        flash_program(0x80, 112);
        memcpy(flash_dat, gtemp, 7);
        flash_dat[7] = 0xA5;
        flash_program(0xF8, 8);
    }
//----------------------------------------------------------------------------
// LED CFG
//
    memcpy_const(led_def_dat_tbl, led_def_tbl, 16*5);

//----------------------------------------------------------------------------
// CFG INFO
//
    cfg_base = 0x7C;
    while(1)
    {
        device_para_tbl[0] = flash_bank_15[cfg_base+0];
        device_para_tbl[1] = flash_bank_15[cfg_base+1];
        device_para_tbl[2] = flash_bank_15[cfg_base+2];
        device_para_tbl[3] = flash_bank_15[cfg_base+3];

        if(iPARA_TYPE == (s_mode&iPARA_TYPE_MASK))
            break;

        if(0 == cfg_base)
        {
            cfg_base = 0xFF;
            break;
        }

        cfg_base &= 0xFC;
        cfg_base -= 0x04;
    }

    sys_ctrl_reg &= 0xF0;
    sys_ctrl_reg |= (s_mode&0x0F);

    lfsr_value = 0x55AA;
    
    load_led_para();
}

/*******************************************************************************
* 函数名称: e2_config_load
* 功能描述:
* 输入参数: 无
* 输出参数:
* 说    明:
*******************************************************************************/
void load_led_para(void)
{
    bkey_lock_status = 0;

    if(iPARA_TYPE != (s_mode&iPARA_TYPE_MASK))
    {
        led_default_load();
    }
    led_def_index = (s_mode&iLED_DEF_INDEX);

    bled_mode_def = 0;
    if(s_led_mode&iLED_DEF)
        bled_mode_def = 1;

    bled_run_dir = 0;
    if(s_led_mode&iLED_DIR)
        bled_run_dir = 1;

    //bled_bright_en = 0;
    //if(s_led_mode&iLED_ENABLE)
        bled_bright_en = 1;
    led_cur_mode = (s_led_mode&iLED_MODE_MASK);

    led_light_lev = (s_led_para&iLEV_MASK);
    led_speed_lev = ((s_led_para>>4)&iLEV_MASK);

    //bwin_lock_status = 0;
    //if(s_cfg_para&iWIN_LOCK)
        //bwin_lock_status = 1;

    bfn_fn_lock_status = 0;
    if(s_cfg_para&iFN_LOCK)
        bfn_fn_lock_status = 1;    

    //bwin_mac_sataus = 0;
    //if(s_cfg_para&iWIN_MODE)
        //bwin_mac_sataus = 1;

    bdir_wasd_status = 0;
    if(s_cfg_para&iDIR_LOCK)
        bdir_wasd_status = 1;
        
    wheel_led_cur_mode = (s_cfg_para&iWHEEL_LED_MODE);
}

/*******************************************************************************
* 函数名称: e2_config_load
* 功能描述:
* 输入参数: 无
* 输出参数:
* 说    明:
*******************************************************************************/
void e2_config_load(void)
{
    cfg_load();
    bwin_lock_status = 0;
    bled_bright_en = 1;

    //bled_bright_en = 1;

    //led_light_lev = iLED_LEV_4;
    //led_speed_lev = iSPEED_LEV_5;
    //led_rgb_index = 6;
    //sys_ctrl_reg = iDEVICE_TYPE_USB;
    //sys_ctrl_reg = iDEVICE_TYPE_BT0;
}

/*******************************************************************************
* 函数名称: cfg_mode_save
* 功能描述:
* 输入参数: 无
* 输出参数:
* 说    明: 模式切换和开关背光保存在FLASH中
*******************************************************************************/
void cfg_mode_save(void)
{
    if(0xFF == cfg_base)
        cfg_base = 0;
    else
    {
        cfg_base += 4;
        if(0x7C<cfg_base)
            cfg_base = 0;
    }

    cfg_base &= 0x7C;
    s_mode = 0xA0;
    s_mode |= (led_def_index&0x0F);
    
    s_led_mode = (led_cur_mode&0x1F);
    if(bled_bright_en)
        s_led_mode |= iLED_ENABLE;
    if(bled_run_dir)
        s_led_mode |= iLED_DIR;
    if(bled_mode_def)
        s_led_mode |= iLED_DEF;

    s_led_para = (led_light_lev&0x0F);
    s_led_para |= (led_speed_lev<<4);

    s_cfg_para = 0;
    //if(bwin_mac_sataus)
        //s_cfg_para |= iWIN_MODE;

    if(bfn_fn_lock_status)
        s_cfg_para |= iFN_LOCK;

    if(bwin_lock_status)
        s_cfg_para |= iWIN_LOCK;
    if(bdir_wasd_status)
        s_cfg_para |= iDIR_LOCK;
        
    s_cfg_para |= (wheel_led_cur_mode&iWHEEL_LED_MODE);
    flash_save_info(iCFG_ADDR+cfg_base);
    cfg_load();
}
/*******************************************************************************
* 函数名称: cfg_mode_save
* 功能描述:
* 输入参数: 无
* 输出参数:
* 说    明: 模式切换和开关背光保存在FLASH中
*******************************************************************************/
void led_def_save(void)
{
    memcpy(flash_dat, led_def_dat_tbl, 16*5);
    flash_program(iLED_ADDR, 16*5);
}