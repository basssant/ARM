/*********************************************
 * Author:				Bassant Abd El-Moniem
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



void Systick_voidInit(void);
void Systick_voidEnableSystick(u8 Copy_u8PeripheralBus);
void Systick_voidEnableSystickinterrupt(u8 Copy_u8PeripheralBus);
void Systick_voidBusyWait(u32 Copy_u32Value);
void Systick_voidSetClockSource(u8 Copy_u8ClockSource);
void Systick_voidDisableSysTick(void);
void Systick_voidDisableInterrupt(void);
u32 Systick_u32GetElapsedTime(void);
u32 Systick_u32GetRemainingTime(void);
void Systick_voidSetPreLoadValue(u32 Copy_u8LoadValue);
void Systick_voidResetSysTick(void);
void Systick_voidSetSingleInterval(u32 Copy_u32Ticks , void (*NotificationFunction)(void));
void Systick_voidSetPeriodicInterval(u32 Copy_u32Ticks , void (*NotificationFunction)(void));


#endif
