/*
 * Application.h
 *
 * Created: 10/3/2022 9:07:10 AM
 *  Author: ibrah
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

/************************************************************************/
/*includes                                                                     */
/************************************************************************/
#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/Interrupts.h"
#include "../MCAL/Timer/timer.h"

/************************************************************************/
/*Macros                                                                     */
/************************************************************************/
#define GREEN 0
#define YELLOW 1
#define RED  2


/************************************************************************/
/* Utilities                                                                     */
/************************************************************************/

void appStart();
void blink(uint8_t LED, uint8_t pedLED);


#endif /* APPLICATION_H_ */