
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "RCC_Interface.h"
#include  "NVIC_Interface.h"

void APP_voidDelay(void);

int  main ()
{

         /* System clock is 8MHZ  HSI*/
		MRCC_voidInitSystemClk();
		/* ENABLE perpherial clk*/
		MRCC_voidEnablePeripheralClock(AHB1 , 0);
		// SET MODE (output)
		GPIO_voidSetPinDirectionMode(GPIOA , PIN1 , OUTPUT );
        // SET TYPE
		GPIO_voidSetPinType(GPIOA , PIN1 , OUTPUT_PP);
        //SET SPEED
		GPIO_voidSetPinSpeed(GPIOA , PIN1 ,OUTPUT_LS );

       // WRITE DATA
		GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
		NVIC_voidEnablePerInt(6);


   while(1)
   {
	   NVIC_voidSetPendingFlag(6);



	}
}

void EXTI0_IRQHandler(void)
{
	       GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_HIGH);
		   APP_voidDelay();
		   GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_LOW);
		   APP_voidDelay();
}

void APP_voidDelay(void)
{
	u32 i;
	for(i=0 ; i< 2000000 ; i++)
	{
		asm("NOP");
	}

}
