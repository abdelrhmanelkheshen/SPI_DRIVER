  /******************************************************************************
 *
 * [FILE NAME]: <types.h>
 *
 * [AUTHOR]: Abdelrhman Hesham
 *
 * [DATE CREATED]: 17/11/2023
 *
 * [DESCRIPTION]: <header file for types>
 *
 *******************************************************************************/
#ifndef types
#define types

typedef unsigned char         uint8;          
typedef signed char           int8;          
typedef unsigned short        uint16;        
typedef signed short          int16;         
typedef unsigned long         uint32;        
typedef signed long           int32;         
typedef unsigned long long    uint64;        
typedef signed long long      int64;         
typedef float                 float32;
typedef double                float64;

typedef unsigned char*         uint8_ptr;          
typedef signed char*           int8_ptr;          
typedef unsigned short*        uint16_ptr;        
typedef signed short*          int16_ptr;         
typedef unsigned long*         uint32_ptr;        
typedef signed long*           int32_ptr;         
typedef unsigned long long*    uint64_ptr;        
typedef signed long long*      int64_ptr;         
typedef float*                 float32_ptr;
typedef double*                float64_ptr;

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}PORT_ID;

typedef enum
{
  PIN0,
  PIN1,
  PIN2,
  PIN3,
  PIN4,
  PIN5,
  PIN6,
  PIN7
}PIN_ID;

typedef enum {
  WHITE,
  RED,
  GREEN,
  BLUE
}Color;

typedef enum
{
    SSI0_ID, 
    SSI1_ID,
    SSI2_ID,
    SSI3_ID
    
}SPI_Num;

typedef enum
{
    MASTER = 0x00, 
    SLAVE_OUTPUT_EN = 0x04,
    SLAVE_OUTPUT_DIS = 0x0C
    
}condition;

typedef enum
{
    DATA_4_BIT = 0x3,
    DATA_5_BIT,
    DATA_6_BIT,
    DATA_7_BIT, 
    DATA_8_BIT, 
    DATA_9_BIT,
    DATA_10_BIT, 
    DATA_11_BIT, 
    DATA_12_BIT,
    DATA_13_BIT,
    DATA_14_BIT, 
    DATA_15_BIT, 
    DATA_16_BIT
    
}data_size;

#define LOGIC_LOW 0
#define LOGIC_HIGH 1

#define LEAST_4_BYTES_HIGH      (0x0000FFFFU)
#define MOST_4_BYTES_HIGH       (0xFFFF0000U)
#define MIDDLE_4_BYTES_HIGH     (0x00FFFF00U)
#define MIDDLE_4_BYTES_LOW      (0xFF0000FFU)



#endif

