/*
 * main.cpp
 *
 *  Created on: May 6, 2013
 *      Author: joao
 */


#include "rf24/RF24.h"
#include <msp430.h>
#include "remote_defines.h"
#include "flash.h"
#include <math.h>

extern "C"
{
#include "conio/conio.h"
#include "serial/serial.h"
#include "timer_msp.h"
}

#define BLINK_RED_LED	P2OUT ^= BIT1;


unsigned long int last_blink_millis = 0;

typedef struct
{
	uint8_t var1;
	uint8_t var2;
	uint8_t var3;
	uint8_t var4;

}payload;

payload var;

// main loop
int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	BCSCTL1 = CALBC1_8MHZ;            // Set DCO to 1MHz
	DCOCTL = CALDCO_8MHZ;

	uint32_t last_millis = 0;

	P2DIR |= BIT1 + BIT0;
//
//	serial_init(9600);

	default_timer();
	__bis_SR_register(GIE);

	RF24 radio = RF24();

	var.var1 = 20;


	while(millis() < 1000);

	// Radio pipe addresses for the 2 nodes to communicate.
	const uint64_t pipes[] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

	// Setup and configure rf radio
	radio.begin();

	// optionally, increase the delay between retries & # of retries
	radio.setRetries(15,1);

	// optionally, reduce the payload size.  seems to
	// improve reliability
	radio.setPayloadSize(sizeof(payload));

	radio.setDataRate(RF24_250KBPS);

	radio.setChannel(100);
	radio.setPALevel(RF24_PA_LOW);

	// Open pipes to other nodes for communication
	radio.openWritingPipe(pipes[0]);
	radio.openReadingPipe(1,pipes[1]);



	// Start listening
	radio.startListening();

	// Dump the configuration of the rf unit for debugging
	radio.printDetails();

	uint32_t dif = 0;
	var.var3 = dif/10;

	//radio.setPALevel(RF24_PA_MAX);
	while(1)
	{


		if( millis()- last_millis > 100)
		{
			last_millis = millis();
			BLINK_RED_LED;

			radio.startListening();
			radio.stopListening();

			var.var2 = last_millis / 1000;


			radio.write(&var, sizeof(payload));

			dif = (millis()- last_millis) / 10;
			var.var3 = dif;

		}

	}



	return 0;


}

