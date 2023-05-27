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

static void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = 0;

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
void Systick_voidEnableSystick(u8 Copy_u8PeripheralBus)
{
    SET_BIT(systick->STK_CTRL,0);
}

void Systick_voidEnableSystickinterrupt(u8 Copy_u8PeripheralBus)
{
     SET_BIT(systick -> STK_CTRL,1);
}
void Systick_voidBusyWait(u32 Copy_u32Value)
{
    systick -> STK_LOAD = Copy_u32Value;
    while((READ_BIT(systick -> STK_CTRL,16)) == 0);
    systick -> STK_VAL = 0;
}
void Systick_voidSetClockSource(u8 Copy_u8ClockSource)
{
    if(Copy_u8ClockSource == AHB)SET_BIT(systick -> STK_CTRL,2);
    else if(Copy_u8ClockSource == AHB_8)CLR_BIT(systick -> STK_CTRL,2);
}
void Systick_voidDisableSysTick(void)
{
    CLR_BIT(systick -> STK_CTRL,0);
}

void Systick_voidDisableInterrupt(void)
{
    CLR_BIT(systick -> STK_CTRL,1);
}
u32 Systick_u32GetElapsedTime(void)
{
    return ((systick ->STK_LOAD )- (systick ->STK_VAL));
}
u32 Systick_u32GetRemainingTime(void)
{
    return (systick ->STK_VAL);
}
void Systick_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
    (systick ->STK_LOAD ) = Copy_u8LoadValue;
}
void Systick_voidResetSysTick(void)
{
    (systick ->STK_VAL) = 0;
}
void Systick_voidSetSingleInterval(u32 Copy_u32Ticks , void (*NotificationFunction)(void))
{
	/*Disable STK*/
	CLR_BIT(systick ->STK_CTRL, 0);
	/*Reset STK*/
	systick ->STK_VAL = 0;
	systick->STK_LOAD = Copy_u32Ticks;

    pvCallBackFunction = NotificationFunction;
    u8IntervalFlag = 0;
    /*Enable STK Interrupt*/
	SET_BIT(systick -> STK_CTRL ,1);
	/*Enable STK*/
	SET_BIT(systick -> STK_CTRL ,0);
}
void Systick_voidSetPeriodicInterval(u32 Copy_u32Ticks , void (*NotificationFunction)(void))
{
	systick->STK_LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
    u8IntervalFlag = 1;
    /*Enable STK Interrupt*/
	SET_BIT(systick -> STK_CTRL ,1);
	/*Enable STK*/
	SET_BIT(systick -> STK_CTRL ,0);   
}

void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == 0)
	{
		(systick ->STK_LOAD )= 0;
		(systick ->STK_VAL) = 0;
		CLR_BIT(systick -> STK_CTRL, 0);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = READ_BIT(systick -> STK_CTRL, 16);
}
