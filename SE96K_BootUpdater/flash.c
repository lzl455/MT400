/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: flash.c
*
* 功能说明: Flash 整页擦写与校验
*           IAP 操作流程与 App / Boot 工程 flash.c 相同
* 修改说明:
*******************************************************************************/
#include "defines.h"

//-----------------------------------------------------------------------------;
// 变量定义
//
static unsigned char            FlashBuff[128]  @(0X780);   // 硬件 Flash 写缓存
unsigned char                   page_buf[iPAGE_SIZE];       // 待写入的页数据

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/*******************************************************************************
* 函数名称: flash_page_compare
* 功能描述: 比较 Flash 中 addr 开始的一整页与 page_buf
* 返 回 值: 1 相同; 0 不同
*******************************************************************************/
unsigned char flash_page_compare(unsigned int addr)
{
    unsigned char i;
    unsigned char const *pRom;

    pRom = (const unsigned char*)addr;
    for(i=0; i<iPAGE_SIZE; i++)
    {
        if(page_buf[i] != *pRom++)
            return 0;
    }
    return 1;
}

/*******************************************************************************
* 函数名称: flash_page_write
* 功能描述: 把 page_buf 擦写到 addr 所在页, 并回读校验
* 输入参数: addr 页起始地址 (128 字节对齐)
* 返 回 值: 1 成功; 0 失败
* 说    明: 内容已一致时不擦写; 失败重试 iWRITE_RETRY 次
*******************************************************************************/
unsigned char flash_page_write(unsigned int addr)
{
    unsigned char i, retry;

    addr &= ~(iPAGE_SIZE-1);
    if(flash_page_compare(addr))
        return 1;

    for(retry=0; retry<iWRITE_RETRY; retry++)
    {
        for(i=0; i<iPAGE_SIZE; i++)
            FlashBuff[i] = page_buf[i];

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

        if(flash_page_compare(addr))
            return 1;
    }
    return 0;
}
