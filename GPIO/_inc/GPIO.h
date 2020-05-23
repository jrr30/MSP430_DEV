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

#define Pin 0x00
#define Pout 0x01

#define OFF 0x00
#define ON 0x01

#define INTERRUPT_ENABLE 0x01;
#define INTERRUPT_DISEBLE 0x00;

response_T Port_State(int pin_value, int state);
response_T Interrupt_PIN(int pin_value, int falling_edge, int interrup_state);
response_T Define_PIN(int pin_value, int pin_direction);

#endif /* GPIO_H_ */
