/*
 * UART.h
 *
 *  Created on: May 29, 2020
 *      Author: Jesus
 */

#ifndef COMUNICATION_UART_UART_H_
#define COMUNICATION_UART_UART_H_

/* #########################################################################
 * #                                                                       #
 * #                      Declarations and definitions                     #
 * #########################################################################
 */
#include <stdint.h>
#define ARRAY_LENGHT(array) ((sizeof(array)/sizeof(array[0])) + 1)
#define BUFFER_OUT_LENGHT 4
#define INITIAL_ELEMENT_ARRAY 0x00

typedef enum uart_error_handling_tag
{
    UART_request_ok,
    UART_request_error

}uart_error_handling_T;

typedef struct buffer_data_tag
{
    uint8_t  buffer_tx;                    /**/
    uint8_t  buffer_rx[BUFFER_OUT_LENGHT]; /**/
}buffer_data_T;

static buffer_data_T global_data_uart;
static uint8_t global_uart_temp_string;

/* #########################################################################
 * #                      Prototype Functions                              #
 * #########################################################################
 */

void uart_setting(void);
uart_error_handling_T read_message(uint8_t * buff_data);
uart_error_handling_T send_message(uint8_t * buff_data);

#endif /* COMUNICATION_UART_UART_H_ */
