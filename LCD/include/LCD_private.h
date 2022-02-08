/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 11/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : LCD       ***/
/********************************************************/

#ifndef  LCD_PRIVATE_H
#define  LCD_PRIVATE_H

#define LCD_U8_8_BIT_MODE    1
#define LCD_U8_4_BIT_MODE    0
  
void LCD_voidSendCmnd       (u8 copy_u8Cmnd);
void LCD_voidSendChar   (u8 copy_u8Char);

static void Private_voidWriteHalfPort(u8 copy_u8Value);

#endif
