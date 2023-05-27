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

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void NVIC_voidInit()
{
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (NVIC_GRP_SUB_DISTRIBUTION << 8);
}
void NVIC_voidEnablePeripheralInterrupt(u8 copy_u8PeripheralID)
{
   u8 Local_u8ISERIndex;
   Local_u8ISERIndex =  copy_u8PeripheralID / 32;
   MNVIC -> ISER[Local_u8ISERIndex] = (1 <<(copy_u8PeripheralID % 32) );
}
void NVIC_voidDisablePeripheralInterrupt(u8 copy_u8PeripheralID)
{

}
void NVIC_voidSetPendingFlag(u8 copy_u8PeripheralID)
{

}
void NVIC_voidClearPendingFlag(u8 copy_u8PeripheralID)
{

}
void NVIC_voidGetActiveFlag(u8 copy_u8PeripheralID)
{

}
void NVIC_voidSetPeripheralPriority(u8 copy_u8PeripheralID, u8 copy_u8Priority)
{
    MNVIC -> IPR[copy_u8PeripheralID] = (copy_u8Priority << 4);     //it's in the most signficant 4 bits
}