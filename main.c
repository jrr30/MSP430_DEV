#include <msp430g2553.h>
#include <stdint.h>
#include "Timer_A/_inc/Timer.h"
#include "Comunication_UART/_inc/UART.h"
#include "GPIO/_inc/GPIO.h"
#include "LCD_1602A/_inc/lcd_1602A.h"


/**
 * This program is intend to generate a driver create timers.
 * Author: Jesus Rodriguez
 * Copyright (c) 2020,
 * All rights reserved.
 */

uint8_t Numers[] = {'0','1','2','3','4','5','6','7','8','9'};
uint8_t seconds = 0x30;
uint8_t Text[11] = "Cuenta: 0";

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    (void)Define_Direction((D4 + D5 + D6 + D7), Pout, Port_2);
    (void)Define_Direction((RS + RW + E), Pout, Port_1);
    (void)Interrupt_Set((BIT4 + BIT5), rising_edge, Port_2);

    __enable_interrupt();
   //Cfg_LCD(four_bit_data);
   // Setting_up_Timer0_A();


    while(1)
    {
        Printf_LCD(Text);
        //Write_Instruction(0xC0u);
        Set_Cursor(1,0);
        Printf_LCD("Hola Itz");
    }

}

#pragma vector=PORT2_VECTOR
__interrupt void PORT2 (void)
{
    seconds++;
    Text[8] = seconds;
    P2IFG &= ~BIT4;
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
    interrupt_counts ++; //it increments every milisecond
    if(1000 <= interrupt_counts)
    {
        interrupt_counts = 0;
        if(10 < seconds)
        {
            seconds = 0;
        }

    }
}
