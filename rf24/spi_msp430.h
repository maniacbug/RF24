/*
 * spi_msp430.h
 *
 *  Created on: May 29, 2013
 *      Author: joao
 */

#ifndef SPI_MSP430_H_
#define SPI_MSP430_H_

#include <msp430.h>

//#define CS_PIN_BASE P1OUT
#define CS_PORT		P2OUT
#define CS_DIR		P2DIR
#define CS_PIN 		BIT2

#define SIMO_PIN    BIT7
#define SOMI_PIN    BIT6
#define SCLK_PIN    BIT5

//#define CE_PIN_BASE P1OUT
#define CE_PIN 		BIT3
#define CE_PORT		P2OUT
#define CE_DIR		P2DIR

#define IRQ_PIN 	BIT3
#define IRQ_PORT	P1OUT
#define IRQ_DIR		P1DIR

#define POWER_DIR	P1DIR
#define POWER_PORT	P1OUT
#define POWER_PIN	BIT1

#endif /* SPI_MSP430_H_ */
