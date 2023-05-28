#ifndef EXTI_INT_H
#define EXTI_INT_H
#include "../../LIB/STD_TYPES.h"

#define     EXT_INT0       0   //PD2
#define     EXT_INT1       1   //PD3
#define     EXT_INT2       2   //PB2

#define     LOW_LEVEL               0
#define     ANY_CHANGE              1
#define     FALLING_EDGE            2
#define     RISING_EDGE             3

void EXTI_voidEnableInt ( u8 Copy_u8INT_ID , u8 Copy_u8Sense);
void EXTI_voidDisableInt ( u8 Copy_u8INT_ID);

void EXT_INT_0_SET_CALLBACK (void(*ptr)(void));
void EXT_INT_1_SET_CALLBACK (void(*ptr)(void));
void EXT_INT_2_SET_CALLBACK (void(*ptr)(void));
#endif
