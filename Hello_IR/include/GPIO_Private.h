/***************************************************************/
/***************  Author : Mona El_saied ***********************/
/**************** Layer  : MCAL     ****************************/
/**************** Driver : GPIO  ******************************/
/**************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

//ANOTHER WAY TO addresses
/*
typedef struct GPIO
{
    volatile u32  MODER;
    volatile u32  OTYPER;
    volatile u32  OSPEEDR;
    volatile u32  PUPDR;
    volatile u32  IDR;
    volatile u32  ODR;
    volatile u32  BSRR;
    volatile u32  LCKR;
    volatile u32  AFRL;
    volatile u32  AFRH;

}GPIOx_t;

#define    GPIOA       *((GPIOx_t*)0x40020000)
#define    GPIOB       *((GPIOx_t*)0x40020400)
#define    GPIOC       *((GPIOx_t*)0x40020800)

*/


//Registers of GPIO
//3 REGISTERS   

//  GPIOA     0x40020000
#define  GPIOA_MODER           (*(volatile u32*)(0x40020000))
#define  GPIOA_OTYPER          (*(volatile u32*)(0x40020004))
#define  GPIOA_OSPEEDR         (*(volatile u32*)(0x40020008))
#define  GPIOA_PUPDR           (*(volatile u32*)(0x4002000C))
#define  GPIOA_IDR             (*(volatile u32*)(0x40020010))
#define  GPIOA_ODR             (*(volatile u32*)(0x40020014))
#define  GPIOA_BSRR            (*(volatile u32*)(0x40020018))
#define  GPIOA_LCKR            (*(volatile u32*)(0x4002001C))
#define  GPIOA_AFRL            (*(volatile u32*)(0x40020020))
#define  GPIOA_AFRH            (*(volatile u32*)(0x40020024))

//GPIOB 
//BASCE ADDERESS    0x40020400
#define  GPIOB_MODER           (*(volatile u32*)(0x40020400))
#define  GPIOB_OTYPER          (*(volatile u32*)(0x40020404))
#define  GPIOB_OSPEEDR         (*(volatile u32*)(0x40020408))
#define  GPIOB_PUPDR           (*(volatile u32*)(0x4002040C))
#define  GPIOB_IDR             (*(volatile u32*)(0x40020410))
#define  GPIOB_ODR             (*(volatile u32*)(0x40020414))
#define  GPIOB_BSRR            (*(volatile u32*)(0x40020418))
#define  GPIOB_LCKR            (*(volatile u32*)(0x4002041C))
#define  GPIOB_AFRL            (*(volatile u32*)(0x40020420))
#define  GPIOB_AFRH            (*(volatile u32*)(0x40020424))

//GPIOC
//BASCE ADDERESS  0x40020800
#define  GPIOC_MODER           (*(volatile u32*)(0x40020800))
#define  GPIOC_OTYPER          (*(volatile u32*)(0x40020804))
#define  GPIOC_OSPEEDR         (*(volatile u32*)(0x40020808))
#define  GPIOC_PUPDR           (*(volatile u32*)(0x4002080C))
#define  GPIOC_IDR             (*(volatile u32*)(0x40020810))
#define  GPIOC_ODR             (*(volatile u32*)(0x40020814))
#define  GPIOC_BSRR            (*(volatile u32*)(0x40020818))
#define  GPIOC_LCKR            (*(volatile u32*)(0x4002081C))
#define  GPIOC_AFRL            (*(volatile u32*)(0x40020820))
#define  GPIOC_AFRH            (*(volatile u32*)(0x40020824))


#endif
