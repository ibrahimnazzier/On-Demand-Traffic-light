#ifndef REGISTERS_H
#define REGISTERS_H

#include "types.h" 
/************************************************************************/
/* Port A registers                                                     */
/************************************************************************/
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
/************************************************************************/
/* Port B register                                                                     */
/************************************************************************/
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

/************************************************************************/
/* Port C registers                                                                     */
/************************************************************************/
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

/************************************************************************/
/* Port D registers                                                                     */
/************************************************************************/
// port D registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

/************************************************************************/
/* Timer0 Registers                                                                      */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)
#define OCR0 *((volatile uint8_t*)0x5C)
#define TIMSK *((volatile uint8_t*)0x59)
/************************************************************************/
/* Timer1 registers                                                                     */
/************************************************************************/
#define TCCR1A *((volatile uint8_t*)0x4F)
#define TCCR1B *((volatile uint8_t*)0x4E)


/************************************************************************/
/* Timer2 Registers                                                              */
/************************************************************************/
#define TCCR2 *((volatile uint8_t*)0x45)
#define TCNT2 *((volatile uint8_t*)0x44)
#define OCR2 *((volatile uint8_t*)0x43)

/************************************************************************/
/* Interrupt                                                                     */
/************************************************************************/
#define GICR *((volatile uint8_t*)0x5B)
#define MCUCR *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define SREG *((volatile uint8_t*)0x5F)


#endif