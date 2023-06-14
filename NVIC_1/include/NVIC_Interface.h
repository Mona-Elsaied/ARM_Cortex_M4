/**************************************************/
/* ! Author  : Mona Elsaied          		      */
/* ! SW      : MCAL   (NVIC)       		    	  */
/* ! Version : v1.0								  */
/**************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidEnablePerInt ( u8 Copy_IntId);

void NVIC_voidDisablePerInt ( u8 Copy_IntId);
void NVIC_voidSetPendingFlag ( u8 Copy_IntId);
void NVIC_voidClrPendingFlag ( u8 Copy_IntId);
void NVIC_SetPriortiyConfiguration(u8 Copy_PriortiyOption);
void NVIC_SetIntPriortiy(u8 Copy_IntId , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId);

#define GROUP_4_BITS_SUB_BITS_0_BITS		0b010
#define GROUP_3_BITS_SUB_BITS_1_BITS		0b100
#define GROUP_2_BITS_SUB_BITS_2_BITS		0b101
#define GROUP_1_BITS_SUB_BITS_3_BITS		0b110
#define GROUP_0_BITS_SUB_BITS_4_BITS		0b111



#endif