/*******************************************************************************
* Copyright (c) 2013, SHENZHEN Co.,LTD.
* All rights reserved.
*
* 文件名称: Main.c
*
* 功能说明: 主函数处理程序
* 修改说明:
*******************************************************************************/
#include "defines.h"

//----------------------------------------------------------------------------;
//变量定义
//
extern void USBD_CalibrationInit(void);

//----------------------------------------------------------------------------;
//变量定义
//
unsigned char               bootloader_val[4] @ 0X0280;

//-----------------------------------------------------------------------------;
// 进 BOOT 按键定义 (与 App 工程矩阵一致, 见 App hal/matrix_key_tbl_win.h 与
// led/led_logo.c timer_int_process):
//   列线: C0~C7 = PB0~PB7, C8~C15 = PC0~PC7, C16~C20 = PD0~PD4 (低电平扫描)
//   行线: R0 = PA0, R1 = PA1, R2 = PE0, R3 = PE3, R4 = PE4, R5 = PE5
//   行状态位与 App matrix_status[] 相同: R0=bit2 ... R5=bit7
//
// 上电时按住 左CTRL(C0 R0) + 左WIN(C1 R0) 进入 BOOT
//
#define iBOOT_ROW_R0            0x04            // PA0
#define iBOOT_ROW_R1            0x08            // PA1
#define iBOOT_ROW_R2            0x10            // PE0
#define iBOOT_ROW_R3            0x20            // PE3
#define iBOOT_ROW_R4            0x40            // PE4
#define iBOOT_ROW_R5            0x80            // PE5

#define iBOOT_KEY0_COL          (1<<0)          // CTRL_L 列 PB0
#define iBOOT_KEY0_ROW          iBOOT_ROW_R0    // CTRL_L 行 PA0
#define iBOOT_KEY1_COL          (1<<1)          // WIN_L  列 PB1
#define iBOOT_KEY1_ROW          iBOOT_ROW_R0    // WIN_L  行 PA0

#define iBOOT_KEY_CHECK_TIMES   3               // 连续检测次数(消抖)

#define iBOOT_FLAG_0            0x3C            // App 跳转 BOOT 标志, 与 App
#define iBOOT_FLAG_1            0xC3            // usb_user_process.c 保持一致
#define iBOOT_FLAG_2            0x55
#define iBOOT_FLAG_3            0xAA

//-----------------------------------------------------------------------------;
// 表格定义区
//
const unsigned int low_int[2] @0x0008 =
{
    0xDF04, 0xF008,                     // goto 0x1008
};
const unsigned int high_int[2] @0x0018 =
{
    0xDF0C, 0xF008,                     // goto 0x1018
};

const unsigned char boot_fw_vs[] @0x0FF0 =
{
    'B',  'o',  'o'-0x60,  't'-0x60,  '-', 'V'-0x60,  '2', '0',
    iPROJECT_ID_0,
    iPROJECT_ID_1,
    iPROJECT_ID_2,
    iPROJECT_ID_3,
    iVERSION_ID,
	0xAA,
	0x55,
	0x5A,
};

const unsigned char boot_key_tbl[] @0x0FE8 =
{												// CTRL_L C0(PB0) R0(PA0)
    0x01,										// port B
    iBOOT_KEY0_COL,								// 列
    iBOOT_KEY0_ROW,								// 行 (App matrix_status 位)
    0xAA,										//
												// WIN_L  C1(PB1) R0(PA0)
    0x01,										// port B
    iBOOT_KEY1_COL,								// 列
    iBOOT_KEY1_ROW,								// 行 (App matrix_status 位)
    0x55,										//
};

//=============================================================================;
// 代码区                                                                      ;
//=============================================================================;

void memcpy(unsigned char  *ptr_d, unsigned char *ptr_s, unsigned char lenght)
{
	for(unsigned char i=0; i<lenght; i++)
    {
        *ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
    }
}

/******************************************************************************
* 函数名称: boot_io_init()
* 功能描述: 矩阵 IO 初始化
* 说    明: 与 App 工程 MAIN.C sys_init() 中 IO 配置一致
******************************************************************************/
static void boot_io_init(void)
{
//IOA  PA0/PA1 行输入上拉
    ANSA = 0x00;
    PUA = 0x03;                                 //0:上拉关闭 1:上拉使能
    PDA = 0x00;                                 //0:下拉关闭 1:下拉使能
    OEA = 0xFC;                                 //0:输入 1:输出
    IOA = 0xFF;                                 //IO口数据
//IOB  列输出高
    ANSB = 0x00;
    PUB = 0x00;
    PDB = 0x00;
    OEB = 0xFF;
    IOB = 0xFF;
//IOC  列输出高
    ANSC = 0x00;
    PUC = 0x00;
    PDC = 0x00;
    OEC = 0xFF;
    IOC = 0xFF;
//IOD  列输出高
    ANSD = 0x00;
    PUD = 0x00;
    PDD = 0x00;
    OED = 0xFF;
    IOD = 0xFF;
//IOE  PE0/PE3/PE4/PE5 行输入上拉
    ANSE = 0x00;
    PUE = 0xFF;
    PDE = 0x00;
    OEE = 0x00;
    IOE = 0xFF;
//IOF
    ANSF = 0x00;
    IOFODS0 = 0x03;
    IOFODS1 = 0x03;
    PUF = 0x00;
    PDF = 0x0E;
    OEF = 0xF0;
    IOF = 0xFF;
}

/******************************************************************************
* 函数名称: boot_col_scan()
* 功能描述: 拉低 PB 口指定列, 读取行状态
* 返 回 值: 行状态, 位定义与 App matrix_status[] 相同
******************************************************************************/
static unsigned char boot_col_scan(unsigned char col)
{
    unsigned char row = 0;

    IOB = ~col;
    delayms(1);

    if(!IOE5)
        row |= iBOOT_ROW_R5;
    if(!IOE4)
        row |= iBOOT_ROW_R4;
    if(!IOE3)
        row |= iBOOT_ROW_R3;
    if(!IOE0)
        row |= iBOOT_ROW_R2;
    if(!IOA1)
        row |= iBOOT_ROW_R1;
    if(!IOA0)
        row |= iBOOT_ROW_R0;

    IOB = 0xFF;
    return row;
}

/******************************************************************************
* 函数名称: boot_key_check()
* 功能描述: 检测上电时是否按住进 BOOT 组合键
* 返 回 值: 1 进入 BOOT; 0 跳转 App
* 说    明: 两列上只允许按下指定按键, 连续 iBOOT_KEY_CHECK_TIMES 次一致才有效
******************************************************************************/
static unsigned char boot_key_check(void)
{
    unsigned char i;

    boot_io_init();
    delayms(5);

    for(i=0; i<iBOOT_KEY_CHECK_TIMES; i++)
    {
        if((iBOOT_KEY0_ROW != boot_col_scan(iBOOT_KEY0_COL))
            || (iBOOT_KEY1_ROW != boot_col_scan(iBOOT_KEY1_COL)))
        {
            return 0;
        }
        delayms(5);
    }
    return 1;
}

/******************************************************************************
* 函数名称: main()
* 功能描述: 主函数
* 说    明:
******************************************************************************/
void main(void)
{
    GIEL = 0;
    GIEH = 0;                                   // 关中断
    USBCON = 0X00;                              // 失能USB

    const unsigned char *pRom = (const unsigned char *)APP_StartAddr;
    if((*pRom != 0XFF) || (*(pRom+1) != 0XFF))
    {                                           // 用户区不为空
        if(!SOFTRST)
        {                                       // 上电复位: 检测组合键
            if(!boot_key_check())
            {
                #asm
                goto APP_StartAddr
                #endasm
            }
        }
        else if((iBOOT_FLAG_0 != bootloader_val[0])
            ||(iBOOT_FLAG_1 != bootloader_val[1])
            ||(iBOOT_FLAG_2 != bootloader_val[2])
            ||(iBOOT_FLAG_3 != bootloader_val[3]))
        {                                       // 软复位且无升级标志
            #asm
            goto APP_StartAddr
            #endasm
        }
    }

    bootloader_val[0] = 0;                      // 清除升级标志
    bootloader_val[1] = 0;
    bootloader_val[2] = 0;
    bootloader_val[3] = 0;

into_bootloader:
	ANSF &= ~0X03;	//DP、DN端口设为数字模式
    UINTCR0 = BIT_INTEP1+BIT_INTEP0+BIT_INTBUS; //中断使能
    USBCON  = BIT_UFS+BIT_USHC+BIT_UE;
    USBEnumState = USBE_Default;
    usb_ctrl_flag = 0;
    usb_status_reg = 0;
    EpState = 0;
    USBEpBusy = 0;

    while(1)
    {
        if(UBRST)
        {
            UBRST = 0;

            USBEnumState = USBE_Default;
            usb_ctrl_flag = 0;
            usb_status_reg = 0;
            EpState = 0;
            USBEpBusy = 0;

            UDADR = 0x00;
            UE0CON = 0x02;
            UE0IOPS = 0x00;

            UE1CON = UE1CON_RSET;
            UE1IOPS = 0x00;
            USBD_CalibrationInit();
        }
        if(UBSPD)
            UBSPD = 0;

        if(UBRSM)
            UBRSM = 0;
//----------------------------------------------
// 端点0中断处理
//
        if(UE0STL)
        {
            unsigned int t = 1000;    //不同运行速度下,可能需要修改t (超过255需用int)
            while(t--)
            {
                if(!UE0STL)
                    break;
            }
            UE0STL = 0;    
        }
        if(UE0SDF)
            USBD_EP0_Handler();

//----------------------------------------------
// 端点1中断处理
//
        if(UE1INF)
        {
            UE1INF = 0;
            UE1IOPS = 0;
            bEp1Busy = 0;
        }

        hid_process();
        usb_data_process(); 
    }
}
