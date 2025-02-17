#define __AVR_ATmega328P__ 1
#include <avr/io.h>
#include "../lib/operaciones.h"

int ciclo = 0;
int main(){
	DDRB |= (1<<0); //Salida PB0
	TCCR1B |= (1<<2)|(1<<1)|(1<<1); // PRE: 1024
	TIMSK1 |= (1<<0);
	TCNT1H = 0xC2;
	TCNT1L = 0xF7; 
	while(1){
		if(TIFR1 & (1<<0)){
            conmutar();
            ciclo++;
            if (ciclo == 2){
                reset();
                ciclo = 0;
                }
		}
	}
}