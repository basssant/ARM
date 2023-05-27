/*********************************************
 * Author:				Bassant Abd El-Moniem
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
#ifndef systick_PRIVATE_H
#define systick_PRIVATE_H




typedef struct
{
    volatile u32 STK_CTRL;
    volatile u32 STK_LOAD;
    volatile u32 STK_VAL;
    volatile u32 STK_CALIB;

}systick_t;


#define     systick         ((volatile systick_t *)0xE000E010)

#define     AHB                      0
#define     AHB_8                    1

#define     ENABLE                   1
#define     DISABLE                  0



#endif
