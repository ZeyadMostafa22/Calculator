/*
 * BIT_MATH.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mostafa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Return required bit from the required register */
#define GET_BIT(REG,BIT) (REG&(1<<BIT))


#endif /* BIT_MATH_H_ */
