/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: hid_process.h
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#ifndef _HID_PROCESS_H_
#define _HID_PROCESS_H_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//-----------------------------------------------------------------------------;
//配置常量定义区
//
#define iPAGE_LENGHT            128
#define iHID_CMD_DATA_SIZE      28
#define iFLASH_R_MAX_SIZE       27

#define iFLASH_MAX_LENGHT       (256*16)

#define iKEY_CFG_BASE_ADDR      0x7000
#define iKEY_MAX_LENGHT         (256*15)
#define iKEY_CFG_ADDR_MAX       (iKEY_CFG_BASE_ADDR+iKEY_MAX_LENGHT)

#define iKEY_CFG_ADDR_0         0x0000
#define iKEY_CFG_LENGHT_0       (256*7)
#define iKEY_CFG_ADDR_1         (iKEY_CFG_LENGHT_0)
#define iKEY_CFG_LENGHT_1       (256*7)

#define iLED_CFG_BASE_ADDR      0x0E00
#define iLED_CFG_MAX_LENGHT     (256)
//{
    #define iLED_CS_ADDR        0x7E
    #define iLED_TPYE_ADDR      0x7F
//}

//=============================================================================;
// HID命令定义区
//=============================================================================;

/*******************************************************************************
 命令应答
*******************************************************************************/
#define iNAK                    0x00
#define iACK                    0x01

/*******************************************************************************
 HID协议命令头
*******************************************************************************/
#define iHID_CMD_HANDLE         0x0F

/*******************************************************************************
 HID控制命令屏蔽位
*******************************************************************************/
#define iHID_CMD_MASK           0xF0

/*******************************************************************************
 HID系统控制命令
*******************************************************************************/
#define iHID_CMD_SYS_CTRL       0x10
#define iHID_CMD_KEY_CFG_MASK   0x0F
#define iHID_CMD_KEY_CFG        (0x10)
#define iHID_CMD_W_FLASH        (0x00)
//{
    #define iID_OK           0
    #define iID_LENGTH_ERR   1
    #define iID_CS_ERR       2
    #define iID_ADDR_ERR     3
    #define iID_W_FLASH_ERR  4
    #define iID_W_FIFO_ERR   1
//}
#define iHID_CMD_W_FIFO         (0x01)
#define iHID_CMD_R_FLASH        (0x02)
#define iHID_CMD_E_FLASH        (0x03)

#define iHID_CMD_ADV_CFG_W_FLASH (0x04)
#define iHID_CMD_ADV_CFG_W_FIFO (0x05)
#define iHID_CMD_ADV_CFG_R      (0x06)
#define iHID_CMD_ADV_CFG_ERASE  (0x07)

#define iHID_CMD_CFG_INFO       (0x08)
#define iHID_CMD_ISP            (0x0E)
//{
    #define iISP_CMD_0          0x55
    #define iISP_CMD_1          0xAA
    #define iISP_CMD_2          0x00
    #define iISP_CMD_3          0xFF
//}

/*******************************************************************************
 设备状态
*******************************************************************************/
#define iHID_CMD_DEVICE_STATUS  0x20

#define iHID_CMD_MODE_INFO      (iHID_CMD_DEVICE_STATUS|0x00)
//{

//}
#define iHID_CMD_TEST           (iHID_CMD_DEVICE_STATUS|0x01)

/*******************************************************************************
 自定义命令 用户自己定义
*******************************************************************************/
//#define iHID_CMD_USER_DEF       0x20~0x70

/*******************************************************************************
 保留命令 保留,系统内部使用
*******************************************************************************/
//#define iHID_CMD_RE             0x20~0x70
//
//-----------------------------------------------------------------------------;

//=============================================================================;
// 外部定义内部引用区
//=============================================================================;

//=============================================================================;
// 外部寄存器引用
//

//=============================================================================;
// 外部函数引用
//

//=============================================================================;
// 外部定义内部引用区
//=============================================================================;

//=============================================================================;
// 外部寄存器引用
//
extern USBD_U8                  uhid_ctrl_reg;
//{
    #define hid_ctrl_reg        uhid_ctrl_reg.u8
    #define bhid_cmd_err        uhid_ctrl_reg.BIT.b7
    #define bcfg_reset          uhid_ctrl_reg.BIT.b3
    #define bjump_boot          uhid_ctrl_reg.BIT.b2
    #define bhid_data_process   uhid_ctrl_reg.BIT.b1
    #define bdevice_status_change uhid_ctrl_reg.BIT.b0
//}
extern unsigned char            in_report_data[];
extern unsigned char            out_report_data[];
extern unsigned char            flash_fifo[128];

//=============================================================================;
// 外部函数引用
//
extern void hid_process(void);

#endif

