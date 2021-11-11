/********************************************************************************************************
* Title                 :   Common - Platform Abstraction
* Filename              :   Platform_Types.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   21/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file    Platform_Types.h
 *  @author  Abdelaziz Moustafa
 *  @brief   Header file for the Platform Abstraction
 *  @details  Platform types for TM4C123
 *
 *  @version 1.0.0
 *  @date 2020-07-21
 *
 *  @copyright Embedded Careers(c) 2020
 *
 */

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/*
 * CPU register type width
 */
#define CPU_TYPE_8                                   (8U)
#define CPU_TYPE_16                                  (16U)
#define CPU_TYPE_32                                  (32U)
#define PU_TYPE_64                                   (64U)

/*
 * Bit order definition
 */
#define MSB_FIRST                                    (0U)        /* Big endian bit ordering        */
#define LSB_FIRST                                    (1U)        /* Little endian bit ordering     */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST                              (0U)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST                               (1U)        /* Little endian byte ordering    */

/*
 * Platform type and endianess definitions, specific for AVR
 */
#define CPU_TYPE            CPU_TYPE_32

#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE                                        (0U)
#endif
#ifndef TRUE
#define TRUE                                         (1U)
#endif

typedef unsigned char         boolean;

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

#endif /* PLATFORM_TYPES_H */
