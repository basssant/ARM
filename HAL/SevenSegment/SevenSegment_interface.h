#ifndef SEVEN_SEGMENT_INTERFACE_H 
#define SEVEN_SEGMENT_INTERFACE_H 

#define SevenSegment_Zero                0x3F
#define SevenSegment_One                 0x06   
#define SevenSegment_Two                 0x5B   
#define SevenSegment_Three               0x4F
#define SevenSegment_Four                0x66
#define SevenSegment_Five                0x6D
#define SevenSegment_Six                 0x7D
#define SevenSegment_Seven               0x07
#define SevenSegment_Eight               0x7F
#define SevenSegment_Nine                0x67

#define ZERO							0
#define ONE								1
#define TWO								2
#define THREE							3
#define FOUR							4
#define FIVE							5
#define SIX								6
#define SEVEN							7
#define EIGHT							8
#define NINE							9

#define SevenSegmentArraySize			10

#define SevenSegment_OutPutDirection     0xFF

#define Seven_Segment_Array             {SevenSegment_Zero, SevenSegment_One, SevenSegment_Two, SevenSegment_Three, SevenSegment_Four, SevenSegment_Five, SevenSegment_Six, SevenSegment_Seven, SevenSegment_Eight, SevenSegment_Nine }

typedef struct 
{
    GPIO_NUM_T SEVEN_SEGMENT_PORT;
    u8 SEVEN_SEGMENT_ARRAY [SevenSegmentArraySize];
}SEVEN_SEGMENT_t;

void SevenSegment_voidInitialize(SEVEN_SEGMENT_t* SevenSegmentObj);
void SevenSegment_voidPrintElement(SEVEN_SEGMENT_t* SevenSegmentObj, u8 copy_u8Element);

#endif
