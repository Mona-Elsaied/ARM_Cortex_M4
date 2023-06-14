#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "STP_Private.h"
#include "STP_Interface.h"
#include "STP_Config.h"

#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"




void STP_voidInit()
{
	GPIO_voidSetPinDirectionMode(STP_SERIAL_DATA , OUTPUT);
	GPIO_voidSetPinDirectionMode(STP_STOR_DATA , OUTPUT);
	GPIO_voidSetPinDirectionMode(STP_SHIFT_DATA , OUTPUT);


}
void STP_voidSendSynchronous(u8 copy_u8DataToBeSent)
{
	u8 local_u8Counter;
	u8 local_u8Bit;

	for (local_u8Counter = 7 ; local_u8Counter >= 0  ; local_u8Counter--)
	{
		local_u8Bit = GET_BIT(copy_u8DataToBeSent , local_u8Counter);
		GPIO_voidSetPinValueAtomic(STP_SERIAL_DATA ,local_u8Bit );

		GPIO_voidSetPinValueAtomic(STP_SHIFT_DATA ,VAL_HIGH );
		STK_voidBusyWait(1);
		GPIO_voidSetPinValueAtomic(STP_SHIFT_DATA ,VAL_LOW );
		STK_voidBusyWait(1);

	}

	GPIO_voidSetPinValueAtomic(STP_STOR_DATA ,VAL_HIGH );
	STK_voidBusyWait(1);
	GPIO_voidSetPinValueAtomic(STP_STOR_DATA ,VAL_LOW );
	STK_voidBusyWait(1);

	////////////////////////////////////////////////

	for (local_u8Counter = 7 ; local_u8Counter >= 0  ; local_u8Counter--)
		{
			local_u8Bit = GET_BIT(copy_u8DataToBeSent , local_u8Counter);
			GPIO_voidSetPinValueAtomic(STP_SERIAL_DATA_1 ,local_u8Bit );

			GPIO_voidSetPinValueAtomic(STP_SHIFT_DATA_1 ,VAL_HIGH );
			STK_voidBusyWait(1);
			GPIO_voidSetPinValueAtomic(STP_SHIFT_DATA_1 ,VAL_LOW );
			STK_voidBusyWait(1);

		}

		GPIO_voidSetPinValueAtomic(STP_STOR_DATA_1 ,VAL_HIGH );
		STK_voidBusyWait(1);
		GPIO_voidSetPinValueAtomic(STP_STOR_DATA_1 ,VAL_LOW );
		STK_voidBusyWait(1);

}
