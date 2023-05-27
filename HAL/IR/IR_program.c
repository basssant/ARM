#include "BitMath.H"
#include "StdTypes.H"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "MNVIC_interface.h"
#include "EXTI_interface.h"


#include "IR_interface.h"

/*First Edge*/
static u8 Global_u8StartEdgeFlag = 0;

/*Time between every two falling edges*/
static u32 Global_u32ReceivedFrame[50] = {0};

/*Carry Decimal Number*/
static u8 Global_u8ButtonData = 0;

/*Edge Number*/
static u8 Global_u8EdgeCounter = 0;


void HIR_voidInit(void)
{
	/*RCC Init*/
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	/*Configure PA0*/
    MGPIO_voidSetPinMode(GPIOA_PORT , PIN0 , INPUT);
    MGPIO_voidSetPinOutputType(GPIOA_PORT , PIN0 , PULL_UP);


	/*Configure PA1*/
	MGPIO_voidSetPinMode(GPIOA_PORT , PIN1 , OUTPUT);
	/*Configure PA2*/
	MGPIO_voidSetPinMode(GPIOA_PORT , PIN2 , OUTPUT);
	/*Configure PA3*/
	MGPIO_voidSetPinMode(GPIOA_PORT , PIN3 , OUTPUT);


	/*Init STK*/
	/*On But not counting cuz load = 0 */
	Systick_voidInit();

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	/*Falling*/
	EXTI_voidChangeSEnseMode(MEXTI_LINE0,EXTI_FALLING_EDGE);
	/*Pass The Function*/
	EXTI_voidSetCallBack(MEXTI_LINE0 , &HIR_voidGetFrame);
	/*Enable Interrupt*/
	EXTI_voidEnableInterrupt(MEXTI_LINE0);

}

void HIR_voidGetFrame(void)
{
	if(Global_u8StartEdgeFlag == 0)
	{
		/*Set timer with Total FrameTime*/
		Systick_voidSetSingleInterval(60000,&HIR_voidTakeAction);

		Global_u8StartEdgeFlag = 1;
	}
	else
	{	/*Get the counted TIME*/
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = Systick_u32GetElapsedTime();
		/*Reset Timer*/
		Systick_voidResetSysTick();
		/*Set PreLoad Value*/
		Systick_voidSetSingleInterval(60000,&HIR_voidTakeAction);
		/*Inc Edge Counter*/
		Global_u8EdgeCounter++;


	}
}

void HIR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8 ; Local_u8LoopCounter ++)
	{
		/*Data From 17 to 24*/
		if ((Global_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
				(Global_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			/*Zero*/
			CLR_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}

		else
		{	/*One*/
			SET_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
	}
	/*Prepare new frame*/
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void HIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{

	  case 22://0
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , LOW);
	  	break;
	  case 12://1
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , LOW);
	  	break;
	  case 24://2
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , HIGH);
	  	break;
	  case 94://3
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , LOW);
	  	break;
	  case 8://4
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , HIGH);
	  	break;
	  case 28://5
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , HIGH);
	  	break;
	  case 90://6
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , HIGH);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , HIGH);
	  	break;
	  case 69://ON-OFF
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN1 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN2 , LOW);
        MGPIO_voidSetOutpinValue(GPIOA_PORT , PIN3 , LOW);
	  	break;
	}
}
