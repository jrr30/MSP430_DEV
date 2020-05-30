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

char Text[] = "Hola";

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    (void) Define_PIN(( BIT2 +BIT1 ), Pout);
    P1SEL  |=  BIT2 +BIT1;
    P1SEL2 |=  BIT2 +BIT1;
    uart_setting();
   _enable_interrupt();

    while(1)
    {
        (void) send_message(Text);
    }

}

