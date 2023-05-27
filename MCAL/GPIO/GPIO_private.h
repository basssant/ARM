/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		07 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  07 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


typedef struct GPIO_priv
{
    /* Registers As Members */
    volatile u32 MODER;     /*port mode register*/
    volatile u32 OTYPER;    /*GPIO port output type register*/
    volatile u32 OSPEEDR;   /*GPIO port output speed register*/
    volatile u32 PUPDR;     /*GPIO port pull-up/pull-down register*/
    volatile u32 IDR;       /*GPIO port input data register*/
    volatile u32 ODR;       /*GPIO port output data register*/
    volatile u32 BSRR;      /*GPIO port bit set/reset register*/
    volatile u32 LCKR;      /*GPIO port configuration lock register*/
    volatile u32 AFRL;      /*GPIO alternate function low register*/
    volatile u32 AFRH;      /*GPIO alternate function high register*/
}GPIO_t;

#define GPIOA ((volatile GPIO_t*)0x40020000)
#define GPIOB ((volatile GPIO_t*)0x40020400)
#define GPIOC ((volatile GPIO_t*)0x40020800)

/***************************************************************************************************
 **********************                         BITS                       *************************
 ***************************************************************************************************/
#define     BIT_0           0 
#define     BIT_1           1

#define     BIT_2           2
#define     BIT_3           3

#define     BIT_4           4 
#define     BIT_5           5

#define     BIT_6           6 
#define     BIT_7           7

#define     BIT_8           8 
#define     BIT_9           9

#define     BIT_10          10 
#define     BIT_11          11

#define     BIT6_12         12
#define     BIT6_13         13

#define     BIT7_14         14
#define     BIT7_15         15

#define     BIT8_16         16 
#define     BIT8_17         17

#define     BIT9_18         18 
#define     BIT9_19         19

#define     BIT10_20        20 
#define     BIT10_21        21

#define     BIT11_22        22 
#define     BIT11_23        23

#define     BIT12_24        24 
#define     BIT12_25        25

#define     BIT13_26        26 
#define     BIT13_27        27

#define     BIT14_28        28
#define     BIT14_29        29

#define     BIT15_30        30
#define     BIT15_31        31

#endif