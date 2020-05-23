/*
 * GPIO.c
 *
 *  Created on: May 21, 2020
 *      Author: Jesus
 */

#include <msp430g2553.h>
#include "GPIO/_inc/GPIO.h"

/*
 * This API receives the BIT to be set and also how this would be enable (in, out).
 * pin_value: BIT0, BIT1, so on. This must be one by one.
 * pin_direction: Pin (Port in); Pout(Port out);
 */
response_T Define_PIN(int pin_value, int pin_direction)
{
    response_T success_set = request_error;
    if(Pin == pin_direction)
    {
        P1DIR &= ~pin_value;
        success_set = request_ok;
    }
    else if(Pout == pin_direction)
    {
        P1DIR |= pin_value;
        success_set = request_ok;
    }
    return success_set;
}

/*
 * This API receives the BIT to be set and also the state as ON or OFF. Keep in mind that this pin was previously set as an output.
 * pin_value: BIT0, BIT1, so on. This must be one by one.
 * State: OFF (0) & ON (1)
 */
response_T Port_State(int pin_value, int state)
{
    response_T success_set = request_error;
    if(OFF == state)
    {
        P1DIR &= ~pin_value;
        success_set = request_ok;
    }
    else if(ON == state)
    {
        P1DIR |= pin_value;
        success_set = request_ok;
    }

    return success_set;
}


response_T Interrupt_PIN(int pin_value, int falling_edge, int interrup_state)
{
    return request_ok;
}
