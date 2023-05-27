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


#endif