/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: Flash_process.h
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#ifndef _FLASH_PROCESS_H_
#define _FLASH_PROCESS_H_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//=============================================================================;
// 配置常量定义区
//
#define iLED_ADDR               0x0E00
#define iCFG_ADDR               0x7F00

#define iCS_0x00_0x0F           0xF0
#define iCS_0x10_0x1F           0xF1
#define iCS_0x20_0x2F           0xF2
#define iCS_0x30_0x3F           0xF3
#define iCS_0x40_0x4F           0xF4
#define iCS_0x50_0x5F           0xF5
#define iCS_0x60_0x6F           0xF6
#define iCS_0x70_0x7F           0xF7

#define iCS_0x80_0x8F           0xF8
#define iCS_0x90_0x9F           0xF9
#define iCS_0xA0_0xAF           0xFA
#define iCS_0xB0_0xBF           0xFB
#define iCS_0xC0_0xCF           0xFC
#define iCS_0xD0_0xDF           0xFD
#define iCS_0xE0_0xEF           0xFE

#define iKEY_TPYE_ADDR          0xFF

//=============================================================================;
// 外部定义内部引用区
//=============================================================================;

//=============================================================================;
// 外部寄存器引用
//
extern unsigned char const flash_bank_15[128];

//=============================================================================;
// 外部函数引用
//

//=============================================================================;
// 内部定义外部引用区
//=============================================================================;

//=============================================================================;
// 内部寄存器引用
//
extern unsigned char            device_para_tbl[];
#define s_mode                  device_para_tbl[0]
//{
    #define iPARA_TYPE_MASK     0xF0
    #define iPARA_TYPE          0xA0
    #define iLED_DEF_INDEX      0x0F
//}
#define s_led_mode              device_para_tbl[1]
//{
    #define iLED_DEF            (1<<7)
    #define iLED_DIR            (1<<6)
    #define iLED_ENABLE         (1<<5)
    #define iLED_MODE_MASK      0x1F
//}
#define s_led_para              device_para_tbl[2]
//{
    #define iSPEED_MASK         0xF0
    #define iLEV_MASK           0x0F
//}
#define s_cfg_para              device_para_tbl[3]
//{
    #define iFN_LOCK            (1<<7)
    #define iDIR_LOCK           (1<<6)
    #define iWIN_MODE           (1<<5)
    #define iWIN_LOCK           (1<<4)
    // #define iFN_LOCK            (1<<3)
    
    #define iWHEEL_LED_MODE     0X0F
//}
#define flash_dat              flash_fifo

//=============================================================================;
// 内部函数引用
//
extern void memcpy_const(unsigned char  *ptr_d, unsigned char const *ptr_s, unsigned char lenght);
extern void memcpy(unsigned char  *ptr_d, unsigned char *ptr_s, unsigned char lenght);
extern void memset(unsigned char  *ptr_d, unsigned char const dat, unsigned char lenght);

extern void cfg_default_load(void);
extern void led_default_load(void);

extern void load_led_para(void);
extern void e2_config_load(void);

extern void cfg_load(void);
extern void cfg_mode_save(void);

#endif
