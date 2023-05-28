/*
 * EEPROM_int.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Mariam
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_

#define EEPROM_FIRST_4BITS 0x50   //0b1010 0000
//INIT
void HEEPROM_voidInit(void);
//WRITE DATA BYTE
void HEEPROM_voidWriteDataByte(u8 Copy_u8DataByte, u16 Copy_u16Adress);
//READ DATA BYTE
void HEEPROM_voidReadDataByte (u8 *Copy_u8PtrData,u16 Copy_u16Adress);

#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
