/*
 * flash.cpp
 *
 *  Created on: Jun 10, 2013
 *      Author: joao
 */
#include <msp430.h>
#include "flash.h"

void flash_init(void)
{
	FCTL2 = FWKEY + FSSEL0 + FN1;             // MCLK/3 for Flash Timing Generator
}

void write_SegC (unsigned char values[], uint8_t dim)
{
	char *Flash_ptr;                          // Flash pointer
	unsigned int i;

	Flash_ptr = (char *) 0x1040;              // Initialize Flash pointer
	FCTL1 = FWKEY + ERASE;                    // Set Erase bit
	FCTL3 = FWKEY;                            // Clear Lock bit
	*Flash_ptr = 0;                           // Dummy write to erase Flash segment

	FCTL1 = FWKEY + WRT;                      // Set WRT bit for write operation

	for (i=0; i<64; i++)
	{
		if(i < dim)
		{
			*Flash_ptr++ = values[i];          // Write value to flash
		}
		else
		{
			*Flash_ptr++ = 0;
		}
	}

	FCTL1 = FWKEY;                            // Clear WRT bit
	FCTL3 = FWKEY + LOCK;                     // Set LOCK bit
}

void read_SegC (unsigned char values[], uint8_t dim, uint8_t offset)
{
	char *Flash_ptr;                          // Flash pointer
	unsigned int i;

	if(64 - offset - dim > 0)
	{
		Flash_ptr = (char *) (0x1040 + offset);   // Initialize Flash pointer
		FCTL1 = FWKEY + ERASE;                    // Set Erase bit
		FCTL3 = FWKEY;                            // Clear Lock bit

		for (i=0; i<dim; i++)
		{
			values[i] = *Flash_ptr++;          // Write value to flash
		}

		FCTL3 = FWKEY + LOCK;                     // Set LOCK bit
	}
}
