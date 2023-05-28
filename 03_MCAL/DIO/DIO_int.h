
#ifndef DIO_INT_H
#define DIO_INT_H
#include "../../LIB/STD_TYPES.h"

//port
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

//pin
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7 

//pin direction
#define PIN_IN   0
#define PIN_OUT  1

//pin value
#define PIN_LOW   0
#define PIN_HIGH  1

//port value
#define PORT_LOW   0
#define PORT_HIGH  (u8)0xff

//port Direction
#define PORT_IN   (u8)0x00
#define PORT_OUT  (u8)0xff

//pin
void MDIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir);
void MDIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value );
u8 MDIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin ); //read

//port
void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Dir);
void MDIO_voidSetPortValue (u8 Copy_u8Port,u8 Copy_u8Value );
u8 MDIO_u8GetPortValue (u8 Copy_u8Port);


//void MDIO_voidSetPullupResistor
void MDIO_voidSetPullupRessistor(u8 Copy_u8Port,u8 Copy_u8Pin);
//void MDIO_voidSetPortPullupResistor( u8 Copy_u8Port);
void MDIO_voidToggleBin (u8 Copy_u8Port,u8 Copy_u8Pin);
#endif
