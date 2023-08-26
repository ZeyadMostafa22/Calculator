/*
 * Key_Pad_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Key_Pad_Interface.h"
#include "Key_Pad_Config.h"
#include <util/delay.h>

u8 kpd_u8GetPressedKey(void)
{
	/**************value if button was not pressed*******************/
		u8 Local_u8_Pressed_Key=  KPD_NO_PRESSED_KEY;

		/*********************counter for (for loop)*********************/
		u8  Local_u8_Column_Counter,Local_u8_Row_Counter;

		/***************************variable for pin state**************************/
		u8  Local_u8_Pint_State;

		/********************KEY_PAD_VALUES*******************************/
	   static u8 Local_u8_Kpd_Arr [ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;

	    /********************KEY_COLUMN_Array*******************************/
	   static u8 Local_u8_Kpd_Column_Array[COLUMN_NUM]={KPD_COLUMN_0,KPD_COLUMN_1,KPD_COLUMN_2,KPD_COLUMN_3};

	    /********************KEY_ROWS_Array*******************************/
	   static  u8 Local_u8_Kpd_Rows_Array[ROW_NUM]={KPD_ROW_0,KPD_ROW_1,KPD_ROW_2,KPD_ROW_3};



	    for(Local_u8_Column_Counter=0;Local_u8_Column_Counter<COLUMN_NUM;Local_u8_Column_Counter++)
	    {
	    	/***************ACTIVATE CURRENT COLUMN*************************/

	    	DIO_VidSetPinValue(KPD_PORT_COLUMNS,Local_u8_Kpd_Column_Array[Local_u8_Column_Counter],PIN_LOW);

	    	/**************READ CURRENT ROW*****************/
	    	for(Local_u8_Row_Counter=0;Local_u8_Row_Counter<ROW_NUM;Local_u8_Row_Counter++)
	    	{
	    		DIO_VidGetPinValue(KPD_PORT_ROWS ,Local_u8_Kpd_Rows_Array[Local_u8_Row_Counter],&Local_u8_Pint_State);

	             /******CHECK IF KEY IS PREESED********/

	    		if(Local_u8_Pint_State==PIN_LOW)
	    		{
	    			Local_u8_Pressed_Key=Local_u8_Kpd_Arr[Local_u8_Row_Counter][Local_u8_Column_Counter];

	    			while(Local_u8_Pint_State==PIN_LOW)
	    			{
	    				DIO_VidGetPinValue(KPD_PORT_ROWS,Local_u8_Kpd_Rows_Array[Local_u8_Row_Counter],&Local_u8_Pint_State);
	    			}
	    			return Local_u8_Pressed_Key;
	    		}
	    	}
	    	/********DEACTIVATE CURRENT COLUMN************/
	    	DIO_VidSetPinValue(KPD_PORT_COLUMNS,Local_u8_Kpd_Column_Array[Local_u8_Column_Counter],PIN_HIGH);

	    }

	    return Local_u8_Pressed_Key;
}


void Kpd_VidInit(void)
{
	  DIO_VidSetPinDirection(KPD_PORT_COLUMNS,KPD_COLUMN_0,OUTPUT);
	  DIO_VidSetPinDirection(KPD_PORT_COLUMNS,KPD_COLUMN_1,OUTPUT);
	  DIO_VidSetPinDirection(KPD_PORT_COLUMNS,KPD_COLUMN_2,OUTPUT);
	  DIO_VidSetPinDirection(KPD_PORT_COLUMNS,KPD_COLUMN_3,OUTPUT);

	  DIO_VidSetPinDirection(KPD_PORT_ROWS,KPD_ROW_0,INPUT);
	  DIO_VidSetPinDirection(KPD_PORT_ROWS,KPD_ROW_1,INPUT);
	  DIO_VidSetPinDirection(KPD_PORT_ROWS,KPD_ROW_2,INPUT);
	  DIO_VidSetPinDirection(KPD_PORT_ROWS,KPD_ROW_3,INPUT);


	  DIO_VidSetPortValue(KPD_PORT_COLUMNS,0b00111100);
	  DIO_VidSetPortValue(KPD_PORT_ROWS,0xF0);

}



