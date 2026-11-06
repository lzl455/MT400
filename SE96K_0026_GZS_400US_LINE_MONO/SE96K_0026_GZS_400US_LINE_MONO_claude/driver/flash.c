/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: flash.c
*
* 功能说明: Flash底层写入与擦除处理
* 修改说明:
*******************************************************************************/
#include "..\defines.h"

//-----------------------------------------------------------------------------;
// 变量定义
//
static unsigned char            FlashBuff[128]  @(0X780);

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/*******************************************************************************
* 函数名称: flash_program
* 功能描述: flash数据写入
* 输入参数: addrh\addrl：E2地址；dat：写入数据的地址指针
* 输出参数: 无
* 说    明:
*******************************************************************************/
void flash_save_info(unsigned int addr)
{
    unsigned char i;

	i = addr&0X007F;
	addr |= 0X7F00;
GIEH = 0;
    off_led();

	FlashBuff[i++] = device_para_tbl[0];
	FlashBuff[i++] = device_para_tbl[1];
	FlashBuff[i++] = device_para_tbl[2];
	FlashBuff[i++] = device_para_tbl[3];
	for(; i<128; i++)
		FlashBuff[i] = 0xFF;

	OPTION = 0; //关闭中断
	ERASE = 1;
	CLRPL = 1;
	WRITE = 1;
	TBLPTRH = 0x7F;
	TBLPTRL = 0x00;
	EELOCK3 = 1;
	EELOCK2 = 1;
	EELOCK1 = 1;
	#asm
	WDT*
	#endasm

    int_iob_dat = 0xFF;
    int_ioc_dat = 0xFF;
    int_iod_dat = 0xFF;
    led_scan_count = 0x00;
	led_index_value=0;
GIEH = 1;
}

/*******************************************************************************
* 函数名称: flash_program
* 功能描述: flash数据写入
* 输入参数: addrh\addrl：E2地址；dat：写入数据的地址指针
* 输出参数: 无
* 说    明:
*******************************************************************************/
void flash_program(unsigned int addr, unsigned char length)
{
    unsigned char i, j;
    unsigned char const *pRom;

    if(iKEY_MAX_LENGHT <= addr)
	{
        bhid_cmd_err = 1;
        return;
    }

	pRom = (const unsigned char*)(addr|iKEY_CFG_BASE_ADDR);
	for(i=0; i<length; i++)
    {
        if(flash_fifo[i] != *pRom++)
        {
            goto flash_w_begin;
        }
    }
    return;

flash_w_begin:
GIEH = 0;
    addr |= iKEY_CFG_BASE_ADDR;
    IOA |= 0xFC;

	pRom = (const unsigned char*)(addr&0x7F80);
	memcpy_const(FlashBuff, pRom, 128);

    j = (addr&0x7F);
	for(i=0; i<length; i++)
	{
		FlashBuff[j++] = flash_fifo[i];	            // 取出页的全部数据
	}

	OPTION = 0; //关闭中断
	ERASE = 1;
	CLRPL = 1;
	WRITE = 1;
	TBLPTRH = ((addr>>8)&0xFF);
	TBLPTRL = ((addr>>0)&0xFF);
	EELOCK3 = 1;
	EELOCK2 = 1;
	EELOCK1 = 1;
	#asm
	WDT*
	#endasm

	pRom = (const unsigned char*)addr;
	for(i=0; i<length; i++)
    {
        if(flash_fifo[i] != *pRom++)
        {
            bhid_cmd_err = 1;
            break;
        }
    }

    int_iob_dat = 0xFF;
    int_ioc_dat = 0xFF;
    int_iod_dat = 0xFF;
    led_scan_count = 0x00;
	led_index_value=0;
GIEH = 1;
}

/*******************************************************************************
* 函数名称: flash_clear
* 功能描述: flash数据写入
* 输入参数: addrh\addrl：E2地址；dat：写入数据的地址指针
* 输出参数: 无
* 说    明:
*******************************************************************************/
void flash_clear(unsigned char bank)
{
    unsigned int addr;

GIEH = 0;
	memset(FlashBuff, 0xFF, 128);
    addr = (iKEY_CFG_BASE_ADDR+(bank<<8));

	OPTION = 0; //关闭中断
	ERASE = 1;
	CLRPL = 1;
	WRITE = 1;
	TBLPTRH = ((addr>>8)&0xFF);
	TBLPTRL = ((addr>>0)&0xFF);
	EELOCK3 = 1;
	EELOCK2 = 1;
	EELOCK1 = 1;
	#asm
	WDT*
	#endasm

    addr += 0x0080;

	OPTION = 0; //关闭中断
	ERASE = 1;
	CLRPL = 1;
	WRITE = 1;
	TBLPTRH = ((addr>>8)&0xFF);
	TBLPTRL = ((addr>>0)&0xFF);
	EELOCK3 = 1;
	EELOCK2 = 1;
	EELOCK1 = 1;
	#asm
	WDT*
	#endasm
GIEH = 1;
}
