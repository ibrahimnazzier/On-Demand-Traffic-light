/*
 * timer.h
 *
 * Created: 9/13/2022 12:32:53 PM
 *  Author: ibrah
 */ 


#ifndef TIMER_H_
#define TIMER_H_
/************************************************************************/
/* Includes                                                                     */
/************************************************************************/
#include "../DIO Driver/dio.h"

/************************************************************************/
/* Macros                                                                     */
/************************************************************************/
#define normal 0
#define PWPM 1 //phase correct PWM mode
#define CTC 2
#define FastPWMmode 3

// for interrupts
#define enable 1
#define disable 0


// for prescaler

#define TIMER_NO_CLOCK_SOURCE   0 // 000
#define TIMER_NO_PRESCALAR      1 // 001
#define TIMER_8_PRESCALAR       2 // 010
#define TIMER_64_PRESCALAR      3 // 011
#define TIMER_256_PRESCALAR     4 // 100
#define TIMER_1024_PRESCALAR    5 // 101
#define EXR_CLK_T0_FALING		6 // 110
#define EXR_CLK_T0_RISING		7 // 111

/************************************************************************/
/*functions deceleration                                                       */
/************************************************************************/
void T0_init(uint8_t timerMode); //mode choosing
void setTimer(uint8_t preload);  // initial value of timer 
void startTimer(uint8_t prescaler);	// prescaler choosing
void stopTimer();	// 
uint8_t getStats();	//
void T0_interrupt(uint8_t value);
void T0_delay(uint8_t overflow, uint8_t prescaler, uint8_t startValue); //delay function
#endif /* TIMER_H_ */