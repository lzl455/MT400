/*******************************************************************************
* Copyright (c) 2012, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: USB_Descriptor.h
* 文件描述: USB描述苻相关定义文件
*
* 版    本: V1.0.0
* 作    者:
*******************************************************************************/
#define	_USBD_DESC_C_

#include<zc.h>
#include<stdio.h>
#include"USBD_CORE.H"
#include"usb_cfg_info.h"

//=============================================================================;
// 常量定义                                                                    ;
//=============================================================================;

//HID Subclass Codes
#define HID_SUBCLASS_NONE                       0x00
#define HID_SUBCLASS_BOOT                       0x01

//HID Protocol Codes
#define HID_PROTOCOL_NONE                       0x00
#define HID_PROTOCOL_KEYBOARD                   0x01
#define HID_PROTOCOL_MOUSE                      0x02

//HID Descriptor Types 
#define HID_HID_DESCRIPTOR_TYPE                 0x21
#define HID_REPORT_DESCRIPTOR_TYPE              0x22
#define HID_PHYSICAL_DESCRIPTOR_TYPE            0x23

//HID Request Codes
#define HID_REQUEST_GET_REPORT                  0x01
#define HID_REQUEST_GET_IDLE                    0x02
#define HID_REQUEST_GET_PROTOCOL                0x03
#define HID_REQUEST_SET_REPORT                  0x09
#define HID_REQUEST_SET_IDLE                    0x0A
#define HID_REQUEST_SET_PROTOCOL                0x0B

//HID Report Types 
#define HID_REPORT_INPUT                        0x01
#define HID_REPORT_OUTPUT                       0x02
#define HID_REPORT_FEATURE                      0x03

//Usage Pages
#define HID_USAGE_PAGE_UNDEFINED                0x00
#define HID_USAGE_PAGE_GENERIC                  0x01
#define HID_USAGE_PAGE_SIMULATION               0x02
#define HID_USAGE_PAGE_VR                       0x03
#define HID_USAGE_PAGE_SPORT                    0x04
#define HID_USAGE_PAGE_GAME                     0x05
#define HID_USAGE_PAGE_DEV_CONTROLS             0x06
#define HID_USAGE_PAGE_KEYBOARD                 0x07
#define HID_USAGE_PAGE_LED                      0x08
#define HID_USAGE_PAGE_BUTTON                   0x09
#define HID_USAGE_PAGE_ORDINAL                  0x0A
#define HID_USAGE_PAGE_TELEPHONY                0x0B
#define HID_USAGE_PAGE_CONSUMER                 0x0C
#define HID_USAGE_PAGE_DIGITIZER                0x0D
#define HID_USAGE_PAGE_UNICODE                  0x10
#define HID_USAGE_PAGE_ALPHANUMERIC             0x14

//Generic Desktop Page (0x01) 
#define HID_USAGE_GENERIC_POINTER               0x01
#define HID_USAGE_GENERIC_MOUSE                 0x02
#define HID_USAGE_GENERIC_FN                    0x03
#define HID_USAGE_GENERIC_JOYSTICK              0x04
#define HID_USAGE_GENERIC_GAMEPAD               0x05
#define HID_USAGE_GENERIC_KEYBOARD              0x06
#define HID_USAGE_GENERIC_KEYPAD                0x07
#define HID_USAGE_GENERIC_X                     0x30
#define HID_USAGE_GENERIC_Y                     0x31
#define HID_USAGE_GENERIC_Z                     0x32
#define HID_USAGE_GENERIC_RX                    0x33
#define HID_USAGE_GENERIC_RY                    0x34
#define HID_USAGE_GENERIC_RZ                    0x35
#define HID_USAGE_GENERIC_SLIDER                0x36
#define HID_USAGE_GENERIC_DIAL                  0x37
#define HID_USAGE_GENERIC_WHEEL                 0x38
#define HID_USAGE_GENERIC_HATSWITCH             0x39
#define HID_USAGE_GENERIC_COUNTED_BUFFER        0x3A
#define HID_USAGE_GENERIC_BYTE_COUNT            0x3B
#define HID_USAGE_GENERIC_MOTION_WAKEUP         0x3C
#define HID_USAGE_GENERIC_VX                    0x40
#define HID_USAGE_GENERIC_VY                    0x41
#define HID_USAGE_GENERIC_VZ                    0x42
#define HID_USAGE_GENERIC_VBRX                  0x43
#define HID_USAGE_GENERIC_VBRY                  0x44
#define HID_USAGE_GENERIC_VBRZ                  0x45
#define HID_USAGE_GENERIC_VNO                   0x46
#define HID_USAGE_GENERIC_SYSTEM_CTL            0x80
#define HID_USAGE_GENERIC_SYSCTL_POWER          0x81
#define HID_USAGE_GENERIC_SYSCTL_SLEEP          0x82
#define HID_USAGE_GENERIC_SYSCTL_WAKE           0x83
#define HID_USAGE_GENERIC_SYSCTL_CONTEXT_MENU   0x84
#define HID_USAGE_GENERIC_SYSCTL_MAIN_MENU      0x85
#define HID_USAGE_GENERIC_SYSCTL_APP_MENU       0x86
#define HID_USAGE_GENERIC_SYSCTL_HELP_MENU      0x87
#define HID_USAGE_GENERIC_SYSCTL_MENU_EXIT      0x88
#define HID_USAGE_GENERIC_SYSCTL_MENU_SELECT    0x89
#define HID_USAGE_GENERIC_SYSCTL_MENU_RIGHT     0x8A
#define HID_USAGE_GENERIC_SYSCTL_MENU_LEFT      0x8B
#define HID_USAGE_GENERIC_SYSCTL_MENU_UP        0x8C
#define HID_USAGE_GENERIC_SYSCTL_MENU_DOWN      0x8D

//Simulation Controls Page (0x02)
#define HID_USAGE_SIMULATION_RUDDER             0xBA
#define HID_USAGE_SIMULATION_THROTTLE           0xBB

//Error "keys" 
#define HID_USAGE_KEYBOARD_NOEVENT              0x00
#define HID_USAGE_KEYBOARD_ROLLOVER             0x01
#define HID_USAGE_KEYBOARD_POSTFAIL             0x02
#define HID_USAGE_KEYBOARD_UNDEFINED            0x03

//Letters
#define HID_USAGE_KEYBOARD_aA                   0x04
#define HID_USAGE_KEYBOARD_zZ                   0x1D

//Numbers
#define HID_USAGE_KEYBOARD_ONE                  0x1E
#define HID_USAGE_KEYBOARD_ZERO                 0x27

#define HID_USAGE_KEYBOARD_RETURN               0x28
#define HID_USAGE_KEYBOARD_ESCAPE               0x29
#define HID_USAGE_KEYBOARD_DELETE               0x2A

//Funtion keys 
#define HID_USAGE_KEYBOARD_F1                   0x3A
#define HID_USAGE_KEYBOARD_F12                  0x45

#define HID_USAGE_KEYBOARD_PRINT_SCREEN         0x46

//Modifier Keys
#define HID_USAGE_KEYBOARD_LCTRL                0xE0
#define HID_USAGE_KEYBOARD_LSHFT                0xE1
#define HID_USAGE_KEYBOARD_LALT                 0xE2
#define HID_USAGE_KEYBOARD_LGUI                 0xE3
#define HID_USAGE_KEYBOARD_RCTRL                0xE4
#define HID_USAGE_KEYBOARD_RSHFT                0xE5
#define HID_USAGE_KEYBOARD_RALT                 0xE6
#define HID_USAGE_KEYBOARD_RGUI                 0xE7
#define HID_USAGE_KEYBOARD_SCROLL_LOCK          0x47
#define HID_USAGE_KEYBOARD_NUM_LOCK             0x53
#define HID_USAGE_KEYBOARD_CAPS_LOCK            0x39

//LED Page (0x08)
#define HID_USAGE_LED_NUM_LOCK                  0x01
#define HID_USAGE_LED_CAPS_LOCK                 0x02
#define HID_USAGE_LED_SCROLL_LOCK               0x03
#define HID_USAGE_LED_COMPOSE                   0x04
#define HID_USAGE_LED_KANA                      0x05
#define HID_USAGE_LED_POWER                     0x06
#define HID_USAGE_LED_SHIFT                     0x07
#define HID_USAGE_LED_DO_NOT_DISTURB            0x08
#define HID_USAGE_LED_MUTE                      0x09
#define HID_USAGE_LED_TONE_ENABLE               0x0A
#define HID_USAGE_LED_HIGH_CUT_FILTER           0x0B
#define HID_USAGE_LED_LOW_CUT_FILTER            0x0C
#define HID_USAGE_LED_EQUALIZER_ENABLE          0x0D
#define HID_USAGE_LED_SOUND_FIELD_ON            0x0E
#define HID_USAGE_LED_SURROUND_FIELD_ON         0x0F
#define HID_USAGE_LED_REPEAT                    0x10
#define HID_USAGE_LED_STEREO                    0x11
#define HID_USAGE_LED_SAMPLING_RATE_DETECT      0x12
#define HID_USAGE_LED_SPINNING                  0x13
#define HID_USAGE_LED_CAV                       0x14
#define HID_USAGE_LED_CLV                       0x15
#define HID_USAGE_LED_RECORDING_FORMAT_DET      0x16
#define HID_USAGE_LED_OFF_HOOK                  0x17
#define HID_USAGE_LED_RING                      0x18
#define HID_USAGE_LED_MESSAGE_WAITING           0x19
#define HID_USAGE_LED_MESSAGE_WAITING           0x19
#define HID_USAGE_LED_DATA_MODE                 0x1A
#define HID_USAGE_LED_BATTERY_OPERATION         0x1B
#define HID_USAGE_LED_BATTERY_OK                0x1C
#define HID_USAGE_LED_BATTERY_LOW               0x1D
#define HID_USAGE_LED_SPEAKER                   0x1E
#define HID_USAGE_LED_HEAD_SET                  0x1F
#define HID_USAGE_LED_HOLD                      0x20
#define HID_USAGE_LED_MICROPHONE                0x21
#define HID_USAGE_LED_COVERAGE                  0x22
#define HID_USAGE_LED_NIGHT_MODE                0x23
#define HID_USAGE_LED_SEND_CALLS                0x24
#define HID_USAGE_LED_CALL_PICKUP               0x25
#define HID_USAGE_LED_CONFERENCE                0x26
#define HID_USAGE_LED_STAND_BY                  0x27
#define HID_USAGE_LED_CAMERA_ON                 0x28
#define HID_USAGE_LED_CAMERA_OFF                0x29
#define HID_USAGE_LED_ON_LINE                   0x2A
#define HID_USAGE_LED_OFF_LINE                  0x2B
#define HID_USAGE_LED_BUSY                      0x2C
#define HID_USAGE_LED_READY                     0x2D
#define HID_USAGE_LED_PAPER_OUT                 0x2E
#define HID_USAGE_LED_PAPER_JAM                 0x2F
#define HID_USAGE_LED_REMOTE                    0x30
#define HID_USAGE_LED_FORWARD                   0x31
#define HID_USAGE_LED_REVERSE                   0x32
#define HID_USAGE_LED_STOP                      0x33
#define HID_USAGE_LED_REWIND                    0x34
#define HID_USAGE_LED_FAST_FORWARD              0x35
#define HID_USAGE_LED_PLAY                      0x36
#define HID_USAGE_LED_PAUSE                     0x37
#define HID_USAGE_LED_RECORD                    0x38
#define HID_USAGE_LED_ERROR                     0x39
#define HID_USAGE_LED_SELECTED_INDICATOR        0x3A
#define HID_USAGE_LED_IN_USE_INDICATOR          0x3B
#define HID_USAGE_LED_MULTI_MODE_INDICATOR      0x3C
#define HID_USAGE_LED_INDICATOR_ON              0x3D
#define HID_USAGE_LED_INDICATOR_FLASH           0x3E
#define HID_USAGE_LED_INDICATOR_SLOW_BLINK      0x3F
#define HID_USAGE_LED_INDICATOR_FAST_BLINK      0x40
#define HID_USAGE_LED_INDICATOR_OFF             0x41
#define HID_USAGE_LED_FLASH_ON_TIME             0x42
#define HID_USAGE_LED_SLOW_BLINK_ON_TIME        0x43
#define HID_USAGE_LED_SLOW_BLINK_OFF_TIME       0x44
#define HID_USAGE_LED_FAST_BLINK_ON_TIME        0x45
#define HID_USAGE_LED_FAST_BLINK_OFF_TIME       0x46
#define HID_USAGE_LED_INDICATOR_COLOR           0x47
#define HID_USAGE_LED_RED                       0x48
#define HID_USAGE_LED_GREEN                     0x49
#define HID_USAGE_LED_AMBER                     0x4A
#define HID_USAGE_LED_GENERIC_INDICATOR         0x4B

//Telephony Device Page (0x0B) 
#define HID_USAGE_TELEPHONY_PHONE               0x01
#define HID_USAGE_TELEPHONY_ANSWERING_MACHINE   0x02
#define HID_USAGE_TELEPHONY_MESSAGE_CONTROLS    0x03
#define HID_USAGE_TELEPHONY_HANDSET             0x04
#define HID_USAGE_TELEPHONY_HEADSET             0x05
#define HID_USAGE_TELEPHONY_KEYPAD              0x06
#define HID_USAGE_TELEPHONY_PROGRAMMABLE_BUTTON 0x07

//Consumer Page (0x0C) 
#define HID_USAGE_CONSUMER_CONTROL              0x01

// HID Report Item Macros 
// Main Items
#define HID_Input(VALUE)            0x81,VALUE
#define HID_Output(VALUE)           0x91,VALUE 
#define HID_Feature(VALUE)          0xB1,VALUE
#define HID_Collection(VALUE)       0xA1,VALUE
#define HID_EndCollection           0xC0

//****************************
//Data (Input, Output, Feature) 
#define HID_Data                    0<<0
#define HID_Constant                1<<0
#define HID_Array                   0<<1
#define HID_Variable                1<<1
#define HID_Absolute                0<<2
#define HID_Relative                1<<2
#define HID_NoWrap                  0<<3
#define HID_Wrap                    1<<3
#define HID_Linear                  0<<4
#define HID_NonLinear               1<<4
#define HID_PreferredState          0<<5
#define HID_NoPreferred             1<<5
#define HID_NoNullPosition          0<<6
#define HID_NullState               1<<6
#define HID_NonVolatile             0<<7
#define HID_Volatile                1<<7

//Collection Data 
#define HID_Physical                0x00
#define HID_Application             0x01
#define HID_Logical                 0x02
#define HID_Report                  0x03
#define HID_NamedArray              0x04
#define HID_UsageSwitch             0x05
#define HID_UsageModifier           0x06

//****************************
//Global Items 
#define HID_UsagePage(VALUE)        0x05,VALUE
#define HID_UsagePageVendor(VALUE)  0x06,VALUE,0xFF
#define HID_LogicalMin(VALUE)       0x15,VALUE
#define HID_LogicalMinS(V_H,V_L)    0x16,V_L,V_H
#define HID_LogicalMax(VALUE)       0x25,VALUE
#define HID_LogicalMaxS(V_H,V_L)    0x26,V_L,V_H
#define HID_PhysicalMin(VALUE)      0x35,VALUE
#define HID_PhysicalMax(VALUE)      0x45,VALUE
#define HID_UnitExponent(VALUE)     0x55,VALUE
#define HID_Unit(VALUE)             0x65,VALUE
#define HID_ReportSize(VALUE)       0x75,VALUE
#define HID_ReportID(VALUE)         0x85,VALUE
#define HID_ReportCount(VALUE)      0x95,VALUE
#define HID_Push                    0xA0 
#define HID_Pop                     0xB0
 
//Local Items
#define HID_Usage(VALUE)            0x09,VALUE
#define HID_UsageS(DATA_H, DATA_L)  0x0A,DATA_L,DATA_H
#define HID_UsageMin(VALUE)         0x19,VALUE
#define HID_UsageMinS(VALUE)        0x1A,VALUE,0
#define HID_UsageMax(VALUE)         0x29,VALUE
#define HID_UsageMaxS(DATA_H, DATA_L) 0x2A,DATA_L,DATA_H

//USB处理相关常量
#define     DEVICE_DESCRIPTOR_TYPE              0x01
#define     CONFIGURATION_DESCRIPTOR_TYPE       0x02
#define     STRING_DESCRIPTOR_TYPE              0x03
#define     INTERFACE_DESCRIPTOR_TYPE           0x04
#define     ENDPOINT_DESCRIPTOR_TYPE            0x05

#define     DESCRIPTOR_UNKNOW_TYPE              0xff
#define     STRING_UNKNOW_INDEX                 0xfe
#define     DESCRIPTOR_DEVICE_TYPE              0x01
#define     DESCRIPTOR_CONFIGURATION_TYPE       0x02
#define     DESCRIPTOR_STRING_TYPE              0x03

#define     SELF_POWERED                        0xc0
#define     BUS_POWERED                         0x80
#define     REMOTE_WAKEUP                       0x20

#define     STATUS_DEVICE_TYPE                  0x00
#define     STATUS_INTERFACE_TYPE               0x01
#define     STATUS_ENDPOINT_TYPE                0x02
                                                
#define     DEVICE_NULL_STATUS                  0x0000
#define     DEVICE_SELFPOWER                    0x0001
#define     DEVICE_REMOTEWAKEUP                 0x0002
#define     INTERFACE_NULL_STATUS               0x0000
#define     ENDPOINT_HALT_STATUS                0x0001
#define     ENDPOINT_NULL_STATUS                0x0000
                                                
#define     iDEVICE_REMOTE_WAKEUP               0x0001
#define     ENDPOINT_HALT                       0x0000

//------------------------------------------------------------------;
//    HID Protocol Types
//------------------------------------------------------------------;
//standard request
#define STD_RQST_GET_STATUS            0x00
#define STD_RQST_CLEAR_FEATURE         0x01
#define STD_RQST_RSVD0                 0x02
#define STD_RQST_SET_FEATURE           0x03
#define STD_RQST_RSVD1                 0x04
#define STD_RQST_SET_ADDRESS           0x05
#define STD_RQST_GET_DESCRIPTOR        0x06
#define STD_RQST_SET_DESCRIPTOR        0x07
#define STD_RQST_GET_CONFIGURATION     0x08
#define STD_RQST_SET_CONFIGURATION     0x09
#define STD_RQST_GET_INTERFACE         0x0A
#define STD_RQST_SET_INTERFACE         0x0B
#define STD_RQST_SYNCH_FRAME           0x0C

// HID Request Codes
#define HID_GET_REPORT                 0x01   // Code for Get Report
#define HID_GET_IDLE                   0x02   // Code for Get Idle
#define HID_GET_PROTOCOL               0x03   // Code for Get Protocol
#define HID_SET_REPORT                 0x09   // Code for Set Report
#define HID_SET_IDLE                   0x0A   // Code for Set Idle
#define HID_SET_PROTOCOL               0x0B   // Code for Set Protocol

//Descriptor types
#define DSCR_TYPE_DEV                  0x01
#define DSCR_TYPE_CONFIGURATION        0x02
#define DSCR_TYPE_STRING               0x03
#define DSCR_TYPE_INTERFACE            0x04
#define DSCR_TYPE_ENDPOINT             0x05
#define DSCR_TYPE_DEV_QUALIFIER        0x06
#define DSCR_TYPE_OTHER_SPEED_CONFIG   0x07
#define DSCR_TYPE_INTERFACE_POWER      0x08 

// HID Descriptor Types
#define DSCR_TYPE_HID                  0x21   // HID Class Descriptor
#define DSCR_TYPE_HID_REPORT           0x22   // HID Report Descriptor

// Define device states
#define  DEV_ATTACHED        0x00      // Device is in Attached State
#define  DEV_POWERED         0x01      // Device is in Powered State
#define  DEV_DEFAULT         0x02      // Device is in Default State
#define  DEV_ADDRESS         0x03      // Device is in Addressed State
#define  DEV_CONFIGURED      0x04      // Device is in Configured State
#define  DEV_SUSPENDED       0x05      // Device is in Suspended State

// Define Endpoint States
#define  EP_IDLE             0x00      // This signifies Endpoint Idle State
#define  EP_TX               0x01      // Endpoint Transmit State
#define  EP_RX               0x02      // Endpoint Receive State
#define  EP_HALT             0x03      // Endpoint Halt State (return stalls)
// Endpoint Stall (send procedural stall next status phase)
#define  EP_STALL            0x04
// Endpoint Address (change FADDR during next status phase)
#define  EP_ADDRESS          0x05

#define     BOOT_PROTOCOL                       0
#define     REPORT_PROTOCOL                     1
                                                
#define     UsbSendBuffers                      0x01
                                                
#define     CTRL_INTERFACE                      0xFF
#define     INTERFACE0                          0x00
#define     INTERFACE1                          0x01
#define     INTERFACE2                          0x02		//20130826
                                                
#define     _Standard_                          0x00
#define     _Class_                             0x20
#define     _Vendor_                            0x40

//USB命令定义
#define     EP0_USBCMD_NONE                     0
#define     EP0_USBCMD_DEVICE_DESC              1
#define     EP0_USBCMD_CONFIG_DESC              2
#define     EP0_USBCMD_STRING0_DESC             3
#define     EP0_USBCMD_STRING1_DESC             4
#define     EP0_USBCMD_HID_DESC                 5
#define     EP0_USBCMD_HID_REPORT               6
#define     EP0_USBCMD_STRING2_DESC             7

//USB字符串相关定义
#define     USB_STRING_TYPE_ASCII               0x00
#define     USB_STRING_TYPE_UNICODE             0x80
#define     USB_STRING_LENGTH_MAX               30

//USB Descriptor Types
#define     USB_DEVICE_DESCRIPTOR_TYPE          0x01
#define     USB_CONFIGURATION_DESCRIPTOR_TYPE   0x02
#define     USB_STRING_DESCRIPTOR_TYPE          0x03
#define     USB_INTERFACE_DESCRIPTOR_TYPE       0x04
#define     USB_ENDPOINT_DESCRIPTOR_TYPE        0x05
#define     USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE 0x06
#define     USB_OTHER_SPEED_CONFIG_DESCRIPTOR_TYPE 0x07
#define     USB_INTERFACE_POWER_DESCRIPTOR_TYPE 0x08

//USB Device Classes
#define     USB_DEVICE_CLASS_RESERVED           0x00
#define     USB_DEVICE_CLASS_AUDIO              0x01
#define     USB_DEVICE_CLASS_COMMUNICATIONS     0x02
#define     USB_DEVICE_CLASS_HUMAN_INTERFACE    0x03
#define     USB_DEVICE_CLASS_MONITOR            0x04
#define     USB_DEVICE_CLASS_PHYSICAL_INTERFACE 0x05
#define     USB_DEVICE_CLASS_POWER              0x06
#define     USB_DEVICE_CLASS_PRINTER            0x07
#define     USB_DEVICE_CLASS_STORAGE            0x08
#define     USB_DEVICE_CLASS_HUB                0x09
#define     USB_DEVICE_CLASS_VENDOR_SPECIFIC    0xFF

//bmAttributes in Configuration Descriptor
#define     USB_CONFIG_POWERED_MASK             0xC0
#define     USB_CONFIG_BUS_POWERED              0x80
#define     USB_CONFIG_SELF_POWERED             0x40
#define     USB_CONFIG_REMOTE_WAKEUP            0x20

//bmAttributes in Endpoint Descriptor
#define     USB_ENDPOINT_TYPE_CONTROL           0x00
#define     USB_ENDPOINT_TYPE_ISOCHRONOUS       0x01
#define     USB_ENDPOINT_TYPE_BULK              0x02
#define     USB_ENDPOINT_TYPE_INTERRUPT         0x03

#define     USB_MAX_PACKET0                     0x08
#define     USB_MAX_PACKET0_MASK                0x07
#define     USB_DEVICE_DESC_SIZE                0x12
#define     USB_CONFIGUARTION_DESC_SIZE         0x09
#define     USB_STRING_DESC_SIZE                0x04
#define     USB_INTERFACE_DESC_SIZE             0x09
#define     HID_DESC_SIZE                       0x09
#define     USB_ENDPOINT_DESC_SIZE              0x07

#define     iUSB_DEFAULT_VID                    0xC2,0x32   // 0x32C2
#define     iUSB_DEFAULT_PID                    0x1B,0x00   // 0x001B
#define     BCD_USB_VERSION                     0x10,0x01   // USB 1.1 (0x0110)
#define     HID_VERSION                         0x10,0x01
#define	    BCD_DEVICE_NUMBER                   0x10,0x01   // 0x0110

//*****************************************************************************
#define	WORD(V_H,V_L)                           V_L, V_H

#define USB_CONFIG_POWER_MA(POWER_MA)           (POWER_MA / 2)
#define USB_ENDPOINT_IN(ENDPOINT_ADDR)          (ENDPOINT_ADDR | 0x80)
#define USB_ENDPOINT_OUT(ENDPOINT_ADDR)         (ENDPOINT_ADDR | 0x00)

#define REPORT0_SIZE			sizeof(HID_ReportDescriptor_Define)

//******************************************************************************
// 描述符定义表格
//******************************************************************************

unsigned char const HID_ReportDescriptor_Define[] = {
//HID REPORT//25byte
    HID_UsagePageVendor(0x0E),
    HID_Usage(0x01),
    HID_Collection(HID_Application),
      HID_Usage(0x02),
      HID_LogicalMin(0),
      HID_LogicalMaxS(0x00, 0xFF),
      HID_ReportSize(8),
      HID_ReportCount(32),
      HID_Input(HID_Data | HID_Variable | HID_Absolute),
      HID_Usage(0x02),
      HID_LogicalMin(0),
      HID_LogicalMaxS(0x00, 0xFF),
      HID_ReportSize(8),
      HID_ReportCount(32),
      HID_Output(HID_Data | HID_Variable | HID_Absolute),
    HID_EndCollection,
};

unsigned char const DeviceDesc[] = 
{
    USB_DEVICE_DESC_SIZE,                       //长度大小,0x12
    USB_DEVICE_DESCRIPTOR_TYPE,                 //描述符类型,0x01(设备描述符)
    BCD_USB_VERSION,                            //符合的USB版本规范,0x0110(USB1.1)
    0x00,                                       //Class code
    0x00,                                       //Subclass code
    0x00,                                       //Protocol code
    MAX_EP0_SIZE,                               //最大封包大小,64
    iUSB_DEFAULT_VID,                           //Vendor ID;
    iUSB_DEFAULT_PID,                           //Product ID;
    BCD_DEVICE_NUMBER,                          //以BCD表示设备发行的序列号,0x0110
    0x01,                                       //制造商的字符串描述索引
    0x02,                                       //产品的字符串描述索引
    0x00,                                       //设备序号的字符串描述符索引
    0x01                                        //配置数目
};

const unsigned char ManuStringDesc[] @0x0F00 =
{
	10,
	0X03,
	'B',0,'Y',0,'C',0,'X',0,
};
// Gaming keyboard
const unsigned char SerialNumberStringDesc[] @0x0F10 = 
{
    30,0x03,
	'B',0,'Y',0,'C',0,'-',0,'B',0,'o',0,
	'o',0,'t',0,'L',0,'o',0,'a',0,'d',0,'e',0,'r',0,
};

unsigned char const ConfigurationDesc[] = {
//CONFIGURATION(9 bytes)
    USB_CONFIGUARTION_DESC_SIZE,                //bLength,9bytes.
    USB_CONFIGURATION_DESCRIPTOR_TYPE,          //Descriptor type,0x02(配置描述符)
    34,0x00,                                    //描述符总长度
    0x01,                                       //bNumInterface,0x02(接口数目)				//20130826
    0x01,                                       //bConfigurationValue
    0x00,                                       //iConfiguration
    0xA0,                                       //bmAttributes,(USB_CONFIG_BUS_POWERED|USB_CONFIG_REMOTE_WAKEUP)
    USB_CONFIG_POWER_MA(100),                   //bMaxPower,100mA

//----------------------------------------------
//Keyboard CONFIGURATION
//INTERFACE(9 bytes)
    USB_INTERFACE_DESC_SIZE,                    //bLength,9bytes
    USB_INTERFACE_DESCRIPTOR_TYPE,              //Descriptor type,0x04(接口描述符)
    0x00,                                       //bInterfaceNumber
    0x00,                                       //bAlternateSetting
    0x01,                                       //bNumEndpoints,0x01(端点数目)
    USB_DEVICE_CLASS_HUMAN_INTERFACE,           //bInterfaceClass,接口群组,USB规定HID码为0x03
    HID_SUBCLASS_BOOT,                          //bInterfaceSubClass,接口次群组,为0x01
    HID_PROTOCOL_KEYBOARD,                      //bInterfaceProtocol
    0x00,                                       //iInterface,接口字符串描述符的索引

//HID(9 bytes)
    HID_DESC_SIZE,                              //bLength,9bytes
    HID_HID_DESCRIPTOR_TYPE,                    //Descriptor type,0x21(HID描述符)
    HID_VERSION,                                //bcdHID
    0x00,                                       //bCountryCode(没有就设为0)
    0x01,                                       //bNumDescriptors,需遵循的HID群组报告的数目
    HID_REPORT_DESCRIPTOR_TYPE,                 //bDescriptorType,0x22(报告描述符).
    REPORT0_SIZE,0x00,                          //wDescriptorLength,报告描述符的长度

//ENDPOINT(7 bytes)
    USB_ENDPOINT_DESC_SIZE,                     //bLength,7bytes
    USB_ENDPOINT_DESCRIPTOR_TYPE,               //Descriptor type,0x05(端点描述符)
    USB_ENDPOINT_IN(1),                         //bEndpointAddress
    USB_ENDPOINT_TYPE_INTERRUPT,                //bmAttributes,传输的特性(中断传输)
    32, 0x00,                                   //wMaxPacketSize,0x08(最大封包)
    0x01,                                       //bInterval,轮询时间(1ms/unit)..
};

unsigned char const DeviceHidDescriptor_KB[]={
    HID_DESC_SIZE,                              //bLength,9bytes
    HID_HID_DESCRIPTOR_TYPE,                    //Descriptor type,0x21(HID描述符)
    HID_VERSION,                                //bcdHID
    0x00,                                       //bCountryCode(没有就设为0)
    0x01,                                       //bNumDescriptors,需遵循的HID群组报告的数目
    HID_REPORT_DESCRIPTOR_TYPE,                 //bDescriptorType,0x22(报告描述符).
    REPORT0_SIZE,0x00,                          //wDescriptorLength,报告描述符的长度
};

//LANGIDs Descriptor
const unsigned char LanguageIDDesc[] = 
{
    USB_STRING_DESC_SIZE,                       //bLength
    USB_STRING_DESCRIPTOR_TYPE,                 //bDescriptorType
    0x09,0x04,                                  //wLANGID,US English
};
//
//----------------------------------------------------------------------------;

unsigned char DeviceDescSize=sizeof(DeviceDesc);
unsigned char LanguageIDDescSize=sizeof(LanguageIDDesc);
unsigned char ManuStringDescSize=sizeof(ManuStringDesc);
unsigned char SerialNumberStringDescSize=sizeof(SerialNumberStringDesc);
unsigned char ConfigurationDescSize=sizeof(ConfigurationDesc);

unsigned char KeyboardReportDescSize=sizeof(HID_ReportDescriptor_Define);
