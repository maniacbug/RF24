/*
 * timer_msp.h
 *
 *  Created on: 30 de Dez de 2012
 *      Author: Asus
 */

#ifndef TIMER_MSP_H_
#define TIMER_MSP_H_

struct timer_msp
{
	unsigned long int ms;
	unsigned long int s;
	unsigned int millis_var;
};

void default_timer(void);
unsigned long int millis(void);

#ifndef DELAY_MSP430
void delay(unsigned long msec);
void delayMicroseconds(unsigned long usec);
#endif

extern struct timer_msp timer0;

#endif /* TIMER_MSP_H_ */
