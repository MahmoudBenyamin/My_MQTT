/*=======================================================================================
============================   - GPIO_program.c				 ============================
============================   - Created: 5/4/2022			 ============================
============================   - Author: Mahmoud_Benyamin    ============================
============================   - Version : _1_				 ============================
============================   - Note :  
									     *-
									     *-
=======================================================================================*/ 


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "GPIO_private.h"
		#include "GPIO_interface.h"
		#include "GPIO_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	




/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	- Function To Set pin mode :
	
							       - Copy_u8Port      :  The GPIO Used ( A,B,C,D,E,H  )
							       - Copy_u8Pin 	  :  The pin we use 
							       - Copy_u8Mode       :  The mode(input , general purpose outpt, alternate function , analog)
	
*/
void MGPIO_vSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA :(MGPIOA ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		case GPIOB :(MGPIOB ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		case GPIOC :(MGPIOC ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		case GPIOD :(MGPIOD ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		case GPIOE :(MGPIOE ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		case GPIOH :(MGPIOH ->MODER)|= (u32)(Copy_u8Mode << (2*Copy_u8Pin)); break;
		default: /**/ break;
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinOutputType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OType)
{
	if(Copy_u8OType == PUSH_PULL)
	{
		switch(Copy_u8Port)
		{
			case GPIOA :CLR_BIT(MGPIOA ->OTYPER,Copy_u8Pin);	break;
			case GPIOB :CLR_BIT(MGPIOB ->OTYPER,Copy_u8Pin);	break;
			case GPIOC :CLR_BIT(MGPIOC ->OTYPER,Copy_u8Pin);	break;
			case GPIOD :CLR_BIT(MGPIOD ->OTYPER,Copy_u8Pin);	break;
			case GPIOE :CLR_BIT(MGPIOE ->OTYPER,Copy_u8Pin);	break;
			case GPIOH :CLR_BIT(MGPIOH ->OTYPER,Copy_u8Pin);	break;
			default: /*  */ break;
		}
	}
	else if(Copy_u8OType == OPEN_DRAIN)
	{
		switch(Copy_u8Port)
		{
			case GPIOA :SET_BIT(MGPIOA ->OTYPER,Copy_u8Pin);	break;
			case GPIOB :SET_BIT(MGPIOB ->OTYPER,Copy_u8Pin);	break;
			case GPIOC :SET_BIT(MGPIOC ->OTYPER,Copy_u8Pin);	break;
			case GPIOD :SET_BIT(MGPIOD ->OTYPER,Copy_u8Pin);	break;
			case GPIOE :SET_BIT(MGPIOE ->OTYPER,Copy_u8Pin);	break;
			case GPIOH :SET_BIT(MGPIOH ->OTYPER,Copy_u8Pin);	break;
			default: /*  */ break;
		}
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinOutputSpeed(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OSpeed)
{
	switch(Copy_u8Port)
	{
		case GPIOA :(MGPIOA ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		case GPIOB :(MGPIOB ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		case GPIOC :(MGPIOC ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		case GPIOD :(MGPIOD ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		case GPIOE :(MGPIOE ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		case GPIOH :(MGPIOH ->OSPEEDR)|= (u32)(Copy_u8OSpeed << (2*Copy_u8Pin)); break;
		default: /**/ break;
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinPullType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType)
{
	switch(Copy_u8Port)
	{
		case GPIOA :(MGPIOA ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		case GPIOB :(MGPIOB ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		case GPIOC :(MGPIOC ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		case GPIOD :(MGPIOD ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		case GPIOE :(MGPIOE ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		case GPIOH :(MGPIOH ->PUPDR)|= (u32)(Copy_u8PullType << (2*Copy_u8Pin)); break;
		default: /**/ break;
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	    u8 Local_u8Value = 0;
		switch(Copy_u8Port)
		{
			case GPIOA :Local_u8Value = GET_BIT(MGPIOA ->IDR,Copy_u8Pin);	break;
			case GPIOB :Local_u8Value = GET_BIT(MGPIOB ->IDR,Copy_u8Pin);	break;
			case GPIOC :Local_u8Value = GET_BIT(MGPIOC ->IDR,Copy_u8Pin);	break;
			case GPIOD :Local_u8Value = GET_BIT(MGPIOD ->IDR,Copy_u8Pin);	break;
			case GPIOE :Local_u8Value = GET_BIT(MGPIOE ->IDR,Copy_u8Pin);	break;
			case GPIOH :Local_u8Value = GET_BIT(MGPIOH ->IDR,Copy_u8Pin);	break;
			default: /*  */ break;
		}
		return Local_u8Value;
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
		{
			case GPIOA :SET_BIT(MGPIOA ->ODR,Copy_u8Pin);	break;
			case GPIOB :SET_BIT(MGPIOB ->ODR,Copy_u8Pin);	break;
			case GPIOC :SET_BIT(MGPIOC ->ODR,Copy_u8Pin);	break;
			case GPIOD :SET_BIT(MGPIOD ->ODR,Copy_u8Pin);	break;
			case GPIOE :SET_BIT(MGPIOE ->ODR,Copy_u8Pin);	break;
			case GPIOH :SET_BIT(MGPIOH ->ODR,Copy_u8Pin);	break;
			default: /*  */ break;
		}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPortValue(u8 Copy_u8Port , u16 Copy_u16Value )
{
		switch(Copy_u8Port)
		{
			case GPIOA :(MGPIOA ->ODR |=(u32) Copy_u16Value);	break;
			case GPIOB :(MGPIOB ->ODR |=(u32) Copy_u16Value);	break;
			case GPIOC :(MGPIOC ->ODR |=(u32) Copy_u16Value);	break;
			case GPIOD :(MGPIOD ->ODR |=(u32) Copy_u16Value);	break;
			case GPIOE :(MGPIOE ->ODR |=(u32) Copy_u16Value);	break;
			case GPIOH :(MGPIOH ->ODR |=(u32) Copy_u16Value);	break;
			default: /*  */ break;
		}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinValueDirect(u8 Copy_u8Port , u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	if(Copy_u8Mode == SET)
	{
		switch(Copy_u8Port)
		{
		case GPIOA :(MGPIOA ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOB :(MGPIOB ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOC :(MGPIOC ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOD :(MGPIOD ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOE :(MGPIOE ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOH :(MGPIOH ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
			default: /*  */ break;
		}
	}
	else if(Copy_u8Mode == RESET)
	{
		Copy_u8Pin +=16;
		switch(Copy_u8Port)
		{
		case GPIOA :(MGPIOA ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOB :(MGPIOB ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOC :(MGPIOC ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOD :(MGPIOD ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOE :(MGPIOE ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
		case GPIOH :(MGPIOH ->BSRR)= (u32)(1 << (Copy_u8Pin)); break;
			default: /*  */ break;
		}
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vLockpin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
		{
			case GPIOA : 
					SET_BIT(MGPIOA ->LCKR,16);
					SET_BIT(MGPIOA ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOA ->LCKR,16));
					break;
				/* ********************* */
			case GPIOB : 
					SET_BIT(MGPIOB ->LCKR,16);
					SET_BIT(MGPIOB ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOB ->LCKR,16));
					break;
				/* ********************* */
			case GPIOC : 
					SET_BIT(MGPIOC ->LCKR,16);
					SET_BIT(MGPIOC ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOC ->LCKR,16));
					break;
				/* ********************* */
			case GPIOD : 
					SET_BIT(MGPIOD ->LCKR,16);
					SET_BIT(MGPIOD ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOD ->LCKR,16));
					break;
				/* ********************* */
			case GPIOE : 
					SET_BIT(MGPIOE ->LCKR,16);
					SET_BIT(MGPIOE ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOE ->LCKR,16));
					break;
				/* ********************* */
			case GPIOH : 
					SET_BIT(MGPIOH ->LCKR,16);
					SET_BIT(MGPIOH ->LCKR,Copy_u8Pin);
					while(!GET_BIT(MGPIOH ->LCKR,16));
					break;
				/* ********************* */
			default: /*  */ break;
		}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinAlternateFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AlternateFunction)
{
	if( Copy_u8Pin < 8U)
	{
		switch(Copy_u8Port)
		{
			case GPIOA :(MGPIOA ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOB :(MGPIOB ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOC :(MGPIOC ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOD :(MGPIOD ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOE :(MGPIOE ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOH :(MGPIOH ->AFRL)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			default: /**/ break;
		}
	}
	else 
	{
		Copy_u8Pin %= 8;
		switch(Copy_u8Port)
		{
			case GPIOA :(MGPIOA ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOB :(MGPIOB ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOC :(MGPIOC ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOD :(MGPIOD ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOE :(MGPIOE ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			case GPIOH :(MGPIOH ->AFRH)|= (u32)(Copy_u8AlternateFunction << (4*Copy_u8Pin)); break;
			default: /**/ break;
		}
	}
}
/*====================================================   END_FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/


void MGPIO_vSendByte(u8 Copy_u8Port , u8 Copy_u8Data , u8 Copy_u8StartPin )
{
		switch(Copy_u8Port)
		{
			case GPIOA :(MGPIOA ->ODR =(MGPIOA ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32) (Copy_u8Data << Copy_u8StartPin));	break;
			case GPIOB :(MGPIOB ->ODR =(MGPIOB ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32)(Copy_u8Data << Copy_u8StartPin));	break;
			case GPIOC :(MGPIOC ->ODR =(MGPIOC ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32)(Copy_u8Data << Copy_u8StartPin));	break;
			case GPIOD :(MGPIOD ->ODR =(MGPIOD ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32)(Copy_u8Data << Copy_u8StartPin));	break;
			case GPIOE :(MGPIOE ->ODR =(MGPIOE ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32)(Copy_u8Data << Copy_u8StartPin));	break;
			case GPIOH :(MGPIOH ->ODR =(MGPIOH ->ODR &(u32) ~(0xff << Copy_u8StartPin)) |(u32)(Copy_u8Data << Copy_u8StartPin));	break;
			default: /*  */ break;
		}
}
