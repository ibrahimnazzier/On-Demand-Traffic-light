/*
 * button.h
 *
 * Created: 9/4/2022 5:10:19 PM
 *  Author: ibrah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
// macros


// button states
#define HIGH 1
#define LOW 0
//functions
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value);



#endif /* BUTTON_H_ */