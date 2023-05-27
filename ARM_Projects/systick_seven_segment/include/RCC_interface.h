#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

//Copy_u8PeripheralBus OPTIONS
#define RCC_AHB1                    0
#define RCC_APB1                    1
#define RCC_AHB2                    2
#define RCC_APB2                    3

//Copy_u8PeripheralID OPTIONS
#define RCC_GPIOA                   0
#define RCC_GPIOB                   1
#define RCC_GPIOC                   2

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);
void MRCC_voidDisablePeripheralClk(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);




#endif