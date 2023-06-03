/*
 * EXTI.h
 *
 * Created: 9/25/2022 11:07:18 PM
 *  Author: ibrah
 */ 


#ifndef EXTI_H_
#define EXTI_H_
/************************************************************************/
/* Includes                                                                     */
/************************************************************************/
#include "../registers.h"

/************************************************************************/
/* Initialization                                                                    */
/************************************************************************/
void EXTI0_init();
void EXTI1_init();
void EXTI2_init();
/************************************************************************/
/* Interrupt sense control                                                                  */
/************************************************************************/
void EXTI0_ISC(uint8_t sense);
void EXTI1_ISC(uint8_t sense);
void EXTI2_ISC(uint8_t sense);			// choosing interrupt sense 
/************************************************************************/
/* defines                                                                     */
/************************************************************************/
#define low_level   0
#define any_change  1
#define faling_edge 2
#define rising_edge 3
#endif /* EXTI_H_ */