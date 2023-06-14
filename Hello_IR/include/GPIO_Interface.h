/***************************************************************/
/***************  Author : Mona El_saied ***********************/
/**************** Layer  : MCAL     ****************************/
/**************** Driver : GPIO  ******************************/
/**************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/***********************************************   PROTOTYPES FUNCTIONS (GPIO)  *******************************************/


/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Mode : INPUT ,OUTPUT , AF , ANALOG*/
void GPIO_voidSetPinDirectionMode(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Mode);
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Type : PUSH_PULL  , OPEN DRAIN*/
void GPIO_voidSetPinType(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Type);
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Speed : low  , medium  , high  , very high*/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Speed);
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8PullState :  3 options  no , pull up  , pull down */
void GPIO_voidSetPinPullState(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PullState);
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8VALUE  : LOW    , HIGH */
// WRITE DATA 
void GPIO_voidSetPinValueNonAtomic(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Value);
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8SenceLevel : SET   , RST */
void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8SenceLevel);
/*  Copy_u8PortId : GPIOA , GPIOB ,GPIOC */
/*  Copy_u8PinId : 0->15*/
/*  Func to read & return var : 1 , 0 */
u8  GPIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);

/*********************************************************************************/
// used in DAC
void Data(u32 copy_data);

/********************************************************************************************************************************/
/********************************************************************************************************************************/


/********* INIT PORTS A-B-C***********/
#define    GPIOA      0
#define    GPIOB      1
#define    GPIOC      2

/*******PINS 0 -> 15 ************/

#define   PIN0          0
#define   PIN1          1
#define   PIN2          2
#define   PIN3          3
#define   PIN4          4
#define   PIN5          5
#define   PIN6          6
#define   PIN7          7
#define   PIN8          8
#define   PIN9          9
#define   PIN10         10
#define   PIN11         11
#define   PIN12         12
#define   PIN13         13
#define   PIN14         14
#define   PIN15         15


/***************** OPTIONS OF OUTPUT REG (MODER)**************/
#define   INPUT     0
#define   OUTPUT    1
#define   AF        2
#define   ANALOG    3

/****** OPTIONS OF OUTPUT REG (TYPE)**************/
/* PUSH PULL  , OPEN DRAIN*/
#define   OUTPUT_PP      0
#define   OUTPUT_OD      1

/******* OPTIONS OF OUTPUT REG (Speed)*/
#define   OUTPUT_LS      0
#define   OUTPUT_MS      1
#define   OUTPUT_HS      2
#define   OUTPUT_VHS     3

/************ OPTIONS OF atomic value ***********/
#define    SET   0
#define    RST   1
/************ OPTIONS OF NON atomic value ***********/
#define   VAL_LOW      0
#define   VAL_HIGH     1

/************ OPTIONS OF PULL UP / PULL DOWN ***********/
#define    NO_PULL_UP_PULL_DOWN    0
#define    PULL_UP                 1
#define    PULL_DOWN               3
    // There are 4 th  type in data sheet  reserved




#endif
