#define PORTB  *(unsigned volatile char*) 0x25
#define DDRB   *(unsigned volatile char*) 0x27
#define TCCR1B *(unsigned volatile char*) 0x81
#define TCNT1H *(unsigned volatile char*) 0x85
#define TCNT1L *(unsigned volatile char*) 0x84
#define TIMSK1 *(unsigned volatile char*) 0x6F
#define TIFR1  *(unsigned volatile char*) 0x36
#define SREG   *(unsigned volatile char*) 0x6E