/*
 * EXTI.c
 *
 * Created: 9/25/2022 11:07:00 PM
 *  Author: ibrah
 */ 
#include "EXTI.h"
/************************************************************************/
/* Init                                                                     */
/************************************************************************/

void EXTI0_init()
{
	GICR |= (1<<6);
}
void EXTI1_init()
{
	GICR |= (1<<7);
}
void EXTI2_init()
{
	GICR |= (1<<5);
}

/************************************************************************/
/* ISC                                                                     */
/************************************************************************/
void EXTI0_ISC(uint8_t sense)
{
	switch (sense)
	{
	case low_level:
	MCUCR |= (1<<2);
	break;
	case any_change:
	MCUCR |= (1<<0);
	break;
	case faling_edge:
	MCUCR |= (1<<1);
	break;
	case rising_edge:
	MCUCR &= 0xFF;
	break;
	default:
	//error
	break;
	}
}
void EXTI1_ISC(uint8_t sense)
{
	switch (sense)
	{
	case low_level:
	MCUCR |= (1<<4);
	break;
	case any_change:
	MCUCR |= (1<<2);
	break;
	case faling_edge:
	MCUCR |= (1<<3);
	break;
	case rising_edge:
	MCUCR &= 0XFC;
	break;
	default:
	//error
	break;
	}
}
void EXTI2_ISC(uint8_t sense)
{
	switch(sense)
	{
		case faling_edge:
		MCUCSR &= ~(1<7);
		break;
		case rising_edge:
		MCUCSR |= 40;
		break; 
	}
}
