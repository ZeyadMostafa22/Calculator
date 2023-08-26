/*
 * LCD_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#include "STD_TYPES.h"

#include <util/delay.h>



#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"



void LCD_VidSendCommand(u8 Copy_u8Command)
{
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN ,PIN_LOW);

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN ,PIN_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8Command );

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN ,PIN_HIGH);

	_delay_ms(2);

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN ,PIN_LOW);
}

void LCD_VidSendData(u8 Copy_u8Data)
{
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN ,PIN_HIGH);

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN ,PIN_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8Data );

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN ,PIN_HIGH);

	_delay_ms(2);

	DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN ,PIN_LOW);

}


void LCD_VidInit(void)
{

	DIO_VidSetPortDirection(PORT_A , OUTPUT);
	DIO_VidSetPinDirection(PORT_C, PIN0, OUTPUT);
	DIO_VidSetPinDirection(PORT_C, PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORT_C, PIN2,OUTPUT);

	_delay_ms(40);

	LCD_VidSendCommand(0b00111000);

	LCD_VidSendCommand(0b00001100);

	LCD_VidSendCommand(1);
}


void LCD_VidDisplayString(const char *str)
{
	u8 i;
	for(i=0;str[i]!='\0';i++)
		LCD_VidSendData(str[i]);
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_VidDisplayString(buff); /* Display the string */
}

void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_VidSendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}


void LCD_floatToString(float num, int decimalPlaces)
{

	    char buffer[16];
	    dtostrf(num, 0, decimalPlaces, buffer); // Convert float to string
	    LCD_VidDisplayString(buffer); // Display the string on the LCD

}






