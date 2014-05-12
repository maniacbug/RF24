/*
 * This file is part of the libemb project.
 *
 * Copyright (C) 2011 Stefan Wendler <sw@kaltpost.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SERIALRB_H_
#define _SERIALRB_H_

/**
 * Type of elements to be enqued in the ringbuffer.
 */
#define SERIAL_RB_Q         unsigned char

/**
 * Definiton of a ringbuffer.
 */
typedef struct {
	/**
 	 * Pointer to the memory where the buffer resides.
 	 */
    SERIAL_RB_Q *buffer;

	/**
 	 * Pointer to the current read position within the buffer.
 	 */
    SERIAL_RB_Q *read;

	/**
 	 * Pointer to the current write position within the buffer.
 	 */
    SERIAL_RB_Q *write;

	/**
 	 * Max. number of elements that fit into buffer (buffer size). 
 	 */
    unsigned short elements;

	/**
 	 * Number of elements currently queued in the buffer.
 	 */
    unsigned short entries;
} serial_rb;

/**
 * Return the number of free elements in a given buffer.
 *
 * @return	number of free elements in the buffer
 */
unsigned short serial_rb_free(serial_rb *rb);

/**
 * Check if given buffer is full (out of free elements).
 *
 * @return 	1 if full, 0 otherwise
 */
int serial_rb_full(serial_rb *rb);

/**
 * Check if given buffer is empty.
 *
 * @return 	1 if empty, 0 otherwise
 */
int serial_rb_empty(serial_rb *rb);

/**
 * Initialize a given ringbuffer by assigning the given buffer with the number
 * of given elements.
 *
 * @param		*rb			the ringbuffer to initialize
 * @param[in]	*buffer		the buffer to assign to this rb (must be allocated!)
 * @param[in]	elements	number of elements which could be stored in buffer
 */
void serial_rb_init(serial_rb *rb, SERIAL_RB_Q *buffer, unsigned short elements);

/**
 * Write a given element to a given buffer. Check if buffer has space left
 * before adding a new element with {@link serial_rb_full).
 *
 * @param		*rb			the ringbuffer to initialize
 * @param[in]	element		the element to add
 */
void serial_rb_write(serial_rb *rb, SERIAL_RB_Q element);

/**
 * Read element from a given buffer. Check if buffer has elements stored 
 * before reading with {@link serial_rb_empty).
 *
 * @param		*rb			the ringbuffer to initialize
 * @param[in]	element		the element to add
 */
SERIAL_RB_Q serial_rb_read(serial_rb *rb);

#endif // _SERIALRB_H_
