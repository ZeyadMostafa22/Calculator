/*
 * LCD_Config.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_DATA_PORT PORT_A

#define LCD_CTRL_PORT PORT_C
#define LCD_RS_PIN    PIN0
#define LCD_RW_PIN    PIN1
#define LCD_E_PIN     PIN2

#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

#endif /* LCD_CONFIG_H_ */
