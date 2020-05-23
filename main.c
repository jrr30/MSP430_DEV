#include <msp430g2553.h>
#include "Timer_A/_inc/Timer.h"
#include "GPIO/_inc/GPIO.h"


/**
 * This program is intend to generate a driver create timers.
 * Author: Jesus Rodriguez
 * Copyright (c) 2020,
 * All rights reserved.
 */

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    (void) Define_PIN((BIT1),Pout);

    UCA0CTL1 |= UCSWRST; /* Reset mode to set UART module*/
    UCA0CTL0 &= (~UCMSB + ~UC7BIT + ~UCSPB + ~UCMODEx + ~UCSYNC); /* LSB, 8 Bit Data, One Stop bit, UART Mode, Asynchronous Mode*/
    UCA0CTL1 = UCSSEL_2 ;
    IE2 = UCA0TXIE + UCA0RXIE;

   _enable_interrupt();

	while(1)
	{

	}
}
