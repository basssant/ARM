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

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*pvCallBack[16])(void) = {{NULL}};

void EXTI_voidInit(void)
{

}
void EXTI_voidEnableInterrupt(u8 copy_u8EXTILine)
{
    //if(copy_u8EXTILine < 16)
    //{
        SET_BIT(EXTI->IMR, copy_u8EXTILine);
    //}
}
void EXTI_voidDisableInterrupt(u8 copy_u8EXTILine)
{
}
void EXTI_voidChangeSEnseMode(u8 copy_u8EXTILine, u8 copy_u8SenseSignal)
{
    
    switch(copy_u8SenseSignal)
    {
        case EXTI_RISING_EDGE:
            CLR_BIT(EXTI ->FTSR, copy_u8EXTILine);
            SET_BIT(EXTI ->RTSR, copy_u8EXTILine);
            break;
        case EXTI_FALLING_EDGE:
            SET_BIT(EXTI ->FTSR, copy_u8EXTILine);
            CLR_BIT(EXTI ->RTSR, copy_u8EXTILine);        
            break;
        case EXTI_ON_CHANGE:
            SET_BIT(EXTI ->FTSR, copy_u8EXTILine);
            SET_BIT(EXTI ->RTSR, copy_u8EXTILine);           
            break;
    }
}
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*pvNotficationFunction)(void))
{
    //if(copy_u8EXTILine < 16)
    pvCallBack[copy_u8EXTILine] = pvNotficationFunction;
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[0] != NULL)
    {
        pvCallBack[0]();
    }
    SET_BIT(EXTI ->PR, 0);
}
