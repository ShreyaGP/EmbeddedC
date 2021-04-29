/**
 * @file Activity4.c
 * @author Shreya
 * @brief Source file for activity4
 * @version 0.1
 * @date 2021-04-29
 * @copyright Copyright (c) 2021
 */

#include <avr/io.h>
#include <util/delay.h>

#define USART_data UDR0

/**
 * @brief Function to initialize USART communication
 * @param UBRR_value Baudrate for data transmission
 */
void Init_USART(uint16_t UBRR_value)
{
    UBRR0L=UBRR_value;//SET BAUD RATE
    UBRR0H=(UBRR_value>>8)&0X00FF;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);  //synchronous 8-bit USART
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);//Enable receiver and transmitter
}

/**
 * @brief Function to read data to the device
 * @return char Data read
 */
char Read_USART()
{
    while(!(UCSR0A & (1<<RXC0)));  //wait for data
    return USART_data;
}

/**
 * @brief Function to write data from the device to the other
 * @param data Message to be sent
 */
void Write_USART(char data)
{
    while(!(UCSR0A & (1<<UDRE0)));   //wait till transmitter is ready
    USART_data=data;
}
