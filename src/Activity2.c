/**
 * @file Activity2.c
 * @author Shreya
 * @brief Source file for activity2 
 * @version 0.1
 * @date 2021-04-27
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Function to initialize ADC 
 * 
 */
void InitADC()
{
    ADMUX=(1<<REFS0);  //for Aref=AVcc
    ADCSRA=(1<<ADEN)|(7<<ADPS0);   //FCPU/128
}

/**
 * @brief Function to set up ADC and get result
 * 
 * @param ch Input ADC channel number
 * @return uint16_t Final value after ADC conversion 
 */
uint16_t ReadADC(uint8_t ch)
{
    ADMUX &= 0XF8;
    ch &= 0b00000111;  
    ADMUX |= ch;  //get the channel number
    ADCSRA |= (1<<ADSC);  //start ADC conversion
    while(!(ADCSRA & (1<<ADIF)));  //wait till conversion done
    ADCSRA |= (1<<ADIF);  //indicate conversion ended
    return(ADC);
}