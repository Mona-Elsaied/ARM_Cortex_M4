
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
#include "STP_Interface.h"




void APP_voidDelay(void);

int  main ()
{

         /* System clock is 8MHZ  HSI*/
		MRCC_voidInitSystemClk();
		/* ENABLE perpherial clk*/
		MRCC_voidEnablePeripheralClock(AHB1 , 0);

		STK_voidInit();

		STP_voidInit();

//		// SET MODE (output)
//		GPIO_voidSetPinDirectionMode(GPIOA , PIN0 , OUTPUT );
//        // SET TYPE
//		GPIO_voidSetPinType(GPIOA , PIN0 , OUTPUT_PP);
//        //SET SPEED
//		GPIO_voidSetPinSpeed(GPIOA , PIN0 ,OUTPUT_LS );
//
//       // WRITE DATA
//		GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
   while(1)
   {
	   for (u8 i =0 ; i<8 ; i++)
	   {
	   STP_voidSendSynchronous(1<<i);
	   APP_voidDelay();
	   }

//	   GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
//	   APP_voidDelay();
//	   GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_LOW);
//	   APP_voidDelay();


	}
}


void APP_voidDelay(void)
{
	u32 i;
	for(i=0 ; i< 2000000 ; i++)
	{
		asm("NOP");
	}

}
