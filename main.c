/**
 * @file Activity1_main.c
 * @author Shreya
 * @brief Activity1 main function to switch on LED whenever the seat is occupied and there is a change in heater interrupt
 * @version 0.1
 * @date 2021-04-27
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED (PORTB2)
#define SEAT (PORTB0)
#define Heater_int (PORTD2)

unsigned volatile HEATER =0;

int main(void)
{
    uint16_t temp;
    pin_port();
    InitADC();
    PWM_pins();
    sei();
    while(1){
        if((PINB & (1<<SEAT))){
        if(HEATER==1){
            PORTB  |= (1<<LED);
            _delay_ms(1000);
            HEATER=0;
            }
        else{
            PORTB &= ~(1<<LED);
            _delay_ms(100);
        }
        }
        temp=ReadADC(0);
        _delay_ms(200);
        PWM_output(temp);
    }
    return 0;
}

ISR(INT0_vect)
{
    HEATER = 1;
}