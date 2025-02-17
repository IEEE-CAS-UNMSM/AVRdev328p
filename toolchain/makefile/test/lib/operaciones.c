#include "../include/definiciones.h"
#include "operaciones.h"

void conmutar(){
    PORTB ^= (1<<0);
}

void reset(){
    TIFR1 = 0;
    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
}