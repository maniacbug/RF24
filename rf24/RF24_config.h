
/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

#ifndef __RF24_CONFIG_H__
#define __RF24_CONFIG_H__

#include <stddef.h>

// Stuff that is normally provided by Arduino
#ifdef ARDUINO
#include <SPI.h>
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif
#elif defined(MSP430)
#include <msp430.h>
extern "C"{
#include "conio/conio.h"
#include "timer_msp.h"
}
#include <stdint.h>
#include <stdio.h>
#include <string.h>
//extern HardwareSPI SPI;
#define _BV(x) (1<<(x))
#else
#include <stdint.h>
#include <stdio.h>
#include <string.h>
//extern HardwareSPI SPI;
#define _BV(x) (1<<(x))
#endif

#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
#define IF_SERIAL_DEBUG(x) ({x;})
#else
#define IF_SERIAL_DEBUG(x)
#endif

// Avoid spurious warnings
#if 1
#if ! defined( NATIVE ) && defined( ARDUINO )
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))
#undef PSTR
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
#endif
#endif

// Progmem is Arduino-specific
#ifdef ARDUINO
#include <avr/pgmspace.h>
#define PRIPSTR "%S"
#elif defined(STELLARIS)
extern "C"{
#include "utils/uartstdio.h"
extern uint32_t millis();
#define printf_P UARTprintf
}
typedef uint16_t prog_uint16_t;
#define PSTR(x) (x)
#define strlen_P strlen
#define PROGMEM
#define pgm_read_word(p) (*(p))
#define PRIPSTR "%s"

#elif defined(MSP430)

//extern unsigned long int millis();
#define PSTR(x) (x)			//ver isto
#define strlen_P strlen
#define printf_P cio_printf
#define PROGMEM
#define pgm_read_word(p) (*(p))
#define PRIPSTR "%s"

#else
typedef char const char;
typedef uint16_t prog_uint16_t;
#define PSTR(x) (x)
#define printf_P printf
#define strlen_P strlen
#define PROGMEM
#define pgm_read_word(p) (*(p)) 
#define PRIPSTR "%s"
#endif

#ifndef ARDUINO

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#endif

#endif // __RF24_CONFIG_H__
// vim:ai:cin:sts=2 sw=2 ft=cpp
