subir: main.hex
	avrdude -P usb -c usbasp -p atmega328p -U flash:w:main.hex:i
main.hex:main.out
	avr-objcopy -O ihex main.out main.hex
main.out: main.o operaciones.o
	avr-gcc -mmcu=atmega328p main.o operaciones.o -o main.out
main.o: main.c
	avr-gcc -mmcu=atmega328p -c main.c -o main.o
operaciones.o: operaciones.c
	avr-gcc -mmcu=atmega328p -c operaciones.c -o operaciones.o