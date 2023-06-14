/***************************************************************/
/***************************************************************/
/***************  Author : Mona El_saied ***********************/
/**************** Layer  : MCAL     ****************************/
/**************** Driver : STK  ******************************/
/**************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void STK_voidInit(void);
void STK_voidBusyWait(u32 Copy_u32Tick);

void STK_voidDiable (void);
void STK_voidSetIntervalSingle( u32 Copy_u32Tick , void *Copy_ptr (void));

void STK_voidSetIntervalPeriodic( u32 Copy_u32Tick , void *Copy_ptr (void));
void STK_voidStopInterval(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);

void STK_Handler (void);


#endif