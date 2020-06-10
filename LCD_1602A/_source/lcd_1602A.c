/*
 * lcd_1602A.c
 *
 *  Created on: Jun 5, 2020
 *      Author: Jesus
 */

#include "LCD_1602A/_inc/lcd_1602A.h"
#include <string.h>

void Write_Data(uint8_t data)
{
    if(four_bit_data == data_line_buff)
    {
        Set_Data_Low_Level((((uint8_t)MASK_HIGH&data)>>4));
        Set_Data_Low_Level(MASK_LOW&data);
    }
    else if(eight_bit_data == data_line_buff)
    {
        Set_Data_Low_Level(data);
    }
}

void Set_Data_Low_Level(uint8_t data_raw)
{
    P1OUT &= ~(RW);    /*RW 1 Read - 0 Write      */
    P1OUT |= RS;           /*RS 1 Data - 0 Instruction*/

    P2OUT = data_raw;
    Pulse_Enable();
    __delay_cycles(38);
}

void Write_Instruction(uint8_t instruction)
{
    if(four_bit_data == data_line_buff)
    {
        Set_Instruction_Low_Level((((uint8_t)MASK_HIGH&instruction)>>4));
        Set_Instruction_Low_Level(MASK_LOW&instruction);
    }
    else if(eight_bit_data == data_line_buff)
    {
        Set_Instruction_Low_Level(instruction);
    }
}

void Set_Instruction_Low_Level(uint8_t instruction_raw)
{
    P1OUT &= ~(RW); /*RW 1 Read - 0 Write      */
    P1OUT &= ~(RS);

    P2OUT = instruction_raw;
    Pulse_Enable();
    __delay_cycles(38);
}

void Pulse_Enable(void)
{
    P1OUT |= E;
    __delay_cycles(300);
    P1OUT &= ~E;
    __delay_cycles(300);
}

void Cfg_LCD(data_line_T data_line)
{
    P2OUT = 0;
    P1OUT = 0;

    data_line_buff = data_line;
    uint8_t line_selection = FUNCTION_SET_8_LINES;

    if(four_bit_data == data_line_buff)
    {
        line_selection = FUNCTION_SET_4_LINES;
    }
    else
    {
         /*TODO Do nothing*/
    }

    __delay_cycles(20000);
    Write_Instruction(line_selection);
    Write_Instruction(DISPLAY_ON);
    Write_Instruction(CLEAR_DISPLAY);
    __delay_cycles(2000);
    Write_Instruction(ENTRY_INCREMENT);
    Write_Instruction(RETURN_HOME);
    __delay_cycles(2000);
}

void Set_Cursor(uint8_t * position)
{

}

void Print_Text(uint8_t * text)
{
    uint8_t iter;

    for(iter = 0; iter <= strlen((char *)text) - 1; iter++)
    {
        if( COLUMNS <= iter )
        {
            Write_Data(text[iter]);
            Write_Instruction(DISPLAY_SHIFT_LEFT);
            __delay_cycles(600000);
        }
        else
        {
            Write_Data(text[iter]);
            __delay_cycles(90000);
        }

    }
    __delay_cycles(600000);
    Write_Instruction(CLEAR_DISPLAY);
    Write_Instruction(RETURN_HOME);
    __delay_cycles(2000);
}
