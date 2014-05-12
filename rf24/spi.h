/*
 * spi.h
 *
 *  Created on: Apr 21, 2013
 *      Author: bgouveia
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

void spi_init(unsigned long bitrate,unsigned long datawidth);
uint8_t spi_transferByte(uint8_t data);

void spi_cs_low();
void spi_cs_high();

void spi_ce_low();
void spi_ce_high();

void delay(unsigned long msec);
void delayMicroseconds(unsigned long usec);


#endif /* SPI_H_ */
