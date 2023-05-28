/*
 * TIMERS_prv.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */

#ifndef MCAL_TIMERS_TIMERS_PRV_H_
#define MCAL_TIMERS_TIMERS_PRV_H_

/*REGISTERS ADDRESS*/
#define TCCR0_REG             (*((volatile u8*)0x53))
#define TCNT0_REG             (*((volatile u8*)0x52))
#define  OCR0_REG             (*((volatile u8*)0x5C))
#define TIMSK_REG             (*((volatile u8*)0x59))
#define  TIFR_REG             (*((volatile u8*)0x58))
#define SFIOR_REG             (*((volatile u8*)0x50))


/*TCCR0_REG*/

#define FOC0_BIT  7
#define WGM00_BIT 6
#define COM01_BIT 5
#define COM00_BIT 4
#define WGM01_BIT 3
#define  CS02_BIT 2
#define  CS01_BIT 1
#define  CS00_BIT 0


/*TIMSK_REG*/
#define OCIE0_BIT  1
#define TOIE0_BIT  0

/*TIFR_REG*/
#define  OCF_BIT   1
#define TOV0_BIT   0

/*SFIOR_REG*/
#define PSR10_BIT 0

#define INVERTING_MODE      1
#define NON_INVERTING_MODE  2

#endif /* MCAL_TIMERS_TIMERS_PRV_H_ */
