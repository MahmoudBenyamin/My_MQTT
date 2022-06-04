/*==============================================================================================
===============================   - GPIO_private.h				 ===============================
===============================   - Created:5/4/2022			 ===============================
===============================   - Author: Mahmoud Benyamin     ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

/*===============================================================================================

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*================================================================
	-----> Macros
			*  Base_Address is				0x40023800 
=================================================================*/

#define GPIOA_BASE_ADDRESS     0x40020000
#define GPIOB_BASE_ADDRESS     0x40020400
#define GPIOC_BASE_ADDRESS     0x40020800
#define GPIOD_BASE_ADDRESS     0x40020C00
#define GPIOE_BASE_ADDRESS     0x40021000
#define GPIOH_BASE_ADDRESS     0x40021C00
/*================================================================*/
typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
} GPIO_t;

#define MGPIOA         ((GPIO_t *)(GPIOA_BASE_ADDRESS))
#define MGPIOB         ((GPIO_t *)(GPIOB_BASE_ADDRESS))
#define MGPIOC         ((GPIO_t *)(GPIOC_BASE_ADDRESS))
#define MGPIOD         ((GPIO_t *)(GPIOD_BASE_ADDRESS))
#define MGPIOE         ((GPIO_t *)(GPIOE_BASE_ADDRESS))
#define MGPIOH         ((GPIO_t *)(GPIOH_BASE_ADDRESS))







#endif
