#include "StdTypes.h"
#include "BitMath.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "MNVIC_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"
#include "systick_interface.h"


void main(void)
{
#if 0
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);

	MGPIO_voidSetPinMode(GPIOA_PORT,PIN0,INPUT);
	MGPIO_voidSetPinOutputMode(GPIOA_PORT,PIN0,PULL_UP);

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	EXTI_voidChangeSEnseMode(MEXTI_LINE0,EXTI_FALLING_EDGE);
	EXTI_voidSetCallBack(MEXTI_LINE0,&Toggle_LED);
	EXTI_voidEnableInterrupt(MEXTI_LINE0);
#endif
		/*RCC Init*/
		MRCC_voidInit();
		MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);

		/*Configure PA0*/
	    MGPIO_voidSetPinMode(GPIOA_PORT , PIN0 , INPUT);
	    MGPIO_voidSetPinOutputType(GPIOA_PORT , PIN0 , PULL_UP);


		/*Configure PA1*/
		MGPIO_voidSetPinMode(GPIOA_PORT , PIN1 , OUTPUT);
		/*Configure PA2*/
		MGPIO_voidSetPinMode(GPIOA_PORT , PIN2 , OUTPUT);
		/*Configure PA3*/
		MGPIO_voidSetPinMode(GPIOA_PORT , PIN3 , OUTPUT);


		/*Init STK*/
		/*On But not counting cuz load = 0 */
		Systick_voidInit();

		MNVIC_voidInit();
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

		/*Falling*/
		EXTI_voidChangeSEnseMode(MEXTI_LINE0,EXTI_FALLING_EDGE);
		/*Pass The Function*/
		EXTI_voidSetCallBack(MEXTI_LINE0 , &HIR_voidGetFrame);
		/*Enable Interrupt*/
		EXTI_voidEnableInterrupt(MEXTI_LINE0);
	while(1)
	{
		HIR_voidPlay();
	}
}



