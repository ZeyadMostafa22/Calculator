/*
 * DIO_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
	PORT_A, PORT_B, PORT_C, PORT_D
} et_port;

typedef enum {
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} et_pin;

typedef enum {
	INPUT, OUTPUT
} et_direction;

typedef enum {
	PIN_LOW, PIN_HIGH
} et_Status;

/* Setting Pin Direction */
void DIO_VidSetPinDirection( u8 u8_port, u8 u8_pin, u8 u8_direction);

/* Setting Pin Value */
void DIO_VidSetPinValue( u8 u8_port, u8 u8_pin, u8 u8_value);

/* Getting Pin Value */
void DIO_VidGetPinValue( u8 u8_port, u8 u8_pin, u8 *p_u8_data);

/* Setting Port Direction */
void DIO_VidSetPortDirection ( u8 u8_port, u8 u8_direction);

/* Setting Port Value */
void DIO_VidSetPortValue ( u8 u8_port, u8 u8_value);

/* Getting Port Value */
void DIO_VidGetPortValue( u8 u8_port, u8 *p_u8_data);


#endif /* DIO_INTERFACE_H_ */
