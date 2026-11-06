/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: HID_Process.c
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#include "defines.h"

//-----------------------------------------------------------------------------;
// 常量定义
//
#define iSK1300_ERR_ID_OK           0

#define iSK1300_ERR_ID_LENGTH_ERR   1
#define iSK1300_ERR_ID_CS_ERR       2
#define iSK1300_ERR_ID_ADDR_ERR     3
#define iSK1300_ERR_ID_W_FLASH_ERR  4

#define iSK1300_ERR_ID_W_FIFO_ERR   1

//-----------------------------------------------------------------------------;
// 变量定义
//
USBD_U8                         uhid_ctrl_reg;

unsigned char                   in_report_data[32];
unsigned char                   out_report_data[32];
unsigned char                   flash_fifo[iPAGE_LENGHT];
unsigned char                   sk1300_err_id;
unsigned char                   hid_delay_count;

unsigned int                    check_sum;

//----------------------------------------------------------------------------—;
//表格定义区
//
unsigned char const fw_info_tbl[] =
{
    iHID_CMD_HANDLE,
	iHID_CMD_MODE_INFO,
    iPROJECT_ID_3,
    iPROJECT_ID_2,
    iPROJECT_ID_1,
    iPROJECT_ID_0,
    iVERSION_ID,
    0x00,
    0x96,
    0x00,
    0x09,
    0x01,
	'Y',
	'i',
	'Q',
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void clear_in_fifo(void)
{
    unsigned char i;

    for(i=0; i<32; i++)
        in_report_data[i]=0;
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
    unsigned int i, j;

    if(0 != (length&0x01))
    {
        bhid_cmd_err = 1;
        return;
    }

	check_sum = 0xFA21;
	for(i = 0; i <length;)
	{
	    j = (ptr[i] | (ptr[i+1]<<8));
	
		check_sum += j;
		i += 2;
	}
}
extern void __delayus(unsigned char time);

/******************************************************************************
* 函数名称: HIDDataProcess
* 功能描述: 处理HID数据
* 输入参数: 无
* 输出参数: 无
* 说    明:
******************************************************************************/
void hid_process(void)
{
    unsigned int i;
    unsigned char j, x, y;
    unsigned int fifo_addr, fifo_length;

    if(bhid_data_process)
    {
        bhid_data_process = 0;

        if(iHID_CMD_HANDLE != out_report_data[0])
        {
            return;
        }
        bhid_cmd_err = 0;
        if(iHID_CMD_SYS_CTRL == (out_report_data[1]&iHID_CMD_MASK))
        {                                       // 系统控制命令
            switch(out_report_data[1]&iHID_CMD_KEY_CFG_MASK)
            {
                case iHID_CMD_W_FLASH:          // 键盘配置信息写flash
// 驱动软件写入24K的数据，保留的部分软件上写成0xFF，因此不需要擦除flash的操作
                    sk1300_err_id = iSK1300_ERR_ID_OK;
        
                    if((iPAGE_LENGHT < out_report_data[4]) || (0xA5 < out_report_data[5]))
                    {                                   // 长度错误
                        sk1300_err_id = iSK1300_ERR_ID_LENGTH_ERR;
                        bhid_cmd_err = 1;
                    }
                    else
                    {
                        checksum_check(out_report_data[4], flash_fifo);
                        if((out_report_data[6] != (check_sum&0xFF))
        				    ||(out_report_data[7] != ((check_sum>>8)&0xFF)))
                        {                               // CS错误
                            sk1300_err_id = iSK1300_ERR_ID_CS_ERR;
                            bhid_cmd_err = 1;
                        }
                    }
        
                    i = ((out_report_data[3]<<8)|out_report_data[2]);
                    if(iCODE_LENGTH < i)
                    {                                   // 地址错误
                        sk1300_err_id = iSK1300_ERR_ID_ADDR_ERR;
                        bhid_cmd_err = 1;
                    }

                    if(!bhid_cmd_err)
                    {
                        flash_program(i, out_report_data[4]);
                        if(bhid_cmd_err)                // 写入错误
                            sk1300_err_id = iSK1300_ERR_ID_W_FLASH_ERR;
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
                    in_report_data[7] = sk1300_err_id;

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
                case iHID_CMD_R_FLASH:                  // 读取FLASH存储区域 4KB+60B
                    clear_in_fifo();
        
                    in_report_data[0] = iHID_CMD_HANDLE;
                    in_report_data[1] = iHID_CMD_R_FLASH|iHID_CMD_SYS_CTRL;

		            fifo_addr = ((out_report_data[3]<<8)|out_report_data[2]);
                    fifo_length = ((out_report_data[5]<<8)|out_report_data[4]);

        		    unsigned char const *pRom = (const unsigned char*)(iCODE_MAIN_ADDR+fifo_addr);
                    for(i=0; i<fifo_length;)
                    {
                        if(iHID_CMD_DATA_SIZE<(fifo_length-i))
                        {
                            y = iHID_CMD_DATA_SIZE;
                        }
                        else
                        {
                            y = ((fifo_length-i)&0xFF);
                        }

                        in_report_data[2] = ((i>>0)&0xFF);
                        in_report_data[3] = ((i>>8)&0xFF);

                        for(x=0; x<y;)
                        {
                            in_report_data[4+x++] = *pRom++;
                            in_report_data[4+x++] = *pRom++;
                            i++;
                            i++;
                        }

                        hid_delay_count = 0;
                        bhid_data_send = 1;
                        while(bhid_data_send)
                        {
                            if(UE0SDF)
                                USBD_EP0_Handler();

                            if(UE1INF)
                            {
                                UE1INF = 0;
                                UE1IOPS = 0;
                                bEp1Busy = 0;
                            }
                            __delayus(100);
                            usb_data_process();
                            hid_delay_count++;
                            if(200 <= hid_delay_count)
                            {
							    bhid_data_send = 0;
							    return;
                            }
                        }
                    }
                    break;
                case iHID_CMD_APP:
                    clear_in_fifo();
                    in_report_data[0x00] = iHID_CMD_HANDLE;
                    in_report_data[0x01] = iHID_CMD_APP|iHID_CMD_SYS_CTRL;
                    in_report_data[0x02] = iNAK;
                    const unsigned char *pRom = (const unsigned char *)APP_StartAddr;
                    if((*pRom != 0XFF) || (*(pRom+1) != 0XFF))
                        in_report_data[0x02] = iACK;

                    bhid_data_send = 1;
                    while(bhid_data_send)
                    {
                        if(UE1INF)
                        {
                            UE1INF = 0;
                            UE1IOPS = 0;
                            bEp1Busy = 0;
                        }

                        usb_data_process();
                    }

                    if(iACK == in_report_data[0x02])
                    {
		                delayms(5);
                        Reset();
                    }

                    break;
            }
        }
        else if(iHID_CMD_MODE_INFO == out_report_data[1])
        {                                       // 系统控制命令
            clear_in_fifo();
            for(j=0; j<sizeof(fw_info_tbl); j++)
                in_report_data[j] = fw_info_tbl[j];

            bhid_data_send = 1;
		}
    }
}
