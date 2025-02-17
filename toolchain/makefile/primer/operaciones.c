#define __AVR_ATmega328P__ 1
#include <avr/io.h>

void conmutar(){
    PORTB ^= (1<<0);
}

void reset(){
    TIFR1 = 0;
    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
}