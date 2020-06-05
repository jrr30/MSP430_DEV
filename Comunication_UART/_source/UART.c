/*
 * UART.c
 *
 *  Created on: May 29, 2020
 *      Author: Jesus
 */

#include <msp430g2553.h>
#include "Comunication_UART/_inc/UART.h"


void uart_setting(void)
{
    /*
     * This set is for a configuration of 9600 bps
     */
    UCA0CTL1 |= UCSWRST; /* Reset mode to set UART module*/
    UCA0CTL0 &= (~UCMSB + ~UC7BIT + ~UCSPB + ~UCMODE_0 + ~UCSYNC); /* LSB, 8 Bit Data, One Stop bit, UART Mode, Asynchronous Mode*/
    UCA0CTL1 = UCSSEL_2 ;
    UCA0BR0 = 0x68;
    UCA0BR1 = 0x00;
    UCA0MCTL = UCBRS0;
    IE2 = UCA0RXIE;
    UCA0CTL1 &= ~UCSWRST;
}

uart_error_handling_T read_message(uint8_t * buff_data)
{
    const uart_error_handling_T read_status = UART_request_error;

    memcpy(buff_data, global_data_uart.buffer_rx, ARRAY_LENGHT(global_data_uart.buffer_rx));

    return read_status;
}

uart_error_handling_T send_message(uint8_t * buff_data)
{
    const uart_error_handling_T send_status = UART_request_error;
    unsigned int iter;

    for(iter = 0; iter <= ARRAY_LENGHT(buff_data); iter++)
    {
        global_data_uart.buffer_tx = buff_data[iter];
        IE2 |= UCA0TXIE;
    }
    return send_status;

}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void UART0_TX (void)
{

    UCA0TXBUF  =  global_data_uart.buffer_tx;
    IE2       &=                   ~UCA0TXIE;
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void UART0_RX (void)
{
    static uint8_t iter = 0;
    global_data_uart.buffer_rx[iter++] = UCA0RXBUF;
    if(BUFFER_OUT_LENGHT == iter)
    {
        iter = 0;
    }

}
