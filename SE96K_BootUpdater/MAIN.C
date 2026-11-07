/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.c
*
* 功能说明: Boot 更新程序 (Updater)
*
*   本程序像普通 App 一样由现有 Boot 写入 0x1000 并运行, 它把 boot_image[]
*   写入 Boot 区 (0x0000-0x0FFF), 完成后设置跳转标志并软复位进入新 Boot,
*   由上位机驱动再把正式 App 写回去。
*
*   写入顺序 (保证任何时刻掉电都能恢复):
*     1. 第 0 页先写成"跳转桩": 0x0000/0x0008/0x0018 -> 0x1000/0x1008/0x1018
*        此后掉电, 上电直接运行 Updater, 重新执行更新
*     2. 依次写第 1~31 页 (0x0080-0x0FFF), 每页回读校验
*     3. 最后写第 0 页 (新 Boot 的复位向量)
*   只有第 1 步和第 3 步各一次页擦写 (约 5ms) 期间掉电会导致无法启动。
*
*   不做更新, 直接进入 Boot 的情况:
*     - Boot 区已与 boot_image[] 完全一致 (已更新过 / 中断后重启已完成)
*     - 当前 Boot 不是本产品的 Boot (项目ID不符, 且不是中断后的跳转桩)
*
*   停机 (死循环, 等待重新上电重试) 的情况:
*     - boot_image[] 自身校验失败且 Boot 区已是跳转桩
*     - 某页重试 iWRITE_RETRY 次仍校验失败
*
* 修改说明:
*******************************************************************************/
#include "defines.h"
#include "boot_image.h"

//----------------------------------------------------------------------------;
// 变量定义
//
unsigned char               bootloader_val[4] @ 0X0280;     // 与 App / Boot 相同

//----------------------------------------------------------------------------;
// Updater 标识信息, 供上位机驱动识别固件文件
//   地址与 App 的 fw_info[] (driver/flash_default.c @0x6FF0) 相同,
//   即 bin 文件偏移 0x5FF0, 16 字节, 驱动可用同一方式读取:
//   [0..3]  项目ID (ID3 ID2 ID1 ID0, 取自新 Boot 镜像)
//   [4]     将写入的新 Boot 版本号
//   [5..7]  0x00 保留
//   [8..15] "UPD-BOOT"   App 此处为 "BYKC-V10", 驱动据 [8..10]=="UPD" 区分
//
const unsigned char updater_info[16] @ iUPD_INFO_ADDR =
{
    BOOT_IMAGE_PID3,
    BOOT_IMAGE_PID2,
    BOOT_IMAGE_PID1,
    BOOT_IMAGE_PID0,
    BOOT_IMAGE_VER,
    0x00,
    0x00,
    0x00,
    'U', 'P', 'D', '-', 'B', 'O', 'O', 'T',
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

/******************************************************************************
* 函数名称: enter_boot()
* 功能描述: 设置跳转标志并软复位, 进入 Boot
******************************************************************************/
static void enter_boot(void)
{
    bootloader_val[0] = iBOOT_FLAG_0;
    bootloader_val[1] = iBOOT_FLAG_1;
    bootloader_val[2] = iBOOT_FLAG_2;
    bootloader_val[3] = iBOOT_FLAG_3;
    Reset();
    while(1);
}

/******************************************************************************
* 函数名称: halt()
* 功能描述: 出错停机, 等待重新上电后重试
******************************************************************************/
static void halt(void)
{
    while(1);
}

/******************************************************************************
* 函数名称: stub_page_load()
* 功能描述: 生成第 0 页"跳转桩"到 page_buf
* 说    明: 与 App driver/BootLoader_bin.c 中 debug 段相同
*           goto 0x1000 / goto 0x1008 / goto 0x1018
******************************************************************************/
static void stub_page_load(void)
{
    unsigned char i;

    for(i=0; i<iPAGE_SIZE; i++)
        page_buf[i] = 0xFF;

    page_buf[0x00] = 0x00;  page_buf[0x01] = 0xDF;      // 0x0000: goto 0x1000
    page_buf[0x02] = 0x08;  page_buf[0x03] = 0xF0;
    page_buf[0x08] = 0x04;  page_buf[0x09] = 0xDF;      // 0x0008: goto 0x1008
    page_buf[0x0A] = 0x08;  page_buf[0x0B] = 0xF0;
    page_buf[0x18] = 0x0C;  page_buf[0x19] = 0xDF;      // 0x0018: goto 0x1018
    page_buf[0x1A] = 0x08;  page_buf[0x1B] = 0xF0;
}

/******************************************************************************
* 函数名称: image_page_load()
* 功能描述: 从 boot_image[] 取出 addr 所在页到 page_buf
******************************************************************************/
static void image_page_load(unsigned int addr)
{
    unsigned char i;
    unsigned char const *pImg;

    pImg = boot_image + addr;
    for(i=0; i<iPAGE_SIZE; i++)
        page_buf[i] = *pImg++;
}

/******************************************************************************
* 函数名称: image_check()
* 功能描述: 校验内嵌的新 Boot 镜像
* 返 回 值: 1 正确; 0 错误
******************************************************************************/
static unsigned char image_check(void)
{
    unsigned int i, sum;

    sum = 0;
    for(i=0; i<iBOOT_SIZE; i++)
        sum += boot_image[i];
    if(sum != boot_image_sum)
        return 0;

    if((0xAA != boot_image[iBOOT_INFO_ADDR+iBOOT_TAG_OFFSET+0])
        || (0x55 != boot_image[iBOOT_INFO_ADDR+iBOOT_TAG_OFFSET+1])
        || (0x5A != boot_image[iBOOT_INFO_ADDR+iBOOT_TAG_OFFSET+2]))
        return 0;

    return 1;
}

/******************************************************************************
* 函数名称: boot_is_new()
* 功能描述: Boot 区是否已与 boot_image[] 完全一致
******************************************************************************/
static unsigned char boot_is_new(void)
{
    unsigned int addr;

    for(addr=0; addr<iBOOT_SIZE; addr+=iPAGE_SIZE)
    {
        image_page_load(addr);
        if(!flash_page_compare(addr))
            return 0;
    }
    return 1;
}

/******************************************************************************
* 函数名称: stub_present()
* 功能描述: 第 0 页是否为跳转桩 (上次更新中途掉电)
******************************************************************************/
static unsigned char stub_present(void)
{
    stub_page_load();
    return flash_page_compare(iBOOT_START_ADDR);
}

/******************************************************************************
* 函数名称: boot_product_match()
* 功能描述: 当前 Boot 是否为本产品的 Boot
* 说    明: 检查版本信息尾标记 AA 55 5A, 并比较项目ID 前两字节 (00 96)
*           项目ID 后两字节新旧 Boot 不同 (旧 FF 01, 新 00 28), 不比较
******************************************************************************/
static unsigned char boot_product_match(void)
{
    unsigned char const *pRom;

    pRom = (const unsigned char *)iBOOT_INFO_ADDR;
    if((0xAA != pRom[iBOOT_TAG_OFFSET+0])
        || (0x55 != pRom[iBOOT_TAG_OFFSET+1])
        || (0x5A != pRom[iBOOT_TAG_OFFSET+2]))
        return 0;

    if((boot_image[iBOOT_INFO_ADDR+iBOOT_PID_OFFSET+0] != pRom[iBOOT_PID_OFFSET+0])
        || (boot_image[iBOOT_INFO_ADDR+iBOOT_PID_OFFSET+1] != pRom[iBOOT_PID_OFFSET+1]))
        return 0;

    return 1;
}

/******************************************************************************
* 函数名称: main()
* 功能描述: 主函数
******************************************************************************/
void main(void)
{
    unsigned int addr;
    unsigned char resume;

    GIEL = 0;
    GIEH = 0;                                   // 关中断
    USBCON = 0X00;                              // 失能USB

    resume = stub_present();

    if(!image_check())
    {                                           // 镜像损坏, 不能写
        if(resume)
            halt();                             // Boot 区已不完整, 不能复位进 Boot
        enter_boot();                           // 旧 Boot 完好, 回到旧 Boot
    }

    if(boot_is_new())
        enter_boot();                           // 已是新 Boot

    if(!resume && !boot_product_match())
        enter_boot();                           // 非本产品 Boot, 不更新

//----------------------------------------------
// 1. 第 0 页写跳转桩
//
    if(!resume)
    {
        stub_page_load();
        if(!flash_page_write(iBOOT_START_ADDR))
            halt();
    }

//----------------------------------------------
// 2. 写第 1~31 页
//
    for(addr=iPAGE_SIZE; addr<iBOOT_SIZE; addr+=iPAGE_SIZE)
    {
        image_page_load(addr);
        if(!flash_page_write(addr))
            halt();
    }

//----------------------------------------------
// 3. 最后写第 0 页
//
    image_page_load(iBOOT_START_ADDR);
    if(!flash_page_write(iBOOT_START_ADDR))
    {                                           // 失败: 尽量恢复跳转桩, 便于重试
        stub_page_load();
        flash_page_write(iBOOT_START_ADDR);
        halt();
    }

    enter_boot();
}
