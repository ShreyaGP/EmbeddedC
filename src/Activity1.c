/**
 * @file Activity1.c
 * @author Shreya
 * @brief Source file for activity1 
 * @version 0.1
 * @date 2021-04-27
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#define LED (PORTB1)
#define SEAT (PORTB0)
#define Heater_int (PORTD2)

/**
 * @brief A function to initialize the required port pins
 * 
 */
void pin_port()
{
    DDRB |= (1<<LED);  //B1 IS SET  AS OUTPUT FOR LED
    DDRB &= ~(1<<SEAT);  //B0 is cleared to set as input for SEAT

    DDRD &= ~(1<<Heater_int); //clear bit
    PORTD  &= ~(1<<Heater_int);  //HEATER interrupt

    EICRA |= (1<<ISC00);  //external interrupt control register
    EIMSK |= (1<<INT0);  //ext interrupt mask register set for INT0

    sei();
}