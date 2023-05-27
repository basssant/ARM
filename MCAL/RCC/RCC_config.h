#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*
    OPTIONS : 
        HSI
        HSE
        PLL
*/
#define CPU_CLK_SOURCE              HSI

/*
    OPTIONS : 
        HSI
        HSE
*/
#define PLL_SOURCE                  HSE

/*
    options : 
        AHB_NO_PRESCALER 
        AHB_PRESCALER_2  
        AHB_PRESCALER_4  
        AHB_PRESCALER_8  
        AHB_PRESCALER_16 
        AHB_PRESCALER_64 
        AHB_PRESCALER_128
        AHB_PRESCALER_256
        AHB_PRESCALER_512    
  
*/
#define AHB_PRESCALER               AHB_PRESCALER_2

/*
    options : 
        AHB_clock_not_divided  
        AHB_clock_divided_by_2 
        AHB_clock_divided_by_4 
        AHB_clock_divided_by_8 
        AHB_clock_divided_by_16
*/
#define APB1_PRESCALER              AHB_clock_divided_by_2

/*
    options : 
        APB1_NO_PRESCALER
        APB1_PRESCALER_2 
        APB1_PRESCALER_4 
        APB1_PRESCALER_8 
        APB1_PRESCALER_16
*/
#define APB2_PRESCALER              APB1_PRESCALER_2

#endif