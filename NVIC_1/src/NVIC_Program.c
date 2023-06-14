#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

static u8 staticglobal_u8PeriodityConf;

void NVIC_voidEnablePerInt ( u8 Copy_IntId)
{
    NVIC->ISER[Copy_IntId/32]=(1<<(Copy_IntId%32));
}

void NVIC_voidDisablePerInt ( u8 Copy_IntId)
{
    NVIC->ICER[Copy_IntId/32]=(1<<(Copy_IntId%32));
}
void NVIC_voidSetPendingFlag ( u8 Copy_IntId)
{
    NVIC->ISPR[Copy_IntId/32]=(1<<(Copy_IntId%32));
}
void NVIC_voidClrPendingFlag ( u8 Copy_IntId)
{
   NVIC->ICPR[Copy_IntId/32]=(1<<(Copy_IntId%32));
}
void NVIC_SetPriortiyConfiguration(u8 Copy_PriortiyOption)
{
    staticglobal_u8PeriodityConf= VECT_KEY | (Copy_PriortiyOption<<8);
	SCB -> AIRCR = staticglobal_u8PeriodityConf;

}
void NVIC_SetIntPriortiy(u8 Copy_IntId , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId)
{
   u8 Local_u8Priority = Copy_u8SubGroupId |(Copy_u8GroupId<<(staticglobal_u8PeriodityConf-0x05FA0300)/256);
	NVIC -> IPR [Copy_IntId] = (Local_u8Priority<<4);
}
