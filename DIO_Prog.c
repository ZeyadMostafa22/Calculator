/*
 * DIO_Prog.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"


/* Setting Pin Direction */
void DIO_VidSetPinDirection(u8 u8_port, u8 u8_pin, u8 u8_direction) {
	if (u8_direction == INPUT) {
		switch (u8_port) {
		case PORT_A:
			CLEAR_BIT(DDRA, u8_pin);
			break;
		case PORT_B:
			CLEAR_BIT(DDRB, u8_pin);
			break;
		case PORT_C:
			CLEAR_BIT(DDRC, u8_pin);
			break;
		case PORT_D:
			CLEAR_BIT(DDRD, u8_pin);
			break;
		}
	} else if (u8_direction == OUTPUT) {
		switch (u8_port) {
		case PORT_A:
			SET_BIT(DDRA, u8_pin);
			break;
		case PORT_B:
			SET_BIT(DDRB, u8_pin);
			break;
		case PORT_C:
			SET_BIT(DDRC, u8_pin);
			break;
		case PORT_D:
			SET_BIT(DDRD, u8_pin);
			break;
		}
	}
}

/* Setting Pin Value */
void DIO_VidSetPinValue(u8 u8_port, u8 u8_pin, u8 u8_value) {
	if (u8_value == PIN_LOW) {
		switch (u8_port) {
		case PORT_A:
			CLEAR_BIT(PORTA, u8_pin);
			break;
		case PORT_B:
			CLEAR_BIT(PORTB, u8_pin);
			break;
		case PORT_C:
			CLEAR_BIT(PORTC, u8_pin);
			break;
		case PORT_D:
			CLEAR_BIT(PORTD, u8_pin);
			break;
		}
	} else if (u8_value == PIN_HIGH) {
		switch (u8_port) {
		case PORT_A:
			SET_BIT(PORTA, u8_pin);
			break;
		case PORT_B:
			SET_BIT(PORTB, u8_pin);
			break;
		case PORT_C:
			SET_BIT(PORTC, u8_pin);
			break;
		case PORT_D:
			SET_BIT(PORTD, u8_pin);
			break;
		}
	}
}

/* Getting Pin Value */
void DIO_VidGetPinValue(u8 u8_port, u8 u8_pin, u8 *p_u8_data) {
	switch (u8_port) {
	case PORT_A:
		*p_u8_data = GET_BIT(PINA, u8_pin);
		break;
	case PORT_B:
		*p_u8_data = GET_BIT(PINB, u8_pin);
		break;
	case PORT_C:
		*p_u8_data = GET_BIT(PINC, u8_pin);
		break;
	case PORT_D:
		*p_u8_data = GET_BIT(PIND, u8_pin);
		break;
	}
}

/* Setting Port Direction */
void DIO_VidSetPortDirection(u8 u8_port, u8 u8_direction) {
	if (u8_direction == INPUT) {
		switch (u8_port) {
		case PORT_A:
			DDRA = 0x00;
			break;
		case PORT_B:
			DDRB = 0x00;
			break;
		case PORT_C:
			DDRC = 0x00;
			break;
		case PORT_D:
			DDRD = 0x00;
			break;
		}
	} else if (u8_direction == OUTPUT) {
		switch (u8_port) {
		case PORT_A:
			DDRA = 0xFF;
			break;
		case PORT_B:
			DDRB = 0xFF;
			break;
		case PORT_C:
			DDRC = 0xFF;
			break;
		case PORT_D:
			DDRD = 0xFF;
			break;
		}
	}
}

/* Setting Port Value */
void DIO_VidSetPortValue(u8 u8_port, u8 u8_value) {
	switch (u8_port) {
	case PORT_A:
		PORTA = u8_value;
		break;
	case PORT_B:
		PORTB = u8_value;
		break;
	case PORT_C:
		PORTC = u8_value;
		break;
	case PORT_D:
		PORTD = u8_value;
		break;
	}
}

/* Getting Port Value */
void DIO_VidGetPortValue(u8 u8_port, u8 *p_u8_data) {
	switch (u8_port) {
	case PORT_A:
		*p_u8_data = PINA;
		break;
	case PORT_B:
		*p_u8_data = PINB;
		break;
	case PORT_C:
		*p_u8_data = PINC;
		break;
	case PORT_D:
		*p_u8_data = PIND;
		break;
	}
}


