/*
 * CFile1.c
 *
 * Created: 9/4/2022 5:10:36 PM
 *  Author: ibrah
 */ 
#include "button.h"
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort, buttonPin, IN);
}
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value)
{
	DIO_read(buttonPort, buttonPin, value);
}
