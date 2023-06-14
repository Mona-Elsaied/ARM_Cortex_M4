
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"



int  main ()
{

         /* System clock is 8MHZ  HSI*/
		MRCC_voidInitSystemClk();
		/*STK ini*/
		STK_voidInit();

		/* ENABLE perpherial clk*/
		MRCC_voidEnablePeripheralClock(AHB1 , 0);
		// SET MODE (output)
		GPIO_voidSetPinDirectionMode(GPIOA , PIN0 , OUTPUT );
        // SET TYPE
		GPIO_voidSetPinType(GPIOA , PIN0 , OUTPUT_PP);
        //SET SPEED
		GPIO_voidSetPinSpeed(GPIOA , PIN0 ,OUTPUT_MS );

       // WRITE DATA
		GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
   while(1)
   {
	   GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
	   STK_voidBusyWait(100000000);
	   GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_LOW);
	   STK_voidBusyWait(100000000);


	}
}



