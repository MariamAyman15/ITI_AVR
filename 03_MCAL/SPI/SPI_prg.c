/*
 * SPI_prg.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Mariam
 */
#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_int.h"
#include "../DIO/DIO_prv.h"

void MSPI_voidInit (void)
{
	SET_BIT(SPCR,5);  //send from LSB first

	#if   SPI_MODE == MASTER
	SET_BIT (SPCR , 4); //MASTER MODE

	CLR_BIT(SPCR , 2);  //clock polarity and phase
	CLR_BIT(SPCR , 3);

    SET_BIT(SPCR,1);   //set prescaller to 128
    SET_BIT(SPCR,0);

	#elif SPI_MODE == SLAVE
	CLR_BIT (SPCR ,4); //MASTER MODE

	#endif

	SET_BIT(SPCR,6);
}
void MSPI_voidSendData (u16 copy_u8Data)
{
	SPDR = copy_u8Data;
	while (GET_BIT(SPSR , 7) == 0);
}
u16 MSPI_u8RecieveData (void)
{
	while (GET_BIT(SPSR , 7) == 0);
	return SPDR;
}
