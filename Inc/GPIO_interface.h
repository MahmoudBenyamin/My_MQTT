/*======================================================================================
===========================   - GPIO_interface.h			     ===========================
===========================   - Created: 5/4/2022			 ===========================
===========================   - Author: Mahmoud_Benyamin     ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include "STD_TYPES.h"
/*  options for the GPIO ports         */
#define GPIOA 0U
#define GPIOB 1U
#define GPIOC 2U
#define GPIOD 3U
#define GPIOE 4U
#define GPIOH 5U

/* optios for the pins                */
#define PIN0 	0U
#define PIN1 	1U
#define PIN2 	2U
#define PIN3 	3U
#define PIN4 	4U
#define PIN5 	5U
#define PIN6 	6U
#define PIN7 	7U
#define PIN8 	8U
#define PIN9 	9U
#define PIN10	10U
#define PIN11	11U
#define PIN12	12U
#define PIN13	13U
#define PIN14	14U
#define PIN15	15U

/* optios for the mode */
#define  INPUT     (0b00)
#define  GPOUPUT   (0b01)
#define  ALTFN     (0b10)
#define  ANALOG    (0b11)


/* function to set pin mode */
void MGPIO_vSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

/*option for the Output types*/
#define PUSH_PULL 	  0U
#define OPEN_DRAIN    1U

/* function to set pin output type */
void MGPIO_vSetPinOutputType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OType);

/*option for the Output speed*/
#define   LOW_SPEED                 (0b00) 
#define   MEDIUM_SPEED              (0b01) 
#define   HIGH_SPEED                (0b10)
#define   VERY_HIGH_SPEED           (0b11)

/* function to set pin output speed */
void MGPIO_vSetPinOutputSpeed(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OSpeed);

/*option for the Pull type*/
#define NO_PULL       (0b00) 
#define PULL_UP       (0b01) 
#define PULL_DOWN     (0b10)


/* function to set pin Pull type */
void MGPIO_vSetPinPullType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType);

/*function to read pin value */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);


/*function to write pin value */
void MGPIO_vSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);

/*function to write port value */
void MGPIO_vSetPortValue(u8 Copy_u8Port , u16 Copy_u16Value );


/*option to either set or reset pins directly */
#define SET    0U
#define RESET  1U

/*function to write pin value Directly */
void MGPIO_vSetPinValueDirect(u8 Copy_u8Port , u8 Copy_u8Pin,u8 Copy_u8Mode);

/* function to lock pin value */
void MGPIO_vLockpin(u8 Copy_u8Port , u8 Copy_u8Pin);


/* options for Alternate functions */
#define AF0        (0b0000)
#define AF1        (0b0001)
#define AF2        (0b0010)
#define AF3        (0b0011)
#define AF4        (0b0100)
#define AF5        (0b0101)
#define AF6        (0b0110)
#define AF7        (0b0111)
#define AF8        (0b1000)
#define AF9        (0b1001)
#define AF10       (0b1010) 
#define AF11       (0b1011)
#define AF12       (0b1100)
#define AF13       (0b1101)
#define AF14       (0b1110)
#define AF15       (0b1111)

/*function to set pin to alternate function */
void MGPIO_vSetPinAlternateFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AlternateFunction);

void MGPIO_vSendByte(u8 Copy_u8Port , u8 Copy_u8Data , u8 Copy_u8StartPin );


#endif
