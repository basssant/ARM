#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_RISING_EDGE                0
#define EXTI_FALLING_EDGE               1
#define EXTI_ON_CHANGE                  2

#define 	MEXTI_LINE0				0
#define 	MEXTI_LINE1				1
#define 	MEXTI_LINE2				2
#define 	MEXTI_LINE3				3
#define 	MEXTI_LINE4				4
#define 	MEXTI_LINE5				5
#define 	MEXTI_LINE6				6
#define 	MEXTI_LINE7				7

void EXTI_voidInit(void);
void EXTI_voidEnableInterrupt(u8 copy_u8EXTILine);
void EXTI_voidDisableInterrupt(u8 copy_u8EXTILine);
void EXTI_voidChangeSEnseMode(u8 copy_u8EXTILine, u8 copy_u8SenseSignal);
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*pvNotficationFunction)(void));


#endif
