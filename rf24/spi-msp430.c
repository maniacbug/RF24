/*
 * spi.c
 *
 *  Created on: Apr 21, 2013
 *      Author: bgouveia
 */

#include <msp430.h>

#include "spi.h"
#include "spi_msp430.h"





void spi_init(unsigned long bitrate,unsigned long datawidth){
	//SSI


	UCB0CTL1 = UCSWRST;

    CS_DIR  |= CS_PIN;
    CS_PORT |= CS_PIN;
    CE_DIR |= CE_PIN;
    CE_PORT|= CE_PIN;

    IRQ_DIR &= ~IRQ_PIN;


  	P1SEL  |= SOMI_PIN + SIMO_PIN + SCLK_PIN;
  	P1SEL2 |= SOMI_PIN + SIMO_PIN + SCLK_PIN;

    // 3-pin, 8-bit SPI master
    UCB0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC;
	UCB0CTL1 |= UCSSEL_2;   // SMCLK

	UCB0CTL1 &= ~UCSWRST;


}

void spi_cs_low()
{
	CS_PORT &= ~CS_PIN;

}

void spi_cs_high()
{
	CS_PORT |= CS_PIN;
}

void spi_ce_low()
{
	CE_PORT &= ~CE_PIN;

}

void spi_ce_high()
{
	CE_PORT |= CE_PIN;
}


uint8_t spi_transferByte(uint8_t data)
{

	    UCB0TXBUF = data;

		// wait for TX
		while (!(IFG2 & UCB0TXIFG));

		return UCB0RXBUF;

}

/*void delay(unsigned long msec)
{
	while(msec--)
	{
		__delay_cycles(1000);
	}
}
void delayMicroseconds(unsigned long usec)
{
	while(usec--)
	{
		__delay_cycles(1);
	}
}*/
