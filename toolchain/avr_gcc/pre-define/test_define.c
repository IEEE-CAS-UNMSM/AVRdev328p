#define PORTB  *(unsigned volatile char*) 0x25
#define DDRB   *(unsigned volatile char*) 0x27
#define TCCR1B *(unsigned volatile char*) 0x81
#define TCNT1H *(unsigned volatile char*) 0x85
#define TCNT1L *(unsigned volatile char*) 0x84
#define TIMSK1 *(unsigned volatile char*) 0x6F
#define TIFR1  *(unsigned volatile char*) 0x36
#define SREG   *(unsigned volatile char*) 0x6E

void conmutar(); //prototipo de funcion
void reset();    //prototipo de funcion

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
void conmutar(){
    PORTB ^= (1<<0);
}

void reset(){
    TIFR1 = 0;
    TCNT1H = 0xC2;
    TCNT1L = 0xF7;
}