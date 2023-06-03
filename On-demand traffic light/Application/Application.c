/*
 * Application.c
 *
 * Created: 10/3/2022 9:06:53 AM
 *  Author: ibrah
 */ 
#include "Application.h"
uint8_t LED =GREEN;
uint8_t pedLED = RED;



	
ISR(EXT_INT_0)
{
	switch(LED)
	{ 
		//****************** green case ****************************
		case GREEN:
		LED_off(PORT_A,LED);
		//pedestrian red led on for 1 sec
		pedLED = RED;	
		LED_on(PORT_B,pedLED);
		// pedestrian led and car's led is yellow
		pedLED = YELLOW;
		LED = YELLOW;
		blink(LED,pedLED);
		LED_off(PORT_B,RED);
		
		// pedestrian led is green car's led is red
		pedLED = GREEN;
		LED = RED;
		LED_on(PORT_A,LED);
		LED_on(PORT_B, pedLED);
		T0_delay(19,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		pedLED = YELLOW;
		LED = YELLOW;
		//blink for 5 secs
		blink(LED,pedLED);
		LED_off(PORT_B, GREEN);
		
		//Last operation 
		LED = GREEN;
		pedLED = RED;
		LED_on(PORT_A,LED);
		LED_on(PORT_B,pedLED);
		T0_delay(19,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_B,pedLED);
		break;
		
		//***************** yellow case ************************
		case YELLOW:
		LED_off(PORT_A,LED);
		//pedestrian red led on for 1 sec
		pedLED = RED;
		LED_on(PORT_B,pedLED);
		// pedestrian led and car's led is yellow
		pedLED = YELLOW;
		LED = YELLOW;
		blink(LED,pedLED);
		LED_off(PORT_B,RED);
		LED_off(PORT_A,LED);
		
		// pedestrian led is green car's led is red
		pedLED = GREEN;
		LED = RED;
		LED_on(PORT_A,LED);
		LED_on(PORT_B, pedLED);
		T0_delay(19,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		pedLED = YELLOW;
		LED = YELLOW;
		//blink for 5 sec
		blink(LED,pedLED);
		LED_off(PORT_B, GREEN);
		
		//Last operation
		LED = GREEN;
		pedLED = RED;
		LED_on(PORT_A,LED);
		LED_on(PORT_B,pedLED);
		T0_delay(19,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_B,pedLED);
		LED_off(PORT_A,LED);
		LED = YELLOW;
		break;
		
		// *********************** red case *********************
		case RED:
		LED = RED;
		pedLED = GREEN;
		LED_on(PORT_A, LED);
		LED_on(PORT_B, pedLED);
		T0_delay(19,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_B,pedLED);
		break;
		
		default:
		//error
		break;		
	}
startTimer(TIMER_1024_PRESCALAR);
}

void blink(uint8_t LED, uint8_t pedLED)
{
	//1
	LED_on(PORT_B,pedLED);
	LED_on(PORT_A, LED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	LED_off(PORT_B,pedLED);
	LED_off(PORT_A,LED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	//2
	LED_on(PORT_A, LED);
	LED_on(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	LED_off(PORT_A,LED);
	LED_off(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	//3
	LED_on(PORT_A, LED);
	LED_on(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	LED_off(PORT_A,LED);
	LED_off(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	//4
	LED_on(PORT_A, LED);
	LED_on(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	LED_off(PORT_A,LED);
	LED_off(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	//5
	LED_on(PORT_A, LED);
	LED_on(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	LED_off(PORT_A,LED);
	LED_off(PORT_B,pedLED);
	T0_delay(2,TIMER_1024_PRESCALAR,12);
	
}
	
void appStart()
{
	//enabling global interrupt
	sci();
	//initializing EXTI0
	BUTTON_init(PORT_D,2);
	EXTI0_init();
	EXTI0_ISC(faling_edge);
	
	//1. LED initialization
	LED_init(PORT_A, GREEN);
	LED_init(PORT_A, YELLOW);
	LED_init(PORT_A, RED);
	LED_init(PORT_B, GREEN);
	LED_init(PORT_B, YELLOW);
	LED_init(PORT_B, RED);
	while(1)
	{
		//2. start normal mode 
		//********* green on *********************
		LED = GREEN;
		LED_on(PORT_A,LED); //turn on led 0
		T0_delay(19, TIMER_1024_PRESCALAR,12); //5sec delay
		LED_off(PORT_A,LED);
					
		//*********** yellow on ******************
		LED = YELLOW;
		//1 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//2 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//3 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//4 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		//5 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//********* red on ************************
		LED = RED;
		LED_on(PORT_A, LED);
		T0_delay(19, TIMER_1024_PRESCALAR,12); //5sec delay
		LED_off(PORT_A,LED);
					
		//********* yellow on *********************
		LED = YELLOW;
		//1 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//2 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//3 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
					
		//4 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		//5 delay
		LED_on(PORT_A, LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
		LED_off(PORT_A,LED);
		T0_delay(2,TIMER_1024_PRESCALAR,12);
	
	}
}