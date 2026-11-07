#ifndef	_HTC_H_
#warning Header file m9f951.h included directly. Use #include <zc.h> instead.
#endif


#ifndef _M9F951_H_
#define _M9F951_H_

/*
 * Register Definitions
 */
extern volatile unsigned char           WDTOCC              @ 0x008;
extern volatile unsigned char           PWM121DL            @ 0xE7E;
extern volatile unsigned char           PWM121DH            @ 0xE7F;
extern volatile unsigned char           PWM120DL            @ 0xE80;
extern volatile unsigned char           PWM120DH            @ 0xE81;
extern volatile unsigned char           PWM119DL            @ 0xE82;
extern volatile unsigned char           PWM119DH            @ 0xE83;
extern volatile unsigned char           PWM118DL            @ 0xE84;
extern volatile unsigned char           PWM118DH            @ 0xE85;
extern volatile unsigned char           PWM117DL            @ 0xE86;
extern volatile unsigned char           PWM117DH            @ 0xE87;
extern volatile unsigned char           PWM116DL            @ 0xE88;
extern volatile unsigned char           PWM116DH            @ 0xE89;
extern volatile unsigned char           PWM115DL            @ 0xE8A;
extern volatile unsigned char           PWM115DH            @ 0xE8B;
extern volatile unsigned char           PWM114DL            @ 0xE8C;
extern volatile unsigned char           PWM114DH            @ 0xE8D;
extern volatile unsigned char           PWM113DL            @ 0xE8E;
extern volatile unsigned char           PWM113DH            @ 0xE8F;
extern volatile unsigned char           PWM112DL            @ 0xE90;
extern volatile unsigned char           PWM112DH            @ 0xE91;
extern volatile unsigned char           PWM111DL            @ 0xE92;
extern volatile unsigned char           PWM111DH            @ 0xE93;
extern volatile unsigned char           PWM110DL            @ 0xE94;
extern volatile unsigned char           PWM110DH            @ 0xE95;
extern volatile unsigned char           PWM109DL            @ 0xE96;
extern volatile unsigned char           PWM109DH            @ 0xE97;
extern volatile unsigned char           PWM108DL            @ 0xE98;
extern volatile unsigned char           PWM108DH            @ 0xE99;
extern volatile unsigned char           PWM107DL            @ 0xE9A;
extern volatile unsigned char           PWM107DH            @ 0xE9B;
extern volatile unsigned char           PWM106DL            @ 0xE9C;
extern volatile unsigned char           PWM106DH            @ 0xE9D;
extern volatile unsigned char           PWM105DL            @ 0xE9E;
extern volatile unsigned char           PWM105DH            @ 0xE9F;
extern volatile unsigned char           PWM104DL            @ 0xEA0;
extern volatile unsigned char           PWM104DH            @ 0xEA1;
extern volatile unsigned char           PWM103DL            @ 0xEA2;
extern volatile unsigned char           PWM103DH            @ 0xEA3;
extern volatile unsigned char           PWM102DL            @ 0xEA4;
extern volatile unsigned char           PWM102DH            @ 0xEA5;
extern volatile unsigned char           PWM101DL            @ 0xEA6;
extern volatile unsigned char           PWM101DH            @ 0xEA7;
extern volatile unsigned char           PWM100DL            @ 0xEA8;
extern volatile unsigned char           PWM100DH            @ 0xEA9;
extern volatile unsigned char           PWM121CR            @ 0xEAA;
extern volatile unsigned char           PWM120CR            @ 0xEAB;
extern volatile unsigned char           PWM119CR            @ 0xEAC;
extern volatile unsigned char           PWM118CR            @ 0xEAD;
extern volatile unsigned char           PWM117CR            @ 0xEAE;
extern volatile unsigned char           PWM116CR            @ 0xEAF;
extern volatile unsigned char           PWM115CR            @ 0xEB0;
extern volatile unsigned char           PWM114CR            @ 0xEB1;
extern volatile unsigned char           PWM113CR            @ 0xEB2;
extern volatile unsigned char           PWM112CR            @ 0xEB3;
extern volatile unsigned char           PWM111CR            @ 0xEB4;
extern volatile unsigned char           PWM110CR            @ 0xEB5;
extern volatile unsigned char           PWM109CR            @ 0xEB6;
extern volatile unsigned char           PWM108CR            @ 0xEB7;
extern volatile unsigned char           PWM107CR            @ 0xEB8;
extern volatile unsigned char           PWM106CR            @ 0xEB9;
extern volatile unsigned char           PWM105CR            @ 0xEBA;
extern volatile unsigned char           PWM104CR            @ 0xEBB;
extern volatile unsigned char           PWM103CR            @ 0xEBC;
extern volatile unsigned char           PWM102CR            @ 0xEBD;
extern volatile unsigned char           PWM101CR            @ 0xEBE;
extern volatile unsigned char           PWM100CR            @ 0xEBF;

extern volatile unsigned char            CMPC2              @ 0xEDD;
extern volatile unsigned char            CMPC1              @ 0xEDE;
extern volatile unsigned char            CMPC0              @ 0xEDF;
extern volatile unsigned char           PWM2PRL             @ 0xEE4;
extern volatile unsigned char           PWM2PRH             @ 0xEE5;
extern volatile unsigned char           PWM2OE              @ 0xEE6;
extern volatile unsigned char           PWM2CR0             @ 0xEE7;
extern volatile unsigned char           PWM2_2NL            @ 0xEE8;
extern volatile unsigned char           PWM2_2NH            @ 0xEE9;
extern volatile unsigned char           PWM2_1NL            @ 0xEEA;
extern volatile unsigned char           PWM2_1NH            @ 0xEEB;
extern volatile unsigned char           PWM2_0NL            @ 0xEEC;
extern volatile unsigned char           PWM2_0NH            @ 0xEED;
extern volatile unsigned char           PWM2_2PL            @ 0xEEE;
extern volatile unsigned char           PWM2_2PH            @ 0xEEF;
extern volatile unsigned char           PWM2_1PL            @ 0xEF0;
extern volatile unsigned char           PWM2_1PH            @ 0xEF1;
extern volatile unsigned char           PWM2_0PL            @ 0xEF2;
extern volatile unsigned char           PWM2_0PH            @ 0xEF3;
extern volatile unsigned char           PWM2RLDEN           @ 0xEF4;
extern volatile unsigned char           PWM2INTF            @ 0xEF5;
extern volatile unsigned char           PWM2INTCR           @ 0xEF6;
extern volatile unsigned char           FLTCR               @ 0xEF7;
extern volatile unsigned char           PWM2DT1L            @ 0xEF8;
extern volatile unsigned char           PWM2DT1H            @ 0xEF9;
extern volatile unsigned char           PWM2DT0L            @ 0xEFA;
extern volatile unsigned char           PWM2DT0H            @ 0xEFB;
extern volatile unsigned char           PMANUALCR1          @ 0xEFC;
extern volatile unsigned char           PMANUALCR0          @ 0xEFD;
extern volatile unsigned char           PWM2CR2             @ 0xEFE;
extern volatile unsigned char           PWM2CR1             @ 0xEFF;
extern volatile unsigned char           WDTCR               @ 0xF08;
extern volatile unsigned char           CALLOCK             @ 0xF09;
extern volatile unsigned char           IRCCAH              @ 0xF0E;
extern volatile unsigned char           IRCCAL              @ 0xF0F;
extern volatile unsigned char           I2C1SR              @ 0xF14;
extern volatile unsigned char           I2C1DBUF            @ 0xF15;
extern volatile unsigned char           I2C1PRESC           @ 0xF16;
extern volatile unsigned char           I2C1OAR             @ 0xF17;
extern volatile unsigned char           I2C1CR2             @ 0xF18;
extern volatile unsigned char           I2C1CR1             @ 0xF19;
extern volatile unsigned char           RX1REG              @ 0xF1A;
extern volatile unsigned char           TX1REG              @ 0xF1B;
extern volatile unsigned char           BRGD1L              @ 0xF1C;
extern volatile unsigned char           BRGD1H              @ 0xF1D;
extern volatile unsigned char           RX1CR               @ 0xF1E;
extern volatile unsigned char           TX1CR               @ 0xF1F;
extern volatile unsigned char           IOFIPS1             @ 0xF28;
extern volatile unsigned char           IOEIPS1             @ 0xF29;
extern volatile unsigned char           IODIPS1             @ 0xF2A;
extern volatile unsigned char           IOCIPS1             @ 0xF2B;
extern volatile unsigned char           IOBIPS1             @ 0xF2C;
extern volatile unsigned char           IOAIPS1             @ 0xF2D;
extern volatile unsigned char           IOFODS1             @ 0xF31;
extern volatile unsigned char           IOEODS1             @ 0xF32;
extern volatile unsigned char           IODODS1             @ 0xF33;
extern volatile unsigned char           IOCODS1             @ 0xF34;
extern volatile unsigned char           IOBODS1             @ 0xF35;
extern volatile unsigned char           IOAODS1             @ 0xF36;
extern volatile unsigned char           IOFODS0             @ 0xF3A;
extern volatile unsigned char           IOEODS0             @ 0xF3B;
extern volatile unsigned char           IODODS0             @ 0xF3C;
extern volatile unsigned char           IOCODS0             @ 0xF3D;
extern volatile unsigned char           IOBODS0             @ 0xF3E;
extern volatile unsigned char           IOAODS0             @ 0xF3F;
extern volatile unsigned char           IOFICR              @ 0xF48;
extern volatile unsigned char           IOEICR              @ 0xF49;
extern volatile unsigned char           IODICR              @ 0xF4A;
extern volatile unsigned char           IOCICR              @ 0xF4B;
extern volatile unsigned char           IOBICR              @ 0xF4C;
extern volatile unsigned char           IOAICR              @ 0xF4D;
extern volatile unsigned char           PDF                 @ 0xF51;
extern volatile unsigned char           PDE                 @ 0xF52;
extern volatile unsigned char           PDD                 @ 0xF53;
extern volatile unsigned char           PDC                 @ 0xF54;
extern volatile unsigned char           PDB                 @ 0xF55;
extern volatile unsigned char           PDA                 @ 0xF56;
extern volatile unsigned char           PUF                 @ 0xF5A;
extern volatile unsigned char           PUE                 @ 0xF5B;
extern volatile unsigned char           PUD                 @ 0xF5C;
extern volatile unsigned char           PUC                 @ 0xF5D;
extern volatile unsigned char           PUB                 @ 0xF5E;
extern volatile unsigned char           PUA                 @ 0xF5F;
extern volatile unsigned char           UCLKCON             @ 0xF6B;
extern volatile unsigned char           UE5IOPS             @ 0xF6C;
extern volatile unsigned char           UE5CON              @ 0xF6D;
extern volatile unsigned char           UE4IOPS             @ 0xF6E;
extern volatile unsigned char           UE4CON              @ 0xF6F;
extern volatile unsigned char           UE3IOPS             @ 0xF70;
extern volatile unsigned char           UE3CON              @ 0xF71;
extern volatile unsigned char           UE2IOPS             @ 0xF72;
extern volatile unsigned char           UE2CON              @ 0xF73;
extern volatile unsigned char           UE1IOPS             @ 0xF74;
extern volatile unsigned char           UE1CON              @ 0xF75;
extern volatile unsigned char           UE0IOPS             @ 0xF76;
extern volatile unsigned char           UE0CON              @ 0xF77;
extern volatile unsigned char           UDADR               @ 0xF78;
extern volatile unsigned char           USBCON              @ 0xF79;
extern volatile unsigned char           I2C0SR              @ 0xF7A;
extern volatile unsigned char           I2C0DBUF            @ 0xF7B;
extern volatile unsigned char           I2C0PRESC           @ 0xF7C;
extern volatile unsigned char           I2C0OAR             @ 0xF7D;
extern volatile unsigned char           I2C0CR2             @ 0xF7E;
extern volatile unsigned char           I2C0CR1             @ 0xF7F;
extern volatile unsigned char           PCON                @ 0xF80;
extern volatile unsigned char           FLIPCR              @ 0xF81;
extern volatile unsigned char           RX0REG              @ 0xF8A;
extern volatile unsigned char           TX0REG              @ 0xF8B;
extern volatile unsigned char           BRGD0L              @ 0xF8C;
extern volatile unsigned char           BRGD0H              @ 0xF8D;
extern volatile unsigned char           RX0CR               @ 0xF8E;
extern volatile unsigned char           TX0CR               @ 0xF8F;
extern volatile unsigned char           TC2CL               @ 0xF90;
extern volatile unsigned char           TC2CH               @ 0xF91;
extern volatile unsigned char           TC2PRL              @ 0xF92;
extern volatile unsigned char           TC2PRH              @ 0xF93;
extern volatile unsigned char           TC2GCR              @ 0xF94;
extern volatile unsigned char           T2CR                @ 0xF95;
extern volatile unsigned char           TC1CL               @ 0xF96;
extern volatile unsigned char           TC1CH               @ 0xF97;
extern volatile unsigned char           TC1PRL              @ 0xF98;
extern volatile unsigned char           TC1PRH              @ 0xF99;
extern volatile unsigned char           T1CR                @ 0xF9A;
extern volatile unsigned char           PWM0D               @ 0xF9B;
extern volatile unsigned char           PWM0CR              @ 0xF9C;
extern volatile unsigned char           TC0CL               @ 0xF9D;
extern volatile unsigned char           TC0CH               @ 0xF9E;
extern volatile unsigned char           T0CR                @ 0xF9F;
extern volatile unsigned char           OSCM                @ 0xFA0;
extern volatile unsigned char           WDTC                @ 0xFA1;
extern volatile unsigned char           ADL                 @ 0xFA2;
extern volatile unsigned char           ADH                 @ 0xFA3;
extern volatile unsigned char           ADCON2              @ 0xFA5;
extern volatile unsigned char           ADCON1              @ 0xFA6;
extern volatile unsigned char           ADCON0              @ 0xFA7;
extern volatile unsigned char           ANSF                @ 0xFAB;
extern volatile unsigned char           ANSE                @ 0xFAC;
extern volatile unsigned char           ANSD                @ 0xFAD;
extern volatile unsigned char           ANSC                @ 0xFAE;
extern volatile unsigned char           ANSB                @ 0xFAF;
extern volatile unsigned char           ANSA                @ 0xFB0;
extern volatile unsigned char           IOFOR               @ 0xFB4;
extern volatile unsigned char           IOEOR               @ 0xFB5;
extern volatile unsigned char           IODOR               @ 0xFB6;
extern volatile unsigned char           IOCOR               @ 0xFB7;
extern volatile unsigned char           IOBOR               @ 0xFB8;
extern volatile unsigned char           IOAOR               @ 0xFB9;
extern volatile unsigned char           OEF                 @ 0xFBD;
extern volatile unsigned char           OEE                 @ 0xFBE;
extern volatile unsigned char           OED                 @ 0xFBF;
extern volatile unsigned char           OEC                 @ 0xFC0;
extern volatile unsigned char           OEB                 @ 0xFC1;
extern volatile unsigned char           OEA                 @ 0xFC2;
extern volatile unsigned char           IOF                 @ 0xFC6;
extern volatile unsigned char           IOE                 @ 0xFC7;
extern volatile unsigned char           IOD                 @ 0xFC8;
extern volatile unsigned char           IOC                 @ 0xFC9;
extern volatile unsigned char           IOB                 @ 0xFCA;
extern volatile unsigned char           IOA                 @ 0xFCB;
extern volatile unsigned char           UINTP               @ 0xFCC;
extern volatile unsigned char           INTP2               @ 0xFCD;
extern volatile unsigned char           INTP1               @ 0xFCE;
extern volatile unsigned char           INTP0               @ 0xFCF;
extern volatile unsigned char           INTF2               @ 0xFD1;
extern volatile unsigned char           INTF1               @ 0xFD2;
extern volatile unsigned char           INTF0               @ 0xFD3;
extern volatile unsigned char           UINTCR0              @ 0xFD4;
extern volatile unsigned char           INTCR2              @ 0xFD5;
extern volatile unsigned char           INTCR1              @ 0xFD6;
extern volatile unsigned char           INTCR0              @ 0xFD7;
extern volatile unsigned char           STATUS              @ 0xFD8;
extern volatile unsigned char           FSR2L               @ 0xFD9;
extern volatile unsigned char           FSR2H               @ 0xFDA;
extern volatile unsigned char           PLUSW2              @ 0xFDB;
extern volatile unsigned char           PREINC2             @ 0xFDC;
extern volatile unsigned char           POSTDEC2            @ 0xFDD;
extern volatile unsigned char           POSTINC2            @ 0xFDE;
extern volatile unsigned char           INDF2               @ 0xFDF;
extern volatile unsigned char           BSR                 @ 0xFE0;
extern volatile unsigned char           FSR1L               @ 0xFE1;
extern volatile unsigned char           FSR1H               @ 0xFE2;
extern volatile unsigned char           PLUSW1              @ 0xFE3;
extern volatile unsigned char           PREINC1             @ 0xFE4;
extern volatile unsigned char           POSTDEC1            @ 0xFE5;
extern volatile unsigned char           POSTINC1            @ 0xFE6;
extern volatile unsigned char           INDF1               @ 0xFE7;
extern volatile unsigned char           AREG                @ 0xFE8;
extern volatile unsigned char           FSR0L               @ 0xFE9;
extern volatile unsigned char           FSR0H               @ 0xFEA;
extern volatile unsigned char           PLUSW0              @ 0xFEB;
extern volatile unsigned char           PREINC0             @ 0xFEC;
extern volatile unsigned char           POSTDEC0            @ 0xFED;
extern volatile unsigned char           POSTINC0            @ 0xFEE;
extern volatile unsigned char           INDF0               @ 0xFEF;
extern volatile unsigned char           EECON2              @ 0xFF0;
extern volatile unsigned char           EECON1              @ 0xFF1;
extern volatile unsigned char           OPTION              @ 0xFF2;
extern volatile unsigned char           PRODL               @ 0xFF3;
extern volatile unsigned char           PRODH               @ 0xFF4;
extern volatile unsigned char           TABLAT              @ 0xFF5;
extern volatile unsigned char           TBLPTRL             @ 0xFF6;
extern volatile unsigned char           TBLPTRH             @ 0xFF7;
extern volatile unsigned char           PCL                 @ 0xFF9;
extern volatile unsigned char           PCLATH              @ 0xFFA;
extern volatile unsigned char           STKPTR              @ 0xFFC;
extern volatile unsigned char           TOSL                @ 0xFFD;
extern volatile unsigned char           TOSH                @ 0xFFE;

extern volatile unsigned       int      PWM121D             @ ((unsigned)&PWM121DL);
extern volatile unsigned       int      PWM120D             @ ((unsigned)&PWM120DL);
extern volatile unsigned       int      PWM119D             @ ((unsigned)&PWM119DL);
extern volatile unsigned       int      PWM118D             @ ((unsigned)&PWM118DL);
extern volatile unsigned       int      PWM117D             @ ((unsigned)&PWM117DL);
extern volatile unsigned       int      PWM116D             @ ((unsigned)&PWM116DL);
extern volatile unsigned       int      PWM115D             @ ((unsigned)&PWM115DL);
extern volatile unsigned       int      PWM114D             @ ((unsigned)&PWM114DL);
extern volatile unsigned       int      PWM113D             @ ((unsigned)&PWM113DL);
extern volatile unsigned       int      PWM112D             @ ((unsigned)&PWM112DL);
extern volatile unsigned       int      PWM111D             @ ((unsigned)&PWM111DL);
extern volatile unsigned       int      PWM110D             @ ((unsigned)&PWM110DL);
extern volatile unsigned       int      PWM109D             @ ((unsigned)&PWM109DL);
extern volatile unsigned       int      PWM108D             @ ((unsigned)&PWM108DL);
extern volatile unsigned       int      PWM107D             @ ((unsigned)&PWM107DL);
extern volatile unsigned       int      PWM106D             @ ((unsigned)&PWM106DL);
extern volatile unsigned       int      PWM105D             @ ((unsigned)&PWM105DL);
extern volatile unsigned       int      PWM104D             @ ((unsigned)&PWM104DL);
extern volatile unsigned       int      PWM103D             @ ((unsigned)&PWM103DL);
extern volatile unsigned       int      PWM102D             @ ((unsigned)&PWM102DL);
extern volatile unsigned       int      PWM101D             @ ((unsigned)&PWM101DL);
extern volatile unsigned       int      PWM100D             @ ((unsigned)&PWM100DL);
extern volatile unsigned       int      PWM2PR              @ ((unsigned)&PWM2PRL );
extern volatile unsigned       int      PWM2_2N             @ ((unsigned)&PWM2_2NL);
extern volatile unsigned       int      PWM2_1N             @ ((unsigned)&PWM2_1NL);
extern volatile unsigned       int      PWM2_0N             @ ((unsigned)&PWM2_0NL);
extern volatile unsigned       int      PWM2_2P             @ ((unsigned)&PWM2_2PL);
extern volatile unsigned       int      PWM2_1P             @ ((unsigned)&PWM2_1PL);
extern volatile unsigned       int      PWM2_0P             @ ((unsigned)&PWM2_0PL);
extern volatile unsigned       int      PWM2DT1             @ ((unsigned)&PWM2DT1L);
extern volatile unsigned       int      PWM2DT0             @ ((unsigned)&PWM2DT0L);
extern volatile unsigned       int      BRGD1               @ ((unsigned)&BRGD1L  );
extern volatile unsigned       int      BRGD0               @ ((unsigned)&BRGD0L  );
extern volatile unsigned       int      TC2C                @ ((unsigned)&TC2CL)   ;
extern volatile unsigned       int      TC2PR               @ ((unsigned)&TC2PRL)  ;
extern volatile unsigned       int      TC1C                @ ((unsigned)&TC1CL)   ;
extern volatile unsigned       int      TC1PR               @ ((unsigned)&TC1PRL)  ;
extern volatile unsigned       int      TC0C                @ ((unsigned)&TC0CL)   ;
extern volatile unsigned       int      AD                  @ ((unsigned)&ADL)     ;
extern volatile unsigned       int      FSR2                @ ((unsigned)&FSR2L)   ;
extern volatile unsigned       int      FSR1                @ ((unsigned)&FSR1L)   ;
extern volatile unsigned       int      FSR0                @ ((unsigned)&FSR0L)   ;
extern volatile unsigned       int      PROD                @ ((unsigned)&PRODL)   ;
extern volatile unsigned       int      TBLPTR              @ ((unsigned)&TBLPTRL) ;
extern volatile unsigned       int      TOS                 @ ((unsigned)&TOSL)     ;

/*
 * Bit Definitions
 */
extern volatile __bit                   PWM121DH0           @ (((unsigned) &PWM121DH)*8) + 0;
extern volatile __bit                   PWM121DH1           @ (((unsigned) &PWM121DH)*8) + 1;
extern volatile __bit                   PWM121DH2           @ (((unsigned) &PWM121DH)*8) + 2;
extern volatile __bit                   PWM121DH3           @ (((unsigned) &PWM121DH)*8) + 3;
extern volatile __bit                   PWM121DH4           @ (((unsigned) &PWM121DH)*8) + 4;
extern volatile __bit                   PWM121DH5           @ (((unsigned) &PWM121DH)*8) + 5;
extern volatile __bit                   PWM121DH6           @ (((unsigned) &PWM121DH)*8) + 6;
extern volatile __bit                   PWM121DH7           @ (((unsigned) &PWM121DH)*8) + 7;

extern volatile __bit                   PWM121DL0           @ (((unsigned) &PWM121DL)*8) + 0;
extern volatile __bit                   PWM121DL1           @ (((unsigned) &PWM121DL)*8) + 1;
extern volatile __bit                   PWM121DL2           @ (((unsigned) &PWM121DL)*8) + 2;
extern volatile __bit                   PWM121DL3           @ (((unsigned) &PWM121DL)*8) + 3;
extern volatile __bit                   PWM121DL4           @ (((unsigned) &PWM121DL)*8) + 4;
extern volatile __bit                   PWM121DL5           @ (((unsigned) &PWM121DL)*8) + 5;
extern volatile __bit                   PWM121DL6           @ (((unsigned) &PWM121DL)*8) + 6;
extern volatile __bit                   PWM121DL7           @ (((unsigned) &PWM121DL)*8) + 7;

extern volatile __bit                   PWM120DH0           @ (((unsigned) &PWM120DH)*8) + 0;
extern volatile __bit                   PWM120DH1           @ (((unsigned) &PWM120DH)*8) + 1;
extern volatile __bit                   PWM120DH2           @ (((unsigned) &PWM120DH)*8) + 2;
extern volatile __bit                   PWM120DH3           @ (((unsigned) &PWM120DH)*8) + 3;
extern volatile __bit                   PWM120DH4           @ (((unsigned) &PWM120DH)*8) + 4;
extern volatile __bit                   PWM120DH5           @ (((unsigned) &PWM120DH)*8) + 5;
extern volatile __bit                   PWM120DH6           @ (((unsigned) &PWM120DH)*8) + 6;
extern volatile __bit                   PWM120DH7           @ (((unsigned) &PWM120DH)*8) + 7;

extern volatile __bit                   PWM120DL0           @ (((unsigned) &PWM120DL)*8) + 0;
extern volatile __bit                   PWM120DL1           @ (((unsigned) &PWM120DL)*8) + 1;
extern volatile __bit                   PWM120DL2           @ (((unsigned) &PWM120DL)*8) + 2;
extern volatile __bit                   PWM120DL3           @ (((unsigned) &PWM120DL)*8) + 3;
extern volatile __bit                   PWM120DL4           @ (((unsigned) &PWM120DL)*8) + 4;
extern volatile __bit                   PWM120DL5           @ (((unsigned) &PWM120DL)*8) + 5;
extern volatile __bit                   PWM120DL6           @ (((unsigned) &PWM120DL)*8) + 6;
extern volatile __bit                   PWM120DL7           @ (((unsigned) &PWM120DL)*8) + 7;

extern volatile __bit                   PWM119DH0           @ (((unsigned) &PWM119DH)*8) + 0;
extern volatile __bit                   PWM119DH1           @ (((unsigned) &PWM119DH)*8) + 1;
extern volatile __bit                   PWM119DH2           @ (((unsigned) &PWM119DH)*8) + 2;
extern volatile __bit                   PWM119DH3           @ (((unsigned) &PWM119DH)*8) + 3;
extern volatile __bit                   PWM119DH4           @ (((unsigned) &PWM119DH)*8) + 4;
extern volatile __bit                   PWM119DH5           @ (((unsigned) &PWM119DH)*8) + 5;
extern volatile __bit                   PWM119DH6           @ (((unsigned) &PWM119DH)*8) + 6;
extern volatile __bit                   PWM119DH7           @ (((unsigned) &PWM119DH)*8) + 7;

extern volatile __bit                   PWM119DL0           @ (((unsigned) &PWM119DL)*8) + 0;
extern volatile __bit                   PWM119DL1           @ (((unsigned) &PWM119DL)*8) + 1;
extern volatile __bit                   PWM119DL2           @ (((unsigned) &PWM119DL)*8) + 2;
extern volatile __bit                   PWM119DL3           @ (((unsigned) &PWM119DL)*8) + 3;
extern volatile __bit                   PWM119DL4           @ (((unsigned) &PWM119DL)*8) + 4;
extern volatile __bit                   PWM119DL5           @ (((unsigned) &PWM119DL)*8) + 5;
extern volatile __bit                   PWM119DL6           @ (((unsigned) &PWM119DL)*8) + 6;
extern volatile __bit                   PWM119DL7           @ (((unsigned) &PWM119DL)*8) + 7;

extern volatile __bit                   PWM118DH0           @ (((unsigned) &PWM118DH)*8) + 0;
extern volatile __bit                   PWM118DH1           @ (((unsigned) &PWM118DH)*8) + 1;
extern volatile __bit                   PWM118DH2           @ (((unsigned) &PWM118DH)*8) + 2;
extern volatile __bit                   PWM118DH3           @ (((unsigned) &PWM118DH)*8) + 3;
extern volatile __bit                   PWM118DH4           @ (((unsigned) &PWM118DH)*8) + 4;
extern volatile __bit                   PWM118DH5           @ (((unsigned) &PWM118DH)*8) + 5;
extern volatile __bit                   PWM118DH6           @ (((unsigned) &PWM118DH)*8) + 6;
extern volatile __bit                   PWM118DH7           @ (((unsigned) &PWM118DH)*8) + 7;

extern volatile __bit                   PWM118DL0           @ (((unsigned) &PWM118DL)*8) + 0;
extern volatile __bit                   PWM118DL1           @ (((unsigned) &PWM118DL)*8) + 1;
extern volatile __bit                   PWM118DL2           @ (((unsigned) &PWM118DL)*8) + 2;
extern volatile __bit                   PWM118DL3           @ (((unsigned) &PWM118DL)*8) + 3;
extern volatile __bit                   PWM118DL4           @ (((unsigned) &PWM118DL)*8) + 4;
extern volatile __bit                   PWM118DL5           @ (((unsigned) &PWM118DL)*8) + 5;
extern volatile __bit                   PWM118DL6           @ (((unsigned) &PWM118DL)*8) + 6;
extern volatile __bit                   PWM118DL7           @ (((unsigned) &PWM118DL)*8) + 7;

extern volatile __bit                   PWM117DH0           @ (((unsigned) &PWM117DH)*8) + 0;
extern volatile __bit                   PWM117DH1           @ (((unsigned) &PWM117DH)*8) + 1;
extern volatile __bit                   PWM117DH2           @ (((unsigned) &PWM117DH)*8) + 2;
extern volatile __bit                   PWM117DH3           @ (((unsigned) &PWM117DH)*8) + 3;
extern volatile __bit                   PWM117DH4           @ (((unsigned) &PWM117DH)*8) + 4;
extern volatile __bit                   PWM117DH5           @ (((unsigned) &PWM117DH)*8) + 5;
extern volatile __bit                   PWM117DH6           @ (((unsigned) &PWM117DH)*8) + 6;
extern volatile __bit                   PWM117DH7           @ (((unsigned) &PWM117DH)*8) + 7;

extern volatile __bit                   PWM117DL0           @ (((unsigned) &PWM117DL)*8) + 0;
extern volatile __bit                   PWM117DL1           @ (((unsigned) &PWM117DL)*8) + 1;
extern volatile __bit                   PWM117DL2           @ (((unsigned) &PWM117DL)*8) + 2;
extern volatile __bit                   PWM117DL3           @ (((unsigned) &PWM117DL)*8) + 3;
extern volatile __bit                   PWM117DL4           @ (((unsigned) &PWM117DL)*8) + 4;
extern volatile __bit                   PWM117DL5           @ (((unsigned) &PWM117DL)*8) + 5;
extern volatile __bit                   PWM117DL6           @ (((unsigned) &PWM117DL)*8) + 6;
extern volatile __bit                   PWM117DL7           @ (((unsigned) &PWM117DL)*8) + 7;

extern volatile __bit                   PWM116DH0           @ (((unsigned) &PWM116DH)*8) + 0;
extern volatile __bit                   PWM116DH1           @ (((unsigned) &PWM116DH)*8) + 1;
extern volatile __bit                   PWM116DH2           @ (((unsigned) &PWM116DH)*8) + 2;
extern volatile __bit                   PWM116DH3           @ (((unsigned) &PWM116DH)*8) + 3;
extern volatile __bit                   PWM116DH4           @ (((unsigned) &PWM116DH)*8) + 4;
extern volatile __bit                   PWM116DH5           @ (((unsigned) &PWM116DH)*8) + 5;
extern volatile __bit                   PWM116DH6           @ (((unsigned) &PWM116DH)*8) + 6;
extern volatile __bit                   PWM116DH7           @ (((unsigned) &PWM116DH)*8) + 7;

extern volatile __bit                   PWM116DL0           @ (((unsigned) &PWM116DL)*8) + 0;
extern volatile __bit                   PWM116DL1           @ (((unsigned) &PWM116DL)*8) + 1;
extern volatile __bit                   PWM116DL2           @ (((unsigned) &PWM116DL)*8) + 2;
extern volatile __bit                   PWM116DL3           @ (((unsigned) &PWM116DL)*8) + 3;
extern volatile __bit                   PWM116DL4           @ (((unsigned) &PWM116DL)*8) + 4;
extern volatile __bit                   PWM116DL5           @ (((unsigned) &PWM116DL)*8) + 5;
extern volatile __bit                   PWM116DL6           @ (((unsigned) &PWM116DL)*8) + 6;
extern volatile __bit                   PWM116DL7           @ (((unsigned) &PWM116DL)*8) + 7;

extern volatile __bit                   PWM115DH0           @ (((unsigned) &PWM115DH)*8) + 0;    
extern volatile __bit                   PWM116DL1           @ (((unsigned) &PWM116DL)*8) + 1;
extern volatile __bit                   PWM116DL2           @ (((unsigned) &PWM116DL)*8) + 2;
extern volatile __bit                   PWM116DL3           @ (((unsigned) &PWM116DL)*8) + 3;
extern volatile __bit                   PWM116DL4           @ (((unsigned) &PWM116DL)*8) + 4;
extern volatile __bit                   PWM116DL5           @ (((unsigned) &PWM116DL)*8) + 5;
extern volatile __bit                   PWM116DL6           @ (((unsigned) &PWM116DL)*8) + 6;
extern volatile __bit                   PWM116DL7           @ (((unsigned) &PWM116DL)*8) + 7;

extern volatile __bit                   PWM115DL0           @ (((unsigned) &PWM115DL)*8) + 0;
extern volatile __bit                   PWM115DL1           @ (((unsigned) &PWM115DL)*8) + 1;
extern volatile __bit                   PWM115DL2           @ (((unsigned) &PWM115DL)*8) + 2;
extern volatile __bit                   PWM115DL3           @ (((unsigned) &PWM115DL)*8) + 3;
extern volatile __bit                   PWM115DL4           @ (((unsigned) &PWM115DL)*8) + 4;
extern volatile __bit                   PWM115DL5           @ (((unsigned) &PWM115DL)*8) + 5;
extern volatile __bit                   PWM115DL6           @ (((unsigned) &PWM115DL)*8) + 6;
extern volatile __bit                   PWM115DL7           @ (((unsigned) &PWM115DL)*8) + 7;

extern volatile __bit                   PWM114DH0           @ (((unsigned) &PWM114DH)*8) + 0;
extern volatile __bit                   PWM114DH1           @ (((unsigned) &PWM114DH)*8) + 1;
extern volatile __bit                   PWM114DH2           @ (((unsigned) &PWM114DH)*8) + 2;
extern volatile __bit                   PWM114DH3           @ (((unsigned) &PWM114DH)*8) + 3;
extern volatile __bit                   PWM114DH4           @ (((unsigned) &PWM114DH)*8) + 4;
extern volatile __bit                   PWM114DH5           @ (((unsigned) &PWM114DH)*8) + 5;
extern volatile __bit                   PWM114DH6           @ (((unsigned) &PWM114DH)*8) + 6;
extern volatile __bit                   PWM114DH7           @ (((unsigned) &PWM114DH)*8) + 7;

extern volatile __bit                   PWM114DL0           @ (((unsigned) &PWM114DL)*8) + 0;
extern volatile __bit                   PWM114DL1           @ (((unsigned) &PWM114DL)*8) + 1;
extern volatile __bit                   PWM114DL2           @ (((unsigned) &PWM114DL)*8) + 2;
extern volatile __bit                   PWM114DL3           @ (((unsigned) &PWM114DL)*8) + 3;
extern volatile __bit                   PWM114DL4           @ (((unsigned) &PWM114DL)*8) + 4;
extern volatile __bit                   PWM114DL5           @ (((unsigned) &PWM114DL)*8) + 5;
extern volatile __bit                   PWM114DL6           @ (((unsigned) &PWM114DL)*8) + 6;
extern volatile __bit                   PWM114DL7           @ (((unsigned) &PWM114DL)*8) + 7;

extern volatile __bit                   PWM113DH0           @ (((unsigned) &PWM113DH)*8) + 0;
extern volatile __bit                   PWM113DH1           @ (((unsigned) &PWM113DH)*8) + 1;
extern volatile __bit                   PWM113DH2           @ (((unsigned) &PWM113DH)*8) + 2;
extern volatile __bit                   PWM113DH3           @ (((unsigned) &PWM113DH)*8) + 3;
extern volatile __bit                   PWM113DH4           @ (((unsigned) &PWM113DH)*8) + 4;
extern volatile __bit                   PWM113DH5           @ (((unsigned) &PWM113DH)*8) + 5;
extern volatile __bit                   PWM113DH6           @ (((unsigned) &PWM113DH)*8) + 6;
extern volatile __bit                   PWM113DH7           @ (((unsigned) &PWM113DH)*8) + 7;

extern volatile __bit                   PWM113DL0           @ (((unsigned) &PWM113DL)*8) + 0;
extern volatile __bit                   PWM113DL1           @ (((unsigned) &PWM113DL)*8) + 1;
extern volatile __bit                   PWM113DL2           @ (((unsigned) &PWM113DL)*8) + 2;
extern volatile __bit                   PWM113DL3           @ (((unsigned) &PWM113DL)*8) + 3;
extern volatile __bit                   PWM113DL4           @ (((unsigned) &PWM113DL)*8) + 4;
extern volatile __bit                   PWM113DL5           @ (((unsigned) &PWM113DL)*8) + 5;
extern volatile __bit                   PWM113DL6           @ (((unsigned) &PWM113DL)*8) + 6;
extern volatile __bit                   PWM113DL7           @ (((unsigned) &PWM113DL)*8) + 7;

extern volatile __bit                   PWM112DH0           @ (((unsigned) &PWM112DH)*8) + 0;
extern volatile __bit                   PWM112DH1           @ (((unsigned) &PWM112DH)*8) + 1;
extern volatile __bit                   PWM112DH2           @ (((unsigned) &PWM112DH)*8) + 2;
extern volatile __bit                   PWM112DH3           @ (((unsigned) &PWM112DH)*8) + 3;
extern volatile __bit                   PWM112DH4           @ (((unsigned) &PWM112DH)*8) + 4;
extern volatile __bit                   PWM112DH5           @ (((unsigned) &PWM112DH)*8) + 5;
extern volatile __bit                   PWM112DH6           @ (((unsigned) &PWM112DH)*8) + 6;
extern volatile __bit                   PWM112DH7           @ (((unsigned) &PWM112DH)*8) + 7;

extern volatile __bit                   PWM112DL0           @ (((unsigned) &PWM112DL)*8) + 0;
extern volatile __bit                   PWM112DL1           @ (((unsigned) &PWM112DL)*8) + 1;
extern volatile __bit                   PWM112DL2           @ (((unsigned) &PWM112DL)*8) + 2;
extern volatile __bit                   PWM112DL3           @ (((unsigned) &PWM112DL)*8) + 3;
extern volatile __bit                   PWM112DL4           @ (((unsigned) &PWM112DL)*8) + 4;
extern volatile __bit                   PWM112DL5           @ (((unsigned) &PWM112DL)*8) + 5;
extern volatile __bit                   PWM112DL6           @ (((unsigned) &PWM112DL)*8) + 6;
extern volatile __bit                   PWM112DL7           @ (((unsigned) &PWM112DL)*8) + 7;

extern volatile __bit                   PWM111DH0           @ (((unsigned) &PWM111DH)*8) + 0;
extern volatile __bit                   PWM111DH1           @ (((unsigned) &PWM111DH)*8) + 1;
extern volatile __bit                   PWM111DH2           @ (((unsigned) &PWM111DH)*8) + 2;
extern volatile __bit                   PWM111DH3           @ (((unsigned) &PWM111DH)*8) + 3;
extern volatile __bit                   PWM111DH4           @ (((unsigned) &PWM111DH)*8) + 4;
extern volatile __bit                   PWM111DH5           @ (((unsigned) &PWM111DH)*8) + 5;
extern volatile __bit                   PWM111DH6           @ (((unsigned) &PWM111DH)*8) + 6;
extern volatile __bit                   PWM111DH7           @ (((unsigned) &PWM111DH)*8) + 7;

extern volatile __bit                   PWM111DL0           @ (((unsigned) &PWM111DL)*8) + 0;
extern volatile __bit                   PWM111DL1           @ (((unsigned) &PWM111DL)*8) + 1;
extern volatile __bit                   PWM111DL2           @ (((unsigned) &PWM111DL)*8) + 2;
extern volatile __bit                   PWM111DL3           @ (((unsigned) &PWM111DL)*8) + 3;
extern volatile __bit                   PWM111DL4           @ (((unsigned) &PWM111DL)*8) + 4;
extern volatile __bit                   PWM111DL5           @ (((unsigned) &PWM111DL)*8) + 5;
extern volatile __bit                   PWM111DL6           @ (((unsigned) &PWM111DL)*8) + 6;
extern volatile __bit                   PWM111DL7           @ (((unsigned) &PWM111DL)*8) + 7;

extern volatile __bit                   PWM110DH0           @ (((unsigned) &PWM110DH)*8) + 0;
extern volatile __bit                   PWM110DH1           @ (((unsigned) &PWM110DH)*8) + 1;
extern volatile __bit                   PWM110DH2           @ (((unsigned) &PWM110DH)*8) + 2;
extern volatile __bit                   PWM110DH3           @ (((unsigned) &PWM110DH)*8) + 3;
extern volatile __bit                   PWM110DH4           @ (((unsigned) &PWM110DH)*8) + 4;
extern volatile __bit                   PWM110DH5           @ (((unsigned) &PWM110DH)*8) + 5;
extern volatile __bit                   PWM110DH6           @ (((unsigned) &PWM110DH)*8) + 6;
extern volatile __bit                   PWM110DH7           @ (((unsigned) &PWM110DH)*8) + 7;

extern volatile __bit                   PWM110DL0           @ (((unsigned) &PWM110DL)*8) + 0;
extern volatile __bit                   PWM110DL1           @ (((unsigned) &PWM110DL)*8) + 1;
extern volatile __bit                   PWM110DL2           @ (((unsigned) &PWM110DL)*8) + 2;
extern volatile __bit                   PWM110DL3           @ (((unsigned) &PWM110DL)*8) + 3;
extern volatile __bit                   PWM110DL4           @ (((unsigned) &PWM110DL)*8) + 4;
extern volatile __bit                   PWM110DL5           @ (((unsigned) &PWM110DL)*8) + 5;
extern volatile __bit                   PWM110DL6           @ (((unsigned) &PWM110DL)*8) + 6;
extern volatile __bit                   PWM110DL7           @ (((unsigned) &PWM110DL)*8) + 7;

extern volatile __bit                   PWM109DH0           @ (((unsigned) &PWM109DH)*8) + 0;
extern volatile __bit                   PWM109DH1           @ (((unsigned) &PWM109DH)*8) + 1;
extern volatile __bit                   PWM109DH2           @ (((unsigned) &PWM109DH)*8) + 2;
extern volatile __bit                   PWM109DH3           @ (((unsigned) &PWM109DH)*8) + 3;
extern volatile __bit                   PWM109DH4           @ (((unsigned) &PWM109DH)*8) + 4;
extern volatile __bit                   PWM109DH5           @ (((unsigned) &PWM109DH)*8) + 5;
extern volatile __bit                   PWM109DH6           @ (((unsigned) &PWM109DH)*8) + 6;
extern volatile __bit                   PWM109DH7           @ (((unsigned) &PWM109DH)*8) + 7;

extern volatile __bit                   PWM109DL0           @ (((unsigned) &PWM109DL)*8) + 0;
extern volatile __bit                   PWM109DL1           @ (((unsigned) &PWM109DL)*8) + 1;
extern volatile __bit                   PWM109DL2           @ (((unsigned) &PWM109DL)*8) + 2;
extern volatile __bit                   PWM109DL3           @ (((unsigned) &PWM109DL)*8) + 3;
extern volatile __bit                   PWM109DL4           @ (((unsigned) &PWM109DL)*8) + 4;
extern volatile __bit                   PWM109DL5           @ (((unsigned) &PWM109DL)*8) + 5;
extern volatile __bit                   PWM109DL6           @ (((unsigned) &PWM109DL)*8) + 6;
extern volatile __bit                   PWM109DL7           @ (((unsigned) &PWM109DL)*8) + 7;

extern volatile __bit                   PWM108DH0           @ (((unsigned) &PWM108DH)*8) + 0;
extern volatile __bit                   PWM108DH1           @ (((unsigned) &PWM108DH)*8) + 1;
extern volatile __bit                   PWM108DH2           @ (((unsigned) &PWM108DH)*8) + 2;
extern volatile __bit                   PWM108DH3           @ (((unsigned) &PWM108DH)*8) + 3;
extern volatile __bit                   PWM108DH4           @ (((unsigned) &PWM108DH)*8) + 4;
extern volatile __bit                   PWM108DH5           @ (((unsigned) &PWM108DH)*8) + 5;
extern volatile __bit                   PWM108DH6           @ (((unsigned) &PWM108DH)*8) + 6;
extern volatile __bit                   PWM108DH7           @ (((unsigned) &PWM108DH)*8) + 7;

extern volatile __bit                   PWM108DL0           @ (((unsigned) &PWM108DL)*8) + 0;
extern volatile __bit                   PWM108DL1           @ (((unsigned) &PWM108DL)*8) + 1;
extern volatile __bit                   PWM108DL2           @ (((unsigned) &PWM108DL)*8) + 2;
extern volatile __bit                   PWM108DL3           @ (((unsigned) &PWM108DL)*8) + 3;
extern volatile __bit                   PWM108DL4           @ (((unsigned) &PWM108DL)*8) + 4;
extern volatile __bit                   PWM108DL5           @ (((unsigned) &PWM108DL)*8) + 5;
extern volatile __bit                   PWM108DL6           @ (((unsigned) &PWM108DL)*8) + 6;
extern volatile __bit                   PWM108DL7           @ (((unsigned) &PWM108DL)*8) + 7;

extern volatile __bit                   PWM107DH0           @ (((unsigned) &PWM107DH)*8) + 0;
extern volatile __bit                   PWM107DH1           @ (((unsigned) &PWM107DH)*8) + 1;
extern volatile __bit                   PWM107DH2           @ (((unsigned) &PWM107DH)*8) + 2;
extern volatile __bit                   PWM107DH3           @ (((unsigned) &PWM107DH)*8) + 3;
extern volatile __bit                   PWM107DH4           @ (((unsigned) &PWM107DH)*8) + 4;
extern volatile __bit                   PWM107DH5           @ (((unsigned) &PWM107DH)*8) + 5;
extern volatile __bit                   PWM107DH6           @ (((unsigned) &PWM107DH)*8) + 6;
extern volatile __bit                   PWM107DH7           @ (((unsigned) &PWM107DH)*8) + 7;

extern volatile __bit                   PWM107DL0           @ (((unsigned) &PWM107DL)*8) + 0;
extern volatile __bit                   PWM107DL1           @ (((unsigned) &PWM107DL)*8) + 1;
extern volatile __bit                   PWM107DL2           @ (((unsigned) &PWM107DL)*8) + 2;
extern volatile __bit                   PWM107DL3           @ (((unsigned) &PWM107DL)*8) + 3;
extern volatile __bit                   PWM107DL4           @ (((unsigned) &PWM107DL)*8) + 4;
extern volatile __bit                   PWM107DL5           @ (((unsigned) &PWM107DL)*8) + 5;
extern volatile __bit                   PWM107DL6           @ (((unsigned) &PWM107DL)*8) + 6;
extern volatile __bit                   PWM107DL7           @ (((unsigned) &PWM107DL)*8) + 7;

extern volatile __bit                   PWM106DH0           @ (((unsigned) &PWM106DH)*8) + 0;
extern volatile __bit                   PWM106DH1           @ (((unsigned) &PWM106DH)*8) + 1;
extern volatile __bit                   PWM106DH2           @ (((unsigned) &PWM106DH)*8) + 2;
extern volatile __bit                   PWM106DH3           @ (((unsigned) &PWM106DH)*8) + 3;
extern volatile __bit                   PWM106DH4           @ (((unsigned) &PWM106DH)*8) + 4;
extern volatile __bit                   PWM106DH5           @ (((unsigned) &PWM106DH)*8) + 5;
extern volatile __bit                   PWM106DH6           @ (((unsigned) &PWM106DH)*8) + 6;
extern volatile __bit                   PWM106DH7           @ (((unsigned) &PWM106DH)*8) + 7;

extern volatile __bit                   PWM106DL0           @ (((unsigned) &PWM106DL)*8) + 0;
extern volatile __bit                   PWM106DL1           @ (((unsigned) &PWM106DL)*8) + 1;
extern volatile __bit                   PWM106DL2           @ (((unsigned) &PWM106DL)*8) + 2;
extern volatile __bit                   PWM106DL3           @ (((unsigned) &PWM106DL)*8) + 3;
extern volatile __bit                   PWM106DL4           @ (((unsigned) &PWM106DL)*8) + 4;
extern volatile __bit                   PWM106DL5           @ (((unsigned) &PWM106DL)*8) + 5;
extern volatile __bit                   PWM106DL6           @ (((unsigned) &PWM106DL)*8) + 6;
extern volatile __bit                   PWM106DL7           @ (((unsigned) &PWM106DL)*8) + 7;

extern volatile __bit                   PWM105DH0           @ (((unsigned) &PWM105DH)*8) + 0;
extern volatile __bit                   PWM105DH1           @ (((unsigned) &PWM105DH)*8) + 1;
extern volatile __bit                   PWM105DH2           @ (((unsigned) &PWM105DH)*8) + 2;
extern volatile __bit                   PWM105DH3           @ (((unsigned) &PWM105DH)*8) + 3;
extern volatile __bit                   PWM105DH4           @ (((unsigned) &PWM105DH)*8) + 4;
extern volatile __bit                   PWM105DH5           @ (((unsigned) &PWM105DH)*8) + 5;
extern volatile __bit                   PWM105DH6           @ (((unsigned) &PWM105DH)*8) + 6;
extern volatile __bit                   PWM105DH7           @ (((unsigned) &PWM105DH)*8) + 7;

extern volatile __bit                   PWM105DL0           @ (((unsigned) &PWM105DL)*8) + 0;
extern volatile __bit                   PWM105DL1           @ (((unsigned) &PWM105DL)*8) + 1;
extern volatile __bit                   PWM105DL2           @ (((unsigned) &PWM105DL)*8) + 2;
extern volatile __bit                   PWM105DL3           @ (((unsigned) &PWM105DL)*8) + 3;
extern volatile __bit                   PWM105DL4           @ (((unsigned) &PWM105DL)*8) + 4;
extern volatile __bit                   PWM105DL5           @ (((unsigned) &PWM105DL)*8) + 5;
extern volatile __bit                   PWM105DL6           @ (((unsigned) &PWM105DL)*8) + 6;
extern volatile __bit                   PWM105DL7           @ (((unsigned) &PWM105DL)*8) + 7;

extern volatile __bit                   PWM104DH0           @ (((unsigned) &PWM104DH)*8) + 0;
extern volatile __bit                   PWM104DH1           @ (((unsigned) &PWM104DH)*8) + 1;
extern volatile __bit                   PWM104DH2           @ (((unsigned) &PWM104DH)*8) + 2;
extern volatile __bit                   PWM104DH3           @ (((unsigned) &PWM104DH)*8) + 3;
extern volatile __bit                   PWM104DH4           @ (((unsigned) &PWM104DH)*8) + 4;
extern volatile __bit                   PWM104DH5           @ (((unsigned) &PWM104DH)*8) + 5;
extern volatile __bit                   PWM104DH6           @ (((unsigned) &PWM104DH)*8) + 6;
extern volatile __bit                   PWM104DH7           @ (((unsigned) &PWM104DH)*8) + 7;

extern volatile __bit                   PWM104DL0           @ (((unsigned) &PWM104DL)*8) + 0;
extern volatile __bit                   PWM104DL1           @ (((unsigned) &PWM104DL)*8) + 1;
extern volatile __bit                   PWM104DL2           @ (((unsigned) &PWM104DL)*8) + 2;
extern volatile __bit                   PWM104DL3           @ (((unsigned) &PWM104DL)*8) + 3;
extern volatile __bit                   PWM104DL4           @ (((unsigned) &PWM104DL)*8) + 4;
extern volatile __bit                   PWM104DL5           @ (((unsigned) &PWM104DL)*8) + 5;
extern volatile __bit                   PWM104DL6           @ (((unsigned) &PWM104DL)*8) + 6;
extern volatile __bit                   PWM104DL7           @ (((unsigned) &PWM104DL)*8) + 7;

extern volatile __bit                   PWM103DH0           @ (((unsigned) &PWM103DH)*8) + 0;
extern volatile __bit                   PWM103DH1           @ (((unsigned) &PWM103DH)*8) + 1;
extern volatile __bit                   PWM103DH2           @ (((unsigned) &PWM103DH)*8) + 2;
extern volatile __bit                   PWM103DH3           @ (((unsigned) &PWM103DH)*8) + 3;
extern volatile __bit                   PWM103DH4           @ (((unsigned) &PWM103DH)*8) + 4;
extern volatile __bit                   PWM103DH5           @ (((unsigned) &PWM103DH)*8) + 5;
extern volatile __bit                   PWM103DH6           @ (((unsigned) &PWM103DH)*8) + 6;
extern volatile __bit                   PWM103DH7           @ (((unsigned) &PWM103DH)*8) + 7;

extern volatile __bit                   PWM103DL0           @ (((unsigned) &PWM103DL)*8) + 0;
extern volatile __bit                   PWM103DL1           @ (((unsigned) &PWM103DL)*8) + 1;
extern volatile __bit                   PWM103DL2           @ (((unsigned) &PWM103DL)*8) + 2;
extern volatile __bit                   PWM103DL3           @ (((unsigned) &PWM103DL)*8) + 3;
extern volatile __bit                   PWM103DL4           @ (((unsigned) &PWM103DL)*8) + 4;
extern volatile __bit                   PWM103DL5           @ (((unsigned) &PWM103DL)*8) + 5;
extern volatile __bit                   PWM103DL6           @ (((unsigned) &PWM103DL)*8) + 6;
extern volatile __bit                   PWM103DL7           @ (((unsigned) &PWM103DL)*8) + 7;

extern volatile __bit                   PWM102DH0           @ (((unsigned) &PWM102DH)*8) + 0;
extern volatile __bit                   PWM102DH1           @ (((unsigned) &PWM102DH)*8) + 1;
extern volatile __bit                   PWM102DH2           @ (((unsigned) &PWM102DH)*8) + 2;
extern volatile __bit                   PWM102DH3           @ (((unsigned) &PWM102DH)*8) + 3;
extern volatile __bit                   PWM102DH4           @ (((unsigned) &PWM102DH)*8) + 4;
extern volatile __bit                   PWM102DH5           @ (((unsigned) &PWM102DH)*8) + 5;
extern volatile __bit                   PWM102DH6           @ (((unsigned) &PWM102DH)*8) + 6;
extern volatile __bit                   PWM102DH7           @ (((unsigned) &PWM102DH)*8) + 7;

extern volatile __bit                   PWM102DL0           @ (((unsigned) &PWM102DL)*8) + 0;
extern volatile __bit                   PWM102DL1           @ (((unsigned) &PWM102DL)*8) + 1;
extern volatile __bit                   PWM102DL2           @ (((unsigned) &PWM102DL)*8) + 2;
extern volatile __bit                   PWM102DL3           @ (((unsigned) &PWM102DL)*8) + 3;
extern volatile __bit                   PWM102DL4           @ (((unsigned) &PWM102DL)*8) + 4;
extern volatile __bit                   PWM102DL5           @ (((unsigned) &PWM102DL)*8) + 5;
extern volatile __bit                   PWM102DL6           @ (((unsigned) &PWM102DL)*8) + 6;
extern volatile __bit                   PWM102DL7           @ (((unsigned) &PWM102DL)*8) + 7;

extern volatile __bit                   PWM101DH0           @ (((unsigned) &PWM101DH)*8) + 0;
extern volatile __bit                   PWM101DH1           @ (((unsigned) &PWM101DH)*8) + 1;
extern volatile __bit                   PWM101DH2           @ (((unsigned) &PWM101DH)*8) + 2;
extern volatile __bit                   PWM101DH3           @ (((unsigned) &PWM101DH)*8) + 3;
extern volatile __bit                   PWM101DH4           @ (((unsigned) &PWM101DH)*8) + 4;
extern volatile __bit                   PWM101DH5           @ (((unsigned) &PWM101DH)*8) + 5;
extern volatile __bit                   PWM101DH6           @ (((unsigned) &PWM101DH)*8) + 6;
extern volatile __bit                   PWM101DH7           @ (((unsigned) &PWM101DH)*8) + 7;

extern volatile __bit                   PWM101DL0           @ (((unsigned) &PWM101DL)*8) + 0;
extern volatile __bit                   PWM101DL1           @ (((unsigned) &PWM101DL)*8) + 1;
extern volatile __bit                   PWM101DL2           @ (((unsigned) &PWM101DL)*8) + 2;
extern volatile __bit                   PWM101DL3           @ (((unsigned) &PWM101DL)*8) + 3;
extern volatile __bit                   PWM101DL4           @ (((unsigned) &PWM101DL)*8) + 4;
extern volatile __bit                   PWM101DL5           @ (((unsigned) &PWM101DL)*8) + 5;
extern volatile __bit                   PWM101DL6           @ (((unsigned) &PWM101DL)*8) + 6;
extern volatile __bit                   PWM101DL7           @ (((unsigned) &PWM101DL)*8) + 7;

extern volatile __bit                   PWM100DH0           @ (((unsigned) &PWM100DH)*8) + 0;
extern volatile __bit                   PWM100DH1           @ (((unsigned) &PWM100DH)*8) + 1;
extern volatile __bit                   PWM100DH2           @ (((unsigned) &PWM100DH)*8) + 2;
extern volatile __bit                   PWM100DH3           @ (((unsigned) &PWM100DH)*8) + 3;
extern volatile __bit                   PWM100DH4           @ (((unsigned) &PWM100DH)*8) + 4;
extern volatile __bit                   PWM100DH5           @ (((unsigned) &PWM100DH)*8) + 5;
extern volatile __bit                   PWM100DH6           @ (((unsigned) &PWM100DH)*8) + 6;
extern volatile __bit                   PWM100DH7           @ (((unsigned) &PWM100DH)*8) + 7;

extern volatile __bit                   PWM100DL0           @ (((unsigned) &PWM100DL)*8) + 0;
extern volatile __bit                   PWM100DL1           @ (((unsigned) &PWM100DL)*8) + 1;
extern volatile __bit                   PWM100DL2           @ (((unsigned) &PWM100DL)*8) + 2;
extern volatile __bit                   PWM100DL3           @ (((unsigned) &PWM100DL)*8) + 3;
extern volatile __bit                   PWM100DL4           @ (((unsigned) &PWM100DL)*8) + 4;
extern volatile __bit                   PWM100DL5           @ (((unsigned) &PWM100DL)*8) + 5;
extern volatile __bit                   PWM100DL6           @ (((unsigned) &PWM100DL)*8) + 6;
extern volatile __bit                   PWM100DL7           @ (((unsigned) &PWM100DL)*8) + 7;

extern volatile __bit                   PWM121P0            @ (((unsigned) &PWM121CR)*8) + 0;
extern volatile __bit                   PWM121P1            @ (((unsigned) &PWM121CR)*8) + 1;
extern volatile __bit                   PWM121P2            @ (((unsigned) &PWM121CR)*8) + 2;
extern volatile __bit                   PWM121P3            @ (((unsigned) &PWM121CR)*8) + 3;
extern volatile __bit                   PWM121P4            @ (((unsigned) &PWM121CR)*8) + 4;
extern volatile __bit                   PWM121M             @ (((unsigned) &PWM121CR)*8) + 5;
extern volatile __bit                   PWM121OE            @ (((unsigned) &PWM121CR)*8) + 6;
extern volatile __bit                   PWM121EN            @ (((unsigned) &PWM121CR)*8) + 7;

extern volatile __bit                   PWM120P0            @ (((unsigned) &PWM120CR)*8) + 0;
extern volatile __bit                   PWM120P1            @ (((unsigned) &PWM120CR)*8) + 1;
extern volatile __bit                   PWM120P2            @ (((unsigned) &PWM120CR)*8) + 2;
extern volatile __bit                   PWM120P3            @ (((unsigned) &PWM120CR)*8) + 3;
extern volatile __bit                   PWM120P4            @ (((unsigned) &PWM120CR)*8) + 4;
extern volatile __bit                   PWM120M             @ (((unsigned) &PWM120CR)*8) + 5;
extern volatile __bit                   PWM120OE            @ (((unsigned) &PWM120CR)*8) + 6;
extern volatile __bit                   PWM120EN            @ (((unsigned) &PWM120CR)*8) + 7;

extern volatile __bit                   PWM119P0            @ (((unsigned) &PWM119CR)*8) + 0;
extern volatile __bit                   PWM119P1            @ (((unsigned) &PWM119CR)*8) + 1;
extern volatile __bit                   PWM119P2            @ (((unsigned) &PWM119CR)*8) + 2;
extern volatile __bit                   PWM119P3            @ (((unsigned) &PWM119CR)*8) + 3;
extern volatile __bit                   PWM119P4            @ (((unsigned) &PWM119CR)*8) + 4;
extern volatile __bit                   PWM119M             @ (((unsigned) &PWM119CR)*8) + 5;
extern volatile __bit                   PWM119OE            @ (((unsigned) &PWM119CR)*8) + 6;
extern volatile __bit                   PWM119EN            @ (((unsigned) &PWM119CR)*8) + 7;

extern volatile __bit                   PWM118P0            @ (((unsigned) &PWM118CR)*8) + 0;
extern volatile __bit                   PWM118P1            @ (((unsigned) &PWM118CR)*8) + 1;
extern volatile __bit                   PWM118P2            @ (((unsigned) &PWM118CR)*8) + 2;
extern volatile __bit                   PWM118P3            @ (((unsigned) &PWM118CR)*8) + 3;
extern volatile __bit                   PWM118P4            @ (((unsigned) &PWM118CR)*8) + 4;
extern volatile __bit                   PWM118M             @ (((unsigned) &PWM118CR)*8) + 5;
extern volatile __bit                   PWM118OE            @ (((unsigned) &PWM118CR)*8) + 6;
extern volatile __bit                   PWM118EN            @ (((unsigned) &PWM118CR)*8) + 7;

extern volatile __bit                   PWM117P0            @ (((unsigned) &PWM117CR)*8) + 0;
extern volatile __bit                   PWM117P1            @ (((unsigned) &PWM117CR)*8) + 1;
extern volatile __bit                   PWM117P2            @ (((unsigned) &PWM117CR)*8) + 2;
extern volatile __bit                   PWM117P3            @ (((unsigned) &PWM117CR)*8) + 3;
extern volatile __bit                   PWM117P4            @ (((unsigned) &PWM117CR)*8) + 4;
extern volatile __bit                   PWM117M             @ (((unsigned) &PWM117CR)*8) + 5;
extern volatile __bit                   PWM117OE            @ (((unsigned) &PWM117CR)*8) + 6;
extern volatile __bit                   PWM117EN            @ (((unsigned) &PWM117CR)*8) + 7;

extern volatile __bit                   PWM116P0            @ (((unsigned) &PWM116CR)*8) + 0;
extern volatile __bit                   PWM116P1            @ (((unsigned) &PWM116CR)*8) + 1;
extern volatile __bit                   PWM116P2            @ (((unsigned) &PWM116CR)*8) + 2;
extern volatile __bit                   PWM116P3            @ (((unsigned) &PWM116CR)*8) + 3;
extern volatile __bit                   PWM116P4            @ (((unsigned) &PWM116CR)*8) + 4;
extern volatile __bit                   PWM116M             @ (((unsigned) &PWM116CR)*8) + 5;
extern volatile __bit                   PWM116OE            @ (((unsigned) &PWM116CR)*8) + 6;
extern volatile __bit                   PWM116EN            @ (((unsigned) &PWM116CR)*8) + 7;

extern volatile __bit                   PWM115P0            @ (((unsigned) &PWM115CR)*8) + 0;
extern volatile __bit                   PWM115P1            @ (((unsigned) &PWM115CR)*8) + 1;
extern volatile __bit                   PWM115P2            @ (((unsigned) &PWM115CR)*8) + 2;
extern volatile __bit                   PWM115P3            @ (((unsigned) &PWM115CR)*8) + 3;
extern volatile __bit                   PWM115P4            @ (((unsigned) &PWM115CR)*8) + 4;
extern volatile __bit                   PWM115M             @ (((unsigned) &PWM115CR)*8) + 5;
extern volatile __bit                   PWM115OE            @ (((unsigned) &PWM115CR)*8) + 6;
extern volatile __bit                   PWM115EN            @ (((unsigned) &PWM115CR)*8) + 7;

extern volatile __bit                   PWM114P0            @ (((unsigned) &PWM114CR)*8) + 0;
extern volatile __bit                   PWM114P1            @ (((unsigned) &PWM114CR)*8) + 1;
extern volatile __bit                   PWM114P2            @ (((unsigned) &PWM114CR)*8) + 2;
extern volatile __bit                   PWM114P3            @ (((unsigned) &PWM114CR)*8) + 3;
extern volatile __bit                   PWM114P4            @ (((unsigned) &PWM114CR)*8) + 4;
extern volatile __bit                   PWM114M             @ (((unsigned) &PWM114CR)*8) + 5;
extern volatile __bit                   PWM114OE            @ (((unsigned) &PWM114CR)*8) + 6;
extern volatile __bit                   PWM114EN            @ (((unsigned) &PWM114CR)*8) + 7;

extern volatile __bit                   PWM113P0            @ (((unsigned) &PWM113CR)*8) + 0;
extern volatile __bit                   PWM113P1            @ (((unsigned) &PWM113CR)*8) + 1;
extern volatile __bit                   PWM113P2            @ (((unsigned) &PWM113CR)*8) + 2;
extern volatile __bit                   PWM113P3            @ (((unsigned) &PWM113CR)*8) + 3;
extern volatile __bit                   PWM113P4            @ (((unsigned) &PWM113CR)*8) + 4;
extern volatile __bit                   PWM113M             @ (((unsigned) &PWM113CR)*8) + 5;
extern volatile __bit                   PWM113OE            @ (((unsigned) &PWM113CR)*8) + 6;
extern volatile __bit                   PWM113EN            @ (((unsigned) &PWM113CR)*8) + 7;

extern volatile __bit                   PWM112P0            @ (((unsigned) &PWM112CR)*8) + 0;
extern volatile __bit                   PWM112P1            @ (((unsigned) &PWM112CR)*8) + 1;
extern volatile __bit                   PWM112P2            @ (((unsigned) &PWM112CR)*8) + 2;
extern volatile __bit                   PWM112P3            @ (((unsigned) &PWM112CR)*8) + 3;
extern volatile __bit                   PWM112P4            @ (((unsigned) &PWM112CR)*8) + 4;
extern volatile __bit                   PWM112M             @ (((unsigned) &PWM112CR)*8) + 5;
extern volatile __bit                   PWM112OE            @ (((unsigned) &PWM112CR)*8) + 6;
extern volatile __bit                   PWM112EN            @ (((unsigned) &PWM112CR)*8) + 7;

extern volatile __bit                   PWM111P0            @ (((unsigned) &PWM111CR)*8) + 0;
extern volatile __bit                   PWM111P1            @ (((unsigned) &PWM111CR)*8) + 1;
extern volatile __bit                   PWM111P2            @ (((unsigned) &PWM111CR)*8) + 2;
extern volatile __bit                   PWM111P3            @ (((unsigned) &PWM111CR)*8) + 3;
extern volatile __bit                   PWM111P4            @ (((unsigned) &PWM111CR)*8) + 4;
extern volatile __bit                   PWM111M             @ (((unsigned) &PWM111CR)*8) + 5;
extern volatile __bit                   PWM111OE            @ (((unsigned) &PWM111CR)*8) + 6;
extern volatile __bit                   PWM111EN            @ (((unsigned) &PWM111CR)*8) + 7;

extern volatile __bit                   PWM110P0            @ (((unsigned) &PWM110CR)*8) + 0;
extern volatile __bit                   PWM110P1            @ (((unsigned) &PWM110CR)*8) + 1;
extern volatile __bit                   PWM110P2            @ (((unsigned) &PWM110CR)*8) + 2;
extern volatile __bit                   PWM110P3            @ (((unsigned) &PWM110CR)*8) + 3;
extern volatile __bit                   PWM110P4            @ (((unsigned) &PWM110CR)*8) + 4;
extern volatile __bit                   PWM110M             @ (((unsigned) &PWM110CR)*8) + 5;
extern volatile __bit                   PWM110OE            @ (((unsigned) &PWM110CR)*8) + 6;
extern volatile __bit                   PWM110EN            @ (((unsigned) &PWM110CR)*8) + 7;

extern volatile __bit                   PWM109P0            @ (((unsigned) &PWM109CR)*8) + 0;
extern volatile __bit                   PWM109P1            @ (((unsigned) &PWM109CR)*8) + 1;
extern volatile __bit                   PWM109P2            @ (((unsigned) &PWM109CR)*8) + 2;
extern volatile __bit                   PWM109P3            @ (((unsigned) &PWM109CR)*8) + 3;
extern volatile __bit                   PWM109P4            @ (((unsigned) &PWM109CR)*8) + 4;
extern volatile __bit                   PWM109M             @ (((unsigned) &PWM109CR)*8) + 5;
extern volatile __bit                   PWM109OE            @ (((unsigned) &PWM109CR)*8) + 6;
extern volatile __bit                   PWM109EN            @ (((unsigned) &PWM109CR)*8) + 7;

extern volatile __bit                   PWM108P0            @ (((unsigned) &PWM108CR)*8) + 0;
extern volatile __bit                   PWM108P1            @ (((unsigned) &PWM108CR)*8) + 1;
extern volatile __bit                   PWM108P2            @ (((unsigned) &PWM108CR)*8) + 2;
extern volatile __bit                   PWM108P3            @ (((unsigned) &PWM108CR)*8) + 3;
extern volatile __bit                   PWM108P4            @ (((unsigned) &PWM108CR)*8) + 4;
extern volatile __bit                   PWM108M             @ (((unsigned) &PWM108CR)*8) + 5;
extern volatile __bit                   PWM108OE            @ (((unsigned) &PWM108CR)*8) + 6;
extern volatile __bit                   PWM108EN            @ (((unsigned) &PWM108CR)*8) + 7;

extern volatile __bit                   PWM107P0            @ (((unsigned) &PWM107CR)*8) + 0;
extern volatile __bit                   PWM107P1            @ (((unsigned) &PWM107CR)*8) + 1;
extern volatile __bit                   PWM107P2            @ (((unsigned) &PWM107CR)*8) + 2;
extern volatile __bit                   PWM107P3            @ (((unsigned) &PWM107CR)*8) + 3;
extern volatile __bit                   PWM107P4            @ (((unsigned) &PWM107CR)*8) + 4;
extern volatile __bit                   PWM107M             @ (((unsigned) &PWM107CR)*8) + 5;
extern volatile __bit                   PWM107OE            @ (((unsigned) &PWM107CR)*8) + 6;
extern volatile __bit                   PWM107EN            @ (((unsigned) &PWM107CR)*8) + 7;

extern volatile __bit                   PWM106P0            @ (((unsigned) &PWM106CR)*8) + 0;
extern volatile __bit                   PWM106P1            @ (((unsigned) &PWM106CR)*8) + 1;
extern volatile __bit                   PWM106P2            @ (((unsigned) &PWM106CR)*8) + 2;
extern volatile __bit                   PWM106P3            @ (((unsigned) &PWM106CR)*8) + 3;
extern volatile __bit                   PWM106P4            @ (((unsigned) &PWM106CR)*8) + 4;
extern volatile __bit                   PWM106M             @ (((unsigned) &PWM106CR)*8) + 5;
extern volatile __bit                   PWM106OE            @ (((unsigned) &PWM106CR)*8) + 6;
extern volatile __bit                   PWM106EN            @ (((unsigned) &PWM106CR)*8) + 7;

extern volatile __bit                   PWM105P0            @ (((unsigned) &PWM105CR)*8) + 0;
extern volatile __bit                   PWM105P1            @ (((unsigned) &PWM105CR)*8) + 1;
extern volatile __bit                   PWM105P2            @ (((unsigned) &PWM105CR)*8) + 2;
extern volatile __bit                   PWM105P3            @ (((unsigned) &PWM105CR)*8) + 3;
extern volatile __bit                   PWM105P4            @ (((unsigned) &PWM105CR)*8) + 4;
extern volatile __bit                   PWM105M             @ (((unsigned) &PWM105CR)*8) + 5;
extern volatile __bit                   PWM105OE            @ (((unsigned) &PWM105CR)*8) + 6;
extern volatile __bit                   PWM105EN            @ (((unsigned) &PWM105CR)*8) + 7;

extern volatile __bit                   PWM104P0            @ (((unsigned) &PWM104CR)*8) + 0;
extern volatile __bit                   PWM104P1            @ (((unsigned) &PWM104CR)*8) + 1;
extern volatile __bit                   PWM104P2            @ (((unsigned) &PWM104CR)*8) + 2;
extern volatile __bit                   PWM104P3            @ (((unsigned) &PWM104CR)*8) + 3;
extern volatile __bit                   PWM104P4            @ (((unsigned) &PWM104CR)*8) + 4;
extern volatile __bit                   PWM104M             @ (((unsigned) &PWM104CR)*8) + 5;
extern volatile __bit                   PWM104OE            @ (((unsigned) &PWM104CR)*8) + 6;
extern volatile __bit                   PWM104EN            @ (((unsigned) &PWM104CR)*8) + 7;

extern volatile __bit                   PWM103P0            @ (((unsigned) &PWM103CR)*8) + 0;
extern volatile __bit                   PWM103P1            @ (((unsigned) &PWM103CR)*8) + 1;
extern volatile __bit                   PWM103P2            @ (((unsigned) &PWM103CR)*8) + 2;
extern volatile __bit                   PWM103P3            @ (((unsigned) &PWM103CR)*8) + 3;
extern volatile __bit                   PWM103P4            @ (((unsigned) &PWM103CR)*8) + 4;
extern volatile __bit                   PWM103M             @ (((unsigned) &PWM103CR)*8) + 5;
extern volatile __bit                   PWM103OE            @ (((unsigned) &PWM103CR)*8) + 6;
extern volatile __bit                   PWM103EN            @ (((unsigned) &PWM103CR)*8) + 7;

extern volatile __bit                   PWM102P0            @ (((unsigned) &PWM102CR)*8) + 0;
extern volatile __bit                   PWM102P1            @ (((unsigned) &PWM102CR)*8) + 1;
extern volatile __bit                   PWM102P2            @ (((unsigned) &PWM102CR)*8) + 2;
extern volatile __bit                   PWM102P3            @ (((unsigned) &PWM102CR)*8) + 3;
extern volatile __bit                   PWM102P4            @ (((unsigned) &PWM102CR)*8) + 4;
extern volatile __bit                   PWM102M             @ (((unsigned) &PWM102CR)*8) + 5;
extern volatile __bit                   PWM102OE            @ (((unsigned) &PWM102CR)*8) + 6;
extern volatile __bit                   PWM102EN            @ (((unsigned) &PWM102CR)*8) + 7;

extern volatile __bit                   PWM101P0            @ (((unsigned) &PWM101CR)*8) + 0;
extern volatile __bit                   PWM101P1            @ (((unsigned) &PWM101CR)*8) + 1;
extern volatile __bit                   PWM101P2            @ (((unsigned) &PWM101CR)*8) + 2;
extern volatile __bit                   PWM101P3            @ (((unsigned) &PWM101CR)*8) + 3;
extern volatile __bit                   PWM101P4            @ (((unsigned) &PWM101CR)*8) + 4;
extern volatile __bit                   PWM101M             @ (((unsigned) &PWM101CR)*8) + 4;
extern volatile __bit                   PWM101OE            @ (((unsigned) &PWM101CR)*8) + 6;
extern volatile __bit                   PWM101EN            @ (((unsigned) &PWM101CR)*8) + 7;

extern volatile __bit                   PWM100P0            @ (((unsigned) &PWM100CR)*8) + 0;
extern volatile __bit                   PWM100P1            @ (((unsigned) &PWM100CR)*8) + 1;
extern volatile __bit                   PWM100P2            @ (((unsigned) &PWM100CR)*8) + 2;
extern volatile __bit                   PWM100P3            @ (((unsigned) &PWM100CR)*8) + 3;
extern volatile __bit                   PWM100P4            @ (((unsigned) &PWM100CR)*8) + 4;
extern volatile __bit                   PWM100M             @ (((unsigned) &PWM100CR)*8) + 4;
extern volatile __bit                   PWM100OE            @ (((unsigned) &PWM100CR)*8) + 6;
extern volatile __bit                   PWM100EN            @ (((unsigned) &PWM100CR)*8) + 7;


extern volatile __bit                   DEB0               @ (((unsigned) &CMPC2)*8) + 0;
extern volatile __bit                   DEB1               @ (((unsigned) &CMPC2)*8) + 1;
extern volatile __bit                   DEB2               @ (((unsigned) &CMPC2)*8) + 2;
extern volatile __bit                   CINTS0             @ (((unsigned) &CMPC2)*8) + 6;
extern volatile __bit                   CINTS1             @ (((unsigned) &CMPC2)*8) + 7;

extern volatile __bit                   CMPVLD0             @ (((unsigned) &CMPC1)*8) + 0;
extern volatile __bit                   CMPVLD1             @ (((unsigned) &CMPC1)*8) + 1;
extern volatile __bit                   CMPVLD2             @ (((unsigned) &CMPC1)*8) + 2;
extern volatile __bit                   CMPVLD3             @ (((unsigned) &CMPC1)*8) + 3;
extern volatile __bit                   CMPVLD4             @ (((unsigned) &CMPC1)*8) + 4;
extern volatile __bit                   CMPHIEN            @ (((unsigned) &CMPC1)*8) + 6;
extern volatile __bit                   CMPOEN             @ (((unsigned) &CMPC1)*8) + 7;

extern volatile __bit                   CMPPS0             @ (((unsigned) &CMPC0)*8) + 0;
extern volatile __bit                   CMPPS1             @ (((unsigned) &CMPC0)*8) + 1;
extern volatile __bit                   CMPPS2             @ (((unsigned) &CMPC0)*8) + 2;
extern volatile __bit                   CMPNS0             @ (((unsigned) &CMPC0)*8) + 3;
extern volatile __bit                   CMPNS1             @ (((unsigned) &CMPC0)*8) + 4;
extern volatile __bit                   CMPNS2             @ (((unsigned) &CMPC0)*8) + 5;
extern volatile __bit                   CMPOUT             @ (((unsigned) &CMPC0)*8) + 6;
extern volatile __bit                   CMPEN              @ (((unsigned) &CMPC0)*8) + 7;

extern volatile __bit                   PWM2PR8             @ (((unsigned) &PWM2PRH)*8) + 0;
extern volatile __bit                   PWM2PR9             @ (((unsigned) &PWM2PRH)*8) + 1;
extern volatile __bit                   PWM2PR10            @ (((unsigned) &PWM2PRH)*8) + 2;
extern volatile __bit                   PWM2PR11            @ (((unsigned) &PWM2PRH)*8) + 3;
extern volatile __bit                   PWM2PR12            @ (((unsigned) &PWM2PRH)*8) + 4;
extern volatile __bit                   PWM2PR13            @ (((unsigned) &PWM2PRH)*8) + 5;
extern volatile __bit                   PWM2PR14            @ (((unsigned) &PWM2PRH)*8) + 6;
extern volatile __bit                   PWM2PR15            @ (((unsigned) &PWM2PRH)*8) + 7;

extern volatile __bit                   PWM2PR0             @ (((unsigned) &PWM2PRL)*8) + 0;
extern volatile __bit                   PWM2PR1             @ (((unsigned) &PWM2PRL)*8) + 1;
extern volatile __bit                   PWM2PR2             @ (((unsigned) &PWM2PRL)*8) + 2;
extern volatile __bit                   PWM2PR3             @ (((unsigned) &PWM2PRL)*8) + 3;
extern volatile __bit                   PWM2PR4             @ (((unsigned) &PWM2PRL)*8) + 4;
extern volatile __bit                   PWM2PR5             @ (((unsigned) &PWM2PRL)*8) + 5;
extern volatile __bit                   PWM2PR6             @ (((unsigned) &PWM2PRL)*8) + 6;
extern volatile __bit                   PWM2PR7             @ (((unsigned) &PWM2PRL)*8) + 7;

extern volatile __bit                   PWM2_0POE           @ (((unsigned) &PWM2OE)*8) + 0;
extern volatile __bit                   PWM2_1POE           @ (((unsigned) &PWM2OE)*8) + 1;
extern volatile __bit                   PWM2_2POE           @ (((unsigned) &PWM2OE)*8) + 2;
extern volatile __bit                   PWM2_0NOE           @ (((unsigned) &PWM2OE)*8) + 3;
extern volatile __bit                   PWM2_1NOE           @ (((unsigned) &PWM2OE)*8) + 4;
extern volatile __bit                   PWM2_2NOE           @ (((unsigned) &PWM2OE)*8) + 5;
//extern volatile __bit                 xx                  @ (((unsigned) &PWM2OE)*8) + 6;
extern volatile __bit                   PWM2EN              @ (((unsigned) &PWM2OE)*8) + 7;

extern volatile __bit                   POSTPS0             @ (((unsigned) &PWM2CR0)*8) + 0;
extern volatile __bit                   POSTPS1             @ (((unsigned) &PWM2CR0)*8) + 1;
extern volatile __bit                   PTCLK0              @ (((unsigned) &PWM2CR0)*8) + 2;
extern volatile __bit                   PTCLK1              @ (((unsigned) &PWM2CR0)*8) + 3;
extern volatile __bit                   PTMOD0              @ (((unsigned) &PWM2CR0)*8) + 4;
extern volatile __bit                   PTMOD1              @ (((unsigned) &PWM2CR0)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2CR0)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2CR0)*8) + 7;

extern volatile __bit                   PWM2_2N8            @ (((unsigned) &PWM2_2NH)*8 + 0;
extern volatile __bit                   PWM2_2N9            @ (((unsigned) &PWM2_2NH)*8 + 1;
extern volatile __bit                   PWM2_2N10           @ (((unsigned) &PWM2_2NH)*8 + 2;
extern volatile __bit                   PWM2_2N11           @ (((unsigned) &PWM2_2NH)*8 + 3;
extern volatile __bit                   PWM2_2N12           @ (((unsigned) &PWM2_2NH)*8 + 4;
extern volatile __bit                   PWM2_2N13           @ (((unsigned) &PWM2_2NH)*8 + 5;
extern volatile __bit                   PWM2_2N14           @ (((unsigned) &PWM2_2NH)*8 + 6;
extern volatile __bit                   PWM2_2N15           @ (((unsigned) &PWM2_2NH)*8 + 7;

extern volatile __bit                   PWM2_2N0            @ (((unsigned) &PWM2_2NL)*8 + 0;
extern volatile __bit                   PWM2_2N1            @ (((unsigned) &PWM2_2NL)*8 + 1;
extern volatile __bit                   PWM2_2N2            @ (((unsigned) &PWM2_2NL)*8 + 2;
extern volatile __bit                   PWM2_2N3            @ (((unsigned) &PWM2_2NL)*8 + 3;
extern volatile __bit                   PWM2_2N4            @ (((unsigned) &PWM2_2NL)*8 + 4;
extern volatile __bit                   PWM2_2N5            @ (((unsigned) &PWM2_2NL)*8 + 5;
extern volatile __bit                   PWM2_2N6            @ (((unsigned) &PWM2_2NL)*8 + 6;
extern volatile __bit                   PWM2_2N7            @ (((unsigned) &PWM2_2NL)*8 + 7;

extern volatile __bit                   PWM2_1N8            @ (((unsigned) &PWM2_1NH)*8 + 0;
extern volatile __bit                   PWM2_1N9            @ (((unsigned) &PWM2_1NH)*8 + 1;
extern volatile __bit                   PWM2_1N10           @ (((unsigned) &PWM2_1NH)*8 + 2;
extern volatile __bit                   PWM2_1N11           @ (((unsigned) &PWM2_1NH)*8 + 3;
extern volatile __bit                   PWM2_1N12           @ (((unsigned) &PWM2_1NH)*8 + 4;
extern volatile __bit                   PWM2_1N13           @ (((unsigned) &PWM2_1NH)*8 + 5;
extern volatile __bit                   PWM2_1N14           @ (((unsigned) &PWM2_1NH)*8 + 6;
extern volatile __bit                   PWM2_1N15           @ (((unsigned) &PWM2_1NH)*8 + 7;

extern volatile __bit                   PWM2_1N0            @ (((unsigned) &PWM2_1NL)*8 + 0;
extern volatile __bit                   PWM2_1N1            @ (((unsigned) &PWM2_1NL)*8 + 1;
extern volatile __bit                   PWM2_1N2            @ (((unsigned) &PWM2_1NL)*8 + 2;
extern volatile __bit                   PWM2_1N3            @ (((unsigned) &PWM2_1NL)*8 + 3;
extern volatile __bit                   PWM2_1N4            @ (((unsigned) &PWM2_1NL)*8 + 4;
extern volatile __bit                   PWM2_1N5            @ (((unsigned) &PWM2_1NL)*8 + 5;
extern volatile __bit                   PWM2_1N6            @ (((unsigned) &PWM2_1NL)*8 + 6;
extern volatile __bit                   PWM2_1N7            @ (((unsigned) &PWM2_1NL)*8 + 7;

extern volatile __bit                   PWM2_0N8            @ (((unsigned) &PWM2_0NH)*8 + 0;
extern volatile __bit                   PWM2_0N9            @ (((unsigned) &PWM2_0NH)*8 + 1;
extern volatile __bit                   PWM2_0N10           @ (((unsigned) &PWM2_0NH)*8 + 2;
extern volatile __bit                   PWM2_0N11           @ (((unsigned) &PWM2_0NH)*8 + 3;
extern volatile __bit                   PWM2_0N12           @ (((unsigned) &PWM2_0NH)*8 + 4;
extern volatile __bit                   PWM2_0N13           @ (((unsigned) &PWM2_0NH)*8 + 5;
extern volatile __bit                   PWM2_0N14           @ (((unsigned) &PWM2_0NH)*8 + 6;
extern volatile __bit                   PWM2_0N15           @ (((unsigned) &PWM2_0NH)*8 + 7;

extern volatile __bit                   PWM2_0N0            @ (((unsigned) &PWM2_0NL)*8 + 0;
extern volatile __bit                   PWM2_0N1            @ (((unsigned) &PWM2_0NL)*8 + 1;
extern volatile __bit                   PWM2_0N2            @ (((unsigned) &PWM2_0NL)*8 + 2;
extern volatile __bit                   PWM2_0N3            @ (((unsigned) &PWM2_0NL)*8 + 3;
extern volatile __bit                   PWM2_0N4            @ (((unsigned) &PWM2_0NL)*8 + 4;
extern volatile __bit                   PWM2_0N5            @ (((unsigned) &PWM2_0NL)*8 + 5;
extern volatile __bit                   PWM2_0N6            @ (((unsigned) &PWM2_0NL)*8 + 6;
extern volatile __bit                   PWM2_0N7            @ (((unsigned) &PWM2_0NL)*8 + 7;

extern volatile __bit                   PWM2_2P8            @ (((unsigned) &PWM2_2PH)*8 + 0;
extern volatile __bit                   PWM2_2P9            @ (((unsigned) &PWM2_2PH)*8 + 1;
extern volatile __bit                   PWM2_2P10           @ (((unsigned) &PWM2_2PH)*8 + 2;
extern volatile __bit                   PWM2_2P11           @ (((unsigned) &PWM2_2PH)*8 + 3;
extern volatile __bit                   PWM2_2P12           @ (((unsigned) &PWM2_2PH)*8 + 4;
extern volatile __bit                   PWM2_2P13           @ (((unsigned) &PWM2_2PH)*8 + 5;
extern volatile __bit                   PWM2_2P14           @ (((unsigned) &PWM2_2PH)*8 + 6;
extern volatile __bit                   PWM2_2P15           @ (((unsigned) &PWM2_2PH)*8 + 7;

extern volatile __bit                   PWM2_2P0            @ (((unsigned) &PWM2_2PL)*8 + 0;
extern volatile __bit                   PWM2_2P1            @ (((unsigned) &PWM2_2PL)*8 + 1;
extern volatile __bit                   PWM2_2P2            @ (((unsigned) &PWM2_2PL)*8 + 2;
extern volatile __bit                   PWM2_2P3            @ (((unsigned) &PWM2_2PL)*8 + 3;
extern volatile __bit                   PWM2_2P4            @ (((unsigned) &PWM2_2PL)*8 + 4;
extern volatile __bit                   PWM2_2P5            @ (((unsigned) &PWM2_2PL)*8 + 5;
extern volatile __bit                   PWM2_2P6            @ (((unsigned) &PWM2_2PL)*8 + 6;
extern volatile __bit                   PWM2_2P7            @ (((unsigned) &PWM2_2PL)*8 + 7;

extern volatile __bit                   PWM2_1P8            @ (((unsigned) &PWM2_1PH)*8 + 0;
extern volatile __bit                   PWM2_1P9            @ (((unsigned) &PWM2_1PH)*8 + 1;
extern volatile __bit                   PWM2_1P10           @ (((unsigned) &PWM2_1PH)*8 + 2;
extern volatile __bit                   PWM2_1P11           @ (((unsigned) &PWM2_1PH)*8 + 3;
extern volatile __bit                   PWM2_1P12           @ (((unsigned) &PWM2_1PH)*8 + 4;
extern volatile __bit                   PWM2_1P13           @ (((unsigned) &PWM2_1PH)*8 + 5;
extern volatile __bit                   PWM2_1P14           @ (((unsigned) &PWM2_1PH)*8 + 6;
extern volatile __bit                   PWM2_1P15           @ (((unsigned) &PWM2_1PH)*8 + 7;

extern volatile __bit                   PWM2_1P0            @ (((unsigned) &PWM2_1PL)*8 + 0;
extern volatile __bit                   PWM2_1P1            @ (((unsigned) &PWM2_1PL)*8 + 1;
extern volatile __bit                   PWM2_1P2            @ (((unsigned) &PWM2_1PL)*8 + 2;
extern volatile __bit                   PWM2_1P3            @ (((unsigned) &PWM2_1PL)*8 + 3;
extern volatile __bit                   PWM2_1P4            @ (((unsigned) &PWM2_1PL)*8 + 4;
extern volatile __bit                   PWM2_1P5            @ (((unsigned) &PWM2_1PL)*8 + 5;
extern volatile __bit                   PWM2_1P6            @ (((unsigned) &PWM2_1PL)*8 + 6;
extern volatile __bit                   PWM2_1P7            @ (((unsigned) &PWM2_1PL)*8 + 7;

extern volatile __bit                   PWM2_0P8            @ (((unsigned) &PWM2_0PH)*8 + 0;
extern volatile __bit                   PWM2_0P9            @ (((unsigned) &PWM2_0PH)*8 + 1;
extern volatile __bit                   PWM2_0P10           @ (((unsigned) &PWM2_0PH)*8 + 2;
extern volatile __bit                   PWM2_0P11           @ (((unsigned) &PWM2_0PH)*8 + 3;
extern volatile __bit                   PWM2_0P12           @ (((unsigned) &PWM2_0PH)*8 + 4;
extern volatile __bit                   PWM2_0P13           @ (((unsigned) &PWM2_0PH)*8 + 5;
extern volatile __bit                   PWM2_0P14           @ (((unsigned) &PWM2_0PH)*8 + 6;
extern volatile __bit                   PWM2_0P15           @ (((unsigned) &PWM2_0PH)*8 + 7;

extern volatile __bit                   PWM2_0P0            @ (((unsigned) &PWM2_0PL)*8 + 0;
extern volatile __bit                   PWM2_0P1            @ (((unsigned) &PWM2_0PL)*8 + 1;
extern volatile __bit                   PWM2_0P2            @ (((unsigned) &PWM2_0PL)*8 + 2;
extern volatile __bit                   PWM2_0P3            @ (((unsigned) &PWM2_0PL)*8 + 3;
extern volatile __bit                   PWM2_0P4            @ (((unsigned) &PWM2_0PL)*8 + 4;
extern volatile __bit                   PWM2_0P5            @ (((unsigned) &PWM2_0PL)*8 + 5;
extern volatile __bit                   PWM2_0P6            @ (((unsigned) &PWM2_0PL)*8 + 6;
extern volatile __bit                   PWM2_0P7            @ (((unsigned) &PWM2_0PL)*8 + 7;

extern volatile __bit                   PWM2RLDEN0          @ (((unsigned) &PWM2RLDEN)*8) + 0;
extern volatile __bit                   PWM2RLDEN1          @ (((unsigned) &PWM2RLDEN)*8) + 1;
extern volatile __bit                   PWM2RLDEN2          @ (((unsigned) &PWM2RLDEN)*8) + 2;
extern volatile __bit                   PWM2RLDEN3          @ (((unsigned) &PWM2RLDEN)*8) + 3;
extern volatile __bit                   PWM2RLDEN4          @ (((unsigned) &PWM2RLDEN)*8) + 4;
extern volatile __bit                   PWM2RLDEN5          @ (((unsigned) &PWM2RLDEN)*8) + 5;
extern volatile __bit                   PWM2RLDEN6          @ (((unsigned) &PWM2RLDEN)*8) + 6;
extern volatile __bit                   PWM2RLDEN7          @ (((unsigned) &PWM2RLDEN)*8) + 7;

extern volatile __bit                   PTUD2_0IF           @ (((unsigned) &PWM2INTF)*8) + 0;
extern volatile __bit                   PTDD2_0IF           @ (((unsigned) &PWM2INTF)*8) + 1;
extern volatile __bit                   PTUD2_1IF           @ (((unsigned) &PWM2INTF)*8) + 2;
extern volatile __bit                   PTDD2_1IF           @ (((unsigned) &PWM2INTF)*8) + 3;
extern volatile __bit                   PTUD2_2IF           @ (((unsigned) &PWM2INTF)*8) + 4;
extern volatile __bit                   PTDD2_2IF           @ (((unsigned) &PWM2INTF)*8) + 5;
extern volatile __bit                   PWMZIF              @ (((unsigned) &PWM2INTF)*8) + 6;
extern volatile __bit                   PWMPIF              @ (((unsigned) &PWM2INTF)*8) + 7;

extern volatile __bit                   PTUD2_0IE           @ (((unsigned) &PWM2INTCR)*8) + 0;
extern volatile __bit                   PTDD2_0IE           @ (((unsigned) &PWM2INTCR)*8) + 1;
extern volatile __bit                   PTUD2_1IE           @ (((unsigned) &PWM2INTCR)*8) + 2;
extern volatile __bit                   PTDD2_1IE           @ (((unsigned) &PWM2INTCR)*8) + 3;
extern volatile __bit                   PTUD2_2IE           @ (((unsigned) &PWM2INTCR)*8) + 4;
extern volatile __bit                   PTDD2_2IE           @ (((unsigned) &PWM2INTCR)*8) + 5;
extern volatile __bit                   PWMZIE              @ (((unsigned) &PWM2INTCR)*8) + 6;
extern volatile __bit                   PWMPIE              @ (((unsigned) &PWM2INTCR)*8) + 7;

extern volatile __bit                   FLTSTAT             @ (((unsigned) &FLTCR)*8) + 0;
extern volatile __bit                   FLTM                @ (((unsigned) &FLTCR)*8) + 1;
extern volatile __bit                   FLT2DEB0            @ (((unsigned) &FLTCR)*8) + 2;
extern volatile __bit                   FLT2DEB1            @ (((unsigned) &FLTCR)*8) + 3;
extern volatile __bit                   FLT2S               @ (((unsigned) &FLTCR)*8) + 4;
extern volatile __bit                   FLT2EN              @ (((unsigned) &FLTCR)*8) + 5;
extern volatile __bit                   FLT1SEL             @ (((unsigned) &FLTCR)*8) + 6;
extern volatile __bit                   FLT1EN              @ (((unsigned) &FLTCR)*8) + 7;

extern volatile __bit                   PWM2DT18            @ (((unsigned) &PWM2DT1H)*8) + 0;
extern volatile __bit                   PWM2DT19            @ (((unsigned) &PWM2DT1H)*8) + 1;
extern volatile __bit                   PWM2DT110           @ (((unsigned) &PWM2DT1H)*8) + 2;
extern volatile __bit                   PWM2DT111           @ (((unsigned) &PWM2DT1H)*8) + 3;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT1H)*8) + 4;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT1H)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT1H)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT1H)*8) + 7;

extern volatile __bit                   PWM2DT10            @ (((unsigned) &PWM2DT1L)*8) + 0;
extern volatile __bit                   PWM2DT11            @ (((unsigned) &PWM2DT1L)*8) + 1;
extern volatile __bit                   PWM2DT12            @ (((unsigned) &PWM2DT1L)*8) + 2;
extern volatile __bit                   PWM2DT13            @ (((unsigned) &PWM2DT1L)*8) + 3;
extern volatile __bit                   PWM2DT14            @ (((unsigned) &PWM2DT1L)*8) + 4;
extern volatile __bit                   PWM2DT15            @ (((unsigned) &PWM2DT1L)*8) + 5;
extern volatile __bit                   PWM2DT16            @ (((unsigned) &PWM2DT1L)*8) + 6;
extern volatile __bit                   PWM2DT17            @ (((unsigned) &PWM2DT1L)*8) + 7;

extern volatile __bit                   PWM2DT08            @ (((unsigned) &PWM2DT0H)*8) + 0;
extern volatile __bit                   PWM2DT09            @ (((unsigned) &PWM2DT0H)*8) + 1;
extern volatile __bit                   PWM2DT010           @ (((unsigned) &PWM2DT0H)*8) + 2;
extern volatile __bit                   PWM2DT011           @ (((unsigned) &PWM2DT0H)*8) + 3;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT0H)*8) + 4;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT0H)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT0H)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2DT0H)*8) + 7;

extern volatile __bit                   PWM2DT00            @ (((unsigned) &PWM2DT0L)*8) + 0;
extern volatile __bit                   PWM2DT01            @ (((unsigned) &PWM2DT0L)*8) + 1;
extern volatile __bit                   PWM2DT02            @ (((unsigned) &PWM2DT0L)*8) + 2;
extern volatile __bit                   PWM2DT03            @ (((unsigned) &PWM2DT0L)*8) + 3;
extern volatile __bit                   PWM2DT04            @ (((unsigned) &PWM2DT0L)*8) + 4;
extern volatile __bit                   PWM2DT05            @ (((unsigned) &PWM2DT0L)*8) + 5;
extern volatile __bit                   PWM2DT06            @ (((unsigned) &PWM2DT0L)*8) + 6;
extern volatile __bit                   PWM2DT07            @ (((unsigned) &PWM2DT0L)*8) + 7;

extern volatile __bit                   POUT2_0P            @ (((unsigned) &PMANUALCR1)*8) + 0;
extern volatile __bit                   POUT2_1P            @ (((unsigned) &PMANUALCR1)*8) + 1;
extern volatile __bit                   POUT2_2P            @ (((unsigned) &PMANUALCR1)*8) + 2;
extern volatile __bit                   POUT2_0N            @ (((unsigned) &PMANUALCR1)*8) + 3;
extern volatile __bit                   POUT2_1N            @ (((unsigned) &PMANUALCR1)*8) + 4;
extern volatile __bit                   POUT2_2N            @ (((unsigned) &PMANUALCR1)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &PMANUALCR1)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PMANUALCR1)*8) + 7;

extern volatile __bit                   PMANUAL2_0P         @ (((unsigned) &PMANUALCR0)*8) + 0;
extern volatile __bit                   PMANUAL2_1P         @ (((unsigned) &PMANUALCR0)*8) + 1;
extern volatile __bit                   PMANUAL2_2P         @ (((unsigned) &PMANUALCR0)*8) + 2;
extern volatile __bit                   PMANUAL2_0N         @ (((unsigned) &PMANUALCR0)*8) + 3;
extern volatile __bit                   PMANUAL2_1N         @ (((unsigned) &PMANUALCR0)*8) + 4;
extern volatile __bit                   PMANUAL2_2N         @ (((unsigned) &PMANUALCR0)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &PMANUALCR0)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PMANUALCR0)*8) + 7;

extern volatile __bit                   DT0                 @ (((unsigned) &PWM2CR2)*8) + 0;
extern volatile __bit                   DT1                 @ (((unsigned) &PWM2CR2)*8) + 1;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2CR2)*8) + 2;
extern volatile __bit                   PDLDEN              @ (((unsigned) &PWM2CR2)*8) + 3;
extern volatile __bit                   ZEAD                @ (((unsigned) &PWM2CR2)*8) + 4;
extern volatile __bit                   PEAD                @ (((unsigned) &PWM2CR2)*8) + 5;
extern volatile __bit                   ZETIM               @ (((unsigned) &PWM2CR2)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &PWM2CR2)*8) + 7;

extern volatile __bit                   PWM2_0PS             @ (((unsigned) &PWM2CR1)*8) + 0;
extern volatile __bit                   PWM2_1PS             @ (((unsigned) &PWM2CR1)*8) + 1;
extern volatile __bit                   PWM2_2PS             @ (((unsigned) &PWM2CR1)*8) + 2;
extern volatile __bit                   PWM2_0NS             @ (((unsigned) &PWM2CR1)*8) + 3;
extern volatile __bit                   PWM2_1NS             @ (((unsigned) &PWM2CR1)*8) + 4;
extern volatile __bit                   PWM2_2NS             @ (((unsigned) &PWM2CR1)*8) + 5;
//extern volatile __bit                 xxx                  @ (((unsigned) &PWM2CR1)*8) + 6;
extern volatile __bit                   POUT                 @ (((unsigned) &PWM2CR1)*8) + 7;

extern volatile __bit                   WDTCR0              @ (((unsigned) &WDTCR)*8) + 0;
extern volatile __bit                   WDTCR1              @ (((unsigned) &WDTCR)*8) + 1;
extern volatile __bit                   WDTT0               @ (((unsigned) &WDTCR)*8) + 2;
extern volatile __bit                   WDTT1               @ (((unsigned) &WDTCR)*8) + 3;
extern volatile __bit                   WDTT2               @ (((unsigned) &WDTCR)*8) + 4;

extern volatile __bit                   IRCCAH0             @ (((unsigned) &IRCCAH)*8) + 0;
extern volatile __bit                   IRCCAH1             @ (((unsigned) &IRCCAH)*8) + 1;
extern volatile __bit                   IRCCAH2             @ (((unsigned) &IRCCAH)*8) + 2;
extern volatile __bit                   IRCCAH3             @ (((unsigned) &IRCCAH)*8) + 3;
extern volatile __bit                   IRCCAH4             @ (((unsigned) &IRCCAH)*8) + 4;
extern volatile __bit                   IRCCAH5             @ (((unsigned) &IRCCAH)*8) + 5;
extern volatile __bit                   IRCCAH6             @ (((unsigned) &IRCCAH)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &IRCCAH)*8) + 7;

extern volatile __bit                   IRCCAL0             @ (((unsigned) &IRCCAL)*8) + 0;
extern volatile __bit                   IRCCAL1             @ (((unsigned) &IRCCAL)*8) + 1;
extern volatile __bit                   IRCCAL2             @ (((unsigned) &IRCCAL)*8) + 2;
extern volatile __bit                   IRCCAL3             @ (((unsigned) &IRCCAL)*8) + 3;
extern volatile __bit                   IRCCAL4             @ (((unsigned) &IRCCAL)*8) + 4;
extern volatile __bit                   IRCCAL5             @ (((unsigned) &IRCCAL)*8) + 5;
extern volatile __bit                   IRCCAL6             @ (((unsigned) &IRCCAL)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &IRCCAL)*8) + 7;

extern volatile __bit                   CALLOCK0            @ (((unsigned) &CALLOCK)*8) + 0;
extern volatile __bit                   CALLOCK1            @ (((unsigned) &CALLOCK)*8) + 1;
extern volatile __bit                   CALLOCK2            @ (((unsigned) &CALLOCK)*8) + 2;
extern volatile __bit                   CALLOCK3            @ (((unsigned) &CALLOCK)*8) + 3;
extern volatile __bit                   CALLOCK4            @ (((unsigned) &CALLOCK)*8) + 4;
extern volatile __bit                   CALLOCK5            @ (((unsigned) &CALLOCK)*8) + 5;
extern volatile __bit                   CALLOCK6            @ (((unsigned) &CALLOCK)*8) + 6;
extern volatile __bit                   CALLOCK7            @ (((unsigned) &CALLOCK)*8) + 7;

extern volatile __bit                   C1ADDF              @ (((unsigned) &I2C1SR)*8) + 0;
extern volatile __bit                   C1NACKF             @ (((unsigned) &I2C1SR)*8) + 1;
extern volatile __bit                   S1IF                @ (((unsigned) &I2C1SR)*8) + 2;
extern volatile __bit                   C1BF                @ (((unsigned) &I2C1SR)*8) + 3;
extern volatile __bit                   C1AD                @ (((unsigned) &I2C1SR)*8) + 4;
extern volatile __bit                   C1DIR               @ (((unsigned) &I2C1SR)*8) + 5;
extern volatile __bit                   C1AL                @ (((unsigned) &I2C1SR)*8) + 6;
extern volatile __bit                   C1ROV               @ (((unsigned) &I2C1SR)*8) + 7;

extern volatile __bit                   C1DBUF0             @ (((unsigned) &I2C1DBUF)*8) + 0;
extern volatile __bit                   C1DBUF1             @ (((unsigned) &I2C1DBUF)*8) + 1;
extern volatile __bit                   C1DBUF2             @ (((unsigned) &I2C1DBUF)*8) + 2;
extern volatile __bit                   C1DBUF3             @ (((unsigned) &I2C1DBUF)*8) + 3;
extern volatile __bit                   C1DBUF4             @ (((unsigned) &I2C1DBUF)*8) + 4;
extern volatile __bit                   C1DBUF5             @ (((unsigned) &I2C1DBUF)*8) + 5;
extern volatile __bit                   C1DBUF6             @ (((unsigned) &I2C1DBUF)*8) + 6;
extern volatile __bit                   C1DBUF7             @ (((unsigned) &I2C1DBUF)*8) + 7;

extern volatile __bit                   C1PRESC0            @ (((unsigned) &I2C1PRESC)*8) + 0;
extern volatile __bit                   C1PRESC1            @ (((unsigned) &I2C1PRESC)*8) + 1;
extern volatile __bit                   C1PRESC2            @ (((unsigned) &I2C1PRESC)*8) + 2;
extern volatile __bit                   C1PRESC3            @ (((unsigned) &I2C1PRESC)*8) + 3;
//extern volatile __bit                 xxx                 @ (((unsigned) &I2C1PRESC)*8) + 4;
//extern volatile __bit                 xxx                 @ (((unsigned) &I2C1PRESC)*8) + 5;
//extern volatile __bit                 xxx                 @ (((unsigned) &I2C1PRESC)*8) + 6;
//extern volatile __bit                 xxx                 @ (((unsigned) &I2C1PRESC)*8) + 7;

extern volatile __bit                   C1OAR0              @ (((unsigned) &I2C1OAR)*8) + 0;
extern volatile __bit                   C1OAR1              @ (((unsigned) &I2C1OAR)*8) + 1;
extern volatile __bit                   C1OAR2              @ (((unsigned) &I2C1OAR)*8) + 2;
extern volatile __bit                   C1OAR3              @ (((unsigned) &I2C1OAR)*8) + 3;
extern volatile __bit                   C1OAR4              @ (((unsigned) &I2C1OAR)*8) + 4;
extern volatile __bit                   C1OAR5              @ (((unsigned) &I2C1OAR)*8) + 5;
extern volatile __bit                   C1OAR6              @ (((unsigned) &I2C1OAR)*8) + 6;
extern volatile __bit                   C1OAR7              @ (((unsigned) &I2C1OAR)*8) + 7;

extern volatile __bit                   C1OAR8              @ (((unsigned) &I2C1CR2)*8) + 0;
extern volatile __bit                   C1OAR9              @ (((unsigned) &I2C1CR2)*8) + 1;
extern volatile __bit                   S1MODE0             @ (((unsigned) &I2C1CR2)*8) + 2;
extern volatile __bit                   S1MODE1             @ (((unsigned) &I2C1CR2)*8) + 3;
extern volatile __bit                   C1ADDR10            @ (((unsigned) &I2C1CR2)*8) + 4;
extern volatile __bit                   C1ACK               @ (((unsigned) &I2C1CR2)*8) + 5;
extern volatile __bit                   S1SDIS              @ (((unsigned) &I2C1CR2)*8) + 6;
extern volatile __bit                   S1MLS               @ (((unsigned) &I2C1CR2)*8) + 7;

extern volatile __bit                   C1GCEN              @ (((unsigned) &I2C1CR1)*8) + 0;
extern volatile __bit                   C1NT0               @ (((unsigned) &I2C1CR1)*8) + 1;
extern volatile __bit                   C1NT1               @ (((unsigned) &I2C1CR1)*8) + 2;
extern volatile __bit                   C1MS                @ (((unsigned) &I2C1CR1)*8) + 3;
extern volatile __bit                   C1SP                @ (((unsigned) &I2C1CR1)*8) + 4;
extern volatile __bit                   C1SR                @ (((unsigned) &I2C1CR1)*8) + 5;
extern volatile __bit                   S1EN                @ (((unsigned) &I2C1CR1)*8) + 6;
extern volatile __bit                   C1EN                @ (((unsigned) &I2C1CR1)*8) + 7;

extern volatile __bit                   BRGD10              @ (((unsigned) &BRGD1L)*8) + 0;
extern volatile __bit                   BRGD11              @ (((unsigned) &BRGD1L)*8) + 1;
extern volatile __bit                   BRGD12              @ (((unsigned) &BRGD1L)*8) + 2;
extern volatile __bit                   BRGD13              @ (((unsigned) &BRGD1L)*8) + 3;
extern volatile __bit                   BRGD14              @ (((unsigned) &BRGD1L)*8) + 4;
extern volatile __bit                   BRGD15              @ (((unsigned) &BRGD1L)*8) + 5;
extern volatile __bit                   BRGD16              @ (((unsigned) &BRGD1L)*8) + 6;
extern volatile __bit                   BRGD17              @ (((unsigned) &BRGD1L)*8) + 7;

extern volatile __bit                   BRGD18              @ (((unsigned) &BRGD1H)*8) + 0;
extern volatile __bit                   BRGD19              @ (((unsigned) &BRGD1H)*8) + 1;
//extern volatile __bit                 xxxx                @ (((unsigned) &BRGD1H)*8) + 2;
//extern volatile __bit                 xxxx                @ (((unsigned) &BRGD1H)*8) + 3;
//extern volatile __bit                 xxxx                @ (((unsigned) &BRGD1H)*8) + 4;
//extern volatile __bit                 xxxx                @ (((unsigned) &BRGD1H)*8) + 5;
//extern volatile __bit                 xxxx                @ (((unsigned) &BRGD1H)*8) + 6;
extern volatile __bit                   SBYTE1              @ (((unsigned) &BRGD1H)*8) + 7;

extern volatile __bit                   RX1D0               @ (((unsigned) &RX1REG)*8) + 0;
extern volatile __bit                   RX1D1               @ (((unsigned) &RX1REG)*8) + 1;
extern volatile __bit                   RX1D2               @ (((unsigned) &RX1REG)*8) + 2;
extern volatile __bit                   RX1D3               @ (((unsigned) &RX1REG)*8) + 3;
extern volatile __bit                   RX1D4               @ (((unsigned) &RX1REG)*8) + 4;
extern volatile __bit                   RX1D5               @ (((unsigned) &RX1REG)*8) + 5;
extern volatile __bit                   RX1D6               @ (((unsigned) &RX1REG)*8) + 6;
extern volatile __bit                   RX1D7               @ (((unsigned) &RX1REG)*8) + 7;

extern volatile __bit                   R1D9                @ (((unsigned) &RX1CR)*8) + 0;
extern volatile __bit                   FR1ER               @ (((unsigned) &RX1CR)*8) + 1;
extern volatile __bit                   R1OVF               @ (((unsigned) &RX1CR)*8) + 2;
extern volatile __bit                   SR1EN               @ (((unsigned) &RX1CR)*8) + 3;
extern volatile __bit                   R1L9                @ (((unsigned) &RX1CR)*8) + 4;
//extern volatile __bit                 xxx                 @ (((unsigned) &RX1CR)*8) + 5;
extern volatile __bit                   R1CKPS              @ (((unsigned) &RX1CR)*8) + 6;
extern volatile __bit                   RX1EN               @ (((unsigned) &RX1CR)*8) + 7;

extern volatile __bit                   TX1D0               @ (((unsigned) &TX1REG)*8) + 0;
extern volatile __bit                   TX1D1               @ (((unsigned) &TX1REG)*8) + 1;
extern volatile __bit                   TX1D2               @ (((unsigned) &TX1REG)*8) + 2;
extern volatile __bit                   TX1D3               @ (((unsigned) &TX1REG)*8) + 3;
extern volatile __bit                   TX1D4               @ (((unsigned) &TX1REG)*8) + 4;
extern volatile __bit                   TX1D5               @ (((unsigned) &TX1REG)*8) + 5;
extern volatile __bit                   TX1D6               @ (((unsigned) &TX1REG)*8) + 6;
extern volatile __bit                   TX1D7               @ (((unsigned) &TX1REG)*8) + 7;

extern volatile __bit                   T1D9                @ (((unsigned) &TX1CR)*8) + 0;
extern volatile __bit                   T1SPD0              @ (((unsigned) &TX1CR)*8) + 1;
extern volatile __bit                   T1SPD1              @ (((unsigned) &TX1CR)*8) + 2;
extern volatile __bit                   T1SLAVE             @ (((unsigned) &TX1CR)*8) + 3;
extern volatile __bit                   T1L9                @ (((unsigned) &TX1CR)*8) + 4;
extern volatile __bit                   T1SYNC              @ (((unsigned) &TX1CR)*8) + 5;
extern volatile __bit                   T1MCLR              @ (((unsigned) &TX1CR)*8) + 6;
extern volatile __bit                   TX1EN               @ (((unsigned) &TX1CR)*8) + 7;

extern volatile __bit                   IOFIPS10            @ (((unsigned) &IOFIPS1)*8) + 0;
extern volatile __bit                   IOFIPS11            @ (((unsigned) &IOFIPS1)*8) + 1;
extern volatile __bit                   IOFIPS12            @ (((unsigned) &IOFIPS1)*8) + 2;
extern volatile __bit                   IOFIPS13            @ (((unsigned) &IOFIPS1)*8) + 3;
extern volatile __bit                   IOFIPS14            @ (((unsigned) &IOFIPS1)*8) + 4;
extern volatile __bit                   IOFIPS15            @ (((unsigned) &IOFIPS1)*8) + 5;
extern volatile __bit                   IOFIPS16            @ (((unsigned) &IOFIPS1)*8) + 6;
extern volatile __bit                   IOFIPS17            @ (((unsigned) &IOFIPS1)*8) + 7;

extern volatile __bit                   IOEIPS10            @ (((unsigned) &IOEIPS1)*8) + 0;
extern volatile __bit                   IOEIPS11            @ (((unsigned) &IOEIPS1)*8) + 1;
extern volatile __bit                   IOEIPS12            @ (((unsigned) &IOEIPS1)*8) + 2;
extern volatile __bit                   IOEIPS13            @ (((unsigned) &IOEIPS1)*8) + 3;
extern volatile __bit                   IOEIPS14            @ (((unsigned) &IOEIPS1)*8) + 4;
extern volatile __bit                   IOEIPS15            @ (((unsigned) &IOEIPS1)*8) + 5;
extern volatile __bit                   IOEIPS16            @ (((unsigned) &IOEIPS1)*8) + 6;
extern volatile __bit                   IOEIPS17            @ (((unsigned) &IOEIPS1)*8) + 7;

extern volatile __bit                   IODIPS10            @ (((unsigned) &IODIPS1)*8) + 0;
extern volatile __bit                   IODIPS11            @ (((unsigned) &IODIPS1)*8) + 1;
extern volatile __bit                   IODIPS12            @ (((unsigned) &IODIPS1)*8) + 2;
extern volatile __bit                   IODIPS13            @ (((unsigned) &IODIPS1)*8) + 3;
extern volatile __bit                   IODIPS14            @ (((unsigned) &IODIPS1)*8) + 4;
extern volatile __bit                   IODIPS15            @ (((unsigned) &IODIPS1)*8) + 5;
extern volatile __bit                   IODIPS16            @ (((unsigned) &IODIPS1)*8) + 6;
extern volatile __bit                   IODIPS17            @ (((unsigned) &IODIPS1)*8) + 7;

extern volatile __bit                   IOCIPS10            @ (((unsigned) &IOCIPS1)*8) + 0;
extern volatile __bit                   IOCIPS11            @ (((unsigned) &IOCIPS1)*8) + 1;
extern volatile __bit                   IOCIPS12            @ (((unsigned) &IOCIPS1)*8) + 2;
extern volatile __bit                   IOCIPS13            @ (((unsigned) &IOCIPS1)*8) + 3;
extern volatile __bit                   IOCIPS14            @ (((unsigned) &IOCIPS1)*8) + 4;
extern volatile __bit                   IOCIPS15            @ (((unsigned) &IOCIPS1)*8) + 5;
extern volatile __bit                   IOCIPS16            @ (((unsigned) &IOCIPS1)*8) + 6;
extern volatile __bit                   IOCIPS17            @ (((unsigned) &IOCIPS1)*8) + 7;

extern volatile __bit                   IOBIPS10            @ (((unsigned) &IOBIPS1)*8) + 0;
extern volatile __bit                   IOBIPS11            @ (((unsigned) &IOBIPS1)*8) + 1;
extern volatile __bit                   IOBIPS12            @ (((unsigned) &IOBIPS1)*8) + 2;
extern volatile __bit                   IOBIPS13            @ (((unsigned) &IOBIPS1)*8) + 3;
extern volatile __bit                   IOBIPS14            @ (((unsigned) &IOBIPS1)*8) + 4;
extern volatile __bit                   IOBIPS15            @ (((unsigned) &IOBIPS1)*8) + 5;
extern volatile __bit                   IOBIPS16            @ (((unsigned) &IOBIPS1)*8) + 6;
extern volatile __bit                   IOBIPS17            @ (((unsigned) &IOBIPS1)*8) + 7;
       
extern volatile __bit                   IOAIPS10            @ (((unsigned) &IOAIPS1)*8) + 0;
extern volatile __bit                   IOAIPS11            @ (((unsigned) &IOAIPS1)*8) + 1;
extern volatile __bit                   IOAIPS12            @ (((unsigned) &IOAIPS1)*8) + 2;
extern volatile __bit                   IOAIPS13            @ (((unsigned) &IOAIPS1)*8) + 3;
extern volatile __bit                   IOAIPS14            @ (((unsigned) &IOAIPS1)*8) + 4;
extern volatile __bit                   IOAIPS15            @ (((unsigned) &IOAIPS1)*8) + 5;
extern volatile __bit                   IOAIPS16            @ (((unsigned) &IOAIPS1)*8) + 6;
extern volatile __bit                   IOAIPS17            @ (((unsigned) &IOAIPS1)*8) + 7;

extern volatile __bit                   IOFODS10            @ (((unsigned) &IOFODS1)*8) + 0;
extern volatile __bit                   IOFODS11            @ (((unsigned) &IOFODS1)*8) + 1;
extern volatile __bit                   IOFODS12            @ (((unsigned) &IOFODS1)*8) + 2;
extern volatile __bit                   IOFODS13            @ (((unsigned) &IOFODS1)*8) + 3;
extern volatile __bit                   IOFODS14            @ (((unsigned) &IOFODS1)*8) + 4;
extern volatile __bit                   IOFODS15            @ (((unsigned) &IOFODS1)*8) + 5;
extern volatile __bit                   IOFODS16            @ (((unsigned) &IOFODS1)*8) + 6;
extern volatile __bit                   IOFODS17            @ (((unsigned) &IOFODS1)*8) + 7;

extern volatile __bit                   IOEODS10            @ (((unsigned) &IOEODS1)*8) + 0;
extern volatile __bit                   IOEODS11            @ (((unsigned) &IOEODS1)*8) + 1;
extern volatile __bit                   IOEODS12            @ (((unsigned) &IOEODS1)*8) + 2;
extern volatile __bit                   IOEODS13            @ (((unsigned) &IOEODS1)*8) + 3;
extern volatile __bit                   IOEODS14            @ (((unsigned) &IOEODS1)*8) + 4;
extern volatile __bit                   IOEODS15            @ (((unsigned) &IOEODS1)*8) + 5;
extern volatile __bit                   IOEODS16            @ (((unsigned) &IOEODS1)*8) + 6;
extern volatile __bit                   IOEODS17            @ (((unsigned) &IOEODS1)*8) + 7;

extern volatile __bit                   IODODS10            @ (((unsigned) &IODODS1)*8) + 0;
extern volatile __bit                   IODODS11            @ (((unsigned) &IODODS1)*8) + 1;
extern volatile __bit                   IODODS12            @ (((unsigned) &IODODS1)*8) + 2;
extern volatile __bit                   IODODS13            @ (((unsigned) &IODODS1)*8) + 3;
extern volatile __bit                   IODODS14            @ (((unsigned) &IODODS1)*8) + 4;
extern volatile __bit                   IODODS15            @ (((unsigned) &IODODS1)*8) + 5;
extern volatile __bit                   IODODS16            @ (((unsigned) &IODODS1)*8) + 6;
extern volatile __bit                   IODODS17            @ (((unsigned) &IODODS1)*8) + 7;

extern volatile __bit                   IOCODS10            @ (((unsigned) &IOCODS1)*8) + 0;
extern volatile __bit                   IOCODS11            @ (((unsigned) &IOCODS1)*8) + 1;
extern volatile __bit                   IOCODS12            @ (((unsigned) &IOCODS1)*8) + 2;
extern volatile __bit                   IOCODS13            @ (((unsigned) &IOCODS1)*8) + 3;
extern volatile __bit                   IOCODS14            @ (((unsigned) &IOCODS1)*8) + 4;
extern volatile __bit                   IOCODS15            @ (((unsigned) &IOCODS1)*8) + 5;
extern volatile __bit                   IOCODS16            @ (((unsigned) &IOCODS1)*8) + 6;
extern volatile __bit                   IOCODS17            @ (((unsigned) &IOCODS1)*8) + 7;

extern volatile __bit                   IOBODS10            @ (((unsigned) &IOBODS1)*8) + 0;
extern volatile __bit                   IOBODS11            @ (((unsigned) &IOBODS1)*8) + 1;
extern volatile __bit                   IOBODS12            @ (((unsigned) &IOBODS1)*8) + 2;
extern volatile __bit                   IOBODS13            @ (((unsigned) &IOBODS1)*8) + 3;
extern volatile __bit                   IOBODS14            @ (((unsigned) &IOBODS1)*8) + 4;
extern volatile __bit                   IOBODS15            @ (((unsigned) &IOBODS1)*8) + 5;
extern volatile __bit                   IOBODS16            @ (((unsigned) &IOBODS1)*8) + 6;
extern volatile __bit                   IOBODS17            @ (((unsigned) &IOBODS1)*8) + 7;

extern volatile __bit                   IOAODS10            @ (((unsigned) &IOAODS1)*8) + 0;
extern volatile __bit                   IOAODS11            @ (((unsigned) &IOAODS1)*8) + 1;
extern volatile __bit                   IOAODS12            @ (((unsigned) &IOAODS1)*8) + 2;
extern volatile __bit                   IOAODS13            @ (((unsigned) &IOAODS1)*8) + 3;
extern volatile __bit                   IOAODS14            @ (((unsigned) &IOAODS1)*8) + 4;
extern volatile __bit                   IOAODS15            @ (((unsigned) &IOAODS1)*8) + 5;
extern volatile __bit                   IOAODS16            @ (((unsigned) &IOAODS1)*8) + 6;
extern volatile __bit                   IOAODS17            @ (((unsigned) &IOAODS1)*8) + 7;

extern volatile __bit                   IOFODS00            @ (((unsigned) &IOFODS0)*8) + 0;
extern volatile __bit                   IOFODS01            @ (((unsigned) &IOFODS0)*8) + 1;
extern volatile __bit                   IOFODS02            @ (((unsigned) &IOFODS0)*8) + 2;
extern volatile __bit                   IOFODS03            @ (((unsigned) &IOFODS0)*8) + 3;
extern volatile __bit                   IOFODS04            @ (((unsigned) &IOFODS0)*8) + 4;
extern volatile __bit                   IOFODS05            @ (((unsigned) &IOFODS0)*8) + 5;
extern volatile __bit                   IOFODS06            @ (((unsigned) &IOFODS0)*8) + 6;
extern volatile __bit                   IOFODS07            @ (((unsigned) &IOFODS0)*8) + 7;

extern volatile __bit                   IOEODS00            @ (((unsigned) &IOEODS0)*8) + 0;
extern volatile __bit                   IOEODS01            @ (((unsigned) &IOEODS0)*8) + 1;
extern volatile __bit                   IOEODS02            @ (((unsigned) &IOEODS0)*8) + 2;
extern volatile __bit                   IOEODS03            @ (((unsigned) &IOEODS0)*8) + 3;
extern volatile __bit                   IOEODS04            @ (((unsigned) &IOEODS0)*8) + 4;
extern volatile __bit                   IOEODS05            @ (((unsigned) &IOEODS0)*8) + 5;
extern volatile __bit                   IOEODS06            @ (((unsigned) &IOEODS0)*8) + 6;
extern volatile __bit                   IOEODS07            @ (((unsigned) &IOEODS0)*8) + 7;

extern volatile __bit                   IODODS00            @ (((unsigned) &IODODS0)*8) + 0;
extern volatile __bit                   IODODS01            @ (((unsigned) &IODODS0)*8) + 1;
extern volatile __bit                   IODODS02            @ (((unsigned) &IODODS0)*8) + 2;
extern volatile __bit                   IODODS03            @ (((unsigned) &IODODS0)*8) + 3;
extern volatile __bit                   IODODS04            @ (((unsigned) &IODODS0)*8) + 4;
extern volatile __bit                   IODODS05            @ (((unsigned) &IODODS0)*8) + 5;
extern volatile __bit                   IODODS06            @ (((unsigned) &IODODS0)*8) + 6;
extern volatile __bit                   IODODS07            @ (((unsigned) &IODODS0)*8) + 7;

extern volatile __bit                   IOCODS00            @ (((unsigned) &IOCODS0)*8) + 0;
extern volatile __bit                   IOCODS01            @ (((unsigned) &IOCODS0)*8) + 1;
extern volatile __bit                   IOCODS02            @ (((unsigned) &IOCODS0)*8) + 2;
extern volatile __bit                   IOCODS03            @ (((unsigned) &IOCODS0)*8) + 3;
extern volatile __bit                   IOCODS04            @ (((unsigned) &IOCODS0)*8) + 4;
extern volatile __bit                   IOCODS05            @ (((unsigned) &IOCODS0)*8) + 5;
extern volatile __bit                   IOCODS06            @ (((unsigned) &IOCODS0)*8) + 6;
extern volatile __bit                   IOCODS07            @ (((unsigned) &IOCODS0)*8) + 7;

extern volatile __bit                   IOBODS00            @ (((unsigned) &IOBODS0)*8) + 0;
extern volatile __bit                   IOBODS01            @ (((unsigned) &IOBODS0)*8) + 1;
extern volatile __bit                   IOBODS02            @ (((unsigned) &IOBODS0)*8) + 2;
extern volatile __bit                   IOBODS03            @ (((unsigned) &IOBODS0)*8) + 3;
extern volatile __bit                   IOBODS04            @ (((unsigned) &IOBODS0)*8) + 4;
extern volatile __bit                   IOBODS05            @ (((unsigned) &IOBODS0)*8) + 5;
extern volatile __bit                   IOBODS06            @ (((unsigned) &IOBODS0)*8) + 6;
extern volatile __bit                   IOBODS07            @ (((unsigned) &IOBODS0)*8) + 7;

extern volatile __bit                   IOAODS00            @ (((unsigned) &IOAODS0)*8) + 0;
extern volatile __bit                   IOAODS01            @ (((unsigned) &IOAODS0)*8) + 1;
extern volatile __bit                   IOAODS02            @ (((unsigned) &IOAODS0)*8) + 2;
extern volatile __bit                   IOAODS03            @ (((unsigned) &IOAODS0)*8) + 3;
extern volatile __bit                   IOAODS04            @ (((unsigned) &IOAODS0)*8) + 4;
extern volatile __bit                   IOAODS05            @ (((unsigned) &IOAODS0)*8) + 5;
extern volatile __bit                   IOAODS06            @ (((unsigned) &IOAODS0)*8) + 6;
extern volatile __bit                   IOAODS07            @ (((unsigned) &IOAODS0)*8) + 7;

extern volatile __bit                   IOFICR0             @ (((unsigned) &IOFICR)*8) + 0;
extern volatile __bit                   IOFICR1             @ (((unsigned) &IOFICR)*8) + 1;
extern volatile __bit                   IOFICR2             @ (((unsigned) &IOFICR)*8) + 2;
extern volatile __bit                   IOFICR3             @ (((unsigned) &IOFICR)*8) + 3;
extern volatile __bit                   IOFICR4             @ (((unsigned) &IOFICR)*8) + 4;
extern volatile __bit                   IOFICR5             @ (((unsigned) &IOFICR)*8) + 5;
extern volatile __bit                   IOFICR6             @ (((unsigned) &IOFICR)*8) + 6;
extern volatile __bit                   IOFICR7             @ (((unsigned) &IOFICR)*8) + 7;

extern volatile __bit                   IOEICR0             @ (((unsigned) &IOEICR)*8) + 0;
extern volatile __bit                   IOEICR1             @ (((unsigned) &IOEICR)*8) + 1;
extern volatile __bit                   IOEICR2             @ (((unsigned) &IOEICR)*8) + 2;
extern volatile __bit                   IOEICR3             @ (((unsigned) &IOEICR)*8) + 3;
extern volatile __bit                   IOEICR4             @ (((unsigned) &IOEICR)*8) + 4;
extern volatile __bit                   IOEICR5             @ (((unsigned) &IOEICR)*8) + 5;
extern volatile __bit                   IOEICR6             @ (((unsigned) &IOEICR)*8) + 6;
extern volatile __bit                   IOEICR7             @ (((unsigned) &IOEICR)*8) + 7;

extern volatile __bit                   IODICR0             @ (((unsigned) &IODICR)*8) + 0;
extern volatile __bit                   IODICR1             @ (((unsigned) &IODICR)*8) + 1;
extern volatile __bit                   IODICR2             @ (((unsigned) &IODICR)*8) + 2;
extern volatile __bit                   IODICR3             @ (((unsigned) &IODICR)*8) + 3;
extern volatile __bit                   IODICR4             @ (((unsigned) &IODICR)*8) + 4;
extern volatile __bit                   IODICR5             @ (((unsigned) &IODICR)*8) + 5;
extern volatile __bit                   IODICR6             @ (((unsigned) &IODICR)*8) + 6;
extern volatile __bit                   IODICR7             @ (((unsigned) &IODICR)*8) + 7;

extern volatile __bit                   IOCICR0             @ (((unsigned) &IOCICR)*8) + 0;
extern volatile __bit                   IOCICR1             @ (((unsigned) &IOCICR)*8) + 1;
extern volatile __bit                   IOCICR2             @ (((unsigned) &IOCICR)*8) + 2;
extern volatile __bit                   IOCICR3             @ (((unsigned) &IOCICR)*8) + 3;
extern volatile __bit                   IOCICR4             @ (((unsigned) &IOCICR)*8) + 4;
extern volatile __bit                   IOCICR5             @ (((unsigned) &IOCICR)*8) + 5;
extern volatile __bit                   IOCICR6             @ (((unsigned) &IOCICR)*8) + 6;
extern volatile __bit                   IOCICR7             @ (((unsigned) &IOCICR)*8) + 7;

extern volatile __bit                   IOBICR0             @ (((unsigned) &IOBICR)*8) + 0;
extern volatile __bit                   IOBICR1             @ (((unsigned) &IOBICR)*8) + 1;
extern volatile __bit                   IOBICR2             @ (((unsigned) &IOBICR)*8) + 2;
extern volatile __bit                   IOBICR3             @ (((unsigned) &IOBICR)*8) + 3;
extern volatile __bit                   IOBICR4             @ (((unsigned) &IOBICR)*8) + 4;
extern volatile __bit                   IOBICR5             @ (((unsigned) &IOBICR)*8) + 5;
extern volatile __bit                   IOBICR6             @ (((unsigned) &IOBICR)*8) + 6;
extern volatile __bit                   IOBICR7             @ (((unsigned) &IOBICR)*8) + 7;

extern volatile __bit                   IOAICR0             @ (((unsigned) &IOAICR)*8) + 0;
extern volatile __bit                   IOAICR1             @ (((unsigned) &IOAICR)*8) + 1;
extern volatile __bit                   IOAICR2             @ (((unsigned) &IOAICR)*8) + 2;
extern volatile __bit                   IOAICR3             @ (((unsigned) &IOAICR)*8) + 3;
extern volatile __bit                   IOAICR4             @ (((unsigned) &IOAICR)*8) + 4;
extern volatile __bit                   IOAICR5             @ (((unsigned) &IOAICR)*8) + 5;
extern volatile __bit                   IOAICR6             @ (((unsigned) &IOAICR)*8) + 6;
extern volatile __bit                   IOAICR7             @ (((unsigned) &IOAICR)*8) + 7;

extern volatile __bit                   PDF0                @ (((unsigned) &PDF)*8) + 0;
extern volatile __bit                   PDF1                @ (((unsigned) &PDF)*8) + 1;
extern volatile __bit                   PDF2                @ (((unsigned) &PDF)*8) + 2;
extern volatile __bit                   PDF3                @ (((unsigned) &PDF)*8) + 3;
extern volatile __bit                   PDF4                @ (((unsigned) &PDF)*8) + 4;
extern volatile __bit                   PDF5                @ (((unsigned) &PDF)*8) + 5;
extern volatile __bit                   PDF6                @ (((unsigned) &PDF)*8) + 6;
extern volatile __bit                   PDF7                @ (((unsigned) &PDF)*8) + 7;

extern volatile __bit                   PDE0                @ (((unsigned) &PDE)*8) + 0;
extern volatile __bit                   PDE1                @ (((unsigned) &PDE)*8) + 1;
extern volatile __bit                   PDE2                @ (((unsigned) &PDE)*8) + 2;
extern volatile __bit                   PDE3                @ (((unsigned) &PDE)*8) + 3;
extern volatile __bit                   PDE4                @ (((unsigned) &PDE)*8) + 4;
extern volatile __bit                   PDE5                @ (((unsigned) &PDE)*8) + 5;
extern volatile __bit                   PDE6                @ (((unsigned) &PDE)*8) + 6;
extern volatile __bit                   PDE7                @ (((unsigned) &PDE)*8) + 7;

extern volatile __bit                   PDD0                @ (((unsigned) &PDD)*8) + 0;
extern volatile __bit                   PDD1                @ (((unsigned) &PDD)*8) + 1;
extern volatile __bit                   PDD2                @ (((unsigned) &PDD)*8) + 2;
extern volatile __bit                   PDD3                @ (((unsigned) &PDD)*8) + 3;
extern volatile __bit                   PDD4                @ (((unsigned) &PDD)*8) + 4;
extern volatile __bit                   PDD5                @ (((unsigned) &PDD)*8) + 5;
extern volatile __bit                   PDD6                @ (((unsigned) &PDD)*8) + 6;
extern volatile __bit                   PDD7                @ (((unsigned) &PDD)*8) + 7;

extern volatile __bit                   PDC0                @ (((unsigned) &PDC)*8) + 0;
extern volatile __bit                   PDC1                @ (((unsigned) &PDC)*8) + 1;
extern volatile __bit                   PDC2                @ (((unsigned) &PDC)*8) + 2;
extern volatile __bit                   PDC3                @ (((unsigned) &PDC)*8) + 3;
extern volatile __bit                   PDC4                @ (((unsigned) &PDC)*8) + 4;
extern volatile __bit                   PDC5                @ (((unsigned) &PDC)*8) + 5;
extern volatile __bit                   PDC6                @ (((unsigned) &PDC)*8) + 6;
extern volatile __bit                   PDC7                @ (((unsigned) &PDC)*8) + 7;

extern volatile __bit                   PDB0                @ (((unsigned) &PDB)*8) + 0;
extern volatile __bit                   PDB1                @ (((unsigned) &PDB)*8) + 1;
extern volatile __bit                   PDB2                @ (((unsigned) &PDB)*8) + 2;
extern volatile __bit                   PDB3                @ (((unsigned) &PDB)*8) + 3;
extern volatile __bit                   PDB4                @ (((unsigned) &PDB)*8) + 4;
extern volatile __bit                   PDB5                @ (((unsigned) &PDB)*8) + 5;
extern volatile __bit                   PDB6                @ (((unsigned) &PDB)*8) + 6;
extern volatile __bit                   PDB7                @ (((unsigned) &PDB)*8) + 7;

extern volatile __bit                   PDA0                @ (((unsigned) &PDA)*8) + 0;
extern volatile __bit                   PDA1                @ (((unsigned) &PDA)*8) + 1;
extern volatile __bit                   PDA2                @ (((unsigned) &PDA)*8) + 2;
extern volatile __bit                   PDA3                @ (((unsigned) &PDA)*8) + 3;
extern volatile __bit                   PDA4                @ (((unsigned) &PDA)*8) + 4;
extern volatile __bit                   PDA5                @ (((unsigned) &PDA)*8) + 5;
extern volatile __bit                   PDA6                @ (((unsigned) &PDA)*8) + 6;
extern volatile __bit                   PDA7                @ (((unsigned) &PDA)*8) + 7;

extern volatile __bit                   PUF0                @ (((unsigned) &PUF)*8) + 0;
extern volatile __bit                   PUF1                @ (((unsigned) &PUF)*8) + 1;
extern volatile __bit                   PUF2                @ (((unsigned) &PUF)*8) + 2;
extern volatile __bit                   PUF3                @ (((unsigned) &PUF)*8) + 3;
extern volatile __bit                   PUF4                @ (((unsigned) &PUF)*8) + 4;
extern volatile __bit                   PUF5                @ (((unsigned) &PUF)*8) + 5;
extern volatile __bit                   PUF6                @ (((unsigned) &PUF)*8) + 6;
extern volatile __bit                   PUF7                @ (((unsigned) &PUF)*8) + 7;

extern volatile __bit                   PUE0                @ (((unsigned) &PUE)*8) + 0;
extern volatile __bit                   PUE1                @ (((unsigned) &PUE)*8) + 1;
extern volatile __bit                   PUE2                @ (((unsigned) &PUE)*8) + 2;
extern volatile __bit                   PUE3                @ (((unsigned) &PUE)*8) + 3;
extern volatile __bit                   PUE4                @ (((unsigned) &PUE)*8) + 4;
extern volatile __bit                   PUE5                @ (((unsigned) &PUE)*8) + 5;
extern volatile __bit                   PUE6                @ (((unsigned) &PUE)*8) + 6;
extern volatile __bit                   PUE7                @ (((unsigned) &PUE)*8) + 7;

extern volatile __bit                   PUD0                @ (((unsigned) &PUD)*8) + 0;
extern volatile __bit                   PUD1                @ (((unsigned) &PUD)*8) + 1;
extern volatile __bit                   PUD2                @ (((unsigned) &PUD)*8) + 2;
extern volatile __bit                   PUD3                @ (((unsigned) &PUD)*8) + 3;
extern volatile __bit                   PUD4                @ (((unsigned) &PUD)*8) + 4;
extern volatile __bit                   PUD5                @ (((unsigned) &PUD)*8) + 5;
extern volatile __bit                   PUD6                @ (((unsigned) &PUD)*8) + 6;
extern volatile __bit                   PUD7                @ (((unsigned) &PUD)*8) + 7;

extern volatile __bit                   PUC0                @ (((unsigned) &PUC)*8) + 0;
extern volatile __bit                   PUC1                @ (((unsigned) &PUC)*8) + 1;
extern volatile __bit                   PUC2                @ (((unsigned) &PUC)*8) + 2;
extern volatile __bit                   PUC3                @ (((unsigned) &PUC)*8) + 3;
extern volatile __bit                   PUC4                @ (((unsigned) &PUC)*8) + 4;
extern volatile __bit                   PUC5                @ (((unsigned) &PUC)*8) + 5;
extern volatile __bit                   PUC6                @ (((unsigned) &PUC)*8) + 6;
extern volatile __bit                   PUC7                @ (((unsigned) &PUC)*8) + 7;

extern volatile __bit                   PUB0                @ (((unsigned) &PUB)*8) + 0;
extern volatile __bit                   PUB1                @ (((unsigned) &PUB)*8) + 1;
extern volatile __bit                   PUB2                @ (((unsigned) &PUB)*8) + 2;
extern volatile __bit                   PUB3                @ (((unsigned) &PUB)*8) + 3;
extern volatile __bit                   PUB4                @ (((unsigned) &PUB)*8) + 4;
extern volatile __bit                   PUB5                @ (((unsigned) &PUB)*8) + 5;
extern volatile __bit                   PUB6                @ (((unsigned) &PUB)*8) + 6;
extern volatile __bit                   PUB7                @ (((unsigned) &PUB)*8) + 7;

extern volatile __bit                   PUA0                @ (((unsigned) &PUA)*8) + 0;
extern volatile __bit                   PUA1                @ (((unsigned) &PUA)*8) + 1;
extern volatile __bit                   PUA2                @ (((unsigned) &PUA)*8) + 2;
extern volatile __bit                   PUA3                @ (((unsigned) &PUA)*8) + 3;
extern volatile __bit                   PUA4                @ (((unsigned) &PUA)*8) + 4;
extern volatile __bit                   PUA5                @ (((unsigned) &PUA)*8) + 5;
extern volatile __bit                   PUA6                @ (((unsigned) &PUA)*8) + 6;
extern volatile __bit                   PUA7                @ (((unsigned) &PUA)*8) + 7;
     
extern volatile __bit                   OVT0                @ (((unsigned) &UCLKCON)*8) + 0;
extern volatile __bit                   OVT1                @ (((unsigned) &UCLKCON)*8) + 1;
extern volatile __bit                   OVT2                @ (((unsigned) &UCLKCON)*8) + 2;
extern volatile __bit                   OVT3                @ (((unsigned) &UCLKCON)*8) + 3;
extern volatile __bit                   OVT4                @ (((unsigned) &UCLKCON)*8) + 4;
extern volatile __bit                   OVT5                @ (((unsigned) &UCLKCON)*8) + 5;
extern volatile __bit                   UCKS0               @ (((unsigned) &UCLKCON)*8) + 6;
extern volatile __bit                   UCKS1               @ (((unsigned) &UCLKCON)*8) + 7;

extern volatile __bit                   UE5IOPS0            @ (((unsigned) &UE5IOPS)*8) + 0;
extern volatile __bit                   UE5IOPS1            @ (((unsigned) &UE5IOPS)*8) + 1;
extern volatile __bit                   UE5IOPS2            @ (((unsigned) &UE5IOPS)*8) + 2;
extern volatile __bit                   UE5IOPS3            @ (((unsigned) &UE5IOPS)*8) + 3;
extern volatile __bit                   UE5IOPS4            @ (((unsigned) &UE5IOPS)*8) + 4;
extern volatile __bit                   UE5IOPS5            @ (((unsigned) &UE5IOPS)*8) + 5;
extern volatile __bit                   UE5IOPS6            @ (((unsigned) &UE5IOPS)*8) + 6;
extern volatile __bit                   UE5IOPS7            @ (((unsigned) &UE5IOPS)*8) + 7;
  
extern volatile __bit                   UE5INS              @ (((unsigned) &UE5CON)*8) + 0;
extern volatile __bit                   UE5OUTS             @ (((unsigned) &UE5CON)*8) + 1;
extern volatile __bit                   UE5IND0             @ (((unsigned) &UE5CON)*8) + 2;
extern volatile __bit                   UE5OUTD0            @ (((unsigned) &UE5CON)*8) + 3;
extern volatile __bit                   UE5INSTL            @ (((unsigned) &UE5CON)*8) + 4;
extern volatile __bit                   UE5OUTSTL           @ (((unsigned) &UE5CON)*8) + 5;
extern volatile __bit                   UE5INF              @ (((unsigned) &UE5CON)*8) + 6;
extern volatile __bit                   UE5OUTF             @ (((unsigned) &UE5CON)*8) + 7;

extern volatile __bit                   UE4IOPS0            @ (((unsigned) &UE4IOPS)*8) + 0;
extern volatile __bit                   UE4IOPS1            @ (((unsigned) &UE4IOPS)*8) + 1;
extern volatile __bit                   UE4IOPS2            @ (((unsigned) &UE4IOPS)*8) + 2;
extern volatile __bit                   UE4IOPS3            @ (((unsigned) &UE4IOPS)*8) + 3;
extern volatile __bit                   UE4IOPS4            @ (((unsigned) &UE4IOPS)*8) + 4;
extern volatile __bit                   UE4IOPS5            @ (((unsigned) &UE4IOPS)*8) + 5;
extern volatile __bit                   UE4IOPS6            @ (((unsigned) &UE4IOPS)*8) + 6;
extern volatile __bit                   UE4IOPS7            @ (((unsigned) &UE4IOPS)*8) + 7;

extern volatile __bit                   UE4INS              @ (((unsigned) &UE4CON)*8) + 0;
extern volatile __bit                   UE4OUTS             @ (((unsigned) &UE4CON)*8) + 1;
extern volatile __bit                   UE4IND0             @ (((unsigned) &UE4CON)*8) + 2;
extern volatile __bit                   UE4OUTD0            @ (((unsigned) &UE4CON)*8) + 3;
extern volatile __bit                   UE4INSTL            @ (((unsigned) &UE4CON)*8) + 4;
extern volatile __bit                   UE4OUTSTL           @ (((unsigned) &UE4CON)*8) + 5;
extern volatile __bit                   UE4INF              @ (((unsigned) &UE4CON)*8) + 6;
extern volatile __bit                   UE4OUTF             @ (((unsigned) &UE4CON)*8) + 7;

extern volatile __bit                   UE3IOPS0            @ (((unsigned) &UE3IOPS)*8) + 0;
extern volatile __bit                   UE3IOPS1            @ (((unsigned) &UE3IOPS)*8) + 1;
extern volatile __bit                   UE3IOPS2            @ (((unsigned) &UE3IOPS)*8) + 2;
extern volatile __bit                   UE3IOPS3            @ (((unsigned) &UE3IOPS)*8) + 3;
extern volatile __bit                   UE3IOPS4            @ (((unsigned) &UE3IOPS)*8) + 4;
extern volatile __bit                   UE3IOPS5            @ (((unsigned) &UE3IOPS)*8) + 5;
extern volatile __bit                   UE3IOPS6            @ (((unsigned) &UE3IOPS)*8) + 6;
extern volatile __bit                   UE3IOPS7            @ (((unsigned) &UE3IOPS)*8) + 7;

extern volatile __bit                   UE3INS              @ (((unsigned) &UE3CON)*8) + 0;
extern volatile __bit                   UE3OUTS             @ (((unsigned) &UE3CON)*8) + 1;
extern volatile __bit                   UE3IND0             @ (((unsigned) &UE3CON)*8) + 2;
extern volatile __bit                   UE3OUTD0            @ (((unsigned) &UE3CON)*8) + 3;
extern volatile __bit                   UE3INSTL            @ (((unsigned) &UE3CON)*8) + 4;
extern volatile __bit                   UE3OUTSTL           @ (((unsigned) &UE3CON)*8) + 5;
extern volatile __bit                   UE3INF              @ (((unsigned) &UE3CON)*8) + 6;
extern volatile __bit                   UE3OUTF             @ (((unsigned) &UE3CON)*8) + 7;

extern volatile __bit                   UE2IOPS0            @ (((unsigned) &UE2IOPS)*8) + 0;
extern volatile __bit                   UE2IOPS1            @ (((unsigned) &UE2IOPS)*8) + 1;
extern volatile __bit                   UE2IOPS2            @ (((unsigned) &UE2IOPS)*8) + 2;
extern volatile __bit                   UE2IOPS3            @ (((unsigned) &UE2IOPS)*8) + 3;
extern volatile __bit                   UE2IOPS4            @ (((unsigned) &UE2IOPS)*8) + 4;
extern volatile __bit                   UE2IOPS5            @ (((unsigned) &UE2IOPS)*8) + 5;
extern volatile __bit                   UE2IOPS6            @ (((unsigned) &UE2IOPS)*8) + 6;
extern volatile __bit                   UE2IOPS7            @ (((unsigned) &UE2IOPS)*8) + 7;

extern volatile __bit                   UE2INS              @ (((unsigned) &UE2CON)*8) + 0;
extern volatile __bit                   UE2OUTS             @ (((unsigned) &UE2CON)*8) + 1;
extern volatile __bit                   UE2IND0             @ (((unsigned) &UE2CON)*8) + 2;
extern volatile __bit                   UE2OUTD0            @ (((unsigned) &UE2CON)*8) + 3;
extern volatile __bit                   UE2INSTL            @ (((unsigned) &UE2CON)*8) + 4;
extern volatile __bit                   UE2OUTSTL           @ (((unsigned) &UE2CON)*8) + 5;
extern volatile __bit                   UE2INF              @ (((unsigned) &UE2CON)*8) + 6;
extern volatile __bit                   UE2OUTF             @ (((unsigned) &UE2CON)*8) + 7;

extern volatile __bit                   UE1IOPS0            @ (((unsigned) &UE1IOPS)*8) + 0;
extern volatile __bit                   UE1IOPS1            @ (((unsigned) &UE1IOPS)*8) + 1;
extern volatile __bit                   UE1IOPS2            @ (((unsigned) &UE1IOPS)*8) + 2;
extern volatile __bit                   UE1IOPS3            @ (((unsigned) &UE1IOPS)*8) + 3;
extern volatile __bit                   UE1IOPS4            @ (((unsigned) &UE1IOPS)*8) + 4;
extern volatile __bit                   UE1IOPS5            @ (((unsigned) &UE1IOPS)*8) + 5;
extern volatile __bit                   UE1IOPS6            @ (((unsigned) &UE1IOPS)*8) + 6;
extern volatile __bit                   UE1IOPS7            @ (((unsigned) &UE1IOPS)*8) + 7;

extern volatile __bit                   UE1INS              @ (((unsigned) &UE1CON)*8) + 0;
extern volatile __bit                   UE1OUTS             @ (((unsigned) &UE1CON)*8) + 1;
extern volatile __bit                   UE1IND0             @ (((unsigned) &UE1CON)*8) + 2;
extern volatile __bit                   UE1OUTD0            @ (((unsigned) &UE1CON)*8) + 3;
extern volatile __bit                   UE1INSTL            @ (((unsigned) &UE1CON)*8) + 4;
extern volatile __bit                   UE1OUTSTL           @ (((unsigned) &UE1CON)*8) + 5;
extern volatile __bit                   UE1INF              @ (((unsigned) &UE1CON)*8) + 6;
extern volatile __bit                   UE1OUTF             @ (((unsigned) &UE1CON)*8) + 7;

extern volatile __bit                   UE0IOPS0            @ (((unsigned) &UE0IOPS)*8) + 0;
extern volatile __bit                   UE0IOPS1            @ (((unsigned) &UE0IOPS)*8) + 1;
extern volatile __bit                   UE0IOPS2            @ (((unsigned) &UE0IOPS)*8) + 2;
extern volatile __bit                   UE0IOPS3            @ (((unsigned) &UE0IOPS)*8) + 3;
extern volatile __bit                   UE0IOPS4            @ (((unsigned) &UE0IOPS)*8) + 4;
extern volatile __bit                   UE0IOPS5            @ (((unsigned) &UE0IOPS)*8) + 5;
extern volatile __bit                   UE0IOPS6            @ (((unsigned) &UE0IOPS)*8) + 6;
extern volatile __bit                   UE0IOPS7            @ (((unsigned) &UE0IOPS)*8) + 7;

extern volatile __bit                   UE0DINS             @ (((unsigned) &UE0CON)*8) + 0;
extern volatile __bit                   UE0DOUTS            @ (((unsigned) &UE0CON)*8) + 1;
extern volatile __bit                   UE0SINS             @ (((unsigned) &UE0CON)*8) + 2;
extern volatile __bit                   UE0SOUTS            @ (((unsigned) &UE0CON)*8) + 3;
extern volatile __bit                   UE0STL              @ (((unsigned) &UE0CON)*8) + 4;
//extern volatile __bit                 xx                  @ (((unsigned) &UE0CON)*8) + 5;
//extern volatile __bit                 xx                  @ (((unsigned) &UE0CON)*8) + 6;
extern volatile __bit                   UE0SDF              @ (((unsigned) &UE0CON)*8) + 7;

extern volatile __bit                   UDADR0              @ (((unsigned) &UDADR)*8) + 0;
extern volatile __bit                   UDADR1              @ (((unsigned) &UDADR)*8) + 1;
extern volatile __bit                   UDADR2              @ (((unsigned) &UDADR)*8) + 2;
extern volatile __bit                   UDADR3              @ (((unsigned) &UDADR)*8) + 3;
extern volatile __bit                   UDADR4              @ (((unsigned) &UDADR)*8) + 4;
extern volatile __bit                   UDADR5              @ (((unsigned) &UDADR)*8) + 5;
extern volatile __bit                   UDADR6              @ (((unsigned) &UDADR)*8) + 6;
//extern volatile __bit                 xx                  @ (((unsigned) &UDADR)*8) + 7;

extern volatile __bit                   UE                  @ (((unsigned) &USBCON)*8) + 0;
extern volatile __bit                   USRSM               @ (((unsigned) &USBCON)*8) + 1;
extern volatile __bit                   UFS                 @ (((unsigned) &USBCON)*8) + 2;
extern volatile __bit                   USHC                @ (((unsigned) &USBCON)*8) + 3;
//extern volatile __bit                 xx                  @ (((unsigned) &USBCON)*8) + 4;
extern volatile __bit                   UBRSM               @ (((unsigned) &USBCON)*8) + 5;
extern volatile __bit                   UBSPD               @ (((unsigned) &USBCON)*8) + 6;
extern volatile __bit                   UBRST               @ (((unsigned) &USBCON)*8) + 7;

extern volatile __bit                   C0ADDF              @ (((unsigned) &I2C0SR)*8) + 0;
extern volatile __bit                   C0NACKF             @ (((unsigned) &I2C0SR)*8) + 1;
extern volatile __bit                   S0IF                @ (((unsigned) &I2C0SR)*8) + 2;
extern volatile __bit                   C0BF                @ (((unsigned) &I2C0SR)*8) + 3;
extern volatile __bit                   C0AD                @ (((unsigned) &I2C0SR)*8) + 4;
extern volatile __bit                   C0DIR               @ (((unsigned) &I2C0SR)*8) + 5;
extern volatile __bit                   C0AL                @ (((unsigned) &I2C0SR)*8) + 6;
extern volatile __bit                   C0ROV               @ (((unsigned) &I2C0SR)*8) + 7;

extern volatile __bit                   C0DBUF0             @ (((unsigned) &I2C0DBUF)*8) + 0;
extern volatile __bit                   C0DBUF1             @ (((unsigned) &I2C0DBUF)*8) + 1;
extern volatile __bit                   C0DBUF2             @ (((unsigned) &I2C0DBUF)*8) + 2;
extern volatile __bit                   C0DBUF3             @ (((unsigned) &I2C0DBUF)*8) + 3;
extern volatile __bit                   C0DBUF4             @ (((unsigned) &I2C0DBUF)*8) + 4;
extern volatile __bit                   C0DBUF5             @ (((unsigned) &I2C0DBUF)*8) + 5;
extern volatile __bit                   C0DBUF6             @ (((unsigned) &I2C0DBUF)*8) + 6;
extern volatile __bit                   C0DBUF7             @ (((unsigned) &I2C0DBUF)*8) + 7;

extern volatile __bit                   C0PRESC0            @ (((unsigned) &I2C0PRESC)*8) + 0;
extern volatile __bit                   C0PRESC1            @ (((unsigned) &I2C0PRESC)*8) + 1;
extern volatile __bit                   C0PRESC2            @ (((unsigned) &I2C0PRESC)*8) + 2;
extern volatile __bit                   C0PRESC3            @ (((unsigned) &I2C0PRESC)*8) + 3;
//extern volatile __bit                 xx                  @ (((unsigned) &I2C0PRESC)*8) + 4;
//extern volatile __bit                 xx                  @ (((unsigned) &I2C0PRESC)*8) + 5;
//extern volatile __bit                 xx                  @ (((unsigned) &I2C0PRESC)*8) + 6;
//extern volatile __bit                 xx                  @ (((unsigned) &I2C0PRESC)*8) + 7;

extern volatile __bit                   C0OAR0              @ (((unsigned) &I2C0OAR)*8) + 0;
extern volatile __bit                   C0OAR1              @ (((unsigned) &I2C0OAR)*8) + 1;
extern volatile __bit                   C0OAR2              @ (((unsigned) &I2C0OAR)*8) + 2;
extern volatile __bit                   C0OAR3              @ (((unsigned) &I2C0OAR)*8) + 3;
extern volatile __bit                   C0OAR4              @ (((unsigned) &I2C0OAR)*8) + 4;
extern volatile __bit                   C0OAR5              @ (((unsigned) &I2C0OAR)*8) + 5;
extern volatile __bit                   C0OAR6              @ (((unsigned) &I2C0OAR)*8) + 6;
extern volatile __bit                   C0OAR7              @ (((unsigned) &I2C0OAR)*8) + 7;

extern volatile __bit                   C0OAR8              @ (((unsigned) &I2C0CR2)*8) + 0;
extern volatile __bit                   C0OAR9              @ (((unsigned) &I2C0CR2)*8) + 1;
extern volatile __bit                   S0MODE0             @ (((unsigned) &I2C0CR2)*8) + 2;
extern volatile __bit                   S0MODE1             @ (((unsigned) &I2C0CR2)*8) + 3;
extern volatile __bit                   C0ADDR10            @ (((unsigned) &I2C0CR2)*8) + 4;
extern volatile __bit                   C0ACK               @ (((unsigned) &I2C0CR2)*8) + 5;
extern volatile __bit                   S0SDIS              @ (((unsigned) &I2C0CR2)*8) + 6;
extern volatile __bit                   S0MLS               @ (((unsigned) &I2C0CR2)*8) + 7;

extern volatile __bit                   C0GCEN              @ (((unsigned) &I2C0CR1)*8) + 0;
extern volatile __bit                   C0NT0               @ (((unsigned) &I2C0CR1)*8) + 1;
extern volatile __bit                   C0NT1               @ (((unsigned) &I2C0CR1)*8) + 2;
extern volatile __bit                   C0MS                @ (((unsigned) &I2C0CR1)*8) + 3;
extern volatile __bit                   C0SP                @ (((unsigned) &I2C0CR1)*8) + 4;
extern volatile __bit                   C0SR                @ (((unsigned) &I2C0CR1)*8) + 5;
extern volatile __bit                   S0EN                @ (((unsigned) &I2C0CR1)*8) + 6;
extern volatile __bit                   C0EN                @ (((unsigned) &I2C0CR1)*8) + 7;

extern volatile __bit                   BOR                 @ (((unsigned) &PCON)*8) + 0;
extern volatile __bit                   POR                 @ (((unsigned) &PCON)*8) + 1;
extern volatile __bit                   MCLR                @ (((unsigned) &PCON)*8) + 2;
//extern volatile __bit                   XX                @ (((unsigned) &PCON)*8) + 3;
extern volatile __bit                   PD                  @ (((unsigned) &PCON)*8) + 4;
extern volatile __bit                   TO                  @ (((unsigned) &PCON)*8) + 5;
extern volatile __bit                   SOFTRST             @ (((unsigned) &PCON)*8) + 6;
//extern volatile __bit                   XX                @ (((unsigned) &PCON)*8) + 7;

extern volatile __bit                   FLIPCR0               @ (((unsigned) &FLIPCR)*8) + 0;

extern volatile __bit                   RX0D0               @ (((unsigned) &RX0REG)*8) + 0;
extern volatile __bit                   RX0D1               @ (((unsigned) &RX0REG)*8) + 1;
extern volatile __bit                   RX0D2               @ (((unsigned) &RX0REG)*8) + 2;
extern volatile __bit                   RX0D3               @ (((unsigned) &RX0REG)*8) + 3;
extern volatile __bit                   RX0D4               @ (((unsigned) &RX0REG)*8) + 4;
extern volatile __bit                   RX0D5               @ (((unsigned) &RX0REG)*8) + 5;
extern volatile __bit                   RX0D6               @ (((unsigned) &RX0REG)*8) + 6;
extern volatile __bit                   RX0D7               @ (((unsigned) &RX0REG)*8) + 7;

extern volatile __bit                   TX0D0               @ (((unsigned) &TX0REG)*8) + 0;
extern volatile __bit                   TX0D1               @ (((unsigned) &TX0REG)*8) + 1;
extern volatile __bit                   TX0D2               @ (((unsigned) &TX0REG)*8) + 2;
extern volatile __bit                   TX0D3               @ (((unsigned) &TX0REG)*8) + 3;
extern volatile __bit                   TX0D4               @ (((unsigned) &TX0REG)*8) + 4;
extern volatile __bit                   TX0D5               @ (((unsigned) &TX0REG)*8) + 5;
extern volatile __bit                   TX0D6               @ (((unsigned) &TX0REG)*8) + 6;
extern volatile __bit                   TX0D7               @ (((unsigned) &TX0REG)*8) + 7;

extern volatile __bit                   BRGD00              @ (((unsigned) &BRGD0L)*8) + 0;
extern volatile __bit                   BRGD01              @ (((unsigned) &BRGD0L)*8) + 1;
extern volatile __bit                   BRGD02              @ (((unsigned) &BRGD0L)*8) + 2;
extern volatile __bit                   BRGD03              @ (((unsigned) &BRGD0L)*8) + 3;
extern volatile __bit                   BRGD04              @ (((unsigned) &BRGD0L)*8) + 4;
extern volatile __bit                   BRGD05              @ (((unsigned) &BRGD0L)*8) + 5;
extern volatile __bit                   BRGD06              @ (((unsigned) &BRGD0L)*8) + 6;
extern volatile __bit                   BRGD07              @ (((unsigned) &BRGD0L)*8) + 7;

extern volatile __bit                   BRGD08              @ (((unsigned) &BRGD0H)*8) + 0;
extern volatile __bit                   BRGD09              @ (((unsigned) &BRGD0H)*8) + 1;
//extern volatile __bit                 xx                  @ (((unsigned) &BRGD0H)*8) + 2;
//extern volatile __bit                 xx                  @ (((unsigned) &BRGD0H)*8) + 3;
//extern volatile __bit                 xx                  @ (((unsigned) &BRGD0H)*8) + 4;
//extern volatile __bit                 xx                  @ (((unsigned) &BRGD0H)*8) + 5;
//extern volatile __bit                 xx                  @ (((unsigned) &BRGD0H)*8) + 6;
extern volatile __bit                   SBYTE0              @ (((unsigned) &BRGD0H)*8) + 7;

extern volatile __bit                   R0D9                @ (((unsigned) &RX0CR)*8) + 0;
extern volatile __bit                   FR0ER               @ (((unsigned) &RX0CR)*8) + 1;
extern volatile __bit                   R0OVF               @ (((unsigned) &RX0CR)*8) + 2;
extern volatile __bit                   SR0EN               @ (((unsigned) &RX0CR)*8) + 3;
extern volatile __bit                   R0L9                @ (((unsigned) &RX0CR)*8) + 4;
//extern volatile __bit                 xx                  @ (((unsigned) &RX0CR)*8) + 5;
extern volatile __bit                   R0CKPS              @ (((unsigned) &RX0CR)*8) + 6;
extern volatile __bit                   RX0EN               @ (((unsigned) &RX0CR)*8) + 7;

extern volatile __bit                   T0D9                @ (((unsigned) &TX0CR)*8) + 0;
extern volatile __bit                   T0SPD0              @ (((unsigned) &TX0CR)*8) + 1;
extern volatile __bit                   T0SPD1              @ (((unsigned) &TX0CR)*8) + 2;
extern volatile __bit                   T0SLAVE             @ (((unsigned) &TX0CR)*8) + 3;
extern volatile __bit                   T0L9                @ (((unsigned) &TX0CR)*8) + 4;
extern volatile __bit                   T0SYNC              @ (((unsigned) &TX0CR)*8) + 5;
extern volatile __bit                   T0MCLR              @ (((unsigned) &TX0CR)*8) + 6;
extern volatile __bit                   TX0EN               @ (((unsigned) &TX0CR)*8) + 7;

extern volatile __bit                   TC2CL0              @ (((unsigned) &TC2CL)*8) + 0;
extern volatile __bit                   TC2CL1              @ (((unsigned) &TC2CL)*8) + 1;
extern volatile __bit                   TC2CL2              @ (((unsigned) &TC2CL)*8) + 2;
extern volatile __bit                   TC2CL3              @ (((unsigned) &TC2CL)*8) + 3;
extern volatile __bit                   TC2CL4              @ (((unsigned) &TC2CL)*8) + 4;
extern volatile __bit                   TC2CL5              @ (((unsigned) &TC2CL)*8) + 5;
extern volatile __bit                   TC2CL6              @ (((unsigned) &TC2CL)*8) + 6;
extern volatile __bit                   TC2CL7              @ (((unsigned) &TC2CL)*8) + 7;

extern volatile __bit                   TC2CH0              @ (((unsigned) &TC2CH)*8) + 0;
extern volatile __bit                   TC2CH1              @ (((unsigned) &TC2CH)*8) + 1;
extern volatile __bit                   TC2CH2              @ (((unsigned) &TC2CH)*8) + 2;
extern volatile __bit                   TC2CH3              @ (((unsigned) &TC2CH)*8) + 3;
extern volatile __bit                   TC2CH4              @ (((unsigned) &TC2CH)*8) + 4;
extern volatile __bit                   TC2CH5              @ (((unsigned) &TC2CH)*8) + 5;
extern volatile __bit                   TC2CH6              @ (((unsigned) &TC2CH)*8) + 6;
extern volatile __bit                   TC2CH7              @ (((unsigned) &TC2CH)*8) + 7;

extern volatile __bit                   TC2PRL0             @ (((unsigned) &TC2PRL)*8) + 0;
extern volatile __bit                   TC2PRL1             @ (((unsigned) &TC2PRL)*8) + 1;
extern volatile __bit                   TC2PRL2             @ (((unsigned) &TC2PRL)*8) + 2;
extern volatile __bit                   TC2PRL3             @ (((unsigned) &TC2PRL)*8) + 3;
extern volatile __bit                   TC2PRL4             @ (((unsigned) &TC2PRL)*8) + 4;
extern volatile __bit                   TC2PRL5             @ (((unsigned) &TC2PRL)*8) + 5;
extern volatile __bit                   TC2PRL6             @ (((unsigned) &TC2PRL)*8) + 6;
extern volatile __bit                   TC2PRL7             @ (((unsigned) &TC2PRL)*8) + 7;

extern volatile __bit                   TC2PRH0             @ (((unsigned) &TC2PRH)*8) + 0;
extern volatile __bit                   TC2PRH1             @ (((unsigned) &TC2PRH)*8) + 1;
extern volatile __bit                   TC2PRH2             @ (((unsigned) &TC2PRH)*8) + 2;
extern volatile __bit                   TC2PRH3             @ (((unsigned) &TC2PRH)*8) + 3;
extern volatile __bit                   TC2PRH4             @ (((unsigned) &TC2PRH)*8) + 4;
extern volatile __bit                   TC2PRH5             @ (((unsigned) &TC2PRH)*8) + 5;
extern volatile __bit                   TC2PRH6             @ (((unsigned) &TC2PRH)*8) + 6;
extern volatile __bit                   TC2PRH7             @ (((unsigned) &TC2PRH)*8) + 7;

extern volatile __bit                   TC2GM0              @ (((unsigned) &TC2GCR)*8) + 0;
extern volatile __bit                   TC2GM1              @ (((unsigned) &TC2GCR)*8) + 1;
extern volatile __bit                   TC2GS0              @ (((unsigned) &TC2GCR)*8) + 2;
extern volatile __bit                   TC2GS1              @ (((unsigned) &TC2GCR)*8) + 3;
//extern volatile __bit                 xx                  @ (((unsigned) &TC2GCR)*8) + 4;
//extern volatile __bit                 xx                  @ (((unsigned) &TC2GCR)*8) + 5;
extern volatile __bit                   TC2GO               @ (((unsigned) &TC2GCR)*8) + 6;
extern volatile __bit                   TC2GEN              @ (((unsigned) &TC2GCR)*8) + 7;

extern volatile __bit                   TC2CKPS0            @ (((unsigned) &T2CR)*8) + 0;
extern volatile __bit                   TC2CKPS1            @ (((unsigned) &T2CR)*8) + 1;
extern volatile __bit                   TC2CKPS2            @ (((unsigned) &T2CR)*8) + 2;
extern volatile __bit                   TC2CKS0             @ (((unsigned) &T2CR)*8) + 3;
extern volatile __bit                   TC2CKS1             @ (((unsigned) &T2CR)*8) + 4;
extern volatile __bit                   T2MOD0              @ (((unsigned) &T2CR)*8) + 5;
extern volatile __bit                   T2MOD1              @ (((unsigned) &T2CR)*8) + 6;
extern volatile __bit                   TC2EN               @ (((unsigned) &T2CR)*8) + 7;

extern volatile __bit                   TC1CL0              @ (((unsigned) &TC1CL)*8) + 0;
extern volatile __bit                   TC1CL1              @ (((unsigned) &TC1CL)*8) + 1;
extern volatile __bit                   TC1CL2              @ (((unsigned) &TC1CL)*8) + 2;
extern volatile __bit                   TC1CL3              @ (((unsigned) &TC1CL)*8) + 3;
extern volatile __bit                   TC1CL4              @ (((unsigned) &TC1CL)*8) + 4;
extern volatile __bit                   TC1CL5              @ (((unsigned) &TC1CL)*8) + 5;
extern volatile __bit                   TC1CL6              @ (((unsigned) &TC1CL)*8) + 6;
extern volatile __bit                   TC1CL7              @ (((unsigned) &TC1CL)*8) + 7;

extern volatile __bit                   TC1CH0              @ (((unsigned) &TC1CH)*8) + 0;
extern volatile __bit                   TC1CH1              @ (((unsigned) &TC1CH)*8) + 1;
extern volatile __bit                   TC1CH2              @ (((unsigned) &TC1CH)*8) + 2;
extern volatile __bit                   TC1CH3              @ (((unsigned) &TC1CH)*8) + 3;
extern volatile __bit                   TC1CH4              @ (((unsigned) &TC1CH)*8) + 4;
extern volatile __bit                   TC1CH5              @ (((unsigned) &TC1CH)*8) + 5;
extern volatile __bit                   TC1CH6              @ (((unsigned) &TC1CH)*8) + 6;
extern volatile __bit                   TC1CH7              @ (((unsigned) &TC1CH)*8) + 7;

extern volatile __bit                   TC1PRL0             @ (((unsigned) &TC1PRL)*8) + 0;
extern volatile __bit                   TC1PRL1             @ (((unsigned) &TC1PRL)*8) + 1;
extern volatile __bit                   TC1PRL2             @ (((unsigned) &TC1PRL)*8) + 2;
extern volatile __bit                   TC1PRL3             @ (((unsigned) &TC1PRL)*8) + 3;
extern volatile __bit                   TC1PRL4             @ (((unsigned) &TC1PRL)*8) + 4;
extern volatile __bit                   TC1PRL5             @ (((unsigned) &TC1PRL)*8) + 5;
extern volatile __bit                   TC1PRL6             @ (((unsigned) &TC1PRL)*8) + 6;
extern volatile __bit                   TC1PRL7             @ (((unsigned) &TC1PRL)*8) + 7;

extern volatile __bit                   TC1PRH0             @ (((unsigned) &TC1PRH)*8) + 0;
extern volatile __bit                   TC1PRH1             @ (((unsigned) &TC1PRH)*8) + 1;
extern volatile __bit                   TC1PRH2             @ (((unsigned) &TC1PRH)*8) + 2;
extern volatile __bit                   TC1PRH3             @ (((unsigned) &TC1PRH)*8) + 3;
extern volatile __bit                   TC1PRH4             @ (((unsigned) &TC1PRH)*8) + 4;
extern volatile __bit                   TC1PRH5             @ (((unsigned) &TC1PRH)*8) + 5;
extern volatile __bit                   TC1PRH6             @ (((unsigned) &TC1PRH)*8) + 6;
extern volatile __bit                   TC1PRH7             @ (((unsigned) &TC1PRH)*8) + 7;

extern volatile __bit                   TC1CKPS0            @ (((unsigned) &T1CR)*8) + 0;
extern volatile __bit                   TC1CKPS1            @ (((unsigned) &T1CR)*8) + 1;
extern volatile __bit                   TC1CKPS2            @ (((unsigned) &T1CR)*8) + 2;
extern volatile __bit                   TC1CKS0             @ (((unsigned) &T1CR)*8) + 3;
extern volatile __bit                   TC1CKS1             @ (((unsigned) &T1CR)*8) + 4;
extern volatile __bit                   TC1MOD0             @ (((unsigned) &T1CR)*8) + 5;
extern volatile __bit                   TC1MOD1             @ (((unsigned) &T1CR)*8) + 6;
extern volatile __bit                   TC1EN               @ (((unsigned) &T1CR)*8) + 7;

extern volatile __bit                   PWM0D0              @ (((unsigned) &PWM0D)*8) + 0;
extern volatile __bit                   PWM0D1              @ (((unsigned) &PWM0D)*8) + 1;
extern volatile __bit                   PWM0D2              @ (((unsigned) &PWM0D)*8) + 2;
extern volatile __bit                   PWM0D3              @ (((unsigned) &PWM0D)*8) + 3;
extern volatile __bit                   PWM0D4              @ (((unsigned) &PWM0D)*8) + 4;
extern volatile __bit                   PWM0D5              @ (((unsigned) &PWM0D)*8) + 5;
extern volatile __bit                   PWM0D6              @ (((unsigned) &PWM0D)*8) + 6;
extern volatile __bit                   PWM0D7              @ (((unsigned) &PWM0D)*8) + 7;

extern volatile __bit                   FLT0EN             @ (((unsigned) &PWM0CR)*8) + 0;
extern volatile __bit                   PWM0M              @ (((unsigned) &PWM0CR)*8) + 1;
//extern volatile __bit                 xx                 @ (((unsigned) &PWM0CR)*8) + 2;
//extern volatile __bit                 xx                 @ (((unsigned) &PWM0CR)*8) + 3;
//extern volatile __bit                 xx                 @ (((unsigned) &PWM0CR)*8) + 4;
//extern volatile __bit                 xx                 @ (((unsigned) &PWM0CR)*8) + 5;
extern volatile __bit                   PWM0OE             @ (((unsigned) &PWM0CR)*8) + 6;
extern volatile __bit                   PWM0EN             @ (((unsigned) &PWM0CR)*8) + 7;

extern volatile __bit                   TC0CL0             @ (((unsigned) &TC0CL)*8) + 0;
extern volatile __bit                   TC0CL1             @ (((unsigned) &TC0CL)*8) + 1;
extern volatile __bit                   TC0CL2             @ (((unsigned) &TC0CL)*8) + 2;
extern volatile __bit                   TC0CL3             @ (((unsigned) &TC0CL)*8) + 3;
extern volatile __bit                   TC0CL4             @ (((unsigned) &TC0CL)*8) + 4;
extern volatile __bit                   TC0CL5             @ (((unsigned) &TC0CL)*8) + 5;
extern volatile __bit                   TC0CL6             @ (((unsigned) &TC0CL)*8) + 6;
extern volatile __bit                   TC0CL7             @ (((unsigned) &TC0CL)*8) + 7;

extern volatile __bit                   TC0CH0             @ (((unsigned) &TC0CH)*8) + 0;
extern volatile __bit                   TC0CH1             @ (((unsigned) &TC0CH)*8) + 1;
extern volatile __bit                   TC0CH2             @ (((unsigned) &TC0CH)*8) + 2;
extern volatile __bit                   TC0CH3             @ (((unsigned) &TC0CH)*8) + 3;
extern volatile __bit                   TC0CH4             @ (((unsigned) &TC0CH)*8) + 4;
extern volatile __bit                   TC0CH5             @ (((unsigned) &TC0CH)*8) + 5;
extern volatile __bit                   TC0CH6             @ (((unsigned) &TC0CH)*8) + 6;
extern volatile __bit                   TC0CH7             @ (((unsigned) &TC0CH)*8) + 7;

extern volatile __bit                   TC0CKPS0           @ (((unsigned) &T0CR)*8) + 0;
extern volatile __bit                   TC0CKPS1           @ (((unsigned) &T0CR)*8) + 1;
extern volatile __bit                   TC0CKPS2           @ (((unsigned) &T0CR)*8) + 2;
extern volatile __bit                   TC0CKS0            @ (((unsigned) &T0CR)*8) + 3;
extern volatile __bit                   TC0CKS1            @ (((unsigned) &T0CR)*8) + 4;
extern volatile __bit                   T0HOSCS            @ (((unsigned) &T0CR)*8) + 5;
extern volatile __bit                   TC0MOD             @ (((unsigned) &T0CR)*8) + 6;
extern volatile __bit                   TC0EN              @ (((unsigned) &T0CR)*8) + 7;

extern volatile __bit                   STPL               @ (((unsigned) &OSCM)*8) + 0;
extern volatile __bit                   LIRC500K           @ (((unsigned) &OSCM)*8) + 1;
extern volatile __bit                   STPH               @ (((unsigned) &OSCM)*8) + 2;
extern volatile __bit                   CLKM               @ (((unsigned) &OSCM)*8) + 3;
extern volatile __bit                   STOP               @ (((unsigned) &OSCM)*8) + 4;
extern volatile __bit                   HSPDX2             @ (((unsigned) &OSCM)*8) + 5;
extern volatile __bit                   STBL               @ (((unsigned) &OSCM)*8) + 6;
extern volatile __bit                   STBH               @ (((unsigned) &OSCM)*8) + 7;

extern volatile __bit                   WDTC0              @ (((unsigned) &WDTC)*8) + 0;
extern volatile __bit                   WDTC1              @ (((unsigned) &WDTC)*8) + 1;
extern volatile __bit                   WDTC2              @ (((unsigned) &WDTC)*8) + 2;
extern volatile __bit                   WDTC3              @ (((unsigned) &WDTC)*8) + 3;
extern volatile __bit                   WDTC4              @ (((unsigned) &WDTC)*8) + 4;
extern volatile __bit                   WDTC5              @ (((unsigned) &WDTC)*8) + 5;
extern volatile __bit                   WDTC6              @ (((unsigned) &WDTC)*8) + 6;
extern volatile __bit                   WDTC7              @ (((unsigned) &WDTC)*8) + 7;
       
extern volatile __bit                   ADL0              @ (((unsigned) &ADL)*8) + 0;
extern volatile __bit                   ADL1              @ (((unsigned) &ADL)*8) + 1;
extern volatile __bit                   ADL2              @ (((unsigned) &ADL)*8) + 2;
extern volatile __bit                   ADL3              @ (((unsigned) &ADL)*8) + 3;
extern volatile __bit                   ADL4              @ (((unsigned) &ADL)*8) + 4;
extern volatile __bit                   ADL5              @ (((unsigned) &ADL)*8) + 5;
extern volatile __bit                   ADL6              @ (((unsigned) &ADL)*8) + 6;
extern volatile __bit                   ADL7              @ (((unsigned) &ADL)*8) + 7;

extern volatile __bit                   ADH0              @ (((unsigned) &ADH)*8) + 0;
extern volatile __bit                   ADH1              @ (((unsigned) &ADH)*8) + 1;
extern volatile __bit                   ADH2              @ (((unsigned) &ADH)*8) + 2;
extern volatile __bit                   ADH3              @ (((unsigned) &ADH)*8) + 3;
extern volatile __bit                   ADH4              @ (((unsigned) &ADH)*8) + 4;
extern volatile __bit                   ADH5              @ (((unsigned) &ADH)*8) + 5;
extern volatile __bit                   ADH6              @ (((unsigned) &ADH)*8) + 6;
extern volatile __bit                   ADH7              @ (((unsigned) &ADH)*8) + 7;

extern volatile __bit                   ADVOS0            @ (((unsigned) &ADCON2)*8) + 0;
extern volatile __bit                   ADVOS1            @ (((unsigned) &ADCON2)*8) + 1;
extern volatile __bit                   ADVOS2            @ (((unsigned) &ADCON2)*8) + 2;
extern volatile __bit                   ADVOS3            @ (((unsigned) &ADCON2)*8) + 3;
extern volatile __bit                   CMPHDEN           @ (((unsigned) &ADCON2)*8) + 4;
extern volatile __bit                   VREFO             @ (((unsigned) &ADCON2)*8) + 5;
extern volatile __bit                   TRGEN             @ (((unsigned) &ADCON2)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &ADCON2)*8) + 7;

extern volatile __bit                   VHS0              @ (((unsigned) &ADCON1)*8) + 0;
extern volatile __bit                   VHS1              @ (((unsigned) &ADCON1)*8) + 1;
extern volatile __bit                   VREMS0            @ (((unsigned) &ADCON1)*8) + 2;
extern volatile __bit                   VREMS1            @ (((unsigned) &ADCON1)*8) + 3;
extern volatile __bit                   ADCKS0            @ (((unsigned) &ADCON1)*8) + 4;
extern volatile __bit                   ADCKS1            @ (((unsigned) &ADCON1)*8) + 5;
extern volatile __bit                   ADCKS2            @ (((unsigned) &ADCON1)*8) + 6;
extern volatile __bit                   VHS2              @ (((unsigned) &ADCON1)*8) + 7;

extern volatile __bit                   CHS0              @ (((unsigned) &ADCON0)*8) + 0;
extern volatile __bit                   CHS1              @ (((unsigned) &ADCON0)*8) + 1;
extern volatile __bit                   CHS2              @ (((unsigned) &ADCON0)*8) + 2;
extern volatile __bit                   CHS3              @ (((unsigned) &ADCON0)*8) + 3;
extern volatile __bit                   CHS4              @ (((unsigned) &ADCON0)*8) + 4;
extern volatile __bit                   ADFM              @ (((unsigned) &ADCON0)*8) + 5;
extern volatile __bit                   ADS               @ (((unsigned) &ADCON0)*8) + 6;
extern volatile __bit                   ADEN              @ (((unsigned) &ADCON0)*8) + 7;

extern volatile __bit                   ANSF0             @ (((unsigned) &ANSF)*8) + 0;
extern volatile __bit                   ANSF1             @ (((unsigned) &ANSF)*8) + 1;
extern volatile __bit                   ANSF2             @ (((unsigned) &ANSF)*8) + 2;
extern volatile __bit                   ANSF3             @ (((unsigned) &ANSF)*8) + 3;
extern volatile __bit                   ANSF4             @ (((unsigned) &ANSF)*8) + 4;
extern volatile __bit                   ANSF5             @ (((unsigned) &ANSF)*8) + 5;
extern volatile __bit                   ANSF6             @ (((unsigned) &ANSF)*8) + 6;
extern volatile __bit                   ANSF7             @ (((unsigned) &ANSF)*8) + 7;

extern volatile __bit                   ANSE0             @ (((unsigned) &ANSE)*8) + 0;
extern volatile __bit                   ANSE1             @ (((unsigned) &ANSE)*8) + 1;
extern volatile __bit                   ANSE2             @ (((unsigned) &ANSE)*8) + 2;
extern volatile __bit                   ANSE3             @ (((unsigned) &ANSE)*8) + 3;
extern volatile __bit                   ANSE4             @ (((unsigned) &ANSE)*8) + 4;
extern volatile __bit                   ANSE5             @ (((unsigned) &ANSE)*8) + 5;
extern volatile __bit                   ANSE6             @ (((unsigned) &ANSE)*8) + 6;
extern volatile __bit                   ANSE7             @ (((unsigned) &ANSE)*8) + 7;

extern volatile __bit                   ANSD0             @ (((unsigned) &ANSD)*8) + 0;
extern volatile __bit                   ANSD1             @ (((unsigned) &ANSD)*8) + 1;
extern volatile __bit                   ANSD2             @ (((unsigned) &ANSD)*8) + 2;
extern volatile __bit                   ANSD3             @ (((unsigned) &ANSD)*8) + 3;
extern volatile __bit                   ANSD4             @ (((unsigned) &ANSD)*8) + 4;
extern volatile __bit                   ANSD5             @ (((unsigned) &ANSD)*8) + 5;
extern volatile __bit                   ANSD6             @ (((unsigned) &ANSD)*8) + 6;
extern volatile __bit                   ANSD7             @ (((unsigned) &ANSD)*8) + 7;

extern volatile __bit                   ANSC0             @ (((unsigned) &ANSC)*8) + 0;
extern volatile __bit                   ANSC1             @ (((unsigned) &ANSC)*8) + 1;
extern volatile __bit                   ANSC2             @ (((unsigned) &ANSC)*8) + 2;
extern volatile __bit                   ANSC3             @ (((unsigned) &ANSC)*8) + 3;
extern volatile __bit                   ANSC4             @ (((unsigned) &ANSC)*8) + 4;
extern volatile __bit                   ANSC5             @ (((unsigned) &ANSC)*8) + 5;
extern volatile __bit                   ANSC6             @ (((unsigned) &ANSC)*8) + 6;
extern volatile __bit                   ANSC7             @ (((unsigned) &ANSC)*8) + 7;

extern volatile __bit                   ANSB0             @ (((unsigned) &ANSB)*8) + 0;
extern volatile __bit                   ANSB1             @ (((unsigned) &ANSB)*8) + 1;
extern volatile __bit                   ANSB2             @ (((unsigned) &ANSB)*8) + 2;
extern volatile __bit                   ANSB3             @ (((unsigned) &ANSB)*8) + 3;
extern volatile __bit                   ANSB4             @ (((unsigned) &ANSB)*8) + 4;
extern volatile __bit                   ANSB5             @ (((unsigned) &ANSB)*8) + 5;
extern volatile __bit                   ANSB6             @ (((unsigned) &ANSB)*8) + 6;
extern volatile __bit                   ANSB7             @ (((unsigned) &ANSB)*8) + 7;

extern volatile __bit                   ANSA0             @ (((unsigned) &ANSA)*8) + 0;
extern volatile __bit                   ANSA1             @ (((unsigned) &ANSA)*8) + 1;
extern volatile __bit                   ANSA2             @ (((unsigned) &ANSA)*8) + 2;
extern volatile __bit                   ANSA3             @ (((unsigned) &ANSA)*8) + 3;
extern volatile __bit                   ANSA4             @ (((unsigned) &ANSA)*8) + 4;
extern volatile __bit                   ANSA5             @ (((unsigned) &ANSA)*8) + 5;
extern volatile __bit                   ANSA6             @ (((unsigned) &ANSA)*8) + 6;
extern volatile __bit                   ANSA7             @ (((unsigned) &ANSA)*8) + 7;

extern volatile __bit                   IOFOR0            @ (((unsigned) &IOFOR)*8) + 0;
extern volatile __bit                   IOFOR1            @ (((unsigned) &IOFOR)*8) + 1;
extern volatile __bit                   IOFOR2            @ (((unsigned) &IOFOR)*8) + 2;
extern volatile __bit                   IOFOR3            @ (((unsigned) &IOFOR)*8) + 3;
extern volatile __bit                   IOFOR4            @ (((unsigned) &IOFOR)*8) + 4;
extern volatile __bit                   IOFOR5            @ (((unsigned) &IOFOR)*8) + 5;
extern volatile __bit                   IOFOR6            @ (((unsigned) &IOFOR)*8) + 6;
extern volatile __bit                   IOFOR7            @ (((unsigned) &IOFOR)*8) + 7;

extern volatile __bit                   IOEOR0            @ (((unsigned) &IOEOR)*8) + 0;
extern volatile __bit                   IOEOR1            @ (((unsigned) &IOEOR)*8) + 1;
extern volatile __bit                   IOEOR2            @ (((unsigned) &IOEOR)*8) + 2;
extern volatile __bit                   IOEOR3            @ (((unsigned) &IOEOR)*8) + 3;
extern volatile __bit                   IOEOR4            @ (((unsigned) &IOEOR)*8) + 4;
extern volatile __bit                   IOEOR5            @ (((unsigned) &IOEOR)*8) + 5;
extern volatile __bit                   IOEOR6            @ (((unsigned) &IOEOR)*8) + 6;
extern volatile __bit                   IOEOR7            @ (((unsigned) &IOEOR)*8) + 7;

extern volatile __bit                   IODOR0            @ (((unsigned) &IODOR)*8) + 0;
extern volatile __bit                   IODOR1            @ (((unsigned) &IODOR)*8) + 1;
extern volatile __bit                   IODOR2            @ (((unsigned) &IODOR)*8) + 2;
extern volatile __bit                   IODOR3            @ (((unsigned) &IODOR)*8) + 3;
extern volatile __bit                   IODOR4            @ (((unsigned) &IODOR)*8) + 4;
extern volatile __bit                   IODOR5            @ (((unsigned) &IODOR)*8) + 5;
extern volatile __bit                   IODOR6            @ (((unsigned) &IODOR)*8) + 6;
extern volatile __bit                   IODOR7            @ (((unsigned) &IODOR)*8) + 7;

extern volatile __bit                   IOCOR0            @ (((unsigned) &IOCOR)*8) + 0;
extern volatile __bit                   IOCOR1            @ (((unsigned) &IOCOR)*8) + 1;
extern volatile __bit                   IOCOR2            @ (((unsigned) &IOCOR)*8) + 2;
extern volatile __bit                   IOCOR3            @ (((unsigned) &IOCOR)*8) + 3;
extern volatile __bit                   IOCOR4            @ (((unsigned) &IOCOR)*8) + 4;
extern volatile __bit                   IOCOR5            @ (((unsigned) &IOCOR)*8) + 5;
extern volatile __bit                   IOCOR6            @ (((unsigned) &IOCOR)*8) + 6;
extern volatile __bit                   IOCOR7            @ (((unsigned) &IOCOR)*8) + 7;

extern volatile __bit                   IOBOR0            @ (((unsigned) &IOBOR)*8) + 0;
extern volatile __bit                   IOBOR1            @ (((unsigned) &IOBOR)*8) + 1;
extern volatile __bit                   IOBOR2            @ (((unsigned) &IOBOR)*8) + 2;
extern volatile __bit                   IOBOR3            @ (((unsigned) &IOBOR)*8) + 3;
extern volatile __bit                   IOBOR4            @ (((unsigned) &IOBOR)*8) + 4;
extern volatile __bit                   IOBOR5            @ (((unsigned) &IOBOR)*8) + 5;
extern volatile __bit                   IOBOR6            @ (((unsigned) &IOBOR)*8) + 6;
extern volatile __bit                   IOBOR7            @ (((unsigned) &IOBOR)*8) + 7;

extern volatile __bit                   IOAOR0            @ (((unsigned) &IOAOR)*8) + 0;
extern volatile __bit                   IOAOR1            @ (((unsigned) &IOAOR)*8) + 1;
extern volatile __bit                   IOAOR2            @ (((unsigned) &IOAOR)*8) + 2;
extern volatile __bit                   IOAOR3            @ (((unsigned) &IOAOR)*8) + 3;
extern volatile __bit                   IOAOR4            @ (((unsigned) &IOAOR)*8) + 4;
extern volatile __bit                   IOAOR5            @ (((unsigned) &IOAOR)*8) + 5;
extern volatile __bit                   IOAOR6            @ (((unsigned) &IOAOR)*8) + 6;
extern volatile __bit                   IOAOR7            @ (((unsigned) &IOAOR)*8) + 7;

extern volatile __bit                   OEF0              @ (((unsigned) &OEF)*8) + 0;
extern volatile __bit                   OEF1              @ (((unsigned) &OEF)*8) + 1;
extern volatile __bit                   OEF2              @ (((unsigned) &OEF)*8) + 2;
extern volatile __bit                   OEF3              @ (((unsigned) &OEF)*8) + 3;
extern volatile __bit                   OEF4              @ (((unsigned) &OEF)*8) + 4;
extern volatile __bit                   OEF5              @ (((unsigned) &OEF)*8) + 5;
extern volatile __bit                   OEF6              @ (((unsigned) &OEF)*8) + 6;
extern volatile __bit                   OEF7              @ (((unsigned) &OEF)*8) + 7;

extern volatile __bit                   OEE0              @ (((unsigned) &OEE)*8) + 0;
extern volatile __bit                   OEE1              @ (((unsigned) &OEE)*8) + 1;
extern volatile __bit                   OEE2              @ (((unsigned) &OEE)*8) + 2;
extern volatile __bit                   OEE3              @ (((unsigned) &OEE)*8) + 3;
extern volatile __bit                   OEE4              @ (((unsigned) &OEE)*8) + 4;
extern volatile __bit                   OEE5              @ (((unsigned) &OEE)*8) + 5;
extern volatile __bit                   OEE6              @ (((unsigned) &OEE)*8) + 6;
extern volatile __bit                   OEE7              @ (((unsigned) &OEE)*8) + 7;

extern volatile __bit                   OED0              @ (((unsigned) &OED)*8) + 0;
extern volatile __bit                   OED1              @ (((unsigned) &OED)*8) + 1;
extern volatile __bit                   OED2              @ (((unsigned) &OED)*8) + 2;
extern volatile __bit                   OED3              @ (((unsigned) &OED)*8) + 3;
extern volatile __bit                   OED4              @ (((unsigned) &OED)*8) + 4;
extern volatile __bit                   OED5              @ (((unsigned) &OED)*8) + 5;
extern volatile __bit                   OED6              @ (((unsigned) &OED)*8) + 6;
extern volatile __bit                   OED7              @ (((unsigned) &OED)*8) + 7;

extern volatile __bit                   OEC0              @ (((unsigned) &OEC)*8) + 0;
extern volatile __bit                   OEC1              @ (((unsigned) &OEC)*8) + 1;
extern volatile __bit                   OEC2              @ (((unsigned) &OEC)*8) + 2;
extern volatile __bit                   OEC3              @ (((unsigned) &OEC)*8) + 3;
extern volatile __bit                   OEC4              @ (((unsigned) &OEC)*8) + 4;
extern volatile __bit                   OEC5              @ (((unsigned) &OEC)*8) + 5;
extern volatile __bit                   OEC6              @ (((unsigned) &OEC)*8) + 6;
extern volatile __bit                   OEC7              @ (((unsigned) &OEC)*8) + 7;

extern volatile __bit                   OEB0              @ (((unsigned) &OEB)*8) + 0;
extern volatile __bit                   OEB1              @ (((unsigned) &OEB)*8) + 1;
extern volatile __bit                   OEB2              @ (((unsigned) &OEB)*8) + 2;
extern volatile __bit                   OEB3              @ (((unsigned) &OEB)*8) + 3;
extern volatile __bit                   OEB4              @ (((unsigned) &OEB)*8) + 4;
extern volatile __bit                   OEB5              @ (((unsigned) &OEB)*8) + 5;
extern volatile __bit                   OEB6              @ (((unsigned) &OEB)*8) + 6;
extern volatile __bit                   OEB7              @ (((unsigned) &OEB)*8) + 7;

extern volatile __bit                   OEA0              @ (((unsigned) &OEA)*8) + 0;
extern volatile __bit                   OEA1              @ (((unsigned) &OEA)*8) + 1;
extern volatile __bit                   OEA2              @ (((unsigned) &OEA)*8) + 2;
extern volatile __bit                   OEA3              @ (((unsigned) &OEA)*8) + 3;
extern volatile __bit                   OEA4              @ (((unsigned) &OEA)*8) + 4;
extern volatile __bit                   OEA5              @ (((unsigned) &OEA)*8) + 5;
extern volatile __bit                   OEA6              @ (((unsigned) &OEA)*8) + 6;
extern volatile __bit                   OEA7              @ (((unsigned) &OEA)*8) + 7;

extern volatile __bit                   PF0              @ (((unsigned) &IOF)*8) + 0;
extern volatile __bit                   PF1              @ (((unsigned) &IOF)*8) + 1;
extern volatile __bit                   PF2              @ (((unsigned) &IOF)*8) + 2;
extern volatile __bit                   PF3              @ (((unsigned) &IOF)*8) + 3;
extern volatile __bit                   PF4              @ (((unsigned) &IOF)*8) + 4;
extern volatile __bit                   PF5              @ (((unsigned) &IOF)*8) + 5;
extern volatile __bit                   PF6              @ (((unsigned) &IOF)*8) + 6;
extern volatile __bit                   PF7              @ (((unsigned) &IOF)*8) + 7;

extern volatile __bit                   PE0              @ (((unsigned) &IOE)*8) + 0;
extern volatile __bit                   PE1              @ (((unsigned) &IOE)*8) + 1;
extern volatile __bit                   PE2              @ (((unsigned) &IOE)*8) + 2;
extern volatile __bit                   PE3              @ (((unsigned) &IOE)*8) + 3;
extern volatile __bit                   PE4              @ (((unsigned) &IOE)*8) + 4;
extern volatile __bit                   PE5              @ (((unsigned) &IOE)*8) + 5;
extern volatile __bit                   PE6              @ (((unsigned) &IOE)*8) + 6;
extern volatile __bit                   PE7              @ (((unsigned) &IOE)*8) + 7;

extern volatile __bit                   PD0              @ (((unsigned) &IOD)*8) + 0;
extern volatile __bit                   PD1              @ (((unsigned) &IOD)*8) + 1;
extern volatile __bit                   PD2              @ (((unsigned) &IOD)*8) + 2;
extern volatile __bit                   PD3              @ (((unsigned) &IOD)*8) + 3;
extern volatile __bit                   PD4              @ (((unsigned) &IOD)*8) + 4;
extern volatile __bit                   PD5              @ (((unsigned) &IOD)*8) + 5;
extern volatile __bit                   PD6              @ (((unsigned) &IOD)*8) + 6;
extern volatile __bit                   PD7              @ (((unsigned) &IOD)*8) + 7;

extern volatile __bit                   PC0              @ (((unsigned) &IOC)*8) + 0;
extern volatile __bit                   PC1              @ (((unsigned) &IOC)*8) + 1;
extern volatile __bit                   PC2              @ (((unsigned) &IOC)*8) + 2;
extern volatile __bit                   PC3              @ (((unsigned) &IOC)*8) + 3;
extern volatile __bit                   PC4              @ (((unsigned) &IOC)*8) + 4;
extern volatile __bit                   PC5              @ (((unsigned) &IOC)*8) + 5;
extern volatile __bit                   PC6              @ (((unsigned) &IOC)*8) + 6;
extern volatile __bit                   PC7              @ (((unsigned) &IOC)*8) + 7;

extern volatile __bit                   PB0              @ (((unsigned) &IOB)*8) + 0;
extern volatile __bit                   PB1              @ (((unsigned) &IOB)*8) + 1;
extern volatile __bit                   PB2              @ (((unsigned) &IOB)*8) + 2;
extern volatile __bit                   PB3              @ (((unsigned) &IOB)*8) + 3;
extern volatile __bit                   PB4              @ (((unsigned) &IOB)*8) + 4;
extern volatile __bit                   PB5              @ (((unsigned) &IOB)*8) + 5;
extern volatile __bit                   PB6              @ (((unsigned) &IOB)*8) + 6;
extern volatile __bit                   PB7              @ (((unsigned) &IOB)*8) + 7;

extern volatile __bit                   PA0              @ (((unsigned) &IOA)*8) + 0;
extern volatile __bit                   PA1              @ (((unsigned) &IOA)*8) + 1;
extern volatile __bit                   PA2              @ (((unsigned) &IOA)*8) + 2;
extern volatile __bit                   PA3              @ (((unsigned) &IOA)*8) + 3;
extern volatile __bit                   PA4              @ (((unsigned) &IOA)*8) + 4;
extern volatile __bit                   PA5              @ (((unsigned) &IOA)*8) + 5;
extern volatile __bit                   PA6              @ (((unsigned) &IOA)*8) + 6;
extern volatile __bit                   PA7              @ (((unsigned) &IOA)*8) + 7;

extern volatile __bit                   UINTBUSP          @ (((unsigned) &UINTP)*8) + 0;
extern volatile __bit                   UINTP0            @ (((unsigned) &UINTP)*8) + 1;
extern volatile __bit                   UINTP1            @ (((unsigned) &UINTP)*8) + 2;
extern volatile __bit                   UINTP2            @ (((unsigned) &UINTP)*8) + 3;
extern volatile __bit                   UINTP3            @ (((unsigned) &UINTP)*8) + 4;
extern volatile __bit                   UINTP4            @ (((unsigned) &UINTP)*8) + 5;
extern volatile __bit                   UINTP5            @ (((unsigned) &UINTP)*8) + 6;
//extern volatile __bit                 xxx               @ (((unsigned) &UINTP)*8) + 7;

extern volatile __bit                   I2C0IP            @ (((unsigned) &INTP2)*8) + 0;
extern volatile __bit                   I2C1IP            @ (((unsigned) &INTP2)*8) + 1;
extern volatile __bit                   ADIP              @ (((unsigned) &INTP2)*8) + 2;
extern volatile __bit                   TKIP              @ (((unsigned) &INTP2)*8) + 3;
extern volatile __bit                   TX0IP             @ (((unsigned) &INTP2)*8) + 4;
extern volatile __bit                   RX0IP             @ (((unsigned) &INTP2)*8) + 5;
extern volatile __bit                   TX1IP             @ (((unsigned) &INTP2)*8) + 6;
extern volatile __bit                   RX1IP             @ (((unsigned) &INTP2)*8) + 7;

extern volatile __bit                   IOACHIP           @ (((unsigned) &INTP1)*8) + 0;
extern volatile __bit                   IOBCHIP           @ (((unsigned) &INTP1)*8) + 1;
extern volatile __bit                   IOCCHIP           @ (((unsigned) &INTP1)*8) + 2;
extern volatile __bit                   IODCHIP           @ (((unsigned) &INTP1)*8) + 3;
extern volatile __bit                   IOECHIP           @ (((unsigned) &INTP1)*8) + 4;
extern volatile __bit                   IOFCHIP           @ (((unsigned) &INTP1)*8) + 5;
extern volatile __bit                   INT0IP            @ (((unsigned) &INTP1)*8) + 6;
extern volatile __bit                   INT1IP            @ (((unsigned) &INTP1)*8) + 7;

extern volatile __bit                   TC0IP             @ (((unsigned) &INTP0)*8) + 0;
extern volatile __bit                   TC1IP             @ (((unsigned) &INTP0)*8) + 1;
extern volatile __bit                   TC2IP             @ (((unsigned) &INTP0)*8) + 2;
extern volatile __bit                   TC2GIP            @ (((unsigned) &INTP0)*8) + 3;
extern volatile __bit                   CMP0IP            @ (((unsigned) &INTP0)*8) + 4;
extern volatile __bit                   CMP1IP            @ (((unsigned) &INTP0)*8) + 5;
extern volatile __bit                   OPA0IP            @ (((unsigned) &INTP0)*8) + 6;
extern volatile __bit                   OPA1IP            @ (((unsigned) &INTP0)*8) + 7;

extern volatile __bit                   I2C0IF            @ (((unsigned) &INTF2)*8) + 0;
extern volatile __bit                   I2C1IF            @ (((unsigned) &INTF2)*8) + 1;
extern volatile __bit                   ADIF              @ (((unsigned) &INTF2)*8) + 2;
extern volatile __bit                   TKIF              @ (((unsigned) &INTF2)*8) + 3;
extern volatile __bit                   TX0IF             @ (((unsigned) &INTF2)*8) + 4;
extern volatile __bit                   RX0IF             @ (((unsigned) &INTF2)*8) + 5;
extern volatile __bit                   TX1IF             @ (((unsigned) &INTF2)*8) + 6;
extern volatile __bit                   RX1IF             @ (((unsigned) &INTF2)*8) + 7;

extern volatile __bit                   IOACHIF           @ (((unsigned) &INTF1)*8) + 0;
extern volatile __bit                   IOBCHIF           @ (((unsigned) &INTF1)*8) + 1;
extern volatile __bit                   IOCCHIF           @ (((unsigned) &INTF1)*8) + 2;
extern volatile __bit                   IODCHIF           @ (((unsigned) &INTF1)*8) + 3;
extern volatile __bit                   IOECHIF           @ (((unsigned) &INTF1)*8) + 4;
extern volatile __bit                   IOFCHIF           @ (((unsigned) &INTF1)*8) + 5;
extern volatile __bit                   INT0IF            @ (((unsigned) &INTF1)*8) + 6;
extern volatile __bit                   INT1IF            @ (((unsigned) &INTF1)*8) + 7;

extern volatile __bit                   TC0IF             @ (((unsigned) &INTF0)*8) + 0;
extern volatile __bit                   TC1IF             @ (((unsigned) &INTF0)*8) + 1;
extern volatile __bit                   TC2IF             @ (((unsigned) &INTF0)*8) + 2;
extern volatile __bit                   TC2GIF            @ (((unsigned) &INTF0)*8) + 3;
extern volatile __bit                   CMP0IF            @ (((unsigned) &INTF0)*8) + 4;
extern volatile __bit                   CMP1IF            @ (((unsigned) &INTF0)*8) + 5;
extern volatile __bit                   OPA0IF            @ (((unsigned) &INTF0)*8) + 6;
extern volatile __bit                   OPA1IF            @ (((unsigned) &INTF0)*8) + 7;

extern volatile __bit                   UINTBUS           @ (((unsigned) &UINTCR0)*8) + 0;
extern volatile __bit                   UINTEP0           @ (((unsigned) &UINTCR0)*8) + 1;
extern volatile __bit                   UINTEP1           @ (((unsigned) &UINTCR0)*8) + 2;
extern volatile __bit                   UINTEP2           @ (((unsigned) &UINTCR0)*8) + 3;
extern volatile __bit                   UINTEP3           @ (((unsigned) &UINTCR0)*8) + 4;
extern volatile __bit                   UINTEP4           @ (((unsigned) &UINTCR0)*8) + 5;
extern volatile __bit                   UINTEP5           @ (((unsigned) &UINTCR0)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &UINTCR0)*8) + 7;

extern volatile __bit                   I2C0IE            @ (((unsigned) &INTCR2)*8) + 0;
extern volatile __bit                   I2C1IE            @ (((unsigned) &INTCR2)*8) + 1;
extern volatile __bit                   ADIE              @ (((unsigned) &INTCR2)*8) + 2;
extern volatile __bit                   TKIE              @ (((unsigned) &INTCR2)*8) + 3;
extern volatile __bit                   TX0IE             @ (((unsigned) &INTCR2)*8) + 4;
extern volatile __bit                   RX0IE             @ (((unsigned) &INTCR2)*8) + 5;
extern volatile __bit                   TX1IE             @ (((unsigned) &INTCR2)*8) + 6;
extern volatile __bit                   RX1IE             @ (((unsigned) &INTCR2)*8) + 7;

extern volatile __bit                   IOACHIE           @ (((unsigned) &INTCR1)*8) + 0;
extern volatile __bit                   IOBCHIE           @ (((unsigned) &INTCR1)*8) + 1;
extern volatile __bit                   IOCCHIE           @ (((unsigned) &INTCR1)*8) + 2;
extern volatile __bit                   IODCHIE           @ (((unsigned) &INTCR1)*8) + 3;
extern volatile __bit                   IOECHIE           @ (((unsigned) &INTCR1)*8) + 4;
extern volatile __bit                   IOFCHIE           @ (((unsigned) &INTCR1)*8) + 5;
extern volatile __bit                   INT0IE            @ (((unsigned) &INTCR1)*8) + 6;
extern volatile __bit                   INT1IE            @ (((unsigned) &INTCR1)*8) + 7;
       
extern volatile __bit                   TC0IE             @ (((unsigned) &INTCR0)*8) + 0;
extern volatile __bit                   TC1IE             @ (((unsigned) &INTCR0)*8) + 1;
extern volatile __bit                   TC2IE             @ (((unsigned) &INTCR0)*8) + 2;
extern volatile __bit                   TC2GIE            @ (((unsigned) &INTCR0)*8) + 3;
extern volatile __bit                   CMP0IE            @ (((unsigned) &INTCR0)*8) + 4;
extern volatile __bit                   CMP1IE            @ (((unsigned) &INTCR0)*8) + 5;
extern volatile __bit                   OPA0IE            @ (((unsigned) &INTCR0)*8) + 6;
extern volatile __bit                   OPA1IE            @ (((unsigned) &INTCR0)*8) + 7;

extern volatile __bit                   C                 @ (((unsigned) &STATUS)*8) + 0;
extern volatile __bit                   DC                @ (((unsigned) &STATUS)*8) + 1;
extern volatile __bit                   Z                 @ (((unsigned) &STATUS)*8) + 2;
extern volatile __bit                   OV                @ (((unsigned) &STATUS)*8) + 3;
extern volatile __bit                   N                 @ (((unsigned) &STATUS)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &STATUS)*8) + 5;
//extern volatile __bit                   SOFTRST           @ (((unsigned) &STATUS)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &STATUS)*8) + 7;

extern volatile __bit                   FSR2L0            @ (((unsigned) &FSR2L)*8) + 0;
extern volatile __bit                   FSR2L1            @ (((unsigned) &FSR2L)*8) + 1;
extern volatile __bit                   FSR2L2            @ (((unsigned) &FSR2L)*8) + 2;
extern volatile __bit                   FSR2L3            @ (((unsigned) &FSR2L)*8) + 3;
extern volatile __bit                   FSR2L4            @ (((unsigned) &FSR2L)*8) + 4;
extern volatile __bit                   FSR2L5            @ (((unsigned) &FSR2L)*8) + 5;
extern volatile __bit                   FSR2L6            @ (((unsigned) &FSR2L)*8) + 6;
extern volatile __bit                   FSR2L7            @ (((unsigned) &FSR2L)*8) + 7;

extern volatile __bit                   FSR2H0            @ (((unsigned) &FSR2H)*8) + 0;
extern volatile __bit                   FSR2H1            @ (((unsigned) &FSR2H)*8) + 1;
extern volatile __bit                   FSR2H2            @ (((unsigned) &FSR2H)*8) + 2;
extern volatile __bit                   FSR2H3            @ (((unsigned) &FSR2H)*8) + 3;
//extern volatile __bit                 xx                @ (((unsigned) &FSR2H)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &FSR2H)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &FSR2H)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &FSR2H)*8) + 7;

extern volatile __bit                   PLUSW20           @ (((unsigned) &PLUSW2)*8) + 0;
extern volatile __bit                   PLUSW21           @ (((unsigned) &PLUSW2)*8) + 1;
extern volatile __bit                   PLUSW22           @ (((unsigned) &PLUSW2)*8) + 2;
extern volatile __bit                   PLUSW23           @ (((unsigned) &PLUSW2)*8) + 3;
extern volatile __bit                   PLUSW24           @ (((unsigned) &PLUSW2)*8) + 4;
extern volatile __bit                   PLUSW25           @ (((unsigned) &PLUSW2)*8) + 5;
extern volatile __bit                   PLUSW26           @ (((unsigned) &PLUSW2)*8) + 6;
extern volatile __bit                   PLUSW27           @ (((unsigned) &PLUSW2)*8) + 7;

extern volatile __bit                   PREINC20          @ (((unsigned) &PREINC2)*8) + 0;
extern volatile __bit                   PREINC21          @ (((unsigned) &PREINC2)*8) + 1;
extern volatile __bit                   PREINC22          @ (((unsigned) &PREINC2)*8) + 2;
extern volatile __bit                   PREINC23          @ (((unsigned) &PREINC2)*8) + 3;
extern volatile __bit                   PREINC24          @ (((unsigned) &PREINC2)*8) + 4;
extern volatile __bit                   PREINC25          @ (((unsigned) &PREINC2)*8) + 5;
extern volatile __bit                   PREINC26          @ (((unsigned) &PREINC2)*8) + 6;
extern volatile __bit                   PREINC27          @ (((unsigned) &PREINC2)*8) + 7;

extern volatile __bit                   POSTDEC20         @ (((unsigned) &POSTDEC2)*8) + 0;
extern volatile __bit                   POSTDEC21         @ (((unsigned) &POSTDEC2)*8) + 1;
extern volatile __bit                   POSTDEC22         @ (((unsigned) &POSTDEC2)*8) + 2;
extern volatile __bit                   POSTDEC23         @ (((unsigned) &POSTDEC2)*8) + 3;
extern volatile __bit                   POSTDEC24         @ (((unsigned) &POSTDEC2)*8) + 4;
extern volatile __bit                   POSTDEC25         @ (((unsigned) &POSTDEC2)*8) + 5;
extern volatile __bit                   POSTDEC26         @ (((unsigned) &POSTDEC2)*8) + 6;
extern volatile __bit                   POSTDEC27         @ (((unsigned) &POSTDEC2)*8) + 7;

extern volatile __bit                   POSTINC20         @ (((unsigned) &POSTINC2)*8) + 0;
extern volatile __bit                   POSTINC21         @ (((unsigned) &POSTINC2)*8) + 1;
extern volatile __bit                   POSTINC22         @ (((unsigned) &POSTINC2)*8) + 2;
extern volatile __bit                   POSTINC23         @ (((unsigned) &POSTINC2)*8) + 3;
extern volatile __bit                   POSTINC24         @ (((unsigned) &POSTINC2)*8) + 4;
extern volatile __bit                   POSTINC25         @ (((unsigned) &POSTINC2)*8) + 5;
extern volatile __bit                   POSTINC26         @ (((unsigned) &POSTINC2)*8) + 6;
extern volatile __bit                   POSTINC27         @ (((unsigned) &POSTINC2)*8) + 7;

extern volatile __bit                   INDF20            @ (((unsigned) &INDF2)*8) + 0;
extern volatile __bit                   INDF21            @ (((unsigned) &INDF2)*8) + 1;
extern volatile __bit                   INDF22            @ (((unsigned) &INDF2)*8) + 2;
extern volatile __bit                   INDF23            @ (((unsigned) &INDF2)*8) + 3;
extern volatile __bit                   INDF24            @ (((unsigned) &INDF2)*8) + 4;
extern volatile __bit                   INDF25            @ (((unsigned) &INDF2)*8) + 5;
extern volatile __bit                   INDF26            @ (((unsigned) &INDF2)*8) + 6;
extern volatile __bit                   INDF27            @ (((unsigned) &INDF2)*8) + 7;

extern volatile __bit                   BSR0              @ (((unsigned) &BSR)*8) + 0;
extern volatile __bit                   BSR1              @ (((unsigned) &BSR)*8) + 1;
extern volatile __bit                   BSR2              @ (((unsigned) &BSR)*8) + 2;
extern volatile __bit                   BSR3              @ (((unsigned) &BSR)*8) + 3;
//extern volatile __bit                 xx                @ (((unsigned) &BSR)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &BSR)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &BSR)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &BSR)*8) + 7;

extern volatile __bit                   FSR1L0            @ (((unsigned) &FSR1L)*8) + 0;
extern volatile __bit                   FSR1L1            @ (((unsigned) &FSR1L)*8) + 1;
extern volatile __bit                   FSR1L2            @ (((unsigned) &FSR1L)*8) + 2;
extern volatile __bit                   FSR1L3            @ (((unsigned) &FSR1L)*8) + 3;
extern volatile __bit                   FSR1L4            @ (((unsigned) &FSR1L)*8) + 4;
extern volatile __bit                   FSR1L5            @ (((unsigned) &FSR1L)*8) + 5;
extern volatile __bit                   FSR1L6            @ (((unsigned) &FSR1L)*8) + 6;
extern volatile __bit                   FSR1L7            @ (((unsigned) &FSR1L)*8) + 7;

extern volatile __bit                   FSR1H0            @ (((unsigned) &FSR1H)*8) + 0;
extern volatile __bit                   FSR1H1            @ (((unsigned) &FSR1H)*8) + 1;
extern volatile __bit                   FSR1H2            @ (((unsigned) &FSR1H)*8) + 2;
extern volatile __bit                   FSR1H3            @ (((unsigned) &FSR1H)*8) + 3;
//extern volatile __bit                 xx                @ (((unsigned) &FSR1H)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &FSR1H)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &FSR1H)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &FSR1H)*8) + 7;

extern volatile __bit                   PLUSW10           @ (((unsigned) &PLUSW1)*8) + 0;
extern volatile __bit                   PLUSW11           @ (((unsigned) &PLUSW1)*8) + 1;
extern volatile __bit                   PLUSW12           @ (((unsigned) &PLUSW1)*8) + 2;
extern volatile __bit                   PLUSW13           @ (((unsigned) &PLUSW1)*8) + 3;
extern volatile __bit                   PLUSW14           @ (((unsigned) &PLUSW1)*8) + 4;
extern volatile __bit                   PLUSW15           @ (((unsigned) &PLUSW1)*8) + 5;
extern volatile __bit                   PLUSW16           @ (((unsigned) &PLUSW1)*8) + 6;
extern volatile __bit                   PLUSW17           @ (((unsigned) &PLUSW1)*8) + 7;

extern volatile __bit                   PREINC10          @ (((unsigned) &PREINC1)*8) + 0;
extern volatile __bit                   PREINC11          @ (((unsigned) &PREINC1)*8) + 1;
extern volatile __bit                   PREINC12          @ (((unsigned) &PREINC1)*8) + 2;
extern volatile __bit                   PREINC13          @ (((unsigned) &PREINC1)*8) + 3;
extern volatile __bit                   PREINC14          @ (((unsigned) &PREINC1)*8) + 4;
extern volatile __bit                   PREINC15          @ (((unsigned) &PREINC1)*8) + 5;
extern volatile __bit                   PREINC16          @ (((unsigned) &PREINC1)*8) + 6;
extern volatile __bit                   PREINC17          @ (((unsigned) &PREINC1)*8) + 7;

extern volatile __bit                   POSTDEC10         @ (((unsigned) &POSTDEC1)*8) + 0;
extern volatile __bit                   POSTDEC11         @ (((unsigned) &POSTDEC1)*8) + 1;
extern volatile __bit                   POSTDEC12         @ (((unsigned) &POSTDEC1)*8) + 2;
extern volatile __bit                   POSTDEC13         @ (((unsigned) &POSTDEC1)*8) + 3;
extern volatile __bit                   POSTDEC14         @ (((unsigned) &POSTDEC1)*8) + 4;
extern volatile __bit                   POSTDEC15         @ (((unsigned) &POSTDEC1)*8) + 5;
extern volatile __bit                   POSTDEC16         @ (((unsigned) &POSTDEC1)*8) + 6;
extern volatile __bit                   POSTDEC17         @ (((unsigned) &POSTDEC1)*8) + 7;
  
extern volatile __bit                   POSTINC10         @ (((unsigned) &POSTINC1)*8) + 0;
extern volatile __bit                   POSTINC11         @ (((unsigned) &POSTINC1)*8) + 1;
extern volatile __bit                   POSTINC12         @ (((unsigned) &POSTINC1)*8) + 2;
extern volatile __bit                   POSTINC13         @ (((unsigned) &POSTINC1)*8) + 3;
extern volatile __bit                   POSTINC14         @ (((unsigned) &POSTINC1)*8) + 4;
extern volatile __bit                   POSTINC15         @ (((unsigned) &POSTINC1)*8) + 5;
extern volatile __bit                   POSTINC16         @ (((unsigned) &POSTINC1)*8) + 6;
extern volatile __bit                   POSTINC17         @ (((unsigned) &POSTINC1)*8) + 7;

extern volatile __bit                   INDF10            @ (((unsigned) &INDF1)*8) + 0;
extern volatile __bit                   INDF11            @ (((unsigned) &INDF1)*8) + 1;
extern volatile __bit                   INDF12            @ (((unsigned) &INDF1)*8) + 2;
extern volatile __bit                   INDF13            @ (((unsigned) &INDF1)*8) + 3;
extern volatile __bit                   INDF14            @ (((unsigned) &INDF1)*8) + 4;
extern volatile __bit                   INDF15            @ (((unsigned) &INDF1)*8) + 5;
extern volatile __bit                   INDF16            @ (((unsigned) &INDF1)*8) + 6;
extern volatile __bit                   INDF17            @ (((unsigned) &INDF1)*8) + 7;

extern volatile __bit                   AREG0             @ (((unsigned) &AREG)*8) + 0;
extern volatile __bit                   AREG1             @ (((unsigned) &AREG)*8) + 1;
extern volatile __bit                   AREG2             @ (((unsigned) &AREG)*8) + 2;
extern volatile __bit                   AREG3             @ (((unsigned) &AREG)*8) + 3;
extern volatile __bit                   AREG4             @ (((unsigned) &AREG)*8) + 4;
extern volatile __bit                   AREG5             @ (((unsigned) &AREG)*8) + 5;
extern volatile __bit                   AREG6             @ (((unsigned) &AREG)*8) + 6;
extern volatile __bit                   AREG7             @ (((unsigned) &AREG)*8) + 7;

extern volatile __bit                   FSR0L0            @ (((unsigned) &FSR0L)*8) + 0;
extern volatile __bit                   FSR0L1            @ (((unsigned) &FSR0L)*8) + 1;
extern volatile __bit                   FSR0L2            @ (((unsigned) &FSR0L)*8) + 2;
extern volatile __bit                   FSR0L3            @ (((unsigned) &FSR0L)*8) + 3;
extern volatile __bit                   FSR0L4            @ (((unsigned) &FSR0L)*8) + 4;
extern volatile __bit                   FSR0L5            @ (((unsigned) &FSR0L)*8) + 5;
extern volatile __bit                   FSR0L6            @ (((unsigned) &FSR0L)*8) + 6;
extern volatile __bit                   FSR0L7            @ (((unsigned) &FSR0L)*8) + 7;

extern volatile __bit                   FSR0H0            @ (((unsigned) &FSR0H)*8) + 0;
extern volatile __bit                   FSR0H1            @ (((unsigned) &FSR0H)*8) + 1;
extern volatile __bit                   FSR0H2            @ (((unsigned) &FSR0H)*8) + 2;
extern volatile __bit                   FSR0H3            @ (((unsigned) &FSR0H)*8) + 3;
//extern volatile __bit                 xx                @ (((unsigned) &FSR0H)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &FSR0H)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &FSR0H)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &FSR0H)*8) + 7;

extern volatile __bit                   PLUSW00           @ (((unsigned) &PLUSW0)*8) + 0;
extern volatile __bit                   PLUSW01           @ (((unsigned) &PLUSW0)*8) + 1;
extern volatile __bit                   PLUSW02           @ (((unsigned) &PLUSW0)*8) + 2;
extern volatile __bit                   PLUSW03           @ (((unsigned) &PLUSW0)*8) + 3;
extern volatile __bit                   PLUSW04           @ (((unsigned) &PLUSW0)*8) + 4;
extern volatile __bit                   PLUSW05           @ (((unsigned) &PLUSW0)*8) + 5;
extern volatile __bit                   PLUSW06           @ (((unsigned) &PLUSW0)*8) + 6;
extern volatile __bit                   PLUSW07           @ (((unsigned) &PLUSW0)*8) + 7;

extern volatile __bit                   PREINC00          @ (((unsigned) &PREINC0)*8) + 0;
extern volatile __bit                   PREINC01          @ (((unsigned) &PREINC0)*8) + 1;
extern volatile __bit                   PREINC02          @ (((unsigned) &PREINC0)*8) + 2;
extern volatile __bit                   PREINC03          @ (((unsigned) &PREINC0)*8) + 3;
extern volatile __bit                   PREINC04          @ (((unsigned) &PREINC0)*8) + 4;
extern volatile __bit                   PREINC05          @ (((unsigned) &PREINC0)*8) + 5;
extern volatile __bit                   PREINC06          @ (((unsigned) &PREINC0)*8) + 6;
extern volatile __bit                   PREINC07          @ (((unsigned) &PREINC0)*8) + 7;

extern volatile __bit                   POSTDEC00         @ (((unsigned) &POSTDEC0)*8) + 0;
extern volatile __bit                   POSTDEC01         @ (((unsigned) &POSTDEC0)*8) + 1;
extern volatile __bit                   POSTDEC02         @ (((unsigned) &POSTDEC0)*8) + 2;
extern volatile __bit                   POSTDEC03         @ (((unsigned) &POSTDEC0)*8) + 3;
extern volatile __bit                   POSTDEC04         @ (((unsigned) &POSTDEC0)*8) + 4;
extern volatile __bit                   POSTDEC05         @ (((unsigned) &POSTDEC0)*8) + 5;
extern volatile __bit                   POSTDEC06         @ (((unsigned) &POSTDEC0)*8) + 6;
extern volatile __bit                   POSTDEC07         @ (((unsigned) &POSTDEC0)*8) + 7;

extern volatile __bit                   POSTINC00         @ (((unsigned) &POSTINC0)*8) + 0;
extern volatile __bit                   POSTINC01         @ (((unsigned) &POSTINC0)*8) + 1;
extern volatile __bit                   POSTINC02         @ (((unsigned) &POSTINC0)*8) + 2;
extern volatile __bit                   POSTINC03         @ (((unsigned) &POSTINC0)*8) + 3;
extern volatile __bit                   POSTINC04         @ (((unsigned) &POSTINC0)*8) + 4;
extern volatile __bit                   POSTINC05         @ (((unsigned) &POSTINC0)*8) + 5;
extern volatile __bit                   POSTINC06         @ (((unsigned) &POSTINC0)*8) + 6;
extern volatile __bit                   POSTINC07         @ (((unsigned) &POSTINC0)*8) + 7;

extern volatile __bit                   INDF00            @ (((unsigned) &INDF0)*8) + 0;
extern volatile __bit                   INDF01            @ (((unsigned) &INDF0)*8) + 1;
extern volatile __bit                   INDF02            @ (((unsigned) &INDF0)*8) + 2;
extern volatile __bit                   INDF03            @ (((unsigned) &INDF0)*8) + 3;
extern volatile __bit                   INDF04            @ (((unsigned) &INDF0)*8) + 4;
extern volatile __bit                   INDF05            @ (((unsigned) &INDF0)*8) + 5;
extern volatile __bit                   INDF06            @ (((unsigned) &INDF0)*8) + 6;
extern volatile __bit                   INDF07            @ (((unsigned) &INDF0)*8) + 7;

extern volatile __bit                   EEWE              @ (((unsigned) &EECON2)*8) + 0;
extern volatile __bit                   EELOCK1           @ (((unsigned) &EECON2)*8) + 1;
extern volatile __bit                   EELOCK2           @ (((unsigned) &EECON2)*8) + 2;
extern volatile __bit                   EELOCK3           @ (((unsigned) &EECON2)*8) + 3;
//extern volatile __bit                 xx                @ (((unsigned) &EECON2)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &EECON2)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &EECON2)*8) + 6;
extern volatile __bit                   WERR              @ (((unsigned) &EECON2)*8) + 7;

extern volatile __bit                   WRITE             @ (((unsigned) &EECON1)*8) + 0;
extern volatile __bit                   ERASE             @ (((unsigned) &EECON1)*8) + 1;
extern volatile __bit                   CLRPL             @ (((unsigned) &EECON1)*8) + 2;
extern volatile __bit                   PRGT00            @ (((unsigned) &EECON1)*8) + 3;
extern volatile __bit                   PRGT01            @ (((unsigned) &EECON1)*8) + 4;
extern volatile __bit                   PRGT02            @ (((unsigned) &EECON1)*8) + 5;
extern volatile __bit                   PRGT03            @ (((unsigned) &EECON1)*8) + 6;
extern volatile __bit                   PRGT04            @ (((unsigned) &EECON1)*8) + 7;

extern volatile __bit                   MINT00            @ (((unsigned) &OPTION)*8) + 0;
extern volatile __bit                   MINT01            @ (((unsigned) &OPTION)*8) + 1;
extern volatile __bit                   MINT10            @ (((unsigned) &OPTION)*8) + 2;
extern volatile __bit                   MINT11            @ (((unsigned) &OPTION)*8) + 3;
//extern volatile __bit                 PD                @ (((unsigned) &OPTION)*8) + 4;
//extern volatile __bit                 TO                @ (((unsigned) &OPTION)*8) + 5;
extern volatile __bit                   GIEL              @ (((unsigned) &OPTION)*8) + 6;
extern volatile __bit                   GIEH              @ (((unsigned) &OPTION)*8) + 7;

extern volatile __bit                   PRODL0            @ (((unsigned) &PRODL)*8) + 0;
extern volatile __bit                   PRODL1            @ (((unsigned) &PRODL)*8) + 1;
extern volatile __bit                   PRODL2            @ (((unsigned) &PRODL)*8) + 2;
extern volatile __bit                   PRODL3            @ (((unsigned) &PRODL)*8) + 3;
extern volatile __bit                   PRODL4            @ (((unsigned) &PRODL)*8) + 4;
extern volatile __bit                   PRODL5            @ (((unsigned) &PRODL)*8) + 5;
extern volatile __bit                   PRODL6            @ (((unsigned) &PRODL)*8) + 6;
extern volatile __bit                   PRODL7            @ (((unsigned) &PRODL)*8) + 7;

extern volatile __bit                   PRODH0            @ (((unsigned) &PRODH)*8) + 0;
extern volatile __bit                   PRODH1            @ (((unsigned) &PRODH)*8) + 1;
extern volatile __bit                   PRODH2            @ (((unsigned) &PRODH)*8) + 2;
extern volatile __bit                   PRODH3            @ (((unsigned) &PRODH)*8) + 3;
extern volatile __bit                   PRODH4            @ (((unsigned) &PRODH)*8) + 4;
extern volatile __bit                   PRODH5            @ (((unsigned) &PRODH)*8) + 5;
extern volatile __bit                   PRODH6            @ (((unsigned) &PRODH)*8) + 6;
extern volatile __bit                   PRODH7            @ (((unsigned) &PRODH)*8) + 7;

extern volatile __bit                   TABLAT00          @ (((unsigned) &TABLAT)*8) + 0;
extern volatile __bit                   TABLAT11          @ (((unsigned) &TABLAT)*8) + 1;
extern volatile __bit                   TABLAT22          @ (((unsigned) &TABLAT)*8) + 2;
extern volatile __bit                   TABLAT33          @ (((unsigned) &TABLAT)*8) + 3;
extern volatile __bit                   TABLAT44          @ (((unsigned) &TABLAT)*8) + 4;
extern volatile __bit                   TABLAT55          @ (((unsigned) &TABLAT)*8) + 5;
extern volatile __bit                   TABLAT66          @ (((unsigned) &TABLAT)*8) + 6;
extern volatile __bit                   TABLAT77          @ (((unsigned) &TABLAT)*8) + 7;

extern volatile __bit                   TBLPTRL0          @ (((unsigned) &TBLPTRL)*8) + 0;
extern volatile __bit                   TBLPTRL1          @ (((unsigned) &TBLPTRL)*8) + 1;
extern volatile __bit                   TBLPTRL2          @ (((unsigned) &TBLPTRL)*8) + 2;
extern volatile __bit                   TBLPTRL3          @ (((unsigned) &TBLPTRL)*8) + 3;
extern volatile __bit                   TBLPTRL4          @ (((unsigned) &TBLPTRL)*8) + 4;
extern volatile __bit                   TBLPTRL5          @ (((unsigned) &TBLPTRL)*8) + 5;
extern volatile __bit                   TBLPTRL6          @ (((unsigned) &TBLPTRL)*8) + 6;
extern volatile __bit                   TBLPTRL7          @ (((unsigned) &TBLPTRL)*8) + 7;

extern volatile __bit                   TBLPTRH0          @ (((unsigned) &TBLPTRH)*8) + 0;
extern volatile __bit                   TBLPTRH1          @ (((unsigned) &TBLPTRH)*8) + 1;
extern volatile __bit                   TBLPTRH2          @ (((unsigned) &TBLPTRH)*8) + 2;
extern volatile __bit                   TBLPTRH3          @ (((unsigned) &TBLPTRH)*8) + 3;
extern volatile __bit                   TBLPTRH4          @ (((unsigned) &TBLPTRH)*8) + 4;
extern volatile __bit                   TBLPTRH5          @ (((unsigned) &TBLPTRH)*8) + 5;
extern volatile __bit                   TBLPTRH6          @ (((unsigned) &TBLPTRH)*8) + 6;
extern volatile __bit                   TBLPTRH7          @ (((unsigned) &TBLPTRH)*8) + 7;

extern volatile __bit                   PCL0              @ (((unsigned) &PCL)*8) + 0;
extern volatile __bit                   PCL1              @ (((unsigned) &PCL)*8) + 1;
extern volatile __bit                   PCL2              @ (((unsigned) &PCL)*8) + 2;
extern volatile __bit                   PCL3              @ (((unsigned) &PCL)*8) + 3;
extern volatile __bit                   PCL4              @ (((unsigned) &PCL)*8) + 4;
extern volatile __bit                   PCL5              @ (((unsigned) &PCL)*8) + 5;
extern volatile __bit                   PCL6              @ (((unsigned) &PCL)*8) + 6;
extern volatile __bit                   PCL7              @ (((unsigned) &PCL)*8) + 7;

extern volatile __bit                   PCLATH0           @ (((unsigned) &PCLATH)*8) + 0;
extern volatile __bit                   PCLATH1           @ (((unsigned) &PCLATH)*8) + 1;
extern volatile __bit                   PCLATH2           @ (((unsigned) &PCLATH)*8) + 2;
extern volatile __bit                   PCLATH3           @ (((unsigned) &PCLATH)*8) + 3;
extern volatile __bit                   PCLATH4           @ (((unsigned) &PCLATH)*8) + 4;
extern volatile __bit                   PCLATH5           @ (((unsigned) &PCLATH)*8) + 5;
extern volatile __bit                   PCLATH6           @ (((unsigned) &PCLATH)*8) + 6;
extern volatile __bit                   PCLATH7           @ (((unsigned) &PCLATH)*8) + 7;

extern volatile __bit                   STKPTR0           @ (((unsigned) &STKPTR)*8) + 0;
extern volatile __bit                   STKPTR1           @ (((unsigned) &STKPTR)*8) + 1;
extern volatile __bit                   STKPTR2           @ (((unsigned) &STKPTR)*8) + 2;
extern volatile __bit                   STKPTR3           @ (((unsigned) &STKPTR)*8) + 3;
extern volatile __bit                   STKPTR4           @ (((unsigned) &STKPTR)*8) + 4;
//extern volatile __bit                 xx                @ (((unsigned) &STKPTR)*8) + 5;
extern volatile __bit                   STKDOV            @ (((unsigned) &STKPTR)*8) + 6;
extern volatile __bit                   STKUOV            @ (((unsigned) &STKPTR)*8) + 7;

extern volatile __bit                   TOSL0             @ (((unsigned) &TOSL)*8) + 0;
extern volatile __bit                   TOSL1             @ (((unsigned) &TOSL)*8) + 1;
extern volatile __bit                   TOSL2             @ (((unsigned) &TOSL)*8) + 2;
extern volatile __bit                   TOSL3             @ (((unsigned) &TOSL)*8) + 3;
extern volatile __bit                   TOSL4             @ (((unsigned) &TOSL)*8) + 4;
extern volatile __bit                   TOSL5             @ (((unsigned) &TOSL)*8) + 5;
extern volatile __bit                   TOSL6             @ (((unsigned) &TOSL)*8) + 6;
extern volatile __bit                   TOSL7             @ (((unsigned) &TOSL)*8) + 7;

extern volatile __bit                   TOSH0             @ (((unsigned) &TOSH)*8) + 0;
extern volatile __bit                   TOSH1             @ (((unsigned) &TOSH)*8) + 1;
extern volatile __bit                   TOSH2             @ (((unsigned) &TOSH)*8) + 2;
extern volatile __bit                   TOSH3             @ (((unsigned) &TOSH)*8) + 3;
extern volatile __bit                   TOSH4             @ (((unsigned) &TOSH)*8) + 4;
extern volatile __bit                   TOSH5             @ (((unsigned) &TOSH)*8) + 5;
//extern volatile __bit                 xx                @ (((unsigned) &TOSH)*8) + 6;
//extern volatile __bit                 xx                @ (((unsigned) &TOSH)*8) + 7;


#endif 
