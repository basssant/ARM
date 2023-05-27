/********************************************************
 * Author:          Bassant Abd El-Moniem
 * Creation Date:   22 MAR 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 * ******************************************************/
 
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)			(REG |= (1 << BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)			(REG &= ~(1 << BIT_NUM))
#define READ_BIT(REG,BIT_NUM)			(REG>>(BIT_NUM))& 1
#define TOGGLE_BIT(REG,BIT_NUM)		(REG ^= (1 << BIT_NUM))

/******** Functions Like Macro To Manipulate Over Specific Register *******/
#define     SET_REG(REG_NAME, VALUE)            (REG_NAME = VALUE)
#define     GET_REG(REG_NAME)                   (REG_NAME)
#define     CLR_REG(REG_NAME)                   (REG_NAME = 0x00)

#endif
