/*******************************************************************************
* Copyright (c) 2013, SHENZHEN SEMITEK Co.,LTD.
* All rights reserved.
*
* 文件名称: types.h
*
* 功能说明: 
* 修改说明:
*******************************************************************************/
#ifndef __TYPES_H
#define __TYPES_H

//=============================================================================;
// 配置引用区                                                                  ;
//=============================================================================;

//-----------------------------------------------------------------------------;
//配置常量定义区
//
#define  ON                     1
#define  OFF                    0

typedef union
{
	struct 
	{    
        unsigned char b0 : 1; 
        unsigned char b1 : 1; 
        unsigned char b2 : 1; 
        unsigned char b3 : 1;
        unsigned char b4 : 1; 
        unsigned char b5 : 1;
        unsigned char b6 : 1; 
        unsigned char b7 : 1;
    }BIT;   
    unsigned char u8;
}USBD_U8; //可位操作，也可字节操作

typedef union
{
	struct 
	{
        unsigned int b0 : 1; 
        unsigned int b1 : 1; 
        unsigned int b2 : 1; 
        unsigned int b3 : 1;
        unsigned int b4 : 1; 
        unsigned int b5 : 1;
        unsigned int b6 : 1; 
        unsigned int b7 : 1;
        unsigned int b8 : 1; 
        unsigned int b9 : 1; 
        unsigned int b10 : 1; 
        unsigned int b11 : 1;
        unsigned int b12 : 1; 
        unsigned int b13 : 1;
        unsigned int b14 : 1; 
        unsigned int b15 : 1;
    }BIT;   
    unsigned int u16;
}USBD_U16; //可位操作，也可字节操作

#endif /* __TYPES_H */
