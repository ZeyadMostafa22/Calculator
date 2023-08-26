/*
 * LCD_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_VidSendCommand(u8 Copy_u8Command);
void LCD_VidSendData(u8 Copy_u8Data);
void LCD_VidDisplayString(const char *str);
void LCD_intgerToString(int data);
void LCD_floatToString(float num, int decimalPlaces);
void LCD_VidInit(void);

void LCD_moveCursor(u8 row,u8 col);


#endif /* LCD_INTERFACE_H_ */
