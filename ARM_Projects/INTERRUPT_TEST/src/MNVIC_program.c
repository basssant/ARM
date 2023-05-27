/************************************************
 * Author:				Ahmed Tahoun
 * Creation Date:		21 MAY	2023
 * Version:				v1.0
 * Compiler:			GNU ARM GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ***********************************************/
/************************************************
 * Version          Date           Author         Description
 * v1.0         21 MAY	2023    Ahmed Tahoun    Initial Creation
************************************************/
/*Library Inclusion*/
#include "StdTypes.h"
#include "BitMath.h"
/*Lower Layer*/

/*Self Files Inclusion*/
#include "MNVIC_interface.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"

void MNVIC_voidInit()
{
    SCB_AIRCR |= (AIRCR_PRIVKEY) | (MVIC_GRP_SUB_DISTRUBTION << EIGHT_BITS);
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InteruptID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8InteruptID / THIRTY_TWO_BITS;
    MNVIC -> ISER[Local_u8ISERIndex] = (1 << (Copy_u8InteruptID % THIRTY_TWO_BITS));
}
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InteruptID)
{
    u8 Local_u8ICERIndex;
    Local_u8ICERIndex = Copy_u8InteruptID / THIRTY_TWO_BITS;
    MNVIC -> ICER[Local_u8ICERIndex] = (1 << (Copy_u8InteruptID % THIRTY_TWO_BITS));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8InteruptID)
{
    u8 Local_u8ISPRIndex;
    Local_u8ISPRIndex = Copy_u8InteruptID / THIRTY_TWO_BITS;
    MNVIC -> ISPR[Local_u8ISPRIndex] = (1 << (Copy_u8InteruptID % THIRTY_TWO_BITS));
}
void MNVIC_voidClearPendingFlag(u8 Copy_u8InteruptID)
{
    u8 Local_u8ICPRIndex;
    Local_u8ICPRIndex = Copy_u8InteruptID / THIRTY_TWO_BITS;
    MNVIC -> ICPR[Local_u8ICPRIndex] = (1 << (Copy_u8InteruptID % THIRTY_TWO_BITS));
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InteruptID)
{
    u8 Local_u8ActiveFlag;
    u8 Local_u8IABRIndex;
    Local_u8IABRIndex = Copy_u8InteruptID / THIRTY_TWO_BITS;
    Local_u8ActiveFlag = GET_BIT(MNVIC -> IABR[Local_u8IABRIndex], (Copy_u8InteruptID % THIRTY_TWO_BITS));
    return Local_u8ActiveFlag;
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8InteruptID, u8 Copy_u8Priority)
{
    MNVIC -> IPR[Copy_u8InteruptID] = (Copy_u8Priority << FOUR_BITS);
}
