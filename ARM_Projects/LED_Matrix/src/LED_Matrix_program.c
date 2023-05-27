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
    }
    //initialize row port
    for(PIN_NUM_t local_PIN_NUM_T_Iterator = PIN0; local_PIN_NUM_T_Iterator<PIN8; local_PIN_NUM_T_Iterator++)
    {
        MGPIO_voidSetPinMode(ROW_PORT  , local_PIN_NUM_T_Iterator , OUTPUT);
    }
    MGPIO_voidSetOutputPortValue(COLUMN_PORT  , 0xFF);//disable all columns
}

void LED_Matrix_voidDisplay(u8 * RowArray)
{
    u8 Local_u8Bit;
	for(PIN_NUM_t col = PIN0; col<PIN8; col++)
    {
        MGPIO_voidSetOutputPortValue(COLUMN_PORT  , 0xFF);//disable all columns
        for(u8 Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++ )
        {
            Local_u8Bit = READ_BIT(RowArray[(u8)col], Local_u8Iterator);
            MGPIO_voidSetOutpinValue(ROW_PORT , (PIN_NUM_t)Local_u8Iterator, Local_u8Bit);
        }
        MGPIO_voidSetOutpinValue(COLUMN_PORT,  col , LOW);//enable column
        Systick_voidBusyWait(2500);//delay for each column
    }
}
