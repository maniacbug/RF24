/*
 * remote_defines.h
 *
 *  Created on: May 9, 2013
 *      Author: joao
 */

#ifndef REMOTE_DEFINES_H_
#define REMOTE_DEFINES_H_

#define COM_DRV_ZERO		690
#define COM_DRV_FRONT		784
#define COM_DRV_REAR		598
#define COM_SERVO_ZERO		645
#define COM_SERVO_RIGHT		733
#define COM_SERVO_LEFT		537
#define ADC_TH			10

#define DRV_ZERO		0
#define DRV_REAR		-99
#define DRV_FRONT		99

#define ADC_ANALOG_LEFT		3
#define ADC_ANALOG_RIGHT	0

#define SEND_MSG_TIME		80

#define ASK_BIT			0x10

typedef struct ROSpberryRemote
{
	int16_t linear;
	int16_t steer;
	uint8_t buttons;

}RC_remote;


typedef struct Analog_properties
{
	int max;
	int min;
	int center;
	int deadzone;
}Analog;

#endif /* REMOTE_DEFINES_H_ */
