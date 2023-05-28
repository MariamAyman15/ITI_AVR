/*
 * MUSART_int.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Mariam
 */

#ifndef MCAL_USART_MUSART_INT_H_
#define MCAL_USART_MUSART_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void MUSART_voidInit (void);
void MUSART_voidTransmitDataSynch (u8 copy_u8Data);
u8 MUSART_u8ReceiveDataSynch (void);
void MUSART_voidTransmitDataASynch (u8 copy_u8Data);

#endif /* MCAL_USART_MUSART_INT_H_ */
