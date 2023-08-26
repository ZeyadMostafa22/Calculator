/******************************************************
 * 		Key_Pad_confg.h
 *
 *  	Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 ******************************************************/

#ifndef KEY_PAD_CONFIG_H_
#define KEY_PAD_CONFIG_H_

/*port*/
#define KPD_PORT_COLUMNS 			PORT_D
#define KPD_PORT_ROWS  				PORT_B
#define KPD_NO_PRESSED_KEY 			0XFF
/*columns pins*/
#define KPD_COLUMN_0				PIN2
#define KPD_COLUMN_1				PIN3
#define KPD_COLUMN_2				PIN4
#define KPD_COLUMN_3				PIN5
/*rows  pins*/
#define KPD_ROW_0					PIN4
#define KPD_ROW_1					PIN5
#define KPD_ROW_2					PIN6
#define KPD_ROW_3					PIN7


/*********row  and column numbers for array******/
#define ROW_NUM       4
#define COLUMN_NUM    4

/******************the value of array (keypad)*****/
#define KPD_ARR_VAL      {{'7','8','9' ,'/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}

#endif /* KEY_PAD_CONFIG_H_ */
