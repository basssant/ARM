/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LEDMATRIX_config.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 14, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   HAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 14, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H

// Columns
#define HLEDMATRIX_C_PORT       GPIOB_PORT

#define HLEDMATRIX_C0_PIN       PIN0
#define HLEDMATRIX_C1_PIN       PIN1
#define HLEDMATRIX_C2_PIN       PIN2
#define HLEDMATRIX_C3_PIN       PIN3
#define HLEDMATRIX_C4_PIN       PIN4
#define HLEDMATRIX_C5_PIN       PIN5
#define HLEDMATRIX_C6_PIN       PIN6
#define HLEDMATRIX_C7_PIN       PIN7

// Rows
#define HLEDMATRIX_R_PORT       GPIOA_PORT

#define HLEDMATRIX_R0_PIN       PIN0
#define HLEDMATRIX_R1_PIN       PIN1
#define HLEDMATRIX_R2_PIN       PIN2
#define HLEDMATRIX_R3_PIN       PIN3
#define HLEDMATRIX_R4_PIN       PIN4
#define HLEDMATRIX_R5_PIN       PIN5
#define HLEDMATRIX_R6_PIN       PIN6
#define HLEDMATRIX_R7_PIN       PIN7


#endif /* LEDMATRIX_CONFIG_H */
