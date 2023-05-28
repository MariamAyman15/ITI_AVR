#ifndef TIMER0_TIMER0_PRV_H_
#define TIMER0_TIMER0_PRV_H_

/*REGISTERS ADDRESS*/
#define TCCR0_REG             (*((volatile u8*)0x53))
#define TCNT0_REG             (*((volatile u8*)0x52))
#define  OCR0_REG             (*((volatile u8*)0x5C))
#define TIMSK_REG             (*((volatile u8*)0x59))
#define  TIFR_REG             (*((volatile u8*)0x58))
#define SFIOR_REG             (*((volatile u8*)0x50))

/*TCCR0 REG BITS */
#define FOC0_BIT  7
#define WGM00_BIT 6
#define COM01_BIT 5
#define COM00_BIT 4
#define WGM01_BIT 3
#define  CS02_BIT 2
#define  CS01_BIT 1
#define  CS00_BIT 0

/*TIMSK REG BITS*/
#define OCIE0_BIT  1
#define TOIE0_BIT  0

/*TIFR REG BITS*/
#define  OCF_BIT   1
#define TOV0_BIT   0

/*SFIOR REG BITS*/
#define PSR10_BIT 0


#define     INERVERTING   1
#define NON_INERVERTING   0

#endif /* TIMER0_TIMER0_PRV_H_ */
