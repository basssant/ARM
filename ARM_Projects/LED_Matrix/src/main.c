#include "StdTypes.h"
#include "BitMath.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "systick_interface.h"

#include "LED_Matrix_interface.h"

int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOB);

	Systick_voidInit();

	LED_Matrix_voidInit();

	u8 B[8] = {0, 0, 254, 146, 146, 108, 0, 0};


	while (1)
	{

		LED_Matrix_voidDisplay(B);

	}
}
