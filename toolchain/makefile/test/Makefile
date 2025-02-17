MCU = atmega328p
PROG = usbasp
PORT = usb

SRC_DIR ?= ejemplos   # Por defecto 'ejemplos'. (ejemplos, ejercicios o lib)
ARCHIVO ?= main_1.c   # Por defecto 'main_1.c'. (Nombre del archivo)

INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin

SRC = $(SRC_DIR)/$(ARCHIVO)
OBJ = $(BIN_DIR)/$(ARCHIVO:.c=.o)  

TARGET = main
HEX = $(BIN_DIR)/$(TARGET).hex

CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os -I$(INC_DIR) -I$(LIB_DIR)
LINKFLAGS = -mmcu=$(MCU)

AVRDUDE = avrdude
AVRDUDE_FLAGS = -c $(PROG) -p $(MCU) -P $(PORT)

.PHONY: all clean subir

all: $(HEX)

$(HEX): $(OBJ)
	$(CC) $(LINKFLAGS) -o $(BIN_DIR)/$(TARGET).elf $(OBJ)
	avr-objcopy -O ihex $(BIN_DIR)/$(TARGET).elf $(HEX)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

subir: $(HEX)
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(HEX):i

clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET).elf $(HEX)