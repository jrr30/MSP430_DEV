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
    TACCR0 = 0; //0 to turn off 1000 - 1
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
        (void) Port_Out_State(bit, state, Port_1);
    }

    TACCR0 = 0; // Turning off counter
    (void) Port_Out_State(bit, (~state), Port_1);
}
/*

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
    interrupt_counts ++; //it increments every milisecond
    if(1000 <= interrupt_counts)
    {
        interrupt_counts = 0;
        Write_Data(Numers[seconds++]);
        if(9 <= interrupt_counts)
        {
            seconds = 0;
            Write_Instruction(CLEAR_DISPLAY);
            Write_Instruction(RETURN_HOME);
        }

    }
}
*/
