/********************************************************
 * Author:          Bassant Abd El-Moniem
 * Creation Date:   2 MAY 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 * ******************************************************/
#include "BitMath.h"
#include "StdTypes.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
   // enable the choosed clock source
    #if CPU_CLK_SOURCE == HSI
        SET_BIT(RCC -> CR, 0); //ENABLE HSI BY SETTING HSION BIT
        //CHOOSE HSI AS SOFTWARE CLOCK
        CLR_BIT(RCC -> CFGR, 0);
        CLR_BIT(RCC -> CFGR, 1);
        while (READ_BIT(RCC ->CR , 1) ==0 ); /*Busy wait until HSI to be Stable AND HSIRDY = 0*/


    #elif CPU_CLK_SOURCE == HSE
        SET_BIT(RCC -> CR, 16); // ENABLE HSE BY SETTING HSEON BIT
        //CHOOSE HSI AS SOFTWARE CLOCK
        SET_BIT(RCC -> CR, 19);
        SET_BIT(RCC -> CFGR, 0);
        CLR_BIT(RCC -> CFGR, 1);
        while (GET_BIT(RCC ->CR , 17) ==0 ); /*Busy wait until HSE to be Stable AND HSERDY = 0*/


    #elif CPU_CLK_SOURCE == PLL
        SET_BIT(RCC -> CR, 24); // PPLON BIT IS SET TOENABLE PLL
        SET_BIT(RCC -> CR, 26); // PLL2SON BIT IS SET
        /*Select PLL as system CLK (CPU Clock)*/
        CLR_BIT(RCC ->CFGR,0);
        SET_BIT(RCC ->CFGR,1);


        #if PLL_SOURCE == HSI
            SET_BIT(RCC -> CR, 0); //ENABLE HSI BY SETTING HSION BIT
            while (GET_BIT(RCC ->CR , 1) ==0 ); /*Busy wait until HSI to be Stable AND HSIRDY = 0*/
            CLR_BIT(RCC -> PLLCFGR, 22); //PLLSRC IS 0 TO ENABLE HSI AS INPUT TP PLL


        #elif PLL_SOURCE == HSE
            SET_BIT(RCC -> CR, 16); // ENABLE HSE BY SETTING HSEON BIT
            while (GET_BIT(RCC ->CR , 17) ==0 ); /*Busy wait until HSE to be Stable AND HSERDY = 0*/
            SET_BIT(RCC -> PLLCFGR, 22); //PLLSRC IS 1 TO ENABLE HSE AS INPUT TP PLL


        #else
         #error "RCC PLL_SOURCE Configuration error"
        #endif 
    #else
        #error "RCC CPU_SOURCE Configuration error"

    #endif 

    // choose prescaler FOR AHB
    (RCC -> CFGR) &= AHB_PRESCALER_MASK;
    (RCC -> CFGR) |= AHB_PRESCALER;

    //CHOOSE PRESCALER FOR APB1
    (RCC -> CFGR) &= APB1_PRESCALER_MASK;
    (RCC -> CFGR) |= APB1_PRESCALER;

    //CHOOSE PRESCALER FOR APB1
    (RCC -> CFGR) &= APB2_PRESCALER_MASK;
    (RCC -> CFGR) |= APB2_PRESCALER;
}



void MRCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1/* constant-expression */:
        SET_BIT(RCC -> AHB1ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_APB1/* constant-expression */:
        SET_BIT(RCC -> APB1ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_AHB2/* constant-expression */:
        SET_BIT(RCC -> AHB2ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_APB2/* constant-expression */:
       SET_BIT(RCC -> APB2ENR, Copy_u8PeripheralID);
        break;
    
    default:
        break;
    }

}
void MRCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1/* constant-expression */:
        CLR_BIT(RCC -> AHB1ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_APB1/* constant-expression */:
        CLR_BIT(RCC -> APB1ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_AHB2/* constant-expression */:
        CLR_BIT(RCC -> AHB2ENR, Copy_u8PeripheralID);
        break;
    
    case RCC_APB2/* constant-expression */:
       CLR_BIT(RCC -> APB2ENR, Copy_u8PeripheralID);
        break;
    
    default:
        break;
    } 
}
