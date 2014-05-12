/*
 * flash.h
 *
 *  Created on: Jun 10, 2013
 *      Author: joao
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "stdint.h"

// Function prototypes
void flash_init(void);
void write_SegC (unsigned char value[], uint8_t dim);
void read_SegC (unsigned char values[], uint8_t dim,  uint8_t offset = 0);

#endif /* FLASH_H_ */
