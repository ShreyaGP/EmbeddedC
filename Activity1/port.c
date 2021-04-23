#include <avr/io.h>
#include <avr/interrupt.h>

void port()
{
    DDRB |= (1<<PB1);  //B1 IS SET  AS OUTPUT FOR LED
    DDRB &= ~(1<<PB0);  //B0 is cleared to set as input for SEAT

    DDRD &= ~(1<<PD2); //clear bit
    PORTD  &= ~(1<<PD2);  //HEATER interrupt

    EICRA |= (1<<ISC00);  //external interrupt control register
    EIMSK |= (1<<INT0);  //ext interrupt mask register ,set for INT0

    sei();
}
