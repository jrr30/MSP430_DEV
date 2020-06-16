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
response_T Define_Direction(int pin_value, int pin_direction, port_T port)
{
    response_T success_set = request_error;

    if(Pin == pin_direction && Port_1 == port)
    {
        P1DIR &= ~pin_value;
        success_set = request_ok;
    }
    else if(Pout == pin_direction && Port_1 == port)
    {
        P1DIR |= pin_value;
        success_set = request_ok;
    }
    else if(Pin == pin_direction && Port_2 == port)
    {
        P2DIR &= pin_value;
        success_set = request_ok;
    }
    else if(Pout == pin_direction && Port_2 == port)
    {
        P2DIR |= pin_value;
        success_set = request_ok;
    }
    return success_set;
}

/*
 * This API receives the BIT to be set and also the state as ON or OFF. Keep in mind that this pin was previously set as an output.
 * pin_value: BIT0, BIT1, so on. This must be one by one.
 * State: OFF (0) & ON (1)
 */
response_T Port_Out_State(int pin_value, int state, port_T port)
{
    response_T success_set = request_error;
    if(OFF == state && Port_1 == port)
    {
        P1DIR &= ~pin_value;
        success_set = request_ok;
    }
    else if(ON == state && Port_1 == port)
    {
        P1DIR |= pin_value;
        success_set = request_ok;
    }
    else if(OFF == state && Port_2 == port)
    {
        P2DIR &= ~pin_value;
        success_set = request_ok;
    }
    else if(ON == state && Port_2 == port)
    {
        P2DIR |= pin_value;
        success_set = request_ok;
    }

    return success_set;
}


response_T Interrupt_Set(int pin_value, falling_edge_T edge, port_T port)
{
    P1SEL = 0;
    P1SEL2 = 0;

    P2SEL = 0;
    P2SEL2 = 0;

    if(rising_edge == edge && Port_1 == port)
    {
        P1IE  |= pin_value;
        P1IES &= ~pin_value;
    }
    else if(falling_edge == edge && Port_1 == port)
    {
        P1IE  |= pin_value;
        P1IES |= pin_value;
    }
    else if(rising_edge == edge && Port_2 == port)
    {
        P2IE  |= pin_value;
        P2IES &= ~pin_value;
    }
    else if(falling_edge == edge && Port_2 == port)
    {
        P2IE  |= pin_value;
        P2IES |= pin_value;
    }
    return request_ok;
}
