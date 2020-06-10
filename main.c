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

uint8_t Text[] = "Hola Mundo";

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P2DIR |= D4 + D5 + D6 + D7;
    P1DIR |= RS + RW + E;

    Cfg_LCD(four_bit_data);


    while(1)
    {
        Print_Text(Text);
    }

}

