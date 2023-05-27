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
#ifndef MCAL_MNVIC_MNVIC_CONFIG_H_
#define MCAL_MNVIC_MNVIC_CONFIG_H_

/*Options:
GRP_0_SUB_4_BITS
GRP_1_SUB_3_BITS
GRP_2_SUB_2_BITS
GRP_3_SUB_1_BITS
GRP_4_SUB_0_BITS
    */
#define			MVIC_GRP_SUB_DISTRUBTION				GRP_2_SUB_2_BITS

#endif /* MCAL_MNVIC_MNVIC_CONFIG_H_ */