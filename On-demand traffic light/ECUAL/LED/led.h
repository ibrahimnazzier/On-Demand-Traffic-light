/*
 * led.h
 *
 * Created: 9/4/2022 4:41:02 PM
 *  Author: ibrah
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"
// macros 
#define LED_1_PORT PORT_A
#define LED_1_PIN PIN1
// Utilities
void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */