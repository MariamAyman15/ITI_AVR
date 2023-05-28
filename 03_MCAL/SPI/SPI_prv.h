/*
 * SPI_prv.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Mariam
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

//REG MACROS
#define SPCR   *((volatile u16*)0x2D)
#define SPSR   *((volatile u16*)0x2E)
#define SPDR   *((volatile u16*)0x2F)
#endif /* MCAL_SPI_SPI_PRV_H_ */
