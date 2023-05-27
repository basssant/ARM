#include "StdTypes.h"
#include "BitMath.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "systick_interface.h"

int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);

	MGPIO_voidSetPinMode(GPIOA_PORT,PIN0,OUTPUT);
	MGPIO_voidSetPinOutputType(GPIOA_PORT,PIN0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinOutputSpeed(GPIOA_PORT, PIN0,LOW_SPEED_2MHZ);

	Systick_voidInit();

	while (1)
	{
		MGPIO_voidSetOutpinValue(GPIOA_PORT, PIN0, HIGH);
		Systick_voidBusyWait(1000000);
		MGPIO_voidSetOutpinValue(GPIOA_PORT, PIN0, LOW);
		Systick_voidBusyWait(1000000);
	}
}
