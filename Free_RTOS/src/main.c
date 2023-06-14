#include "BIT_MATH.h"
#include  "STD_TYPES.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


SemaphoreHandle_t     Tst_semph;
BaseType_t    semph_state;

void TASK_1(void)
{
	static u8 flag =0;
	while (1)
	{
		semph_state = xSemaphoreTake( Tst_semph, 1100 );
		if (semph_state == pdTRUE)
		{
			if (flag == 0)
			{
				GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
				flag =1;

			}
			else {
				GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_LOW);
				flag =0;

			}
			xSemaphoreGive(Tst_semph);
			vTaskDelay(1000);

		}
	}

}
void TASK_2(void)
{
	static u8 flag =0;
	while (1)
	{
		semph_state = xSemaphoreTake( Tst_semph, 2100 );
		if (semph_state == pdTRUE)
		{
			if (flag == 0)
			{
				GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_HIGH);
				flag =1;

			}
			else {
				GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_LOW);
				flag =0;

			}
			xSemaphoreGive(Tst_semph);
			vTaskDelay(2000);

		}
	}

}
void TASK_3(void)
{
	static u8 flag =0;
	while (1)
	{semph_state = xSemaphoreTake( Tst_semph, 3100 );
	if (semph_state == pdTRUE)
	{
		if (flag == 0)
		{
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN2 , VAL_HIGH);
			flag =1;

		}
		else {
			GPIO_voidSetPinValueNonAtomic(GPIOA , PIN2 , VAL_LOW);
			flag =0;

		}
		xSemaphoreGive(Tst_semph);
		vTaskDelay(3000);

	}
	}

}


int main ()
{
	/* System clock is 8MHZ  HSI*/
	MRCC_voidInitSystemClk();
	/* ENABLE perpherial clk*/
	MRCC_voidEnablePeripheralClock(AHB1 , 0);
	// SET MODE (output)
	GPIO_voidSetPinDirectionMode(GPIOA , PIN0 , OUTPUT );
	GPIO_voidSetPinDirectionMode(GPIOA , PIN1 , OUTPUT );
	GPIO_voidSetPinDirectionMode(GPIOA , PIN2 , OUTPUT );
	// SET TYPE
	GPIO_voidSetPinType(GPIOA , PIN0 , OUTPUT_PP);
	GPIO_voidSetPinType(GPIOA , PIN1 , OUTPUT_PP);
	GPIO_voidSetPinType(GPIOA , PIN2 , OUTPUT_PP);
	//SET SPEED
	GPIO_voidSetPinSpeed(GPIOA , PIN0 ,OUTPUT_LS );
	GPIO_voidSetPinSpeed(GPIOA , PIN1 ,OUTPUT_LS );
	GPIO_voidSetPinSpeed(GPIOA , PIN2 ,OUTPUT_LS );

	// write data
	GPIO_voidSetPinValueNonAtomic(GPIOA , PIN0 , VAL_HIGH);
	GPIO_voidSetPinValueNonAtomic(GPIOA , PIN1 , VAL_HIGH);
	GPIO_voidSetPinValueNonAtomic(GPIOA , PIN2 , VAL_HIGH);

	//create semaphore binary

	vSemaphoreCreateBinary( Tst_semph ) ;
	// creat task
	xTaskCreate( TASK_1, NULL , 50 , NULL , 1,NULL );
	xTaskCreate (TASK_2, NULL , 50 , NULL , 4,NULL );
	//xTaskCreate( TASK_3, NULL , 50 , NULL , 1,NULL );

	// start os
	vTaskStartScheduler();

	while (1)
	{
		// call tasks

	}



	return 0;
}
