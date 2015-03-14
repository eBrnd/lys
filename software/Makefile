FORMAT = ihex
MCU = atmega168a
AVRDUDE_MCU = m168
CC = avr-gcc
F_CPU = 20000000UL
CFLAGS += -Wall -g -Os -mmcu=$(MCU) -std=gnu99 -pedantic-errors -D F_CPU=$(F_CPU)
LDFLAGS +=
OBJCOPY = avr-objcopy
FUSES = -U lfuse:w:0xce:m -U hfuse:w:0xdf:m -U efuse:w:0xf9:m
PROGRAMMER = usbasp

TARGET = lys

SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, ${SOURCES})

.PHONY: all program fuses clean

all: $(TARGET).hex

program: $(TARGET).hex
	avrdude -p $(AVRDUDE_MCU) -c $(PROGRAMMER) -U flash:w:$(TARGET).hex

fuses:
	avrdude -p $(AVRDUDE_MCU) -c $(PROGRAMMER) $(FUSES)


$(TARGET).elf: $(OBJS)
	$(CC) -mmcu=$(MCU) -o $@ $(OBJS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f $(TARGET).hex $(TARGET).elf $(OBJS)
