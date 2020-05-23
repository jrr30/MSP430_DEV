/*
 * Timer.c
 *
 *  Created on: May 21, 2020
 *      Author: Jesus
 */

#include <msp430g2553.h>
#include "Timer_A/_inc/Timer.h"
#include "GPIO/_inc/GPIO.h"

void Setting_up_Timer0_A(void)
{
    TACTL = TASSEL_2 + MC_1 + ID_0;
    TACCTL0 |= CCIE;
    TACCR0 = 0;
}

void Setting_up_PWM(void)
{
    TA0CTL  = TASSEL_2 + MC_1 + ID_0;
    TACCTL0 =         CAP + OUTMOD_7;
    TA0CCR0 =                 10 - 1; //Period
    TA0CCR1 =                      5;  //Duty cycle
}

/*
 * This API is intend to generate a pulse with a specific time
 * @parameter: BIT, State (ON, OFF), Time (given in ms)
 * Return: None
 */

void Pulse(int ms, int state, int bit)
{

    interrupt_counts = 0; // Staring counts in cero
    TACCR0 = 1000 - 1; // One milisecond & initialized counter

    while(interrupt_counts <= ms)
    {
        (void) Port_State(bit, state);
    }

    TACCR0 = 0; // Turning off counter
    (void) Port_State(bit, (~state));
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
    interrupt_counts ++; //it increments every milisecond
}
