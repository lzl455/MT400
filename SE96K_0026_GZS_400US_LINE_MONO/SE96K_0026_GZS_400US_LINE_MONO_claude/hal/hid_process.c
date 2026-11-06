/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: HID_Process.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "..\defines.h"

//-----------------------------------------------------------------------------;
// 常量定义
//

//-----------------------------------------------------------------------------;
// 变量定义
//
USBD_U8                         uhid_ctrl_reg;

unsigned char                   in_report_data[32];
unsigned char                   out_report_data[32];
unsigned char                   flash_fifo[iPAGE_LENGHT];

unsigned int                    check_sum;

unsigned char                   bootloader_val[4] @ 0X0280;
//----------------------------------------------------------------------------—;
//表格定义区
//

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void clear_in_fifo(void)
{
	memset(in_report_data, 0x00, 32);
}

/******************************************************************************
* 函数名称: checksum_check
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void checksum_check(unsigned int length, unsigned char *ptr)
{
    unsigned int i;

    if(0 != (length&0x01))
    {
        bhid_cmd_err = 1;
        return;
    }

	check_sum = 0xFA21;
	for(i = 0; i < (length/2); i++)
	{
		check_sum += (ptr[i] | (ptr[i+1]<<8));
	}
}

/******************************************************************************
* 函数名称: flash_ctrl
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 说    明: 下载程序到flash采用缓存的机制，先下载到缓存，再下发命令下载到flash，
            可以有效提高下载速度
******************************************************************************/
void flash_ctrl(void)
{
    unsigned int i, length;
    unsigned char j, x;
    unsigned char err_id;

    err_id = iID_OK;
    switch(out_report_data[1]&iHID_CMD_KEY_CFG_MASK)
    {
        case iHID_CMD_W_FLASH: // 键盘配置信息写flash
            if((iPAGE_LENGHT < out_report_data[4]) || (0xA5 != out_report_data[5]))
            {                                   // 长度错误
                err_id = iID_LENGTH_ERR;
                bhid_cmd_err = 1;
            }
            else
            {
                checksum_check(out_report_data[4], flash_fifo);
                if((out_report_data[6] != (check_sum&0xFF))
				    ||(out_report_data[7] != ((check_sum>>8)&0xFF)))
                {                               // CS错误
                    err_id = iID_CS_ERR;
                    bhid_cmd_err = 1;
                }
            }

            i = ((out_report_data[3]<<8)|out_report_data[2]);
            if(iKEY_MAX_LENGHT < i)
            {                                   // 地址错误
                err_id = iID_ADDR_ERR;
                bhid_cmd_err = 1;
            }

            if(!bhid_cmd_err)
            {
                flash_program(i, out_report_data[4]);
                if(bhid_cmd_err)                // 写入错误
                    err_id = iID_W_FLASH_ERR;
            }

            clear_in_fifo();
            in_report_data[0] = iHID_CMD_HANDLE;
            in_report_data[1] = iHID_CMD_W_FLASH|iHID_CMD_SYS_CTRL;
            in_report_data[2] = ((i>>0)&0xFF);
            in_report_data[3] = ((i>>8)&0xFF);
            in_report_data[4] = out_report_data[4];
            in_report_data[5] = iACK;
            if(bhid_cmd_err)
                in_report_data[5] = iNAK;
            in_report_data[7] = err_id;

            bhid_data_send = 1;
            break;
        case iHID_CMD_W_FIFO:
            clear_in_fifo();

            in_report_data[0] = iHID_CMD_HANDLE;
            in_report_data[1] = iHID_CMD_W_FIFO|iHID_CMD_SYS_CTRL;
            in_report_data[2] = out_report_data[2];
            in_report_data[3] = out_report_data[3];
            if((28>=out_report_data[3]) && ((out_report_data[3]+out_report_data[2])<=iPAGE_LENGHT))
            {
                j = out_report_data[2];
                for(x=0; x<out_report_data[3]; x++)
                {
                    flash_fifo[j++] = out_report_data[x+4];
                }

                j = out_report_data[2];
                for(x=0; x<out_report_data[3]; x++)
                {
                    in_report_data[4+x] = flash_fifo[j++];
                    if(in_report_data[4+x] != out_report_data[4+x])
                    {
                        in_report_data[3] |= 0x80;
                    }
                }
            }
            else
            {
                in_report_data[3] |= 0x80;
            }
            bhid_data_send = 1;

            break;
        case iHID_CMD_R_FLASH:
            in_report_data[0] = iHID_CMD_HANDLE;
            in_report_data[1] = iHID_CMD_R_FLASH|iHID_CMD_SYS_CTRL;
            in_report_data[2] = out_report_data[2];
            in_report_data[3] = out_report_data[3];

            i = ((out_report_data[3]<<8) | out_report_data[2]);
            length = out_report_data[4];
            if(0==out_report_data[4])
                length = 256;

            if(iFLASH_MAX_LENGHT < (i+length))
            {
                bhid_cmd_err = 1;
            }
            else
            {
                if(length > iFLASH_R_MAX_SIZE)
                {
                    length = (length-iFLASH_R_MAX_SIZE);
                    j = iFLASH_R_MAX_SIZE;
                }
                else
                {
                    j = length;
                    length = 0;
                }

	            const unsigned char *pRom = (const unsigned char*)(i+iKEY_CFG_BASE_ADDR);
                for(x=0; x<j; x++)
                {
                    in_report_data[5+x] = *pRom++;
                }

                if(length != 0x00)
                {
                    i += j;
                    out_report_data[2] = (i&0xFF);
                    out_report_data[3] = ((i>>8)&0xFF);

                    out_report_data[4] = (length&0xFF);
                    bhid_data_process = 1;
                }
            }
            in_report_data[4] = j;
            if(bhid_cmd_err)
                in_report_data[4] |= 0x80;
            bhid_data_send = 1;

            break;
        case iHID_CMD_E_FLASH: // 擦除FLASH
            in_report_data[0] = iHID_CMD_HANDLE;
            in_report_data[1] = iHID_CMD_E_FLASH|iHID_CMD_SYS_CTRL;
            in_report_data[2] = out_report_data[2];
            in_report_data[3] = ~out_report_data[3];
            in_report_data[4] = iACK;

            if((out_report_data[2] == in_report_data[3])
                && (16 > out_report_data[2])
                && (0x55 == out_report_data[4])
                && (0xAA == out_report_data[5]))
            {
                flash_clear(out_report_data[2]);
            }

            bhid_data_send = 1;
            break;
    }
}

/******************************************************************************
* 函数名称: hid_get_fw_mode_info
* 功能描述: 获取程序版本信息
* 输入参数: 无
* 输出参数: 无
* 说    明: 获取程序版本信息
******************************************************************************/
extern unsigned char const fw_info[];

void hid_get_fw_mode_info(void)
{
    clear_in_fifo();
    in_report_data[0] = iHID_CMD_HANDLE;
    in_report_data[1] = iHID_CMD_MODE_INFO;

    in_report_data[0x08] = led_cur_mode;
    if(bled_run_dir)
        in_report_data[0x08] |= (1<<5);
    if(bled_bright_en)
        in_report_data[0x08] |= (1<<6);
    in_report_data[0x09] = 0;
    in_report_data[0x0A] = ((led_speed_lev<<4) | led_light_lev);
    //in_report_data[0x0B] = (led_rgb_index&0x07);

    memcpy_const(in_report_data+0x0E, fw_info, 16);
    bhid_data_send = 1;
}

/******************************************************************************
* 函数名称: HIDDataProcess
* 功能描述: 处理HID数据
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void hid_process(void)
{
    //unsigned int i;

    if(bdevice_status_change)
    {
        bdevice_status_change = 0;

        hid_get_fw_mode_info();
    }
    else if(bhid_data_process)
    {
        bhid_data_process = 0;

        if(iHID_CMD_HANDLE != out_report_data[0])
        {
            return;
        }
        bhid_cmd_err = 0;
        if(iHID_CMD_SYS_CTRL == (out_report_data[1]&iHID_CMD_MASK))
        {                                       // 系统控制命令
            if(iHID_CMD_KEY_CFG == (out_report_data[1]&0xFC))
            {
                flash_ctrl();
            }
            else if(iHID_CMD_CFG_INFO == (out_report_data[1]&0x0F))
            {
                clear_in_fifo();
                in_report_data[0x00] = iHID_CMD_HANDLE;
                in_report_data[0x01] = iHID_CMD_SYS_CTRL|iHID_CMD_CFG_INFO;
                in_report_data[0x02] = 0x01;
                in_report_data[0x03] = (128>>2);
                in_report_data[0x04] = ((iKEY_CFG_ADDR_0>>0)&0xFF);
                in_report_data[0x05] = ((iKEY_CFG_ADDR_0>>8)&0xFF);
                in_report_data[0x06] = ((iKEY_CFG_LENGHT_0>>0)&0xFF);
                in_report_data[0x07] = ((iKEY_CFG_LENGHT_0>>8)&0xFF);
                in_report_data[0x08] = ((iKEY_CFG_ADDR_1>>0)&0xFF);
                in_report_data[0x09] = ((iKEY_CFG_ADDR_1>>8)&0xFF);
                in_report_data[0x0A] = ((iKEY_CFG_LENGHT_1>>0)&0xFF);
                in_report_data[0x0B] = ((iKEY_CFG_LENGHT_1>>8)&0xFF);

                in_report_data[0x1C] = ((iLED_CFG_BASE_ADDR>>0)&0xFF);
                in_report_data[0x1D] = ((iLED_CFG_BASE_ADDR>>8)&0xFF);

				checksum_check(30, in_report_data);
                in_report_data[0x1E] = ((check_sum>>0)&0xFF);
                in_report_data[0x1F] = ((check_sum>>8)&0xFF);

                bhid_data_send = 1;
            }
            else if(iHID_CMD_ISP == (out_report_data[1]&0x0F))
            {
                if((0x55 == out_report_data[2])
                    && (0xAA == out_report_data[3])
                    && (0x00 == out_report_data[4])
                    && (0xFF == out_report_data[5]))
                {
				    bjump_boot = 1;
					clear_in_fifo();
					in_report_data[0x00] = iHID_CMD_HANDLE;
					in_report_data[0x01] = iHID_CMD_SYS_CTRL|iHID_CMD_ISP;
					in_report_data[0x02] = 0x01;
                    bhid_data_send = 1;
               }
            }
        }
        else if(iHID_CMD_DEVICE_STATUS == (out_report_data[1]&iHID_CMD_MASK))
        {
            if(iHID_CMD_MODE_INFO == out_report_data[1])
            {
                key_temp_delay = out_report_data[8];
                if(bkey_delay7)
                {				// 设置模式
					if((iMODE_LED_MAX >= (out_report_data[8]&0x1F))
					    &&(led_cur_mode != (out_report_data[8]&0x1F)))
                    {
					    led_cur_mode = (out_report_data[8]&0x1F);
                        bsave_flash = 1;
					}
					
					if(bled_run_dir != bkey_delay5)
					{
				        bled_run_dir = bkey_delay5;
                        bsave_flash = 1;
					}

					// if(bled_bright_en != bkey_delay6)
					// {
					// 	bled_bright_en = bkey_delay6;
                    //     bsave_flash = 1;
					// }
				}

                if(out_report_data[10]&(1<<3))
				{				// 设置亮度
                    if(led_light_lev != (out_report_data[10]&0x07))
					{
					    led_light_lev = (out_report_data[10]&0x07);
                        bsave_flash = 1;
					}
				}

                if(out_report_data[10]&(1<<7))
				{				// 设置速度
                    if(led_speed_lev != ((out_report_data[10]>>4)&0x07))
					{
					    led_speed_lev = ((out_report_data[10]>>4)&0x07);

                        bsave_flash = 1;
					}
				}

                hid_get_fw_mode_info();
                bhid_data_send = 1;
            }
        }
    }
}