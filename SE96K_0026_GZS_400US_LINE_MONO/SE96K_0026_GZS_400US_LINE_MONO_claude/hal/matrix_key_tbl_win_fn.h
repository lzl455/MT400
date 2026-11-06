/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: _MATRIX_KEY_TBL_
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#ifndef _matrix_key_tbl_win_fn_
#define _matrix_key_tbl_win_fn_

//=============================================================================;
// 配置引用区
//=============================================================================;

//-----------------------------------------------------------------------------;
//配置常量定义区
//

//-----------------------------------------------------------------------------;
//配置区
//

// WIN FN键值表
unsigned char           const   matrixkey_win_fn_tbl[] =
{
//---------------------------------------------- 0x00
// C0
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iLEFT_CTRL,
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iLEFT_SHIFT,
    iSTD_CAPITAL,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_TAB,       iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_WAVE,      iKEY_TYPE_STD|iKEY_PRESS,
    iKEY_FN_LOCK,   iKEY_TYPE_SPECIAL, 
// C1
    iKEY_WIN_LOCK,  iKEY_TYPE_SPECIAL, 
    iSTD_QUROPE2,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_A,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_Q,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_01,   iKEY_TYPE_SPECIAL,
    iSTD_NULL,      iKEY_TYPE_INVALID,
// C2
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iLEFT_ALT,
    iSTD_Z,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_S,         iKEY_TYPE_STD|iKEY_PRESS,
    iKEY_DIR_WASD,  iKEY_TYPE_SPECIAL,
    iLED_MODE_02,   iKEY_TYPE_SPECIAL,
    iMMK_MEDIA_SELECT_L, iKEY_TYPE_MMK|iMMK_MEDIA_SELECT_H,
// C3
    iSTD_NUMPAD_ENTER,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_X,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_D,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_E,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_03,   iKEY_TYPE_SPECIAL,
    iMMK_VOLUMEDOWN_L,       iKEY_TYPE_MMK|iMMK_VOLUMEDOWN_H,
// C4
    iSTD_NUMPAD_ADD,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_C,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_F,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_R,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_04,   iKEY_TYPE_SPECIAL,
    iMMK_VOLUMEUP_L,         iKEY_TYPE_MMK|iMMK_VOLUMEUP_H,
// C5
    iSTD_NUMPAD_SUBTRACT,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_V,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_G,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_T,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_05,   iKEY_TYPE_SPECIAL,
    iMMK_MUTE_L,       iKEY_TYPE_MMK| iMMK_MUTE_H,
// C6
    iLED_MODE_RST,  iKEY_TYPE_SPECIAL,
    iSTD_B,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_H,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_Y,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_06,   iKEY_TYPE_SPECIAL,
    iMMK_STOP_L,       iKEY_TYPE_MMK|iMMK_STOP_H,
// C7
    iSTD_NULL,      iKEY_TYPE_INVALID,
    iSTD_N,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_J,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_U,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_07,   iKEY_TYPE_SPECIAL,
    iMMK_PREV_TRACK_L,      iKEY_TYPE_MMK| iMMK_PREV_TRACK_H,
// C8
    iSTD_K,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_M,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_K,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_I,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_08,   iKEY_TYPE_SPECIAL,
    iMMK_PLAY_PAUSE_L,     iKEY_TYPE_MMK| iMMK_PLAY_PAUSE_H,
// C9
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iRIGHT_ALT,
    iSTD_COMMA,     iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_L,         iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_O,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_09,   iKEY_TYPE_SPECIAL,
    iMMK_NEXT_TRACK_L,     iKEY_TYPE_MMK| iMMK_NEXT_TRACK_H,
// C10
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iRIGHT_ALT,
    iSTD_FULLSTOP,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_SEMICOLON, iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_P,         iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_0,   iKEY_TYPE_SPECIAL,
    iMMK_MAIL_L,   iKEY_TYPE_MMK| iMMK_MAIL_H,
// C11
    iMODE_KEY_FN,   iKEY_TYPE_SPECIAL,
    iSTD_SLASH,     iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_QUOTATION_SIGN, iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_SQUARE_BRACKET_LEFT, iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_SUBTRACT,  iKEY_TYPE_STD|iKEY_PRESS,
    iMMK_WWW_HOME_L,   iKEY_TYPE_MMK| iMMK_WWW_HOME_H,
// C12
    iSTD_APP,       iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iRIGHT_SHIFT,
    iSTD_BACKSLASH,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_SQUARE_BRACKET_RIGHT, iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_ADD,       iKEY_TYPE_STD|iKEY_PRESS,
    iMMK_MY_COMPUTER_L,    iKEY_TYPE_MMK| iMMK_MY_COMPUTER_H,
// C13
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iRIGHT_CTRL,
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS|iRIGHT_SHIFT,
    iSTD_RETURN,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_BACKSLASH, iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_BACKSPACE, iKEY_TYPE_STD|iKEY_PRESS,
    iMMK_CALCULATOR_L,     iKEY_TYPE_MMK|iMMK_CALCULATOR_H,
// C14
    iLED_SPEED_SUB, iKEY_TYPE_SPECIAL,
    iSTD_NUMPAD1,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD4,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_DELETE,    iKEY_TYPE_STD|iKEY_PRESS,
    iLED_MODE_CYC_ADD,   iKEY_TYPE_SPECIAL,
    iSTD_SNAPSHOT,  iKEY_TYPE_STD|iKEY_PRESS,
// C15
    iLED_BRIGHT_SUB, iKEY_TYPE_SPECIAL,
    iLED_BRIGHT_ADD, iKEY_TYPE_SPECIAL,
    iSTD_NUMPAD5,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_END,       iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_HOME,      iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_SCROLL,    iKEY_TYPE_STD|iKEY_PRESS,
// C16
    iLED_SPEED_ADD, iKEY_TYPE_SPECIAL,
    iSTD_NUMPAD3,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD6,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_PAGEDOWN,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_PAGEUP,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_PAUSE,     iKEY_TYPE_STD|iKEY_PRESS,
// C17
    iSTD_NUMPAD0,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD1,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD4,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD7,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMLOCK,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,     iKEY_TYPE_STD|iKEY_PRESS,
// C18
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD2,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD5,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD8,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD_DIVIDE,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,     iKEY_TYPE_STD|iKEY_PRESS,
// C19
    iSTD_NUMPAD_FULLSTOP,     iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD3,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD6,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD9,  iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NUMPAD_MULTIPLY,    iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,     iKEY_TYPE_STD|iKEY_PRESS,
// C20
    iSTD_NULL,      iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,      iKEY_TYPE_INVALID,
    iSTD_NULL,   iKEY_TYPE_STD|iKEY_PRESS,
    iSTD_NULL,      iKEY_TYPE_INVALID,
    iSTD_NULL,      iKEY_TYPE_INVALID,
    iSTD_NULL,     iKEY_TYPE_STD|iKEY_PRESS,
};
//-----------------------------------------------------------------------------;
#endif
