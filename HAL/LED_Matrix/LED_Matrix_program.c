/*********************************************
 * Author:				Bassant Abd El-Moniem
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 May, 2023	Bassant Abd El-Moniem		  Initial Creation
*********************************************/
#include "StdTypes.h"
#include "BitMath.h"

#include "GPIO_interface.h"
#include "systick_interface.h"

#include "LED_Matrix_interface.h"
#include "LED_Matrix_private.h"
#include "LED_Matrix_config.h"

void LED_Matrix_voidInit()
{
    //initialize column port
    for(PIN_NUM_t local_PIN_NUM_T_Iterator = PIN0; local_PIN_NUM_T_Iterator<PIN8; local_PIN_NUM_T_Iterator++)
    {
        MGPIO_voidSetPinMode(COLUMN_PORT  , local_PIN_NUM_T_Iterator , OUTPUT);
		MGPIO_voidSetPinOutputType(COLUMN_PORT ,local_PIN_NUM_T_Iterator ,OUTPUT_PUSH_PULL);
		MGPIO_voidSetPinOutputSpeed(COLUMN_PORT  , local_PIN_NUM_T_Iterator ,LOW_SPEED_2MHZ);
    }
    //initialize row port
    for(PIN_NUM_t local_PIN_NUM_T_Iterator = PIN0; local_PIN_NUM_T_Iterator<PIN8; local_PIN_NUM_T_Iterator++)
    {
        MGPIO_voidSetPinMode(ROW_PORT  , local_PIN_NUM_T_Iterator , OUTPUT);
		MGPIO_voidSetPinOutputType(ROW_PORT ,local_PIN_NUM_T_Iterator ,OUTPUT_PUSH_PULL);
		MGPIO_voidSetPinOutputSpeed(ROW_PORT  , local_PIN_NUM_T_Iterator ,LOW_SPEED_2MHZ);
    }
}

void LED_Matrix_voidDisplay(u8 * RowArray)
{
    for(PIN_NUM_t col = PIN0; col<PIN8; col++)
    {
        MGPIO_voidSetOutputPortValue(COLUMN_PORT  , 0xFF);//disable all columns
        for(u8 Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++ )
        {
           MGPIO_voidSetOutputPortValue(ROW_PORT  , RowArray[Local_u8Iterator]);//Row values 
        }
        MGPIO_voidSetOutpinValue(ROW_PORT,  col , LOW);//enable column
        Systick_voidBusyWait(5000);//delay for each column
    }
}