/*
 * GPIO.h
 *
 *  Created on: May 14, 2020
 *      Author: Jesus
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef enum response_tag
{
    request_error,
    request_ok
} response_T;

typedef enum falling_edge_tag
{
    rising_edge,
    falling_edge
} falling_edge_T;

typedef enum port_tag
{
    Port_1,
    Port_2
}port_T;

#define Pin 0x00
#define Pout 0x01

#define OFF 0x00
#define ON 0x01

#define INTERRUPT_ENABLE 0x01;
#define INTERRUPT_DISEBLE 0x00;

response_T Port_Out_State(int pin_value, int state, port_T port);
response_T Interrupt_Set(int pin_value, falling_edge_T edge, port_T port);
response_T Define_Direction(int pin_value, int pin_direction, port_T port);

#endif /* GPIO_H_ */
