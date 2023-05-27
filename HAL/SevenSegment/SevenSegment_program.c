#include "../../LIB/StdTypes.h"
#include "../../LIB/BitMath.h"

#include "GPIO_interface.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_config.h"
#include "SevenSegment_private.h"

void SevenSegment_voidInitialize(SEVEN_SEGMENT_t* SevenSegmentObj)
{
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[ZERO] = SevenSegment_Zero;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[ONE] = SevenSegment_One;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[TWO] = SevenSegment_Two;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[THREE] = SevenSegment_Three;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[FOUR] = SevenSegment_Four;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[FIVE] = SevenSegment_Five;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[SIX] = SevenSegment_Six;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[SEVEN] = SevenSegment_Seven;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[EIGHT] = SevenSegment_Eight;
    SevenSegmentObj-> SEVEN_SEGMENT_ARRAY[NINE] = SevenSegment_Nine;

    for(PIN_NUM_t local_PIN_NUM_T_Iterator = PIN0; local_PIN_NUM_T_Iterator<PIN8; local_PIN_NUM_T_Iterator++)
	{
		MGPIO_voidSetPinMode(SevenSegmentObj ->SEVEN_SEGMENT_PORT , local_PIN_NUM_T_Iterator , OUTPUT);
		MGPIO_voidSetPinOutputType(SevenSegmentObj ->SEVEN_SEGMENT_PORT ,local_PIN_NUM_T_Iterator ,OUTPUT_PUSH_PULL);
		MGPIO_voidSetPinOutputSpeed(SevenSegmentObj ->SEVEN_SEGMENT_PORT , local_PIN_NUM_T_Iterator ,LOW_SPEED_2MHZ);
	}
}
void SevenSegment_voidPrintElement(SEVEN_SEGMENT_t* SevenSegmentObj, u8 copy_u8Element)
{
    MGPIO_voidSetOutputPortValue(SevenSegmentObj ->SEVEN_SEGMENT_PORT , (u16)copy_u8Element);
}
