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

#ifndef __NRF24L01REGS_H_
#define __NRF24L01REGS_H_

/*
 * Setting this to 1 enables compilation of meta information
 * for the registers. Meta information contains readable register
 * names which could be used for debugging or displaying.
 * <br/><br/>
 * NOTE: Use "-DNRF_REG_DEF_META" compiler switch from makefile
 * is the preferred way to set this flag.
 */
// #define NRF_REG_DEF_META		1

/**
 * Maximum number of bytes needed to store register information (largest
 * block of data to be read from nNRF is the address register with 5 bytes).
 */
#define NRF_MAX_REG_BUF			5

/*
 * NRF2041 Registers
 */

#define NRF_REG_CONFIG			0x00
#define NRF_REG_EN_AA			0x01
#define NRF_REG_EN_RXADDR		0x02
#define NRF_REG_SETUP_AW		0x03
#define NRF_REG_SETUP_RETR		0x04
#define NRF_REG_RF_CH			0x05
#define NRF_REG_RF_SETUP		0x06
#define NRF_REG_STATUS			0x07
#define NRF_REG_OBSERVE_TX		0x08
#define NRF_REG_CD				0x09
#define NRF_REG_RX_ADDR_P0		0x0A
#define NRF_REG_RX_ADDR_P1		0x0B
#define NRF_REG_RX_ADDR_P2		0x0C
#define NRF_REG_RX_ADDR_P3		0x0D
#define NRF_REG_RX_ADDR_P4		0x0E
#define NRF_REG_RX_ADDR_P5		0x1F
#define NRF_REG_TX_ADDR			0x10
#define NRF_REG_RX_PW_P0		0x11
#define NRF_REG_RX_PW_P1		0x12
#define NRF_REG_RX_PW_P2		0x13
#define NRF_REG_RX_PW_P3		0x14
#define NRF_REG_RX_PW_P4		0x15
#define NRF_REG_RX_PW_P5		0x16
#define NRF_REG_FIFO_STATUS		0x17
// N/A							0x18
// N/A							0x19
// N/A							0x1A
// N/A							0x1B
#define NRF_REG_DYNPD			0x1C
#define NRF_REG_FEATURE			0x1D

/*
 * NRF2401 Register Fields
 */

// CONFIG
#define NRF_REGF_PRIM_RX			0
#define NRF_REGF_PWR_UP				1
#define NRF_REGF_CRCO				2
#define NRF_REGF_EN_CRC				3
#define NRF_REGF_MASK_MAX_RT		4
#define NRF_REGF_MASK_TX_DS			5
#define NRF_REGF_MASK_RX_DR			6

// EN_AA
#define NRF_REGF_ENAA_P0			0
#define NRF_REGF_ENAA_P1			1
#define NRF_REGF_ENAA_P2			2
#define NRF_REGF_ENAA_P3			3
#define NRF_REGF_ENAA_P4			4
#define NRF_REGF_ENAA_P5			5

// EN_RXADDR
#define NRF_REGF_ERX_P0				0
#define NRF_REGF_ERX_P1				1
#define NRF_REGF_ERX_P2				2
#define NRF_REGF_ERX_P3				3
#define NRF_REGF_ERX_P4				4
#define NRF_REGF_ERX_P5				5

// SETUP_AW
#define NRF_REGF_AW					0

// SETUP_RETR
#define NRF_REGF_ARC				0
#define NRF_REGF_ARD				1

// RF_CH
#define NRF_REGF_RF_CH				0

// RF_SETUP
#define NRF_REGF_LNA_HCURR			0
#define NRF_REGF_RF_PWR				1
#define NRF_REGF_RF_DR				2
#define NRF_REGF_PLL_LOCK			3

// STATUS
#define NRF_REGF_TX_FULL			0
#define NRF_REGF_RX_P_NO			1
#define NRF_REGF_MAX_RT				2
#define NRF_REGF_TX_DS				3
#define NRF_REGF_RX_DR				4

// OBSERVE_TX
#define NRF_REGF_ARC_CNT			0
#define NRF_REGF_PLOS_CNT			1

// CD
#define NRF_REGF_CD					0

// ADDR
#define NRF_REGF_ADDR_A				0
#define NRF_REGF_ADDR_B				1
#define NRF_REGF_ADDR_C				2
#define NRF_REGF_ADDR_D				3
#define NRF_REGF_ADDR_E				4

// RX_PW
#define NRF_REGF_PW					0

// FIFO_STATUS
#define NRF_REGF_FIFO_RX_EMPTY		0
#define NRF_REGF_FIFO_RX_FULL		1
#define NRF_REGF_FIFO_TX_EMPTY		4
#define NRF_REGF_FIFO_TX_FULL		5
#define NRF_REGF_FIFO_TX_REUSE		6

// DYNPD
#define NRF_REGF_DPL_P0			0
#define NRF_REGF_DPL_P1			1
#define NRF_REGF_DPL_P2			2
#define NRF_REGF_DPL_P3			3
#define NRF_REGF_DPL_P4			4
#define NRF_REGF_DPL_P5			5

// FEATURE
#define NRF_REGF_EN_DYN_ACK		0
#define NRF_REGF_EN_ACK_PAY		1
#define NRF_REGF_EN_DPL			2

/**
 * Defines how many bits make up a certain value in the register.
 */
typedef struct {
#ifdef NRF_REG_DEF_META
     /**
      * If META is enabled, the readable name for the bit fiels.
      */
     char 			*name;
#endif
     /**
      * Number of bits which make up that field.
      */
     unsigned char	 size;
#ifdef NRF_REG_DEF_META
     /**
      * Defines if the bit field is read-/writable. If set to 1,
      * it means read+write access is allowd, otherwise only read
      * access is possible to that field.
      */
     unsigned char	 rw;
#endif
} nrf_reg_bits;

typedef struct {
     unsigned char 	 count;
     nrf_reg_bits	 data[];
} nrf_reg_fields;

/**
 * Definitoin of a register.
 */
typedef struct {
#ifdef NRF_REG_DEF_META
     /**
      * If META is enabled, the readable name for the register.
      */
     char 			*name;
#endif
     /**
      * Size of the register in bytes.
      */
     unsigned char 	 size;

     /**
      * Array of bit-fields which make up this register.
      */
     nrf_reg_fields	*fields;
} nrf_reg;

/**
 * Definition of all available registers on the nRF24l01.
 */
typedef struct {
     /**
      * Number of registers in the "data" array.
      */
     unsigned char count;

     /**
      * Array with registers on the nRF24l01.
      */
     nrf_reg data[];
} nrf_regs;

/**
 * Buffer used to store the data for reading/writing a register.
 */
typedef struct {
     /**
      * Number of bytes to read/write from/to the
      * "data" array.
      */
     unsigned char size;

     /**
      * The data to read/write to/from the register.
      */
     unsigned char data[NRF_MAX_REG_BUF];
} nrf_reg_buf;

/**
 * Fields of the CONFIG register.
 */
extern nrf_reg_fields nrf_reg_config_fields;

/**
 * Fields of the ENAA register.
 */
extern nrf_reg_fields nrf_reg_enaa_fields;

/**
 * Fields of the EN_RXADDR register.
 */
extern nrf_reg_fields nrf_reg_enrxaddr_fields;

/**
 * Fields of the SETUP_AW register.
 */
extern nrf_reg_fields nrf_reg_setupaw_fields;

/**
 * Fields of the SETUP_RETR register.
 */
extern nrf_reg_fields nrf_reg_setupretr_fields;

/**
 * Fields of the RF_CH register.
 */
extern nrf_reg_fields nrf_reg_rfch_fields;

/**
 * Fields of the RF_SETUP register.
 */
extern nrf_reg_fields nrf_reg_rfsetup_fields;

/**
 * Fields of the STATUS register.
 */
extern nrf_reg_fields nrf_reg_status_fields;

/**
 * Fields of the OBSERVE_TX register.
 */
extern nrf_reg_fields nrf_reg_observetx_fields;

/**
 * Fields of the CD register.
 */
extern nrf_reg_fields nrf_reg_cd_fields;

/**
 * Fields of the ADDR register.
 */
extern nrf_reg_fields nrf_reg_addr_fields;

/**
 * Fields of the RX_PW register.
 */
extern nrf_reg_fields nrf_reg_rxpw_fields;

/**
 * Fields of the FIFO_STAT register.
 */
extern nrf_reg_fields nrf_reg_fifostat_fields;

/**
 * Fields of the DYNPD register.
 */
extern nrf_reg_fields nrf_reg_dynpd_fields;

/**
 * Fields of the FEATURE register.
 */
extern nrf_reg_fields nrf_reg_feature_fields;

/**
 * Complete register definition for the nNRF24l01.
 */
extern nrf_regs nrf_reg_def;

/**
 * Extract the value of a given field for a given register out of the
 * given buffer and return it. The buffer has to be read by nrf_read_reg
 * first.
 *
 * @param[in]	reg		the register definition to use for extracting (one of NRF_REG_*)
 * @param[in]	regf	the field definition to use for extracting (one of NRF_REGF_*)
 * @param[in]	*buf	the buffer containing the content of the register
 * @return				the value extracted for the field
 */
unsigned char nrf_get_reg_field(unsigned char reg, unsigned char regf, nrf_reg_buf *buf);

/**
 * Write a value  to a given field for a given register into the
 * given buffer. The buffer has to be read by nrf_read_reg
 * first, and written back by nrf_write_reg.
 *
 * @param[in]	reg		the register definition to use for extracting (one of NRF_REG_*)
 * @param[in]	regf	the field definition to use for extracting (one of NRF_REGF_*)
 * @param[out]	*buf	the buffer to write the field value to
 * @param[in]	value	the value to write to the field
 * @return				the value extracted for the field
 */
void nrf_set_reg_field(unsigned char reg, unsigned char regf, nrf_reg_buf *buf, unsigned char value);

#endif
