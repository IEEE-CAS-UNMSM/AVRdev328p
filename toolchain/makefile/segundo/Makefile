MCU = atmega328p
PROG = usbasp
PORT = usb

SRC_DIR = ../primer
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/operaciones.c
OBJ = $(SRC_DIR)/main.o $(SRC_DIR)/operaciones.o
TARGET = main
HEX = $(TARGET).hex

CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os
LINKFLAGS = -mmcu=$(MCU)

AVRDUDE = avrdude
AVRDUDE_FLAGS = -c $(PROG) -p $(MCU) -P $(PORT)

.PHONY: all clean

all: $(HEX)

$(HEX): $(OBJ)
	$(CC) $(LINKFLAGS) -o $(TARGET).out $(OBJ)
	avr-objcopy -O ihex $(TARGET).out $(HEX)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

subir: $(HEX)
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(HEX):i

clean:
	rm -f $(OBJ) $(TARGET).out $(HEX)