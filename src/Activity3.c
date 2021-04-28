/**
 * @file Activity3.c
 * @author Shreya
 * @brief Source file for activity3
 * @version 0.1
 * @date 2021-04-28
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define PWM (PORTB1)

/**
 * @brief Function to initialize port pins for PWM
 */
void PWM_pins()
{
    TCCR1A|=(1<<COM1A1)|(3<<WGM10);  //TIMER 1 FAST PWM MODE
    TCCR1B|=(5<<CS10)|(1<<WGM12);  //Prescaler=1024
    DDRB|=(1<<PWM);
}

/**
 * @brief Function to output pulses for given input adc
 * @param adc Input to produce PWM output 
 */
void PWM_output(uint16_t adc)
{
    OCR1A=adc;
    _delay_ms(200);
}
