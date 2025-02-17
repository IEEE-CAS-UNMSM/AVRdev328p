#include "../include/definiciones.h"
#include "../lib/operaciones.h"

int main(){
    DDRB |= (1<<0);
    //Salida PB0
    TCCR1B |= (1<<2)|(1<<1)|(1<<0);//PRE: 1024
    TIMSK1 |= (1<<0);
    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
    while(1){
        if(TIFR1 & (1<<0)){
            conmutar();
            reset();
        }
    }
}