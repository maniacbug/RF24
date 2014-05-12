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

#ifndef __NRF24L01_H_
#define __NRF24L01_H_

#include "nrf24l01_hw.h"
#include "nrf24l01_regs.h"

/**
 * Maximum payload size the NRF is able to send in bytes.
 */
#define NRF_MAX_PAYLOAD		32

/**
 * Primery mode TX
 */
#define NRF_MODE_PTX		0

/**
 * Primery mode RX
 */
#define NRF_MODE_PRX		1

/**
 * Retry delay for auto retransmit 250us
 */
#define	NRF_RT_DELAY_250	0

/**
 * Retry delay for auto retransmit 500us
 */
#define NRF_RT_DELAY_500	1

/**
 * Retry delay for auto retransmit 750us
 */
#define NRF_RT_DELAY_750	2

/**
 * Retry delay for auto retransmit 1000us
 */
#define NRF_RT_DELAY_1000	3

/**
 * Retry delay for auto retransmit 1250us
 */
#define NRF_RT_DELAY_1250	4

/**
 * Retry delay for auto retransmit 1500us
 */
#define NRF_RT_DELAY_1500	5

/**
 * Retry delay for auto retransmit 1750us
 */
#define NRF_RT_DELAY_1750	6

/**
 * Retry delay for auto retransmit 2000us
 */
#define NRF_RT_DELAY_2000	7

/**
 * Retry delay for auto retransmit 2250us
 */
#define NRF_RT_DELAY_2250	8

/**
 * Retry delay for auto retransmit 2500us
 */
#define NRF_RT_DELAY_2500	9

/**
 * Retry delay for auto retransmit 2750us
 */
#define NRF_RT_DELAY_2750	10

/**
 * Retry delay for auto retransmit 3000us
 */
#define NRF_RT_DELAY_3000	11

/**
 * Retry delay for auto retransmit 3250us
 */
#define NRF_RT_DELAY_3250	12

/**
 * Retry delay for auto retransmit 3500us
 */
#define NRF_RT_DELAY_3500	13

/**
 * Retry delay for auto retransmit 3750us
 */
#define NRF_RT_DELAY_3750	14

/**
 * Retry delay for auto retransmit 4000us
 */
#define NRF_RT_DELAY_4000	15

/**
 * Error code for max retry reached
 */
#define NRF_ERR_MAX_RT		(-1)

/**
 * Error code for TX buffer full
 */
#define NRF_ERR_TX_FULL		(-2)

/**
 * Error code for RX buffer full
 */
#define NRF_ERR_RX_FULL		(-3)

/**
 * Definition of payload send through the device.
 */
typedef struct {

     /**
      * Payload size in bytes (must not exceed NRF_MAX_PAYLOAD]).
      */
     unsigned char size;

     /**
      * The payload.
      */
     unsigned char data[NRF_MAX_PAYLOAD];
} nrf_payload;

/**
 * Read contents of a register form the nRF24l01.
 *
 * @param[in]   reg	register to read (see NRF_REG_* form nrf24l01_regs.h)
 * @param[out] *buf	the value(s) read from the register
 * @return 			number of bytes read from the register
 */
int nrf_read_reg(unsigned char reg, nrf_reg_buf *buf);

/**
 * Write contents of a register to the nRF24l01.
 *
 * @param[in]  reg	register to write (see NRF_REG_* form nrf24l01_regs.h)
 * @param[in] *buf	the value(s) to write the register
 * @return 			number of bytes written to the register
 */
int nrf_write_reg(unsigned char reg, nrf_reg_buf *buf);

/**
 * Send payload non-blocking through the nRF24l01.
 *
 * @param[in] *payload	the payload to send
 * @return 				number of bytes sent or NRF_ERR_TX_FULL if TX buffer is full
 * 						or NRF_ERR_MAX_RT if auto ACK with retry was enabled and
 * 						payload was not delivered after configured retrys
 */
int nrf_send(nrf_payload *payload);

/**
 * Send payload blocking through the nRF24l01.
 *
 * @param[in] *payload	the payload to send
 * @return 				number of bytes sent or NRF_ERR_TX_FULL if TX buffer is full
 * 						or NRF_ERR_MAX_RT if auto ACK with retry was enabled and
 * 						payload was not delivered after configured retrys
 */
int nrf_send_blocking(nrf_payload *payload);

/**
 * Receive payload non-blocking from nRF24l01.
 *
 * @param	*payload	the payload received, "size" member of payload
 * 						must be set to correct payload size (as configured for nRF)
 * @return				number of bytes received or NRF_ERR_RX_FULL when RX buffer is full
d
 */
int nrf_receive(nrf_payload *payload);

/**
 * Receive payload blocking from nRF24l01.
 *
 * @param	*payload	the payload received, "size" member of payload
 * 						must be set to correct payload size (as configured for nRF)
 * @return				number of bytes received or NRF_ERR_RX_FULL when RX buffer is full
 */
int nrf_receive_blocking(nrf_payload *payload);

/**
 * Set ACK payload for a given pipe to be sent back in ESB mode with ACK-payload.
 *
 * @param[in]	*payload	ACK payload to send back on next RX
 * @return 					number of bytes sent
 */
int nrf_write_ack_pl(nrf_payload *payload, unsigned char pipe);

/**
 * Read ACK payload received as response to the last TX request (only ESB mode with
 * ACK-payload enabled).
 *
 * @param[out]	*payload	ACK payload received
 * @return 					number of bytes received
 */
int nrf_read_ack_pl(nrf_payload *payload);

/**
 * Preset configuration to configure the nRF24l01 into SB (Shock Burst) mode.
 *
 * @param[in]	mode	primery device mode: NRF_MODE_PRX for RX, or NRF_MODE_PTX for TX
 * @param[in]	rf_ch	RF channel to use
 * @param[in]	pw		payload width in bytes (must not exceed NRF_MAX_PAYLOAD)
 * @param[in]	*addr	Address to use for TX and RX on pipe 0
 */
void nrf_preset_sb(unsigned char mode, unsigned char rf_ch, unsigned char pw, nrf_reg_buf *addr);

/**
 * Preset configuration to configure the nRF24l01 into ESB (Enhenced Shock Burst) mode.
 *
 * @param[in]	mode	primery device mode: NRF_MODE_PRX for RX, or NRF_MODE_PTX for TX
 * @param[in]	rf_ch	RF channel to use
 * @param[in]	pw		payload width in bytes (must not exceed NRF_MAX_PAYLOAD)
 * @param[in]	rert	number of retrys for receiving ACK
 * @param[in]	delay	delay to wait before next retry (one of NRF_RT_DELAY_*)
 * @param[in]	*addr	Address to use for TX and RX on pipe 0
 */
void nrf_preset_esb(unsigned char mode, unsigned char rf_ch, unsigned char pw, unsigned char retr, unsigned char delay, nrf_reg_buf *addr);

/**
 * Preset configuration to configure the nRF24l01 into ESB (Enhenced Shock Burst) mode with
 * enabled ACL payload.
 *
 * @param[in]	mode	primery device mode: NRF_MODE_PRX for RX, or NRF_MODE_PTX for TX
 * @param[in]	rf_ch	RF channel to use
 * @param[in]	pw		payload width in bytes (must not exceed NRF_MAX_PAYLOAD)
 * @param[in]	rert	number of retrys for receiving ACK
 * @param[in]	delay	delay to wait before next retry (one of NRF_RT_DELAY_*)
 * @param[in]	*addr	Address to use for TX and RX on pipe 0
 */
void nrf_preset_esbpl(unsigned char mode, unsigned char rf_ch, unsigned char pw, unsigned char retr, unsigned char delay, nrf_reg_buf *addr);

#endif
