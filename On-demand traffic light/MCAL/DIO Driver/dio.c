/*
 * CFile1.c
 *
 * Created: 9/3/2022 5:54:03 PM
 *  Author: ibrah
 */ 
// including .h
#include "dio.h"
// global variables 
// function definitions
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)	//Initialize DIO direction
{
	switch(portNumber)
	{
	//*************case A**********
		case PORT_A:
			if(direction == IN)
			{ 
				DDRA &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRA |= (1<<pinNumber);
			}
			else {
				// error handling
			}
		break;
	//*************case B**********
		case PORT_B:
			if(direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
			else if (direction == OUT)
			{
				DDRB |= (1<<pinNumber);
			}
			else {
				// error handling
			}
			break;
	//*************case C**********
		case PORT_C:
				if(direction == IN)
				{
					DDRC &= ~(1<<pinNumber);
				}
				else if (direction == OUT)
				{
					DDRC |= (1<<pinNumber);
				}
				else {
					// error handling
				}
			break;
	//*************case D**********
		case PORT_D:
				if(direction == IN)
				{
					DDRD &= ~(1<<pinNumber);
				}
				else if (direction == OUT)
				{
					DDRD |= (1<<pinNumber);
				}
				else {
					// error handling
				}
		break;
	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value) //write data to DIO
{
	switch(portNumber)
	{
	//*************case A**********
		case PORT_A:
			if(value == LOW)
			{ 
				PORTA &= ~(1<<pinNumber); // write 0 
			}
			else if (value  == HIGH)
			{
				PORTA |= (1<<pinNumber); // write 1 
			}
			else {
				// error handling
			}
		break;
	//*************case B**********
		case PORT_B:
			if(value == LOW)
			{
				PORTB &= ~(1<<pinNumber);
			}
			else if (value == HIGH)
			{
				PORTB |= (1<<pinNumber);
			}
			else {
				// error handling
			}
			break;
	//*************case C**********
		case PORT_C:
				if(value == LOW)
				{
					PORTC &= ~(1<<pinNumber);
				}
				else if (value == HIGH)
				{
					PORTC |= (1<<pinNumber);
				}
				else {
					// error handling
				}
			break;
	//*************case D**********
		case PORT_D:
				if(value == LOW)
				{
					PORTD &= ~(1<<pinNumber);
				}
				else if (value == HIGH)
				{
					PORTD |= (1<<pinNumber);
				}
				else {
					// error handling
				}
		break;
	}
}
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber) // toggle DIO
{
	switch (portNumber)
	{
		case PORT_A:
			PORTA ^= (1<<pinNumber);
		break;
		case PORT_B:
			PORTB ^= (1<<pinNumber);
		break;
		case PORT_C:
			PORTC ^= (1<<pinNumber);
		break;
		case PORT_D:
			PORTD ^= (1<<pinNumber);
		break;
		default:
		//error handling
		break;			
	}
}

uint8_t DIO_read(uint8_t portNumber,uint8_t pinNumber, uint8_t* value) // read DIO
{
	switch(portNumber)
	{
		case PORT_A:
			*value = (PINA & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
			*value = (PINB & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
			*value = (PINC & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
			*value = (PIND & (1<<pinNumber))>>pinNumber;
		break;
		default:
		//error handling
		break;
	}
			return 0;

}