/*
 * TWI_prv.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mariam
 */

#ifndef MCAL_TWI_TWI_PRV_H_
#define MCAL_TWI_TWI_PRV_H_

#define TWBR   *((volatile u8*)0x20)
#define TWCR   *((volatile u8*)0x56)
#define TWSR   *((volatile u8*)0x21)
#define TWDR   *((volatile u8*)0x23)
#define TWAR   *((volatile u8*)0x22)  //SLAVE ADDRESS

//TWBR BITS bit rate reg
#define TWBR7    7
#define TWBR6    6
#define TWBR5    5
#define TWBR4    4
#define TWBR3    3
#define TWBR2    2
#define TWBR1    1
#define TWBR0    0

//TWCR BITS control reg
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

//TWSR BITS STATUS
#define TWS7  7
#define TWS6  6
#define TWS5  5
#define TWS4  4
#define TWS3  3
#define TWPS1 1
#define TWPS0 0

//TWDR DATA REG
#define TWD7 7
#define TWD6 6
#define TWD5 5
#define TWD4 4
#define TWD3 3
#define TWD2 2
#define TWD1 1
#define TWD0 0

//TWAR SLAVE REG
#define TWA6 7
#define TWA5 6
#define TWA4 5
#define TWA3 4
#define TWA2 3
#define TWA1 2
#define TWA0 1
#define TWGCE 0

//status code for master transmitter
#define START_ACK                 0x08
#define REP_START_ACK             0x10
#define MSTR_ACK_RECEIVED         0x18
#define MSTR_NACK_RECEIVED        0x20
#define MSTR_ACK_RECEIVED_DATA    0x28
#define MSTR_NACK_RECEIVED_DATA   0x30
#define ARBITRATION_LOST          0x38

//status code for master receiver
#define MSTR_ACK_RECEIVED_SLAR    0x40
#define MSTR_NACK_RECEIVED_SLAR   0x48
#define MSTR_ACK_RETURNED_DATA    0x50
#define MSTR_NACK_RETURNED_DATA   0x58

//status code for slave transmitter
//status code for slave receiver

#define Checking_Mask  0xf8
#endif /* MCAL_TWI_TWI_PRV_H_ */
