#include "StdTypes.h"
#include "BitMath.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "systick_interface.h"

#include "SevenSegment_interface.h"

int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOA);
	MRCC_voidEnablePeripheralClk(RCC_AHB1, RCC_GPIOB);

	Systick_voidInit();

	SEVEN_SEGMENT_t tens;
	SEVEN_SEGMENT_t units;

	tens.SEVEN_SEGMENT_PORT= GPIOB_PORT;
	units.SEVEN_SEGMENT_PORT= GPIOA_PORT;

	SevenSegment_voidInitialize(&tens);
	SevenSegment_voidInitialize(&units);


	while (1)
	{

		SevenSegment_voidPrintElement(&tens, tens.SEVEN_SEGMENT_ARRAY[ZERO]);
		for(u8 local_u8_Iterator = ZERO; local_u8_Iterator<=NINE; local_u8_Iterator++)
		{

			SevenSegment_voidPrintElement(&units, units.SEVEN_SEGMENT_ARRAY[local_u8_Iterator]);
			Systick_voidBusyWait(1000000);
		}
		SevenSegment_voidPrintElement(&tens, tens.SEVEN_SEGMENT_ARRAY[ONE]);
		SevenSegment_voidPrintElement(&units, units.SEVEN_SEGMENT_ARRAY[ZERO]);
		Systick_voidBusyWait(1000000);
	}
}
