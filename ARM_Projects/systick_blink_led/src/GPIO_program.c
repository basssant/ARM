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
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinMode(GPIO_NUM_t GPIO_N , PIN_NUM_t PIN_NUMBER , PIN_MODE_t PinMode)
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	switch (PinMode)
	    	{
	    	    case INPUT:
	    	    	CLR_BIT(GPIOA->MODER , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->MODER , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case OUTPUT:
	    	    	SET_BIT(GPIOA->MODER , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->MODER , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case ALTERNATIVE_FUNCTION:
	    	    	CLR_BIT(GPIOA->MODER , (PIN_NUMBER*2));
	    	    	SET_BIT(GPIOA->MODER , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case ANALOG:
	    	    	SET_BIT(GPIOA->MODER , (PIN_NUMBER*2));
	    	    	SET_BIT(GPIOA->MODER , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    default:
	    	    	break;
	    	}
	    	break;
        case GPIOB_PORT:
            switch (PinMode)
            {
                case INPUT:
                    CLR_BIT(GPIOB->MODER , (PIN_NUMBER*2));
                    CLR_BIT(GPIOB->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case OUTPUT:
                    SET_BIT(GPIOB->MODER , (PIN_NUMBER*2));
                    CLR_BIT(GPIOB->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case ALTERNATIVE_FUNCTION:
                    CLR_BIT(GPIOB->MODER , (PIN_NUMBER*2));
                    SET_BIT(GPIOB->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case ANALOG:
                    SET_BIT(GPIOB->MODER , (PIN_NUMBER*2));
                    SET_BIT(GPIOB->MODER , ((PIN_NUMBER*2)+1));
                    break;
                default:
                    break;
            }
            break;
        case GPIOC_PORT:
            switch (PinMode)
            {
                case INPUT:
                    CLR_BIT(GPIOC->MODER , (PIN_NUMBER*2));
                    CLR_BIT(GPIOC->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case OUTPUT:
                    SET_BIT(GPIOC->MODER , (PIN_NUMBER*2));
                    CLR_BIT(GPIOC->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case ALTERNATIVE_FUNCTION:
                    CLR_BIT(GPIOC->MODER , (PIN_NUMBER*2));
                    SET_BIT(GPIOC->MODER , ((PIN_NUMBER*2)+1));
                    break;
                case ANALOG:
                    SET_BIT(GPIOC->MODER , (PIN_NUMBER*2));
                    SET_BIT(GPIOC->MODER , ((PIN_NUMBER*2)+1));
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
	}

}
void MGPIO_voidSetPinOutputType(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_TYPE_t Output_Type)
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	switch (Output_Type)
	    	{
	    	    case OUTPUT_PUSH_PULL:
	    	    	CLR_BIT(GPIOA->OTYPER , PIN_NUMBER);
	    	    	break;
	    	    case OUTPUT_OPEN_DRAIN:
	    	    	SET_BIT(GPIOA->OTYPER , PIN_NUMBER);
	    	    	break;
	    	    default:
	    	    	/*Do Nothing*/
	    	    	break;
	    	}
            break;
		case GPIOB_PORT:
			switch (Output_Type)
			{
			    case OUTPUT_PUSH_PULL:
			    	CLR_BIT(GPIOB->OTYPER , PIN_NUMBER);
			    	break;
			    case OUTPUT_OPEN_DRAIN:
			    	SET_BIT(GPIOB->OTYPER , PIN_NUMBER);
			    	break;
			    default:
			    	/*Do Nothing*/
			    	break;
			}
            break;
        case GPIOC_PORT:
            switch (Output_Type)
            {
                case OUTPUT_PUSH_PULL:
                    CLR_BIT(GPIOC->OTYPER , PIN_NUMBER);
                    break;
                case OUTPUT_OPEN_DRAIN:
                    SET_BIT(GPIOC->OTYPER , PIN_NUMBER);
                    break;
                default:
                    /*Do Nothing*/
                    break;
            }
            break;
        default:
            /*Do Nothing*/
            break;
	}

}

void MGPIO_voidSetPinOutputSpeed(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_SPEED_t Output_Speed)
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	switch (Output_Speed)
	    	{
	    	    case LOW_SPEED_2MHZ:
	    	    	CLR_BIT(GPIOA->OSPEEDR , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->OSPEEDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case MEDIUM_SPEED_UP_TO_10MHZ:
	    	    	SET_BIT(GPIOA->OSPEEDR , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->OSPEEDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case HIGH_SPEED_UP_TO_50MHZ:
	    	    	CLR_BIT(GPIOA->OSPEEDR , (PIN_NUMBER*2));
	    	    	SET_BIT(GPIOA->OSPEEDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case VERY_HIGH_SPEED_UP_TO_100MHZ:
	    	    	SET_BIT(GPIOA->OSPEEDR , (PIN_NUMBER*2));
	    	    	SET_BIT(GPIOA->OSPEEDR ,((PIN_NUMBER*2)+1));
	    	    	break;
	    	    default:
	    	    	break;
	    	}
            break;
        case GPIOB_PORT:
            switch (Output_Speed)
            {
                case LOW_SPEED_2MHZ:
                    CLR_BIT(GPIOB->OSPEEDR , (PIN_NUMBER*2));
                    CLR_BIT(GPIOB->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case MEDIUM_SPEED_UP_TO_10MHZ:
                    SET_BIT(GPIOB->OSPEEDR , (PIN_NUMBER*2));
                    CLR_BIT(GPIOB->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case HIGH_SPEED_UP_TO_50MHZ:
                    CLR_BIT(GPIOB->OSPEEDR , (PIN_NUMBER*2));
                    SET_BIT(GPIOB->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case VERY_HIGH_SPEED_UP_TO_100MHZ:
                    SET_BIT(GPIOB->OSPEEDR , (PIN_NUMBER*2));
                    SET_BIT(GPIOB->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                default:
                    break;
            }
            break;
        case GPIOC_PORT:
            switch (Output_Speed)
            {
                case LOW_SPEED_2MHZ:
                    CLR_BIT(GPIOC->OSPEEDR , (PIN_NUMBER*2));
                    CLR_BIT(GPIOC->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case MEDIUM_SPEED_UP_TO_10MHZ:
                    SET_BIT(GPIOC->OSPEEDR , (PIN_NUMBER*2));
                    CLR_BIT(GPIOC->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case HIGH_SPEED_UP_TO_50MHZ:
                    CLR_BIT(GPIOC->OSPEEDR , (PIN_NUMBER*2));
                    SET_BIT(GPIOC->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                case VERY_HIGH_SPEED_UP_TO_100MHZ:
                    SET_BIT(GPIOC->OSPEEDR , (PIN_NUMBER*2));
                    SET_BIT(GPIOC->OSPEEDR , ((PIN_NUMBER*2)+1));
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
	}
}


void MGPIO_voidSetPinOutputMode(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , OUTPUT_MODE_t Mode)
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	switch (Mode)
	    	{
	    	    case NO_PULL_UP_NO_PULL_DOWN:
	    	    	CLR_BIT(GPIOA->PUPDR , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->PUPDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case PULL_UP:
	    	    	SET_BIT(GPIOA->PUPDR , (PIN_NUMBER*2));
	    	    	CLR_BIT(GPIOA->PUPDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    case PULL_DOWN:
	    	    	CLR_BIT(GPIOA->PUPDR , (PIN_NUMBER*2));
	    	    	SET_BIT(GPIOA->PUPDR , ((PIN_NUMBER*2)+1));
	    	    	break;
	    	    default:
	    	    	break;
	    	}
	    	break;
		case GPIOB_PORT:
			switch (Mode)
			{
			    case NO_PULL_UP_NO_PULL_DOWN:
			    	CLR_BIT(GPIOB->PUPDR , (PIN_NUMBER*2));
			    	CLR_BIT(GPIOB->PUPDR , ((PIN_NUMBER*2)+1));
			    	break;
			    case PULL_UP:
			    	SET_BIT(GPIOB->PUPDR , (PIN_NUMBER*2));
			    	CLR_BIT(GPIOB->PUPDR , ((PIN_NUMBER*2)+1));
			    	break;
			    case PULL_DOWN:
			    	CLR_BIT(GPIOB->PUPDR , (PIN_NUMBER*2));
			    	SET_BIT(GPIOB->PUPDR , ((PIN_NUMBER*2)+1));
			    	break;
			    default:
			    	break;
			}
			break;
        case GPIOC_PORT:
            switch (Mode)
            {
				case NO_PULL_UP_NO_PULL_DOWN:
					CLR_BIT(GPIOC->PUPDR , (PIN_NUMBER*2));
					CLR_BIT(GPIOC->PUPDR , ((PIN_NUMBER*2)+1));
					break;
				case PULL_UP:
					SET_BIT(GPIOC->PUPDR , (PIN_NUMBER*2));
					CLR_BIT(GPIOC->PUPDR , ((PIN_NUMBER*2)+1));
					break;
				case PULL_DOWN:
					CLR_BIT(GPIOC->PUPDR , (PIN_NUMBER*2));
					SET_BIT(GPIOC->PUPDR , ((PIN_NUMBER*2)+1));
					break;
				default:
					break;
            }
            break;
        default:
            break;
	}
}

void MGPIO_voidReadInputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value)    //Read IDR)
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOA->IDR ,PIN_NUMBER);
	    	break;
	    case GPIOB_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOB->IDR ,PIN_NUMBER);
	    	break;
	    case GPIOC_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOC->IDR ,PIN_NUMBER);
	    	break;
	    default:
	    	/*Do Nothing*/
	    	break;
	}
}

void MGPIO_voidReadOutputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value)   //Read ORD
{
	switch (GPIO_N)
	{
	    case GPIOA_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOA->ODR ,PIN_NUMBER);
	    	break;
	    case GPIOB_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOB->ODR ,PIN_NUMBER);
	    	break;
	    case GPIOC_PORT:
	    	*Local_pu8Value = READ_BIT (GPIOC->ODR ,PIN_NUMBER);
	    	break;
	    default:
	    	/*Do Nothing*/
	    	break;
	}

}

void MGPIO_voidSetOutpinValue(GPIO_NUM_t GPIO_N,  PIN_NUM_t PIN_NUMBER , u8 Copy_u8PinValue)
{
    switch(GPIO_N)
    {
        case GPIOA_PORT:
                switch(Copy_u8PinValue)
                {
                    case HIGH:
                        SET_BIT(GPIOA ->ODR,PIN_NUMBER);
                        break;
                    case LOW:
                        CLR_BIT(GPIOA ->ODR,PIN_NUMBER);
                        break;
                }
            break;
        case GPIOB_PORT:
                switch(Copy_u8PinValue)
                {
                    case HIGH:
                        SET_BIT(GPIOB ->ODR,PIN_NUMBER);
                        break;
                    case LOW:
                        CLR_BIT(GPIOB ->ODR,PIN_NUMBER);
                        break;
                }
            break;
        case GPIOC_PORT:
                switch(Copy_u8PinValue)
                {
                    case HIGH:
                        SET_BIT(GPIOC ->ODR,PIN_NUMBER);
                        break;
                    case LOW:
                        CLR_BIT(GPIOC ->ODR,PIN_NUMBER);
                        break;
                }
            break;
        default:
            break;
    }
}

void MGPIO_voidSetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER)    //BSRR
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		GPIOA->BSRR = (1 << PIN_NUMBER);
		break;
	case GPIOB_PORT:
		GPIOB->BSRR = (1 << PIN_NUMBER);
		break;
	case GPIOC_PORT:
		GPIOB->BSRR = (1 << PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}
void MGPIO_voidResetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		GPIOA->BSRR = (0x10000<< PIN_NUMBER);
		break;
	case GPIOB_PORT:
		GPIOB->BSRR = (0x10000 << PIN_NUMBER);
		break;
	case GPIOC_PORT:
		GPIOB->BSRR = (0x10000 << PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}
