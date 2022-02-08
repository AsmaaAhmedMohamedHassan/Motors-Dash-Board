/*
 * main.c
 *
 *  Created on: Jan 13, 2021
 *      Author: Asmaa Ahmed
 */

/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
/*MCAL layer*/
#include "DIO_interface.h"

/*HAL layer*/
#include"LCD_interface.h"
#include"KPD_interface.h"
u8 entered[4],flag2=1;

u8 getPass(void);
u8 getAngle(void);

u8 getAngle(void)
{
	u8 button = KPD_U8_NOT_PRESSED ,flag =0 ;
	u8 angle = 0;
	while(1)
	{

		if(button == KPD_U8_NOT_PRESSED)
		{
			KPD_u8GetSwitch(&button);
			while((button !=KPD_U8_NOT_PRESSED))
			{
				if(button != '=')   /*to enter angle*/
				{
				  angle = (angle*10) + button ;
				  LCD_voidSendChar(button);
				  KPD_u8GetSwitch(&button);

				}
				else
				{
					flag =1;
					break;
				}

		     }
			if(flag)
			{
				flag =0;
				break;
			}

	      }
	}
	return angle;

}
u8 getPass(void)
{
	const u8 psw[4] = {'1','2','3','4'};
	u8 button = KPD_U8_NOT_PRESSED ,flag =0 ;
	u8 pass[4] ,i=0;
	while(1)
	{

		if(button == KPD_U8_NOT_PRESSED)
		{
			KPD_u8GetSwitch(&button);
			while((button !=KPD_U8_NOT_PRESSED))
			{
				if(button != '=')   /*to enter password*/
				{
				  pass[i] = button ;
				  LCD_voidSendChar('*');
				  KPD_u8GetSwitch(&button);
				  i++;
				}
				else
				{
					flag =1;
					break;
				}

		     }
			if(flag)
			{
				break;
			}

	      }
	}

	 for(u8 i=0 ;i<4;i++)
	 {
		 if(pass[i] != psw[i])
		 {
			 flag2 =0;
			 break;
		 }
		 else
		 {
			 i++;
			 flag2 =1;
		 }

	 }

	return flag2;
}

int main(void)
{
   u8 flag3 =0 ,button = KPD_U8_NOT_PRESSED,button2 = KPD_U8_NOT_PRESSED,button3 = KPD_U8_NOT_PRESSED,ANGLE;
	DIO_voidInit();
	LCD_voidInit();
	LCD_voidSendStr("hello");
	_delay_ms(3000);

	LCD_voidClear();
	LCD_voidSendStr("enter password");
	LCD_voidGoToXY(LCD_U8_LINE2,0);
    flag3 = getPass();

	 if(flag3)
	 {
		 LCD_voidClear();
		 LCD_voidGoToXY(LCD_U8_LINE1,0);
		 LCD_voidSendStr("1-DC motor");
		 LCD_voidGoToXY(LCD_U8_LINE1,10);
		 LCD_voidSendStr("2-stepper");
		 LCD_voidGoToXY(LCD_U8_LINE2,0);
		 LCD_voidSendStr("3-servo motor");
		 flag3 = 0;
	 }
		while(1)
		{

			if(button == KPD_U8_NOT_PRESSED)
			{
				KPD_u8GetSwitch(&button);
				while((button !=KPD_U8_NOT_PRESSED))
				{
					if(button == '1' )
					{
						 LCD_voidClear();
						 LCD_voidGoToXY(LCD_U8_LINE1,0);
						 LCD_voidSendStr("1-CW");
						 LCD_voidGoToXY(LCD_U8_LINE2,0);
						 LCD_voidSendStr("2-CCW");
						 button = KPD_U8_NOT_PRESSED;

                       while(1)
                       {
						if(button == KPD_U8_NOT_PRESSED)
						{
			     			KPD_u8GetSwitch(&button);
							while((button !=KPD_U8_NOT_PRESSED))
							 {
								if((button == '1')||(button == '2'))
								{
								 LCD_voidClear();
								 LCD_voidGoToXY(LCD_U8_LINE1,0);
								 LCD_voidSendStr("1-full speed");
								 LCD_voidGoToXY(LCD_U8_LINE2,0);
								 LCD_voidSendStr("2-map pot");
								 button = KPD_U8_NOT_PRESSED;
			                       while(1)
			                       {
									if(button == KPD_U8_NOT_PRESSED)
									{
						     			KPD_u8GetSwitch(&button);
										while((button !=KPD_U8_NOT_PRESSED))
										 {
											if((button == '1')||(button == '2'))
											{
												 LCD_voidClear();
												 LCD_voidGoToXY(LCD_U8_LINE1,0);
												 LCD_voidSendStr("1-DC motor");
												 LCD_voidGoToXY(LCD_U8_LINE1,10);
												 LCD_voidSendStr("2-stepper motor");
												 LCD_voidGoToXY(LCD_U8_LINE2,0);
												 LCD_voidSendStr("3-servo motor");
                                                 button = KPD_U8_NOT_PRESSED;

											}

										     KPD_u8GetSwitch(&button);
									     }

									 }
			                       }

								}

							     KPD_u8GetSwitch(&button2);
						     }

						 }
						break;
                       }

					}
					else if(button == '3' )
					{
						 LCD_voidClear();
						 LCD_voidGoToXY(LCD_U8_LINE1,0);
						 LCD_voidSendStr("enter angle");
						 LCD_voidGoToXY(LCD_U8_LINE2,0);
						 ANGLE = getAngle();
						// LCD_VidWriteNum(ANGLE);
//						 LCD_voidClear();
//						 LCD_voidGoToXY(LCD_U8_LINE1,0);
//						 LCD_voidSendStr("1-CW");
//						 LCD_voidGoToXY(LCD_U8_LINE2,0);
//						 LCD_voidSendStr("2-CCW");
						 _delay_ms(1000);
						// KPD_u8GetSwitch(&button);
						 LCD_voidClear();
						 LCD_voidGoToXY(LCD_U8_LINE1,0);
						 LCD_voidSendStr("1-DC motor");
						 LCD_voidGoToXY(LCD_U8_LINE1,10);
						 LCD_voidSendStr("2-stepper motor");
						 LCD_voidGoToXY(LCD_U8_LINE2,0);
						 LCD_voidSendStr("3-servo motor");
						 button =0 ;
//						 if(button == '3')
//						 {
//							 LCD_voidClear();
//							 LCD_voidGoToXY(LCD_U8_LINE1,0);
//							 LCD_voidSendStr("logged off ");
//							 button =0 ;
//						 }

					}
//					else if(button == '3')
//					{
//						 LCD_voidClear();
//						 LCD_voidGoToXY(LCD_U8_LINE1,0);
//						 LCD_voidSendStr("logged off ");
//						 button =0 ;
//					}
					KPD_u8GetSwitch(&button);

		      }
		}



		}
 return 0;
}

