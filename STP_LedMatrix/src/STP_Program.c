#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "STP_Private.h"
#include "STP_Config.h"
#include "STP_Interface.h"


#include "MGPIO_Private.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"




void STP_voidInit()
{
	MGPIO_voidSetPinMode(STP_SERIAL_DATA,MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode(STP_STOR_DATA,MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode(STP_SHIFT_DATA,MGPIO_MODE_OUTPUT );

	MGPIO_voidSetPinMode(STP_SERIAL_DATA_1,MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode(STP_STOR_DATA_1,MGPIO_MODE_OUTPUT );
	MGPIO_voidSetPinMode(STP_SHIFT_DATA_1,MGPIO_MODE_OUTPUT );



}
void STP_voidSendSynchronous(u8 copy_u8DataToBeSent)
{
	u8 local_u8Counter;
	u8 local_u8Bit;

	for (local_u8Counter = 7 ; local_u8Counter >= 0  ; local_u8Counter--)
	{
		local_u8Bit = GET_BIT(copy_u8DataToBeSent , local_u8Counter);
		MGPIO_voidSetPinValue(STP_SERIAL_DATA ,local_u8Bit );

		MGPIO_voidSetPinValue(STP_SHIFT_DATA ,MGPIO_HIGH );
		MSTK_voidDelayMs(1);
		MGPIO_voidSetPinValue(STP_SHIFT_DATA ,MGPIO_LOW );
		MSTK_voidDelayMs(1);

	}

	GPIO_voidSetPinValueAtomic(STP_STOR_DATA ,MGPIO_HIGH );
	STK_voidBusyWait(1);
	GPIO_voidSetPinValueAtomic(STP_STOR_DATA ,MGPIO_HIGH );
	STK_voidBusyWait(1);

	////////////////////////////////////////////////

	for (local_u8Counter = 7 ; local_u8Counter >= 0  ; local_u8Counter--)
	{
		local_u8Bit = GET_BIT(copy_u8DataToBeSent , local_u8Counter);
		MGPIO_voidSetPinValue(STP_SERIAL_DATA_1 ,local_u8Bit );

		MGPIO_voidSetPinValue(STP_SHIFT_DATA_1 ,MGPIO_HIGH );
		MSTK_voidDelayMs(1);
		MGPIO_voidSetPinValue(STP_SHIFT_DATA_1 ,MGPIO_LOW );
		MSTK_voidDelayMs(1);

	}

	MGPIO_voidSetPinValue(STP_STOR_DATA_1 ,MGPIO_HIGH );
	MSTK_voidDelayMs(1);
	MGPIO_voidSetPinValue(STP_STOR_DATA_1 ,MGPIO_LOW );
	MSTK_voidDelayMs(1);

}
