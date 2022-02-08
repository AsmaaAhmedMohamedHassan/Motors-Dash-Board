/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 6/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : DIO       ***/
/********************************************************/

#ifndef   DIO_INTERFACE_H
#define   DIO_INTERFACE_H

/*macros for PORT ID*/
#define   DIO_u8_PORTA     0
#define   DIO_u8_PORTB     1 
#define   DIO_u8_PORTC     2
#define   DIO_u8_PORTD     3
/*macros for PIN id*/
#define   DIO_u8_PIN0      0
#define   DIO_u8_PIN1      1
#define   DIO_u8_PIN2      2
#define   DIO_u8_PIN3      3
#define   DIO_u8_PIN4      4
#define   DIO_u8_PIN5      5
#define   DIO_u8_PIN6      6
#define   DIO_u8_PIN7      7

/*macros for PIN direction*/

#define   DIO_u8_INPUT     0
#define   DIO_u8_OUTPUT    1

/*macros for PIN Value*/
#define   LOW              0
#define   HIGH             1

/*macros for port value*/
#define  MAX_PORT_VALUE    255
#define  MIN_PORT_VALUE    0
        
		
void DIO_voidInit(void);		
u8   DIO_u8SetPinDirection  (u8 copy_u8PortId, u8 copy_u8PinId ,u8 copy_u8PinDirection) ;

u8   DIO_u8SetPinValue      (u8 copy_u8PortId, u8 copy_u8PinId ,u8 copy_u8PinValue) ;
 
u8   DIO_u8GetPinValue      (u8 copy_u8PortId, u8 copy_u8PinId ,u8 * copy_Pu8PinValue) ;

u8   DIO_u8SetPortDirection (u8 copy_u8PortId, u8 copy_u8PinDirection) ;

u8   DIO_u8SetPortValue     (u8 copy_u8PortId, u8 copy_u8PortValue) ;

u8   DIO_u8GetPortValue     (u8 copy_u8PortId, u8 * copy_Pu8PortValue) ;

#endif
