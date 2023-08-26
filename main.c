/*************************************
 *     ( Simple Calculator)
 *      main.c
 *      Created on: Aug 22, 2023
 *      Author: Zeyad Mostafa
 *****************************************/
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include  "Key_Pad_Config.h"
#include "Key_Pad_Interface.h"

int main(void)
{

  LCD_VidInit();
  Kpd_VidInit();

  /*******************************************************************/
  u8 pressed_key=KPD_NO_PRESSED_KEY ,op;
  s16 num1=0,num2=0;

  while(1)
  {
	        pressed_key = kpd_u8GetPressedKey();
	  		if (pressed_key != KPD_NO_PRESSED_KEY)
	  		{


	  			if (pressed_key >= '0' && pressed_key <= '9')
				{
					LCD_VidSendData(pressed_key);
					num1 = (num1 * 10) + (pressed_key - '0');

				}

			    if ( (pressed_key == '-') || (pressed_key == '+') ||  (pressed_key == '*') || (pressed_key == '/') )
				{
					num2 = num1;
					num1 = 0;
					LCD_VidSendData(pressed_key);
					op = pressed_key;
				}
	  			if (pressed_key == '=')
	  			{

	  				LCD_VidSendData(pressed_key);
	  				switch (op)
	  				{
						case '+':
							LCD_intgerToString(num1 + num2);
							break;
						case '-':
							LCD_intgerToString(num2 - num1);
							break;
						case '*':
							LCD_intgerToString(num1 * num2);
							break;
						case '/':
							LCD_floatToString( ( ((double)num2)/num1 ) , 3);
							break;
	  				}
	  			}
	  			if (pressed_key == 'c')
	  			{
	  				LCD_VidSendCommand(1);
	  				num1 = 0;
	  				num2 = 0;
	  			}

	  		}


  }


}
