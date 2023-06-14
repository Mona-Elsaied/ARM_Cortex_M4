
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "STK_Private.h"
#include "STK_Interface.h"
#include "STK_Config.h"


static void (*STK_CallBack) (void);
static u8 STK_ModeInterval ;
void STK_voidInit(void)
{
    #if (STK_CLK_SOURCE == AHB )
     {
        SET_BIT(STK_CTRL , 2);
     }
    #elif (STK_CLK_SOURCE == AHB_div_8 )
    {
        CLR_BIT(STK_CTRL , 2);
    }
    #endif

}
void STK_voidBusyWait(u32 Copy_u32Tick)
{
   

   STK_LOAD = Copy_u32Tick;
   // before load enable systick
      SET_BIT (STK_CTRL , 0);
   // wait the flag raise (polling)
   while (GET_BIT(STK_CTRL ,16) == 0);
   // stop timer 
   STK_LOAD=0;
   STK_VAL =0;
   CLR_BIT(STK_CTRL , 0);
}

void STK_voidDiable (void)
{
  CLR_BIT (STK_CTRL , 1);

}

void STK_voidSetIntervalSingle( u32 Copy_u32Tick , void *Copy_ptr (void))
{
    // disable timer
    CLR_BIT(STK_CTRL , 0);
    STK_VAL =0;
    // Load time to load reg 
    STK_LOAD = Copy_u32Tick;
    // start timer 
    SET_BIT(STK_CTRL , 0);
    // save call back 
    STK_CallBack = Copy_ptr;
    // set mode to single 
    STK_ModeInterval = STK_SINGLE_INTERVAL ;
    // enable interrupt
    SET_BIT(STK_CTRL , 1);


}

void STK_voidSetIntervalPeriodic( u32 Copy_u32Tick , void *Copy_ptr (void))
{
    // Load time to load reg 
    STK_LOAD = Copy_u32Tick;
    // start timer 
    SET_BIT(STK_CTRL , 0);
    // save call back 
    STK_CallBack = Copy_ptr;
    // set mode to single 
    STK_ModeInterval = STK_PERIODIC_INTERVAL ;
    // enable interrupt
    SET_BIT(STK_CTRL , 1);

}
void STK_voidStopInterval(void)
{
     // Disable STK Interrupt
        CLR_BIT(STK_CTRL , 1);
        // stop timer
        CLR_BIT(STK_CTRL , 0);
        STK_LOAD=0;
        STK_VAL =0;

}
u32 STK_u32GetElapsedTime(void)
{
    u32 LOC_u32ElapsedTime ;
    LOC_u32ElapsedTime = STK_LOAD  - STK_VAL ;
    return LOC_u32ElapsedTime;

}

u32 STK_u32GetRemainingTime(void)
{
    u32 LOC_u32RemainTime ;
    LOC_u32RemainTime = STK_VAL;
    return LOC_u32RemainTime;
}

void STK_Handler (void)
{
    u8 LOC_u8Temporary ;
    if (STK_ModeInterval == STK_SINGLE_INTERVAL )
    {
        // Disable STK Interrupt
        CLR_BIT(STK_CTRL , 1);
        // stop timer
        CLR_BIT(STK_CTRL , 0);
        STK_LOAD=0;
        STK_VAL =0;
    }
    // call back func
    STK_CallBack();
    // clear interrupt 
    LOC_u8Temporary = GET_BIT(STK_CTRL , 16);

}
