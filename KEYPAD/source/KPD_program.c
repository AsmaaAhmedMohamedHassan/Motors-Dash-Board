/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 13/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : KPD       ***/
/********************************************************/


/*lib layer*/
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#define  F_CPU     8000000UL
#include <util/delay.h>

/*MCAL layer*/
#include"DIO_interface.h"

/*HAL layer*/
#include"KPD_interface.h"
#include"KPD_private.h"
#include"KPD_config.h"




u8 KPD_u8GetSwitch(u8 *copy_Pu8ReturenedSwitch)
{
	u8 local_u8ReturnStet = STD_TYPES_OK ;
	u8 local_u8PinValue,flag=0;
	static u8 local_Au8RowsPinArr[KPD_U8_ROWS_NUM] = KPD_U8_ROWS_PINS;
	static u8 local_Au8ColsPinArr[KPD_U8_COLS_NUM] = KPD_U8_COLS_PINS;
	static u8 local_Au8KPDValue[KPD_U8_ROWS_NUM][KPD_U8_COLS_NUM] = KPD_U8_KEYS ;
	if(copy_Pu8ReturenedSwitch != NULL)
	{                      
        *copy_Pu8ReturenedSwitch = KPD_U8_NOT_PRESSED;
		for(u8 local_u8RowsCounter=0 ;local_u8RowsCounter<KPD_U8_ROWS_NUM;local_u8RowsCounter++)
		{
			/*activate each row*/
			DIO_u8SetPinValue(KPD_U8_ROWS_PORT,local_Au8RowsPinArr[local_u8RowsCounter],LOW);
			/*loop for cols pin check*/
			for(u8 local_u8ColsCounter=0 ;local_u8ColsCounter<KPD_U8_COLS_NUM;local_u8ColsCounter++)
			{
				/*check col activate*/
				DIO_u8GetPinValue(KPD_U8_COLS_PORT,local_Au8ColsPinArr[local_u8ColsCounter],&local_u8PinValue);
				if(local_u8PinValue == LOW)
				{
					*copy_Pu8ReturenedSwitch = local_Au8KPDValue[local_u8RowsCounter][local_u8ColsCounter];
					while(local_u8PinValue == LOW)
					{
						DIO_u8GetPinValue(KPD_U8_COLS_PORT,local_Au8ColsPinArr[local_u8ColsCounter],&local_u8PinValue);
					}
					flag =1 ;
					break;
				}
			}
			/*deactivate row*/
			DIO_u8SetPinValue(KPD_U8_ROWS_PORT,local_Au8RowsPinArr[local_u8RowsCounter],HIGH);
			if(flag ==1)
			{
				break;
			}
		}
		
		
		
		
	}
	else
	{
		local_u8ReturnStet = STD_TYPES_NOK ;
	}
    return local_u8ReturnStet;
	
}
