
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"

#include "file.h"


volatile u32 count =0;
void SetDAC(void)
{
    Data(song_raw[count]);
    count++;
    if(count == 24335)
    {
    	count=0;
    }
}
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
			GPIO_voidSetPinDirectionMode(GPIOA , PIN1 , OUTPUT );
			GPIO_voidSetPinDirectionMode(GPIOA , PIN2 , OUTPUT );
			GPIO_voidSetPinDirectionMode(GPIOA , PIN3 , OUTPUT );
			GPIO_voidSetPinDirectionMode(GPIOA , PIN4 , OUTPUT );
			GPIO_voidSetPinDirectionMode(GPIOA , PIN5 , OUTPUT );
			GPIO_voidSetPinDirectionMode(GPIOA , PIN6 , OUTPUT );
			// SET TYPE
			GPIO_voidSetPinType(GPIOA , PIN0 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN1 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN2 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN3 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN4 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN5 , OUTPUT_PP);
			GPIO_voidSetPinType(GPIOA , PIN6 , OUTPUT_PP);
			//SET SPEED
			GPIO_voidSetPinSpeed(GPIOA , PIN0 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN1 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN2 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN3 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN4 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN5 ,OUTPUT_LS );
			GPIO_voidSetPinSpeed(GPIOA , PIN6 ,OUTPUT_LS );

			// WRITE DATA
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN2 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN3 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN4 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN5 , VAL_HIGH);
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN6 , VAL_HIGH);

           // Set interval periodic
           STK_voidSetIntervalPeriodic(125 , SetDAC);

   while(1);

}
