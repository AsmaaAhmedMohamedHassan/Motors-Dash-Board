/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 11/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : LCD       ***/
/********************************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H



#define   LCD_U8_LINE1    1
#define   LCD_U8_LINE2    2

void LCD_voidInit       (void);

void LCD_voidSendCmnd       (u8 copy_u8Cmnd);
void LCD_voidSendChar       (u8 copy_u8Char);
void LCD_voidClear          (void);
void LCD_voidGoToXY         (u8 copy_u8Line,u8 copy_u8Col);
void LCD_voidSendStr        (u8 *copy_u8PSTR);
void LCD_voidSendNum        (u32 copy_u8Num);
void LCD_VidWriteNum        (u32 Copy_u8Num);


#endif
