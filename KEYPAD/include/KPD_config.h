/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 13/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : KPD       ***/
/********************************************************/

#ifndef   KPD_CONFIG_H
#define   KPD_CONFIG_H

/* rows output pins*/
#define  KPD_U8_ROWS_PORT      DIO_u8_PORTB
#define  KPD_U8_R1_PIN         DIO_u8_PIN4
#define  KPD_U8_R2_PIN         DIO_u8_PIN5
#define  KPD_U8_R3_PIN         DIO_u8_PIN6
#define  KPD_U8_R4_PIN         DIO_u8_PIN7

/* cols input pins*/
#define  KPD_U8_COLS_PORT      DIO_u8_PORTD
#define  KPD_U8_C1_PIN         DIO_u8_PIN2
#define  KPD_U8_C2_PIN         DIO_u8_PIN3
#define  KPD_U8_C3_PIN         DIO_u8_PIN4
#define  KPD_U8_C4_PIN         DIO_u8_PIN5



#define  KPD_U8_ROWS_NUM       4
#define  KPD_U8_COLS_NUM       4

#define KPD_U8_ROWS_PINS      {KPD_U8_R1_PIN,KPD_U8_R2_PIN,KPD_U8_R3_PIN,KPD_U8_R4_PIN}
#define KPD_U8_COLS_PINS      {KPD_U8_C1_PIN,KPD_U8_C2_PIN,KPD_U8_C3_PIN,KPD_U8_C4_PIN}

#define  KPD_U8_KEYS  {{'1','2','3','+'},\
                       {'4','5','6','-'},\
					   {'7','8','9','*'},\
					   {'0','%','/','='}}






#endif
