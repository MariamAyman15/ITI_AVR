#ifndef EXTI_PRV_H
#define EXTI_PRV_H

#define     MSREG_REG            *((volatile u8*)0x5f)
#define     MGICR_REG            *((volatile u8*)0x5B)
#define     MMCUCR_REG           *((volatile u8*)0x55)
#define     MMCUCSR_REG          *((volatile u8*)0x54)
#define     MGIFR_REG            *((volatile u8*)0x5A)

/*MGIFR_REG BITS*/
//GENERAL INTTERUPT FLAG
#define     INTF1       7  //EX ITN F 1
#define     INTF0       6  //EX ITN F 0
#define     INTF2       5  //EX ITN F 2

/*MGICR_REG BITS*/
//GENERAL INTERRUPT CONTROL
#define     INT1       7  //INT1 ENABLE
#define     INT0       6  //INT0 ENABLE
#define     INT2       5  //INT2 ENABLE

/*MMCUCSR_REG BITS*/
//MCU CONTROL AND STATUS REG
#define     I2C2       6  //INT SENSE CONTROL 2

/*MMCUCR_REG BITS*/
//MCU CONTROL REG
#define     ISC11       3  //INT SENSE CONTROL 1
#define     ISC10       2  //INT SENSE CONTROL 1
#define     ISC01       1  //INT SENSE CONTROL 0
#define     ISC00       0  //INT SENSE CONTROL 0

/*MSREG_REG BITS*/
//STATUS REG
#define     GICR         7  //GLOBAL INTERRUPT
#endif
