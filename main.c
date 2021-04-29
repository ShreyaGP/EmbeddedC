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
    char *data;
    unsigned int i=0;
    pin_port();
    InitADC();
    PWM_pins();
    sei();
    while(1){
        if((PINB & (1<<SEAT))){   //To check if the seat is occupied
        if(HEATER==1){   //To check if heater is ON
            PORTB  |= (1<<LED);  //To turn on the LED
            _delay_ms(1000);
            HEATER=0;
            }
        else{
            PORTB &= ~(1<<LED); //To turn OFF the LED
            _delay_ms(100);
        }
        }
        temp=ReadADC(0);   //To read ADC value
        _delay_ms(200);
        PWM_output(temp);  //To produce PWM output
        if(temp>=0 && temp<=200)  //To send temperature through USART
            data="Temperature: 20 'C\n";
        else if(temp>=210 && temp<=500)
            data="Temperature: 25 'C\n";
        else if(temp>=510 && temp<=700)
           data="Temperature: 29 'C\n";
        else
           data="Temperature: 33 'C\n";
        while(data[i]!='\0'){
            Write_USART(data[i]);  
            i++;
        }
        i=0;
    }
    return 0;
}

/**
 * @brief Construct a new ISR object for INT0
 */
ISR(INT0_vect)
{
    HEATER = 1;
}