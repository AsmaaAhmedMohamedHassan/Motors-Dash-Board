/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 6/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : DIO       ***/
/********************************************************/


#ifndef  DIO_PRIVATE_H
#define  DIO_PRIVATE_H

#define  DIO_U8_PORTA_REG       *((volatile u8 *)0x3B)
#define  DIO_U8_DDRA_REG        *((volatile u8 *)0x3A)
#define  DIO_U8_PINA_REG        *((volatile u8 *)0x39)

#define  DIO_U8_PORTB_REG       *((volatile u8 *)0x38)
#define  DIO_U8_DDRB_REG        *((volatile u8 *)0x37)
#define  DIO_U8_PINB_REG        *((volatile u8 *)0x36)



#define  DIO_U8_PORTC_REG       *((volatile u8 *)0x35)
#define  DIO_U8_DDRC_REG        *((volatile u8 *)0x34)
#define  DIO_U8_PINC_REG        *((volatile u8 *)0x33)




#define  DIO_U8_PORTD_REG       *((volatile u8 *)0x32)
#define  DIO_U8_DDRD_REG        *((volatile u8 *)0x31)
#define  DIO_U8_PIND_REG        *((volatile u8 *)0x30)



#define  DIO_U8_INITIAL_INPUT          0
#define  DIO_U8_INITIAL_OUTPUT         1

#define    DIO_U8_OUTPUT_HIGH          1
#define    DIO_U8_OUTPUT_LOW           0
#define    DIO_U8_INPUT_FLOATING       0
#define    DIO_U8_INPUT_PULLUP         1


#define  conc(b7,b6,b5,b4,b3,b2,b1,b0)       conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define  conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0 
 
 
#endif