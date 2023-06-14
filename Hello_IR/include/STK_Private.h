/***************************************************************/
/***************************************************************/
/***************  Author : Mona El_saied ***********************/
/**************** Layer  : MCAL     ****************************/
/**************** Driver : STK  ******************************/
/**************************************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


//STK register   (4 reg) 

#define   STK_BASE_ADDRESS      0xE000E010

#define   STK_CTRL         *((volatile u32*)(STK_BASE_ADDRESS + 0x00))
#define   STK_LOAD         *((volatile u32*)(STK_BASE_ADDRESS + 0x04))
#define   STK_VAL          *((volatile u32*)(STK_BASE_ADDRESS + 0x08))
#define   STK_CALIB        *((volatile u32*)(STK_BASE_ADDRESS + 0x0C))

#define  STK_CLK_SOURCE    AHB_div_8
#define  AHB         1
#define  AHB_div_8   0


#define   STK_SINGLE_INTERVAL       0
#define   STK_PERIODIC_INTERVAL     1

#endif
