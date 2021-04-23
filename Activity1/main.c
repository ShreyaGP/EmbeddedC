#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned volatile FLAG =0;

int main(void)
{
    port();
    sei();
    while(1){
        if((PINB & (1<<PB0))){
        if(FLAG==1){
            PORTB  |= (1<<PB1);
            _delay_ms(1000);
            FLAG=0;
            }
        else{
            PORTB &= ~(1<<PB1);
            _delay_ms(100);
        }
        }
    }
    return 0;
}

ISR(INT0_vect)
{
    FLAG = 1;
}
