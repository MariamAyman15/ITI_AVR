/*
 * MUSART_prv.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Mariam
 */

#ifndef MCAL_USART_MUSART_PRV_H_
#define MCAL_USART_MUSART_PRV_H_

#define UDR     *((volatile u8*)0x2C)
#define UCSRA   *((volatile u8*)0x2B)
#define UCSRB   *((volatile u8*)0x2A)
#define UCSRC   *((volatile u8*)0x40) //u16
#define  UBRR
#define UBRRL   *((volatile u8*)0x29)
#define UBRRH   *((volatile u8*)0x40) //u16

//UCSRA BITS
#define RXC   7  //receive complete
#define TXC   6  //transmit complete
#define UDRE  5  //data reg is empty
#define FE    4  //frame error
#define DOR   3  //dat over run
#define PE    2  //parity error
#define U2X   1  //double transmission speed
#define MPCM  0  //multi-processor communication mode

//UCSRB BITS
#define RXCIE  7  //rx complete interrupt enable
#define TXCIE  6  //tx complete interrupt enable
#define UDRIE  5  //data reg empty interrupt enable
#define RXEN   4  //rx enable
#define TXEN   3  //tx enable
#define UCSZ2  2  //character size
#define RXB8   1  //rx data bit 8
#define TXB8   0  //tx data bit 8

//UCSRC BITS
#define UCPOL            0  //clock polarity
#define UCSZ0            1  //char size
#define UCSZ1            2  //char size
#define  USBS            3  //stop bit select
#define  UPM0            4  //parity mode
#define  UPM1            5  //parity mode
#define UMSEL            6  //mode select
#define URSEL            7  //reg select

//BAUDRATE EQUATION RESULT
#define BAUD_EQU_RESULT ((((F_OSC)/(16*BAUDRATE_VAL))-1)

#endif /* MCAL_USART_MUSART_PRV_H_ */
