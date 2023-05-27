
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



void Systick_voidInit(void);
void Systick_voidEnableSystick(u8 Copy_u8PeripheralBus);
void Systick_voidEnableSystickinterrupt(u8 Copy_u8PeripheralBus);
void Systick_voidBusyWait(u32 Copy_u32Value);


#endif
