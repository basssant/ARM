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
#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_

//Peripherals Macros
#define         MNVIC_WWDG			                0       //Window Watchdog interrupt
#define         MNVIC_PVD         	                1       //EXTI Line 16 interrupt / PVD through EXTI line detection interrupt
#define         MNVIC_RTC_WKUP                      2       //EXTI Line 21 interrupt / Tamper and TimeStamp interrupts through the EXTI line
#define         MNVIC_RTC WKUP                      3       //EXTI Line 22 interrupt / RTC Wakeup interrupt through the EXTI line
#define         MNVIC_FLASH			                4       //Flash global interrupt
#define         MNVIC_RCC				            5       //RCC global interrupt
#define         MNVIC_EXTI0			                6       //EXTI Line0 interrupt
#define         MNVIC_EXTI1			                7       //EXTI Line1 interrupt
#define         MNVIC_EXTI2			                8       //EXTI Line2 interrupt
#define         MNVIC_EXTI3			                9       //EXTI Line3 intemupt
#define         MNVIC_EXTI4			                10      //EXTI Line4 interrupt
#define         MNVIC_DMA1_Stream0	                11      //DMA1 Stream0 global interrupt
#define         MNVIC_DMA1_Stream1	                12      //DMA1 Stream1 global interrupt
#define         MNVIC_DMA1_Stream2	                13      //DMA1 Stream2 global interrupt
#define         MNVIC_DMA1_Stream3	                14      //DMA1 Stream3 global interrupt
#define         MNVIC_DMA1_Stream4	                15      //DMA1 Stream4 global interrupt
#define         MNVIC_DMA1_Stream5	                16      //DMA1 Stream5 global interrupt
#define         MNVIC_DMA1_Stream6	                17      //DMA1 Stream6 global interrupt
#define         MNVIC_ADC				            18      //ADC global interupts
#define         MNVIC_EXTI9_5			            23      //EXTI Line[9:5] interrupts
#define         MNVIC_TIM1_BRK_TIM9	                24      //TIM1 Break interrupt and TIM9 global interrupt
#define         MNVIC_TIM1_UP_TIM10	                25      //TIM1 Update interrupt and TIM10 global interrupt
#define         MNVIC_TIM1_TRG_COM_TIM              26      //TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
#define         MNVIC_TIM1_CC			            27      //TIM1 Capture Compare interrupt
#define         MNVIC_TIM2			                28      //TIM2 global interrupt
#define         MNVIC_TIM3			                29      //TIM3 global interrupt
#define         MNVIC_TIM4			                30      //TIM4 global interrupt
#define         MNVIC_I2C1_EV			            31      //I2C1 event interrupt
#define         MNVIC_I2C1_ER			            32      //I2C1 error interrupt
#define         MNVIC_I2C2_EV			            33      //I2C2 event interrupt
#define         MNVIC_I2C2_ER			            34      //I2C2 error interrupt
#define         MNVIC_SPI1			                35      //SPI1 global interrupt
#define         MNVIC_SPI2			                36      //SPI2 global interrupt
#define         MNVIC_USART1			            37      //USART1 global interrupt
#define         MNVIC_USART2			            38      //USART2 global interrupt
#define         MNVIC_EXTI15_10		                40      //EXTI Line[15:10] interrupts
#define         MNVIC_RTC_Alarm                     41      //EXTI Line 17 interrupt / RTC Alarms (A and B) through EXTI line interrupt
#define         MNVIC_OTG_FS_WKUP                   42      //EXTI Line 18 interrupt / USB On-The-Go FS Wakeup through EXTI line interrupt
#define         MNVIC_DMA1_Stream7	                47      //DMA1 Stream7 global interrupt 
#define         MNVIC_SDIO			                49      //SDIO global interrupt
#define         MNVIC_TIM5			                50      //TIM5 global interrupt
#define         MNVIC_SPI3			                51      //SPI3 global interrupt
#define         MNVIC_DMA2_Stream0	                56      //DMA2 Stream0 global interrupt 
#define         MNVIC_DMA2_Stream1	                57      //DMA2 Stream1 global interrupt
#define         MNVIC_DMA2_Stream2	                58      //DMA2 Stream2 global interrupt
#define         MNVIC_DMA2_Stream3	                59      //DMA2 Stream3 global interrupt
#define         MNVIC_DMA2_Stream4	                60      //DMA2 Stream4 global interrupt
#define         MNVIC_OTG_FS			            67      //USB On The Go FS global interrupt
#define         MNVIC_DMA2_Stream5	                68      //DMA2 Stream5 global interrupt 
#define         MNVIC_DMA2_Stream6	                69      //DMA2 Stream6 global interrupt 
#define         MNVIC_DMA2_Stream7	                70      //DMA2 Stream7 global interrupt 
#define         MNVIC_USART6			            71      //USART6 global interrupt 
#define         MNVIC_I2C3_EV			            72      //I2C3 event interrupt
#define         MNVIC_I2C3_ER			            73      //I2C3 error interrupt
#define         MNVIC_FPU				            81      //FPU global interrupt
#define         MNVIC_SPI4			                84      //SPI 4 global interrupt

//Functions prototypes
void MNVIC_voidInit();
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InteruptID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InteruptID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8InteruptID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8InteruptID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */