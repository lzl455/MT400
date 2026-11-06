/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: flash.c
*
* 功能说明: Flash底层写入与擦除处理
* 修改说明:
*******************************************************************************/
#include "defines.h"

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
void flash_program(unsigned int addr, unsigned char length)
{
    unsigned char i, j;
    unsigned char const *pRom;

    if((iCODE_LENGTH <= addr)
		||(128<length))
	{
        bhid_cmd_err = 1;
        return;
    }
    addr += iCODE_MAIN_ADDR;

	pRom = (const unsigned char*)(addr&0x7F80);
	for(i=0; i<length; i++)
	{
		if(flash_fifo[i] != *pRom++)
			goto flash_w_begin;
	}
    bhid_cmd_err = 0;
    return;

flash_w_begin:
	pRom = (const unsigned char*)(addr&0x7F80);
	for(i=0; i<128; i++)
	{
		FlashBuff[i] = *pRom++;	            // 取出页的全部数据
	}

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
    j = (addr&0x7F);
	for(i=0; i<length; i++)
    {
        if(flash_fifo[j++] != *pRom++)
        {
            bhid_cmd_err = 1;
            break;
        }
    }
}
