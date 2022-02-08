/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 11/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : LCD       ***/
/********************************************************/


/*lib layer*/
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#define  F_CPU     8000000UL
#include <util/delay.h>
/*MCAL layer*/
#include"DIO_interface.h"

/*HAL layer*/
#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"



void LCD_voidInit       (void)
{
	_delay_ms(35);
#if  LCD_U8_MODE== LCD_U8_8_BIT_MODE
	/*send cmnd */
	LCD_voidSendCmnd(0b00111000);
#elif LCD_U8_MODE== LCD_U8_4_BIT_MODE
	
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN ,LOW);
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN ,LOW);
	Private_voidWriteHalfPort(0b0010);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);	
	LCD_voidSendCmnd(0b00101000);
	
#endif
	_delay_us(45);
	/*display on /off control*/
	LCD_voidSendCmnd(0b00001111);/*display on , blink on, cursor on */
	_delay_us(45);
	LCD_voidSendCmnd(0b00000001);/*clear display*/
	_delay_ms(2);
	/*entry mode set*/
	LCD_voidSendCmnd(0b00000110);

}

void LCD_voidSendCmnd       (u8 copy_u8Cmnd)
{
#if  LCD_U8_MODE== LCD_U8_8_BIT_MODE
	/*RS =0,R/W =0*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN ,LOW);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN ,LOW);
	/*write cmnd on date pins*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Cmnd);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);	
#elif LCD_U8_MODE== LCD_U8_4_BIT_MODE
	/*RS =0,R/W =0*/
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN ,LOW);
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN ,LOW);
	/*send most 4 bits*/
	Private_voidWriteHalfPort(copy_u8Cmnd>>4);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);		
	/*send least 4 bits*/
	Private_voidWriteHalfPort(copy_u8Cmnd);
	/*unable pulse*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);	
#endif
	
	
}   
void LCD_voidSendChar   (u8 copy_u8Char)
{
#if  LCD_U8_MODE== LCD_U8_8_BIT_MODE
	/*RS =1,R/W =0*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,HIGH);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,LOW);
	/*write cmnd on date pins*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Char);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);		
#elif LCD_U8_MODE== LCD_U8_4_BIT_MODE
	/*RS =1,R/W =0*/
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN ,HIGH);
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN ,LOW);
	/*send most 4 bits*/
	Private_voidWriteHalfPort(copy_u8Char>>4);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);		
	/*send least 4 bits*/
	Private_voidWriteHalfPort(copy_u8Char);
	/*unable pulse*/
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_u8_EN_PORT,LCD_u8_EN_PIN,LOW);
	_delay_ms(1);	
#endif
}


void LCD_voidGoToXY     (u8 copy_u8Line,u8 copy_u8Col)
{

	switch(copy_u8Line)
	{
		case LCD_U8_LINE1 :
		   LCD_voidSendCmnd(0x80 + copy_u8Col);
		break;
		case LCD_U8_LINE2 :
		   LCD_voidSendCmnd(0xc0 + copy_u8Col);
		break;		
	}
	
}

void LCD_voidClear      (void)
{
	
	 LCD_voidSendCmnd(0x01);
	
	
}

static void Private_voidWriteHalfPort(u8 copy_u8Value)
{
	u8 local_u8BitValue = GET_BIT(copy_u8Value,0);
	if(local_u8BitValue == LOW)
	{
	    DIO_u8SetPinValue(LCD_u8_D4_PORT ,LCD_u8_D4_PIN,LOW);
	}
	else
	{
	    DIO_u8SetPinValue(LCD_u8_D4_PORT ,LCD_u8_D4_PIN,HIGH);		
	}
    local_u8BitValue = GET_BIT(copy_u8Value,1);
	if(local_u8BitValue == LOW)
	{
	    DIO_u8SetPinValue(LCD_u8_D5_PORT ,LCD_u8_D5_PIN,LOW);
	}
	else
	{
	    DIO_u8SetPinValue(LCD_u8_D5_PORT ,LCD_u8_D5_PIN,HIGH);		
	}
	local_u8BitValue = GET_BIT(copy_u8Value,2);
	if(local_u8BitValue == LOW)
	{
	    DIO_u8SetPinValue(LCD_u8_D6_PORT ,LCD_u8_D6_PIN,LOW);
	}
	else
	{
	    DIO_u8SetPinValue(LCD_u8_D6_PORT ,LCD_u8_D6_PIN,HIGH);		
	}
	local_u8BitValue = GET_BIT(copy_u8Value,3);
	if(local_u8BitValue == LOW)
	{
	    DIO_u8SetPinValue(LCD_u8_D7_PORT ,LCD_u8_D7_PIN,LOW);
	}
	else
	{
	    DIO_u8SetPinValue(LCD_u8_D7_PORT ,LCD_u8_D7_PIN,HIGH);		
	}
}


void LCD_voidSendStr        (u8 *copy_u8PSTR)
{
	u8 i=0;
	while(copy_u8PSTR[i] !='\0')
	{
		LCD_voidSendChar(copy_u8PSTR[i]);
		i++;

	}

}


void LCD_voidSendNum    (u32 copy_u8Num)
{
	u32 local_s32ArrValue[32],local_s32ArrSwap[32];
	u32 local_u32NumberOfDigits=0;
	u32 local_u8Counter1 =0,local_u8Counter2 =0;
	while(copy_u8Num !=0)/*get ascii of each digit*/
	{
		local_u32NumberOfDigits ++;
		local_s32ArrValue[local_u8Counter1] = (copy_u8Num % 10) + '0' ;
		copy_u8Num /= 10;
		local_u8Counter1 ++;

	}
	/*revers local_s32ArrValue */
	while(local_u32NumberOfDigits >0)
	{
		local_s32ArrSwap[local_u8Counter2]= local_s32ArrValue[local_u32NumberOfDigits -1];
		local_u8Counter2 ++;
		local_u32NumberOfDigits --;
	}

	LCD_voidSendStr(local_s32ArrSwap);



}

void LCD_VidWriteNum(u32 Copy_u8Num)
{
	if(Copy_u8Num <=9 &&Copy_u8Num >=0)
	{
		LCD_voidSendChar(Copy_u8Num + 48);
	}

	else
	{ u16 i=0;

	  while(Copy_u8Num%10==0)
	  {
		i++;
		Copy_u8Num=Copy_u8Num/10;
	  }

		u32 Local_u16rev=0;
		while(Copy_u8Num>0)
		{
			Local_u16rev=Local_u16rev*10+Copy_u8Num %10;
			Copy_u8Num=Copy_u8Num/10;

		}
		while(Local_u16rev>0)
		{
			LCD_voidSendChar(48+(Local_u16rev % 10));
			Local_u16rev=Local_u16rev/10;

		}
//		while(i>0)
//		{
//			LCD_voidSendChar('0');
//			i--;
//		}
//

	}
}

