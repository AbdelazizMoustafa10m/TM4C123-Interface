/********************************************************************************************************
* Title                 :   Macros
* Filename              :   Macros.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   15/07/2020
* Version               :   1.0.0
* Brief                 :   This file contains Macros definitions
*
********************************************************************************************************/


#ifndef MACROS_H_
#define MACROS_H_

										/* BIT MANPULATING MACROS */

/* This line sets a certain bit in any register*/
#define SET_BIT(Reg,Bit_no) ((Reg)|=(1U<<(Bit_no)))
/* This line clears a certain bit in any register*/
#define CLEAR_BIT(Reg,Bit_no) ((Reg)&=~(1U<<(Bit_no)))
/* This line toggles a certain bit in any register*/
#define TOGGLE_BIT(Reg,Bit_no) ((Reg)^=(1U<<(Bit_no)))
/* This line Reads the value of a certain bit in any register*/
#define READ_BIT(Reg,Bit_no) (((Reg) & (1U<<Bit_no)) >>(Bit_no))



#endif /* MACROS_H_ */
