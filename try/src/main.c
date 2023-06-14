#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"

#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"

#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"

int main()
{
	MRCC_voidInitSystemClk();
	STK_voidInt();

	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	GPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT);
	GPIO_voidSetPinOutType(GPIOA,PIN1,OUTPUT_PP);
	GPIO_voidSetPinOutSpeed(GPIOA,PIN1,OUTPUT_MS);
	NVIC_voidEnableInterrupt(6);

	while(1)
    {
		NVIC_voidEnableInterruptPending(6);

    }
}
void ExTI0_IRQHandeler(void)
{
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN1,HIGH);
	STK_voidSetBadyWait(50000);
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN1,LOW);
	STK_voidSetBadyWait(50000);
}

