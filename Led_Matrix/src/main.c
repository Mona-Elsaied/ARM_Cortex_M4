
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "HLED_MATRIX_Interface.h"

u8 GLOB_u8DataArr[8] = {0, 195, 165, 153, 129, 129, 129, 129} ;//{0, 127, 73, 73, 65, 0, 0, 0} ;

u8 GLOB_u8DataArr_1[8] = {0, 24, 148, 147, 144, 144, 144, 16} ;

u8 GLOB_u8DataArr_2[8] = {0, 0, 15, 9, 9, 9, 15, 0} ;



//    (0, 62, 42, 42, 42, 42, 0, 0)      m
//    (0, 31, 21, 21, 21, 21, 0, 0)  <m
//    (0, 7, 5, 5, 5, 5, 0, 0)      < n
//    (0, 59, 42, 42, 42, 58, 0, 0)   < n , o
void APP_voidDelay(void);
void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step 3 : Enable GPIO Peripherial Clock For Port B*/
    MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOB);

	/*Step 4 : Initialize For LED Matrix*/
    HLEDMAT_voidInit() ;

    /*Send Data To Led Matrix*/
    		HLEDMAT_voidDisplay(GLOB_u8DataArr) ;
    		//APP_voidDelay();
    		//MSTK_voidDelayMs(100000);
    		HLEDMAT_voidDisplay(GLOB_u8DataArr_1) ;

	/* Loop forever */
	while(1)
	{


	}

}

void APP_voidDelay(void)
{
	u32 i;
	for(i=0 ; i< 20000000000 ; i++)
	{
		asm("NOP");
	}

}
