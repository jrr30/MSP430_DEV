/*
 * lcd_1602A.h
 *
 *  Created on: Jun 5, 2020
 *      Author: Jesus
 */

#ifndef LCD_1602A_H_
#define LCD_1602A_H_

#include <stdint.h>
#include <msp430g2553.h>
#include <intrinsics.h>

#define RS BIT7
#define RW BIT6
#define E  BIT5

/* the next 4 bit are used when 8 lines are on*/
#define D4 BIT0
#define D5 BIT1
#define D6 BIT2
#define D7 BIT3
/* the next 4 bit are used when 8 lines are on*/
#define D0 BIT0
#define D1 BIT1
#define D2 BIT2
#define D3 BIT3

#define COLUMNS 15 /*ROWS starts at 0 to 15, having a total of 16 COLUMNS*/

#define CLEAR_DISPLAY 0x01u
#define RETURN_HOME   0x02u
#define DISPLAY_ON    0x0Eu /*C*/
#define DISPLAY_OFF   0x08u
#define ENTRY_INCREMENT 0x06u
#define ENTRY_DECREMENT 0x04u
#define FUNCTION_SET_8_LINES  0X38u
#define FUNCTION_SET_4_LINES  0X28u
#define DISPLAY_SHIFT_RIGTH 0x1Cu
#define DISPLAY_SHIFT_LEFT 0x18u
#define MASK_HIGH 0xF0u
#define MASK_LOW 0x0Fu

typedef enum data_line_tag
{
    four_bit_data,
    eight_bit_data
}data_line_T;

data_line_T data_line_buff;

void Write_Data(uint8_t data);
void Set_Data_Low_Level(uint8_t data_raw);
void Write_Instruction(uint8_t instruction);
void Set_Instruction_Low_Level(uint8_t instruction_raw);
void Pulse_Enable(void);
void Cfg_LCD(data_line_T data_line);
void Printf_LCD(uint8_t * text);
void Set_Cursor(uint8_t row, uint8_t column);

#endif /* LCD_1602A_H_ */
