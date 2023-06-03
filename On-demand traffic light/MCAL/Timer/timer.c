/*
 * timer.c
 *
 * Created: 9/13/2022 12:33:17 PM
 *  Author: ibrah
 */
#include "timer.h"
 
void setTimer(uint8_t preload)
	{
			TCNT0 = preload;
	}

void T0_init(uint8_t timerMode)
{
	switch(timerMode)
	{
		case normal:
		TCCR0 = 0x00;
		//TIFR = 0x00;
		break;
		case PWPM:
		TCCR0 |= (1<<0);
		break;
		case CTC:
		TCCR0 |= (1<<4);
		break;
		case FastPWMmode:
		TCCR0 |= 17;
		break;
		default:
		//exception 
		break;
	}
}

uint8_t getStats()
	{
		uint8_t Status = TIFR & (1<<0);
		return Status;
	}
	
void startTimer(uint8_t prescaler)
	{
		switch (prescaler)
		{
			case TIMER_NO_CLOCK_SOURCE:
			TCCR0 =0x00;
			break;
			case TIMER_NO_PRESCALAR:
			TCCR0 |= (1<<0);
			break;
			case TIMER_8_PRESCALAR:
			TCCR0 |= (1<<1);
			break;
			case TIMER_64_PRESCALAR:
			TCCR0 |= 3;
			break;
			case TIMER_256_PRESCALAR:
			TCCR0 |= 4;
			break;
			case TIMER_1024_PRESCALAR:
			TCCR0 |= 5;
			break;
			case EXR_CLK_T0_FALING:
			TCCR0 |= 6;
			break;
			case EXR_CLK_T0_RISING:
			TCCR0 |= 7;
			break;
			default:
			//exception
			break;
		}
	}

void stopTimer()
	{
		TCCR0 &= 0xF8;
	}

void T0_interrupt(uint8_t value)
{
	switch(value)
	{
		case enable:
		TIMSK |= (1<<0);
		break;
		case disable:
		TIMSK &= 0xFE;
		break;
		default:
		//exception
		break;
	}
}
void T0_delay(uint8_t overflow, uint8_t prescaler, uint8_t startValue)
{
	uint8_t OVF_count = overflow;
	T0_init(normal);
	setTimer(startValue);
	//T0_interrupt(enable);
	startTimer(prescaler);
	while(OVF_count>0)
	{
		while ((TIFR & (1<<0))==0);
		TIFR |=(1<<0);
		OVF_count--;
	}
}