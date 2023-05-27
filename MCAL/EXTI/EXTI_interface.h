#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_RISING_EDGE                0
#define EXTI_FALLING_EDGE               1
#define EXTI_ON_CHANGE                  2

void EXTI_voidInit(void);
void EXTI_voidEnableInterrupt(u8 copy_u8EXTILine);
void EXTI_voidDisableInterrupt(u8 copy_u8EXTILine);
void EXTI_voidChangeSEnseMode(u8 copy_u8EXTILine, u8 copy_u8SenseSignal);
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*pvNotficationFunction)(void));


#endif