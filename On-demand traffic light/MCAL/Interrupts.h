/*
 * Interrupts.h
 *
 * Created: 9/14/2022 3:22:45 PM
 *  Author: ibrah
 */ 

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
/************************************************************************/
/* includes                                                                     */
/************************************************************************/
#include "registers.h"
/************************************************************************/
/* Vectors                                                                     */
/************************************************************************/
#define EXT_INT_0 __vector_1	//external interrupt 0
#define EXT_INT_1 __vector_2	// external interrupt 1
#define EXT_INT_2 __vector_3	// external interrupt 2

#define TIMER0_ISR_VECTOR_OVERFLOW			__vector_11	 //timer interrupt 0	
#define TIMER0_ISR_VECTOR_COMPARE			__vector_10	 // timer0 compare  

//set global interrupt
#define sci()  __asm__ __volatile__ ("sei" ::: "memory");//clear global interrupt#define cli()  __asm__ __volatile__ ("cli" ::: "memory");


/************************************************************************/
/* ISR definition                                                                     */
/************************************************************************/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)




#endif /* INTERRUPTS_H_ */