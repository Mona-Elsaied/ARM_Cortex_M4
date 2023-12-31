

/***********************************************************************/
/*                           Standard Types LIB                        */
/***********************************************************************/
#include"../include/STD_TYPES.h"
#include"../include/BIT_MATH.h"
#include <RCC_Config.h>
#include <RCC_Interface.h>
#include <RCC_Private.h>


/***********************************************************************/
/*                           Lower Layer Interfaces                    */
/***********************************************************************/


/***********************************************************************/
/*                            own Header Files                         */
/***********************************************************************/



/***********************************************************************/
/*                        Function Implementation                      */
/***********************************************************************/

/*#####################################################################*/

/*
   @fu MRCC_voidEnablePeripheralClock 
   @brief   This Function used To Enable Peripheral clock  
   @param[in]   Copy_uddtBusName  : The Bus of The Peripheral [AHB1 , AHB2 , APB1 ,APB2] Every one  Detect 
   Which REG to Choise Peripherial From It   
   @param[in]   Copy_u8PerNum  : The order of Peripheral On The Selected Register
*/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName,u8 Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{  
     case AHB1  : SET_BIT(RCC_AHB1ENR,Copy_u8PerNum) ; break ; 
     case AHB2  : SET_BIT(RCC_AHB2ENR,Copy_u8PerNum) ; break ; 
     case APB1  : SET_BIT(RCC_APB1ENR,Copy_u8PerNum) ; break ; 
     case APB2  : SET_BIT(RCC_APB2ENR,Copy_u8PerNum) ; break ; 
	 default    : /* ERROR*/         break ; 
	}
	
}

/*#####################################################################*/

/*
   @fu MRCC_voidDisablePeripheralClock 
   @brief   This Function used To Disable Peripheral clock  
   @param[in]   Copy_uddtBusName  : The Bus of The Peripheral [AHB1 , AHB2 , APB1 ,APB2] Every one  Detect 
   Which REG to Choise Peripherial From It   
   @param[in]   Copy_u8PerNum  : The order of Peripheral On The Selected Register
*/
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName,u8 Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{  
     case AHB1  : CLR_BIT(RCC_AHB1ENR,Copy_u8PerNum) ; break ; 
     case AHB2  : CLR_BIT(RCC_AHB2ENR,Copy_u8PerNum) ; break ; 
     case APB1  : CLR_BIT(RCC_APB1ENR,Copy_u8PerNum) ; break ; 
     case APB2  : CLR_BIT(RCC_APB2ENR,Copy_u8PerNum) ; break ; 
	 default    : /* ERROR*/         break ; 
	}
}

/*
   @fu MRCC_voidInitSystemClk 
   @brief   This Function used To Initializaion for System clock   
*/
void MRCC_voidInitSystemClk(void)
{   
    /***************HSI************/
	#if MRCC_CLKSRC == HSI
	/*1- Enable HSI */
	SET_BIT(RCC_CR,0U);
	/*2-Clk System -->HSI */
	CLR_BIT(RCC_CFGR,0U);
	CLR_BIT(RCC_CFGR,1U);
	/***************HSE***********/
   #elif MRCC_CLKSRC == HSE
   
        #if MRCC_HSE_SRC == HSE_CRYSTAL
		  /* 1- Enable HSE */
		  	SET_BIT(RCC_CR,16U);
		  /* 2- Disable BYPASS */
		  	CLR_BIT(RCC_CR,18U);
		  /* 3- Clk System -->HSE */
		    SET_BIT(RCC_CFGR,0U);
            CLR_BIT(RCC_CFGR,1U);
		  
		#elif MRCC_HSE_SRC == HSE_RC
		  /* 1- Enable HSE */
		  	SET_BIT(RCC_CR,16U);
		  /* 2- Enable BYPASS */
		  	SET_BIT(RCC_CR,18U);
		  /* 3- Clk System -->HSE */
		    SET_BIT(RCC_CFGR,0U);
            CLR_BIT(RCC_CFGR,1U);
		#else
			/*Error*/
		#endif
	
	#elif MRCC_CLKSRC == PLL
      /****************/
     
    #else 
      #error "Invalid Option For Clock Source  ..... " 		
	#endif
/*#####################################################################*/
/*                  THE END OF PROGRAM FILE                      */
/*#####################################################################*/
}
