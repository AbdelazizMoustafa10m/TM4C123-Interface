/********************************************************************************************************
* Title                 :   Common - Compiler Abstraction
* Filename              :   Compiler.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   21/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file    Compiler.h
 *  @author  Abdelaziz Moustafa
 *  @brief   Header file for the Compiler Abstraction
 *  @details This file contains the definitions and macros specified by
 *           AUTOSAR for the abstraction of compiler specific keywords.
 *
 *  @version 1.0.0
 *  @date 2020-07-21
 *
 *  @copyright Embedded Careers(c) 2020
 *
 */

#ifndef COMPILER_H
#define COMPILER_H


/* The memory class is used for the declaration of local pointers */
#define AUTOMATIC

/* The memory class is used within type definitions, where no memory
   qualifier can be specified */
#define TYPEDEF

/* This is used to define the void pointer to zero definition */
#define NULL_PTR          ((void *)0)

/* This is used to define the abstraction of compiler keyword inline */
#define INLINE            inline

/* This is used to define the local inline function */
#define LOCAL_INLINE      static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static

#define PTR_FAR

#define FUNC(returntype,memclass)                   returntype
#define VAR(vartype,memclass)                       vartype
#define P2FUNC(returntype,memclass,funcname)        returntype (* funcname)
#define CONST(consttype, memclass)                  const consttype
#define P2CONST(ptrtype,memclass,ptrclass)          const ptrtype *
#define P2VAR(ptrtype,memclass,ptrclass)            ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass)     ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass)   const ptrtype * const

#endif
