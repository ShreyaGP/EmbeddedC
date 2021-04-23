#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED (PORTB1)
#define SEAT (PORTB0)

unsigned volatile HEATER =0;

int main(void)
{
    port();
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
    }
    return 0;
}

ISR(INT0_vect)
{
    HEATER = 1;
}
