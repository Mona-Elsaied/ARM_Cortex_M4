#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


// I NEED HERE NEW FUNCTION TO COLLECT ALL


/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Mode : INPUT ,OUTPUT , AF , ANALOG*/
void GPIO_voidSetPinDirectionMode(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Mode)
{
   /*I/P validation */
   if( (Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15))
   {
       /*Do nothing*/
   }
   else
   {
    switch (Copy_u8Mode)
    {
    case INPUT:   switch (Copy_u8PortId)
                 {
                    
                    // INPUT -> CLR 2 BITS
                    case GPIOA:  CLR_BIT(GPIOA_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case AF:   switch (Copy_u8PortId)
                 {
                    // AF -> SET BIT ONE & CLR BIT TWO
                    case GPIOA:  CLR_BIT(GPIOA_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOA_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOB_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOC_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;


                 }
              
        break;
    case OUTPUT    :   switch (Copy_u8PortId)
                 {
                    // OUTPUT -> CLR BIT ONE & SET  BIT TWO
                    
                    case GPIOA:  SET_BIT(GPIOA_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_MODER , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case ANALOG:   switch (Copy_u8PortId)
                 {
                    // ANALOG  -> SET BIT ONE & SET  BIT TWO
                    case GPIOA:  SET_BIT(GPIOA_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOA_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOB_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_MODER , (Copy_u8PinId*2));
                                 SET_BIT(GPIOC_MODER , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break; 

                 }
              
        break;            

    
    default: /*ERROR*/
        break;
    }

   }

}
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Type : PUSH_PULL  , OPEN DRAIN*/
void GPIO_voidSetPinType(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Type)
{
   /*I/P validation */
   if( (Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15))
   {
       /*Do nothing*/
   }
   else
   {
    switch (Copy_u8Type)
    {
    case OUTPUT_PP:   switch (Copy_u8PortId)
                 {
                    case GPIOA:  CLR_BIT(GPIOA_OTYPER , (Copy_u8PinId));
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_OTYPER , (Copy_u8PinId));
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_OTYPER , (Copy_u8PinId));
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case OUTPUT_OD : switch (Copy_u8PortId)
                 {
                    case GPIOA:  SET_BIT(GPIOA_OTYPER , (Copy_u8PinId));
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_OTYPER , (Copy_u8PinId));
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_OTYPER , (Copy_u8PinId));
                                 break;
                    default :/*ERROR*/ 
                    break;

                 }          
       
        break;            

    default:/*ERROR*/
        break;
    }

   }
}
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*copy_u8Speed : low  , medium  , high  , very high*/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Speed)
{
    /*I/P validation */
   if( (Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15))
   {
       /*Do nothing*/
   }
   else
   {
    switch (Copy_u8Speed)
    {
    case OUTPUT_LS:   switch (Copy_u8PortId)
                 {
                    
                    // OUTPUT_LS -> CLR 2 BITS
                    case GPIOA:  CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case OUTPUT_HS:   switch (Copy_u8PortId)
                 {
                    // OUTPUT_MS -> SET BIT ONE & CLR BIT TWO
                    case GPIOA:  CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;


                 }
              
        break;
    case OUTPUT_MS :   switch (Copy_u8PortId)
                 {
                    // OUTPUT_HS -> CLR BIT ONE & SET  BIT TWO
                    
                    case GPIOA:  SET_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case OUTPUT_VHS:   switch (Copy_u8PortId)
                 {
                    // OUTPUT_VHS  -> SET BIT ONE & SET  BIT TWO
                    case GPIOA:  SET_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOA_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOB_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOC_OSPEEDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break; 

                 }
              
        break;            
    default: /*ERROR*/
        break;
    }

   }

}

/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8PullState :  3 options  no , pull up  , pull down */
void GPIO_voidSetPinPullState(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PullState)
{
      /*I/P validation */
   if( (Copy_u8PortId > GPIOC) || (Copy_u8PinId > PIN15))
   {
       /*Do nothing*/
   }
   else
   {
    switch (Copy_u8PullState)
    {
    case NO_PULL_UP_PULL_DOWN:   switch (Copy_u8PortId)
                 {
                    
                    // NO_PULL_UP_PULL_DOWN  -> CLR 2 BITS
                    case GPIOA:  CLR_BIT(GPIOA_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;

                 }
              
        break;
    case PULL_DOWN:   switch (Copy_u8PortId)
                 {
                    //  PULL_DOWN-> SET BIT ONE & CLR BIT TWO
                    case GPIOA:  CLR_BIT(GPIOA_PUPDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOA_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  CLR_BIT(GPIOB_PUPDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOB_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  CLR_BIT(GPIOC_PUPDR , (Copy_u8PinId*2));
                                 SET_BIT(GPIOC_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;
                 }
              
        break;
    case PULL_UP :
    	       switch (Copy_u8PortId)
                 {
                    // PULL_UP -> CLR BIT ONE & SET  BIT TWO
                    
                    case GPIOA:  SET_BIT(GPIOA_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOA_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOB:  SET_BIT(GPIOB_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOB_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    case GPIOC:  SET_BIT(GPIOC_PUPDR , (Copy_u8PinId*2));
                                 CLR_BIT(GPIOC_PUPDR , (Copy_u8PinId*2)+1);
                                 break;
                    default : /*ERROR*/
                    break;
                 }
              
        break;            
    default:    /*ERROR*/
        break;
    }

   }
}
/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8VALUE  : LOW    , HIGH */
// WRITE DATA 
void GPIO_voidSetPinValueNonAtomic(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Value)
{
    /*I/P validation */
    if ((Copy_u8PortId > GPIOC)  || (Copy_u8PinId > 15) )
    {
        /*DO NOTHING */
    }
    else 
    {
        switch (Copy_u8Value)
        {
        case VAL_LOW :
                     switch (Copy_u8PortId)
                     {
                     case GPIOA:
                       CLR_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;
                      case GPIOB:
                       CLR_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;
                      case GPIOC:
                       CLR_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;      
                     
                     default: /*ERROR*/
                        break;
                     }
            break;

        case VAL_HIGH :
                     switch (Copy_u8PortId)
                     {
                     case GPIOA:
                       SET_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;
                      case GPIOB:
                       SET_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;
                      case GPIOC:
                       SET_BIT(GPIOA_ODR , Copy_u8PinId);
                        break;      
                     
                     default: /*ERROR*/
                        break;
                     }
            break;    
        
        default:  /*ERROR*/
            break;
        }
    }


}

/*copy_u8port : GPIOA , GPIOB ,GPIOC */
/*copy_u8PINS :  0 ->  15*/
/*Copy_u8SenceLevel : SET   , RST */
void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8SenceLevel)
{
    if ((Copy_u8PortId > GPIOC )  || (Copy_u8PinId > 15))
    {
        /*D NOTHING*/
    }
    else 
    {
        switch (Copy_u8SenceLevel)
        {
        case SET:  switch ( Copy_u8PortId )
                    {
                        case GPIOA : GPIOA_BSRR =(1<< Copy_u8PinId);
                        break;
                        case GPIOB : GPIOB_BSRR =(1<< Copy_u8PinId);
                        break;
                        case GPIOC : GPIOC_BSRR =(1<< Copy_u8PinId);
                        break;
                        default : /*ERROR*/
                        break;

                    }
        break;
        
        case RST: 
            switch ( Copy_u8PortId )
                    {
                        case GPIOA : GPIOA_BSRR =(1<< (Copy_u8PinId+16));
                        break;
                        case GPIOB : GPIOB_BSRR =(1<< (Copy_u8PinId+16));
                        break;
                        case GPIOC : GPIOC_BSRR =(1<< (Copy_u8PinId+16));
                        break;
                        default :  /*ERROR*/
                        break;

                    }
            break;
        
        default:  /*ERROR*/
            break;
        
        }

    }

}
/*  Copy_u8PortId : GPIOA , GPIOB ,GPIOC */
/*  Copy_u8PinId : 0->15*/
/*  Func to read & return var : 1 , 0 */
u8  GPIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
      u8 Loc_u8Variable ;
      /*I/P validation */
      if ((Copy_u8PortId >GPIOC) || (Copy_u8PinId >PIN15) )
      {
        /*DO NOTHING*/
      }
      else
      {
        switch (Copy_u8PortId)
        {
        case GPIOA : Loc_u8Variable = GET_BIT(GPIOA_IDR , Copy_u8PinId);
            break;
        case GPIOB : Loc_u8Variable = GET_BIT(GPIOB_IDR , Copy_u8PinId);
            break;
        case GPIOC : Loc_u8Variable = GET_BIT(GPIOC_IDR , Copy_u8PinId);
            break;        
        
        default: /*ERROR*/
            break;
        }
      }

    return Loc_u8Variable;

}
