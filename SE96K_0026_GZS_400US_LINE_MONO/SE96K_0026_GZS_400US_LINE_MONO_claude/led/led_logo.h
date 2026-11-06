/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: led.h
*
* 功能说明:
* 修改说明:
*******************************************************************************/
#ifndef _LED_LOGO_H_
#define _LED_LOGO_H_

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;
#define iLFSR_MULTINOMIAL       0xF521

//-----------------------------------------------------------------------------;
// 配置常量定义区
//
#define iPWM_MAX                128

#define iLED_COL_NUM            21
#define iLED_ROW_NUM        	6
#define iLED_BACK_MAX         	(iLED_COL_NUM*iLED_ROW_NUM)
#define iLED_ALL_MAX         	(iLED_COL_NUM*iLED_ROW_NUM)

#define iLED_INDEX_WIN          (iR*3 + 2)    // S
#define iLED_INDEX_MAC          (iR*3 + 1)    // A

#define iMODE_HINT_TIME         (3000/20)

//-----------------------------------------------------------------------------;
//配置区
//
#define PWM_C0_LOW              PB7=0
#define PWM_C1_LOW              PC0=0
#define PWM_C2_LOW              PC1=0
#define PWM_C3_LOW              PC2=0
#define PWM_C4_LOW              PC3=0
#define PWM_C5_LOW              PC4=0
#define PWM_C6_LOW              PC5=0
#define PWM_C7_LOW              PC6=0
#define PWM_C8_LOW              PC7=0
#define PWM_C9_LOW              PD0=0
#define PWM_C10_LOW             PD1=0
#define PWM_C11_LOW             PD2=0
#define PWM_C12_LOW             PD3=0
#define PWM_C13_LOW             PD4=0
#define PWM_C14_LOW             PB6=0
#define PWM_C15_LOW             PB5=0
#define PWM_C16_LOW             PB4=0
#define PWM_C17_LOW             PB3=0
#define PWM_C18_LOW             PB2=0
#define PWM_C19_LOW             PB1=0
#define PWM_C20_LOW             PB0=0

#define PWM_C0_HIGH             PB7=1
#define PWM_C1_HIGH             PC0=1
#define PWM_C2_HIGH             PC1=1
#define PWM_C3_HIGH             PC2=1
#define PWM_C4_HIGH             PC3=1
#define PWM_C5_HIGH             PC4=1
#define PWM_C6_HIGH             PC5=1
#define PWM_C7_HIGH             PC6=1
#define PWM_C8_HIGH             PC7=1
#define PWM_C9_HIGH             PD0=1
#define PWM_C10_HIGH            PD1=1
#define PWM_C11_HIGH            PD2=1
#define PWM_C12_HIGH            PD3=1
#define PWM_C13_HIGH            PD4=1
#define PWM_C14_HIGH            PB6=1
#define PWM_C15_HIGH            PB5=1
#define PWM_C16_HIGH            PB4=1
#define PWM_C17_HIGH            PB3=1
#define PWM_C18_HIGH            PB2=1
#define PWM_C19_HIGH            PB1=1
#define PWM_C20_HIGH            PB0=1

#define LED_NUM_PIN             PF4
#define LED_CAPS_PIN            PF5
#define LED_SCROLL_PIN          PF6
#define LED_WIN_LOCK_PIN        PF7

//-----------------------------------------------------------------------------;
// 配置区
//
enum led_mod
{
    iMODE_LED_INVALID   =0,
    iMODE_LED_OFF       =1,
    iMODE_LED_BREATH    =2,                     // 呼吸
    iMODE_LED_XLBH      =3,                     // 斜拉变换
    iMODE_LED_LG_L_R    =4,                     // 随波逐流 左右
    iMODE_LED_ZXB       =5,                    // 正玄波
    iMODE_LED_17        =6,                    // 波涛汹涌 由下往上
    iMODE_LED_CENTRE    =7,                     // 中心
    iMODE_LED_ON        =8,                     // 常亮
    iMODE_LED_SNAKE     =9,                     // 蛇形跑马
    iMODE_LED_SNAKE_1   =10,                     // 蛇形跑马
    iMODE_LED_SNAKE_2   =11,                     // 蛇形跑马
    iMODE_LED_ROLLING   =12,                     // 滚动
    iMODE_LED_SINGLE    =13,                     // 踏雪无痕
    iMODE_LED_LG_U_D    =14,                    // 随波逐流 上下
    iMODE_LED_STAR      =15,                    // 繁星点点
    iMODE_LED_YZMB      =16,                    // 雨中漫步
    iMODE_LED_CHLP      =17,                    // 峰回路转
    iMODE_LED_BHQF      =18,                    // 微波粼粼
    iMODE_LED_ARROW     =19,                    // 箭头
    iMODE_LED_MAX       =20,                   
    iMODE_LED_DEF       =iMODE_LED_BREATH,                   

    
};
enum led_level
{
    iLED_LEV_MIN=0,// 最暗
    iLED_LEV_0 = 0,
    iLED_LEV_1 = 1,
    iLED_LEV_2 = 2,
    iLED_LEV_3 = 3,
    iLED_LEV_4 = 4,
    iLED_LEV_MAX = 4,	// 最亮
    iLED_LEV_MAX_LVD = 2,// 最亮
};

enum speed_level
{
    iSPEED_LEV_MIN = 0,
    iSPEED_LEV_1 = 0,
    iSPEED_LEV_2 = 1,
    iSPEED_LEV_3 = 2,
    iSPEED_LEV_4 = 3,
    iSPEED_LEV_5 = 4,
    iSPEED_LEV_MAX = 4,
};

//=============================================================================;
// 外部定义内部引用区                                                          ;
//=============================================================================;

//-----------------------------------------------------------------------------;
// 外部寄存器引用
//
//-----------------------------------------------------------------------------;
// 外部函数引用
//
extern unsigned char    const   led_liuguang_l_r_tbl[];
extern unsigned char    const   led_liuguang_u_d_tbl[];

//=============================================================================;
// 内部定义外部引用区      
//=============================================================================;

//-----------------------------------------------------------------------------;
// 寄存器引用
//
extern USBD_U16                 uled_ctrl_reg;
//{
    #define led_ctrl_reg        uled_ctrl_reg.u16

    #define bsave_flash_bak     uled_ctrl_reg.BIT.b15
    #define bled_hint_ing       uled_ctrl_reg.BIT.b13
    #define bled_mode_def       uled_ctrl_reg.BIT.b12

    #define bled_run_dir        uled_ctrl_reg.BIT.b11 // 方向：0：左→右；1：右→左；
    #define bled_def_rec        uled_ctrl_reg.BIT.b10
    #define bled_dir_status     uled_ctrl_reg.BIT.b9

    #define bsave_flash         uled_ctrl_reg.BIT.b8
    #define bsave_led           uled_ctrl_reg.BIT.b7

    #define bdelay_time         uled_ctrl_reg.BIT.b6
    #define bled_mode_jg        uled_ctrl_reg.BIT.b5
    #define bmode_swtich_hint   uled_ctrl_reg.BIT.b4
    #define bback_led_off       uled_ctrl_reg.BIT.b3
    #define bled_mode_single    uled_ctrl_reg.BIT.b2
    #define bback_led_status    uled_ctrl_reg.BIT.b0
//}
extern USBD_U16                 uled_status_reg;
//{
    #define led_status_reg      uled_status_reg.u16
    #define bled15_status       uled_status_reg.BIT.b15
    #define bled14_status       uled_status_reg.BIT.b14
    #define bled13_status       uled_status_reg.BIT.b13
    #define bled12_status       uled_status_reg.BIT.b12
    #define bled11_status       uled_status_reg.BIT.b11
    #define bled10_status       uled_status_reg.BIT.b10
    #define bled9_status        uled_status_reg.BIT.b9
    #define bled8_status        uled_status_reg.BIT.b8
    #define bled7_status        uled_status_reg.BIT.b7
    #define bled6_status        uled_status_reg.BIT.b6
    #define bled5_status        uled_status_reg.BIT.b5
    #define bled4_status        uled_status_reg.BIT.b4
    #define bled3_status        uled_status_reg.BIT.b3
    #define bled2_status        uled_status_reg.BIT.b2
    #define bled1_status        uled_status_reg.BIT.b1
    #define bled0_status        uled_status_reg.BIT.b0
//}
extern USBD_U8                  uled_status_reg_ex;
//{
    #define led_status_reg_ex   uled_status_reg_ex.u8

    #define bled18_status       uled_status_reg_ex.BIT.b2
    #define bled17_status       uled_status_reg_ex.BIT.b1
    #define bled16_status       uled_status_reg_ex.BIT.b0
//}

extern unsigned char            pwm_time_count;
extern unsigned int             delay_time_count;

extern enum led_mod             led_cur_mode;
extern enum led_mod             led_pre_mode;
extern enum led_level           led_light_lev;
extern enum speed_level         led_speed_lev;
extern unsigned char            led_index_value;
extern unsigned char            led_scan_count;

extern unsigned char            pwm_duty_array[];

extern unsigned char            pwm_duty_array_0[];
extern unsigned char            pwm_duty_array_1[];
extern unsigned char            pwm_duty_array_2[];
extern unsigned char            pwm_duty_array_3[];

extern unsigned char            pwm_duty_array_x[];
extern unsigned char            pwm_duty_array_y[];

extern unsigned char            snake_led_index;
extern unsigned char            rolling_led_index;
extern unsigned int             lfsr_value;
extern unsigned char            led_index0;
extern unsigned char            snake_led_index0;
extern unsigned char            gtemp_jg;
extern unsigned char            scan_index;
extern unsigned int             hint_time_count;

extern unsigned char            back_led_off_delay;
extern unsigned char            save_flash_delay;
extern unsigned char            led_def_index;
extern unsigned char            led_def_dat_tbl[];

extern unsigned char    const   led_snake_table[];
extern unsigned char    const   led_to_matrix_tab_1[];
extern unsigned char    const   sbzl_ctrl_tbl[];
extern unsigned char    const   chlp_r_tbl[];
extern unsigned char    const   chlp_g_tbl[];
extern unsigned char    const   chlp_b_tbl[];
extern unsigned char    const   chlp_ctrl_tbl[];
extern unsigned char    const   led_to_matrix_tab_2[iLED_COL_NUM][iLED_ROW_NUM];
extern unsigned char    const   led_to_matrix_tab_0[iLED_ROW_NUM][iLED_COL_NUM];
extern unsigned char    const   matrix_to_led_tab[];
extern unsigned char    const   led_to_matrix_tab_3[];
extern unsigned char    const   led_to_matrix_tab_down_up[];
extern unsigned char    const   led_def_tbl[];
extern unsigned char    const   led_to_matrix_tab_14_14[];

//-----------------------------------------------------------------------------;
// 函数引用
//

/*******************************************************************************
 led_process: 
*******************************************************************************/

extern void led_hint(void);
extern void pwm2_init(void);
extern void pwm_driver_set(void);
extern void led_ctrl_check(void);
extern void led_process(void);
extern void device_led_off(void);
extern void clr_led_data(void);

extern void clr_led(void);
extern void set_led(void);

extern void led_mode_on(void);
extern void led_mode_breath(void);
extern void led_mode_snake(void);
extern void led_mode_single(void);
extern void led_mode_snake_1(void);
extern void led_mode_snake_2(void);
extern void led_mode_xilabianhuan(void);

extern void led_mode_roling(void);
extern void led_mode_liuguang_l_r(void);
extern void led_mode_liuguang_u_d(void);
extern void led_mode_star(void);
extern void led_mode_wasd(void);

extern void led_mode_zxb(void);
extern void led_mode_yzmb(void);
extern void led_mode_chlp(void);
extern void led_mode_bhqf(void);

extern void led_mode_12(void);
extern void led_mode_17(void);
extern void led_mode_18(void);

extern void led_mode_jg_init(unsigned char led_c);
extern void led_mode_jiguang(void);

extern void led_mode_bolang(void);
extern void led_mode_arrow(void);
extern void led_mode_centre(void);
extern void led_mode_def(void);

extern void bevel_process(void);
extern void left_right_process(void);
extern void ripple_process(void);
extern void led_def_save(void);

extern void timer_int_process(void);
//
//-----------------------------------------------------------------------------;
#endif
