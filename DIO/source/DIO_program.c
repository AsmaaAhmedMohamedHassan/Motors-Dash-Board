/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 6/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : DIO       ***/
/********************************************************/

/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*MCAL layer*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidInit(void)
{
	/*SET PIN DIRECTIONS*/

	DIO_U8_DDRA_REG = conc(DIO_U8_PA7_DIRECTION,DIO_U8_PA6_DIRECTION,DIO_U8_PA5_DIRECTION,DIO_U8_PA4_DIRECTION,
	                       DIO_U8_PA3_DIRECTION,DIO_U8_PA2_DIRECTION,DIO_U8_PA1_DIRECTION,DIO_U8_PA0_DIRECTION);

	DIO_U8_DDRB_REG = conc(DIO_U8_PB7_DIRECTION,DIO_U8_PB6_DIRECTION,DIO_U8_PB5_DIRECTION,DIO_U8_PB4_DIRECTION,
	                       DIO_U8_PB3_DIRECTION,DIO_U8_PB2_DIRECTION,DIO_U8_PB1_DIRECTION,DIO_U8_PB0_DIRECTION);

	DIO_U8_DDRC_REG = conc(DIO_U8_PC7_DIRECTION,DIO_U8_PC6_DIRECTION,DIO_U8_PC5_DIRECTION,DIO_U8_PC4_DIRECTION,
	                       DIO_U8_PC3_DIRECTION,DIO_U8_PC2_DIRECTION,DIO_U8_PC1_DIRECTION,DIO_U8_PC0_DIRECTION);
						   
	DIO_U8_DDRD_REG = conc(DIO_U8_PD7_DIRECTION,DIO_U8_PD6_DIRECTION,DIO_U8_PD5_DIRECTION,DIO_U8_PD4_DIRECTION,
	                       DIO_U8_PD3_DIRECTION,DIO_U8_PD2_DIRECTION,DIO_U8_PD1_DIRECTION,DIO_U8_PD0_DIRECTION);
	/*SET INITIAL VALUES FOR PINS*/   
	DIO_U8_PORTA_REG = conc(DIO_U8_PA7_INITIAL_VALUE,DIO_U8_PA6_INITIAL_VALUE,DIO_U8_PA5_INITIAL_VALUE,DIO_U8_PA4_INITIAL_VALUE,
	                       DIO_U8_PA3_INITIAL_VALUE,DIO_U8_PA2_INITIAL_VALUE,DIO_U8_PA1_INITIAL_VALUE,DIO_U8_PA0_INITIAL_VALUE);
                                                                                                                 
	DIO_U8_PORTB_REG = conc(DIO_U8_PB7_INITIAL_VALUE,DIO_U8_PB6_INITIAL_VALUE,DIO_U8_PB5_INITIAL_VALUE,DIO_U8_PB4_INITIAL_VALUE,
	                       DIO_U8_PB3_INITIAL_VALUE,DIO_U8_PB2_INITIAL_VALUE,DIO_U8_PB1_INITIAL_VALUE,DIO_U8_PB0_INITIAL_VALUE);
						                                                                                         
	DIO_U8_PORTC_REG = conc(DIO_U8_PC7_INITIAL_VALUE,DIO_U8_PC6_INITIAL_VALUE,DIO_U8_PC5_INITIAL_VALUE,DIO_U8_PC4_INITIAL_VALUE,
	                       DIO_U8_PC3_INITIAL_VALUE,DIO_U8_PC2_INITIAL_VALUE,DIO_U8_PC1_INITIAL_VALUE,DIO_U8_PC0_INITIAL_VALUE);
						                                                                                         
	DIO_U8_PORTD_REG = conc(DIO_U8_PD7_INITIAL_VALUE,DIO_U8_PD6_INITIAL_VALUE,DIO_U8_PD5_INITIAL_VALUE,DIO_U8_PD4_INITIAL_VALUE,
	                       DIO_U8_PD3_INITIAL_VALUE,DIO_U8_PD2_INITIAL_VALUE,DIO_U8_PD1_INITIAL_VALUE,DIO_U8_PD0_INITIAL_VALUE);	
	
						   
						   
						   
}	



u8   DIO_u8SetPinDirection (u8 copy_u8PortId, u8   copy_u8PinId ,u8  copy_u8PinDirection) 
{
	u8 local_u8ErrorState = STD_TYPES_OK ;
	if((copy_u8PortId<=DIO_u8_PORTD)&&(copy_u8PinId <= DIO_u8_PIN7)
       &&((copy_u8PinDirection == DIO_u8_INPUT)||(copy_u8PinDirection ==DIO_u8_OUTPUT)))
	{
		switch(copy_u8PortId)
		{
		  case DIO_u8_PORTA :
			 if(copy_u8PinDirection == DIO_u8_INPUT)
			 {
				 CLR_BIT(DIO_U8_DDRA_REG,copy_u8PinId);
			 }
			 else
			 {
				 SET_BIT(DIO_U8_DDRA_REG,copy_u8PinId);
			 }
		  break;
		  case DIO_u8_PORTB :
			 if(copy_u8PinDirection == DIO_u8_INPUT)
			 {
				 CLR_BIT(DIO_U8_DDRB_REG,copy_u8PinId);
			 }
			 else
			 {
				 SET_BIT(DIO_U8_DDRB_REG,copy_u8PinId);
			 }
		  break;
		  case DIO_u8_PORTC :
			 if(copy_u8PinDirection == DIO_u8_INPUT)
			 {
				 CLR_BIT(DIO_U8_DDRC_REG,copy_u8PinId);
			 }
			 else
			 {
				 SET_BIT(DIO_U8_DDRC_REG,copy_u8PinId);
			 }
		 break;
		 case DIO_u8_PORTD :
			 if(copy_u8PinDirection == DIO_u8_INPUT)
			 {
				 CLR_BIT(DIO_U8_DDRD_REG,copy_u8PinId);
			 }
			 else
			 {
				 SET_BIT(DIO_U8_DDRD_REG,copy_u8PinId);
			 }
			 		 
		}
	}
	else
	{
		local_u8ErrorState = STD_TYPES_NOK;
		
	}
	return local_u8ErrorState;
}

u8   DIO_u8SetPinValue     (u8 copy_u8PortId, u8   copy_u8PinId ,u8  copy_u8PinValue) 
{
	u8 local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId <=DIO_u8_PORTD)&&(copy_u8PinId<=DIO_u8_PIN7)&&
	  ((copy_u8PinValue ==LOW)||(copy_u8PinValue ==HIGH)))
	  {
		  switch(copy_u8PortId)
		  {
			 case DIO_u8_PORTA :
		       if(copy_u8PinValue == LOW)
		        {
			      CLR_BIT(DIO_U8_PORTA_REG,copy_u8PinId);
		        }
		       else
		        {
			     SET_BIT(DIO_U8_PORTA_REG,copy_u8PinId);
		        }
			break;
			case DIO_u8_PORTB :
		       if(copy_u8PinValue == LOW)
		        {
			      CLR_BIT(DIO_U8_PORTB_REG,copy_u8PinId);
		        }
		       else
		        {
			     SET_BIT(DIO_U8_PORTB_REG,copy_u8PinId);
		        }
			break;
			case DIO_u8_PORTC :
		       if(copy_u8PinValue == LOW)
		        {
			      CLR_BIT(DIO_U8_PORTC_REG,copy_u8PinId);
		        }
		       else
		        {
			     SET_BIT(DIO_U8_PORTC_REG,copy_u8PinId);
		        }
			break;
			case DIO_u8_PORTD :
		       if(copy_u8PinValue == LOW)
		        {
			      CLR_BIT(DIO_U8_PORTD_REG,copy_u8PinId);
		        }
		       else
		        {
			     SET_BIT(DIO_U8_PORTD_REG,copy_u8PinId);
		        }
			break;			
			   
		  }
	  }
	else
	{
		local_u8ErrorState =STD_TYPES_NOK ;
	}
	return local_u8ErrorState ;
	
}
 
u8   DIO_u8GetPinValue     (u8 copy_u8PortId, u8   copy_u8PinId ,u8  *copy_Pu8PinValue) 
{
	u8 local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId <=DIO_u8_PORTD)&&(copy_u8PinId <=DIO_u8_PIN7)&&(copy_Pu8PinValue != NULL))
	{
		u8 local_returnValue;
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA :
			 local_returnValue = GET_BIT(DIO_U8_PINA_REG,copy_u8PinId);
			 if(local_returnValue == 1)
			  *copy_Pu8PinValue = HIGH;
		     else
				*copy_Pu8PinValue = LOW; 
			break;
			case DIO_u8_PORTB :
			  local_returnValue = GET_BIT(DIO_U8_PINB_REG,copy_u8PinId);
			 if(local_returnValue == 1)
			  *copy_Pu8PinValue = HIGH;
		     else
				*copy_Pu8PinValue = LOW; 			 
			break;
			case DIO_u8_PORTC :
			 local_returnValue = GET_BIT(DIO_U8_PINC_REG,copy_u8PinId);
			 if(local_returnValue == 1)
			  *copy_Pu8PinValue = HIGH;
		     else
				*copy_Pu8PinValue = LOW; 			 
			break;
			case DIO_u8_PORTD :
			 local_returnValue = GET_BIT(DIO_U8_PIND_REG,copy_u8PinId);
			 if(local_returnValue == 1)
			  *copy_Pu8PinValue = HIGH;
		     else
				*copy_Pu8PinValue = LOW; 			 
			break;			
		}
	}
	else
	{
		local_u8ErrorState = STD_TYPES_NOK ;
	}
	return local_u8ErrorState ;
	
	
	
}

u8   DIO_u8SetPortDirection (u8 copy_u8PortId, u8   copy_u8PinDirection)
{
	u8 local_u8ErrorState = STD_TYPES_OK ;
	if((copy_u8PortId <=DIO_u8_PORTD)&&((copy_u8PinDirection ==DIO_u8_INPUT)||(copy_u8PinDirection ==DIO_u8_OUTPUT)))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA :
			  if(copy_u8PinDirection == HIGH)
			  {
				 SET_PORT(DIO_U8_DDRA_REG);
			  }
			  else
			  {
				  CLR_PORT(DIO_U8_DDRA_REG);
			  }
			break;  
			case DIO_u8_PORTB :
			  if(copy_u8PinDirection == HIGH)
			  {
				 SET_PORT(DIO_U8_DDRB_REG);
			  }
			  else
			  {
				  CLR_PORT(DIO_U8_DDRB_REG);
			  }
			break;
			case DIO_u8_PORTC :
			  if(copy_u8PinDirection == HIGH)
			  {
				 SET_PORT(DIO_U8_DDRC_REG);
			  }
			  else
			  {
				  CLR_PORT(DIO_U8_DDRC_REG);
			  }
			break;
			case DIO_u8_PORTD :
			  if(copy_u8PinDirection == HIGH)
			  {
				 SET_PORT(DIO_U8_DDRD_REG);
			  }
			  else
			  {
				  CLR_PORT(DIO_U8_DDRD_REG);
			  }
			break;			
		}
	}
	else
	{
		local_u8ErrorState = STD_TYPES_NOK;
	}
	return local_u8ErrorState ;
	
	
}


u8   DIO_u8SetPortValue    (u8 copy_u8PortId, u8   copy_u8PortValue) 
{
	u8 local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId <=DIO_u8_PORTD)&&(copy_u8PortValue<=MAX_PORT_VALUE))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA :
				DIO_U8_PORTA_REG = copy_u8PortValue;
			break;
			case DIO_u8_PORTB :
				DIO_U8_PORTB_REG = copy_u8PortValue;
			break;
			case DIO_u8_PORTC :
				DIO_U8_PORTC_REG = copy_u8PortValue;
			break;
			case DIO_u8_PORTD :
				DIO_U8_PORTD_REG = copy_u8PortValue;
			break;			
		}
		
	}
	else
	{
		local_u8ErrorState = STD_TYPES_NOK ;
	}
	return local_u8ErrorState ;
	
}

u8   DIO_u8GetPortValue    (u8 copy_u8PortId, u8 * copy_Pu8PortValue) 
{
	u8 local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId <=DIO_u8_PORTD)&&(copy_Pu8PortValue != NULL))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA :
			  *copy_Pu8PortValue = GET_PORT(DIO_U8_PINA_REG);
			break;
			case DIO_u8_PORTB :
			  *copy_Pu8PortValue = GET_PORT(DIO_U8_PINB_REG);
			break;
			case DIO_u8_PORTC :
			  *copy_Pu8PortValue = GET_PORT(DIO_U8_PINC_REG);
			break;
			case DIO_u8_PORTD :
			  *copy_Pu8PortValue = GET_PORT(DIO_U8_PIND_REG);
			break;			
		}
	}
	else
	{
		local_u8ErrorState = STD_TYPES_NOK ;
	}
	return local_u8ErrorState ;
}
