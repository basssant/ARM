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
#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_

// Struct of NVIC registers
typedef struct
{
	volatile u32 ISER[8];					//Interrupt Set Enable Registers
	volatile u32 RESERVED0[24];
	volatile u32 ICER[8];					//Interrupt Clear Enable Registers
	volatile u32 RESERVED1[24];
	volatile u32 ISPR[8];					//Interrupt Set Pending Registers
	volatile u32 RESERVED2[24];
	volatile u32 ICPR[8];					//Interrupt Clear Pending Registers
	volatile u32 RESERVED3[24];
	volatile u32 IABR[8];					//Interrupt Active Bit Registers
	volatile u32 RESERVED4[56];
	volatile u8  IPR[240];					//Interrupt Priority Registers
	volatile u32 RESERVED5[580];
	volatile u32 STIR;						//Software Trigger Interrupt Registers
}NVIC_t;
#define			MNVIC				((volatile NVIC_t*)(0xE000E100))
#define			SCB_AIRCR			(*(volatile u32*)0xE000ED0C)


#define			AIRCR_PRIVKEY					0x05FA0000

#define			GRP_4_SUB_0_BITS				0b000
#define			GRP_3_SUB_1_BITS				0b100
#define			GRP_2_SUB_2_BITS				0b101
#define			GRP_1_SUB_3_BITS				0b110
#define			GRP_0_SUB_4_BITS				0b111

#define			EIGHT_BITS						8
#define			FOUR_BITS						4
#define			THIRTY_TWO_BITS					32


#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
