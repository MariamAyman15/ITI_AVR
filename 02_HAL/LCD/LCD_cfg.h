/*
 * LCD_cfg.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Mariam
 */

#ifndef LCD_CFG_H
#define LCD_CFG_H

#define LCD_Mode   HLCD_4BIT_MODE

#define HLCD_DATA_PORT PORTC
#define HLCD_PIN4 PIN4  //4 bit mode
#define HLCD_PIN5 PIN5
#define HLCD_PIN6 PIN6
#define HLCD_PIN7 PIN7

#define HLCD_CTRL_PORT PORTD
#define HLCD_RS_PIN PIN0
#define HLCD_RW_PIN PIN1
#define HLCD_EN_PIN PIN2


#endif /* HAL_LCD_LCD_CFG_H_ */
