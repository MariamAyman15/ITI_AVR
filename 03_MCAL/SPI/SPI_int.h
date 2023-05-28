/*
 * SPI_int.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Mariam
 */
#include "../../LIB/STD_TYPES.h"
#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

#define MASTER  1
#define SLAVE   2

void MSPI_voidInit (void);
void MSPI_voidSendData (u16 copy_u8Data);
u16 MSPI_u8RecieveData (void);

#endif /* MCAL_SPI_SPI_INT_H_ */
