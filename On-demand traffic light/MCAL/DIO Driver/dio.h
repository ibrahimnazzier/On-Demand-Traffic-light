/*
 * dio.h
 *
 * Created: 9/3/2022 5:55:46 PM
 *  Author: ibrah
 */ 


#ifndef DIO_H_
#define DIO_H_

//all internal driver typedefs
#include "../Interrupts.h"

//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// PINS
#define PIN0 0 
#define PIN1 1 
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// direction
#define IN 0 
#define OUT 1
// value
#define LOW 0
#define HIGH 1

// all driver function deceleration
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);	//Initialize DIO direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to DIO
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); // toggle DIO
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t* value); // read DIO

#endif /* DIO_H_ */