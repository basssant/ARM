/*********************************************
 * Author:				Bassant Abd El-Moniem
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 May, 2023	Bassant Abd El-Moniem		  Initial Creation
*********************************************/
#include "StdTypes.h"
#include "BitMath.h"

#include "systick_interface.h"
#include "systick_private.h"
#include "systick_config.h"

void Systick_voidInit(void)
{
    #if     SYSTICK_ENABLE == DISABLE
        
            CLR_BIT(systick -> STK_CTRL,0);

    #elif   SYSTICK_ENABLE == ENABLE
            SET_BIT(systick->STK_CTRL,0);
    #else
    #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif        
            
    #if     SYSTICK_CLOCK_SOURCE  == AHB
        SET_BIT(systick -> STK_CTRL,2);
    
    #elif SYSTICK_CLOCK_SOURCE  == AHB_8
        CLR_BIT(systick -> STK_CTRL,2);
    #else
        #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif

    #if     SYSTICK_INTERRUPT_ENABLE == ENABLE
        SET_BIT(systick -> STK_CTRL,1);
    #elif     SYSTICK_INTERRUPT_ENABLE == DISABLE
        CLR_BIT(systick -> STK_CTRL,1);
    #else
        #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif
}

void Systick_voidBusyWait(u32 Copy_u32Value)
{
    systick -> STK_LOAD = Copy_u32Value;
    while((READ_BIT(systick -> STK_CTRL,16)) == 0);
    systick -> STK_VAL = 0;
}
