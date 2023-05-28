#ifndef LCD_INT_H
#define LCD_INT_H

#define HLCD_8BIT_MODE                0
#define HLCD_4BIT_MODE                1

void HLCD_voidInit (void);
void HLCD_voidCLRScreen(void);
void HLCD_voidSendData (u8 copy_u8Data);
void HLCD_voidSendCommand (u8 copy_u8Command);
void HLCD_voidGoToXy (u8 Copy_u8XPosition, u8 Copy_u8YPosition); //set position
void HLCD_voidSendString (const char *copy_ps8str); //send string
void HLCD_SendSpecialChar (u8 *copy_ps8arr, u8 copy_u8Pattern_num , u8 Copy_u8XPosition , u8 Copy_u8YPosition );
void HLCD_voidSendNumber(s32 Copy_s32Number);

#endif
