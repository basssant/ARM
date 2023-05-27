/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		07 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  07 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

typedef enum {
    GPIOA_PORT,
    GPIOB_PORT,
    GPIOC_PORT
}GPIO_NUM_t;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
    PIN16
}PIN_NUM_t;

typedef enum {
    INPUT =0,                          /*Input (reset state)*/
    OUTPUT=1,                          /*General purpose output mode*/
    ALTERNATIVE_FUNCTION,              /*Alternate function mode*/
    ANALOG                            /*Analog mode*/
}PIN_MODE_t;

typedef enum {
    OUTPUT_PUSH_PULL,
    OUTPUT_OPEN_DRAIN
}OUTPUT_TYPE_t;

typedef enum {
    LOW_SPEED_2MHZ,
    MEDIUM_SPEED_UP_TO_10MHZ,
    HIGH_SPEED_UP_TO_50MHZ,
    VERY_HIGH_SPEED_UP_TO_100MHZ
}OUTPUT_SPEED_t;

typedef enum {
    NO_PULL_UP_NO_PULL_DOWN,
    PULL_UP,
    PULL_DOWN
}OUTPUT_MODE_t;



#define LOW         0
#define HIGH        1

void MGPIO_voidSetPinMode(GPIO_NUM_t GPIO_N , PIN_NUM_t PIN_NUMBER , PIN_MODE_t PinMode);
void MGPIO_voidSetPinOutputType(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_TYPE_t Output_Type);
void MGPIO_voidSetPinOutputSpeed(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_SPEED_t Output_Speed);
void MGPIO_voidSetPinOutputMode(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , OUTPUT_MODE_t Mode);
void MGPIO_voidReadInputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value);    //Read IDR)
void MGPIO_voidReadOutputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value);   //Read ORD
void MGPIO_voidSetOutpinValue(GPIO_NUM_t GPIO_N,  PIN_NUM_t PIN_NUMBER , u8 Copy_u8PinValue);
void MGPIO_voidSetOutputPortValue(GPIO_NUM_t GPIO_N, u16 Copy_u16PortValue);
void MGPIO_voidSetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER);    //BSRR
void MGPIO_voidResetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER);

#endif