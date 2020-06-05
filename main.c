#include <msp430g2553.h>
#include <stdint.h>
#include "Timer_A/_inc/Timer.h"
#include "Comunication_UART/_inc/UART.h"
#include "GPIO/_inc/GPIO.h"


/**
 * This program is intend to generate a driver create timers.
 * Author: Jesus Rodriguez
 * Copyright (c) 2020,
 * All rights reserved.
 */

uint8_t Text[] = "Hola";

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    uart_setting();
    (void) Define_PIN(( BIT1 + BIT2), Pin);
    P1SEL  |=  BIT1 + BIT2;
    P1SEL2 |=  BIT1 + BIT2;

    uint8_t temp_buffer[4];

   _enable_interrupt();

    while(1)
    {
       (void)send_message(Text);
       (void)read_message(temp_buffer);
    }

}

