CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m4 -mthumb -O2 -g -ffreestanding -fdata-sections -ffunction-sections -Wall

LDFLAGS = -Tquickfeather.ld -nostartfiles -Wl,--gc-sections
SRC = main.c \
      gpio.c \
      delay.c \
      startup_EOSS3B_GCC.c \
      vectors_CM4F_gcc.c
OBJ = $(SRC:.c=.o)

TARGET = main

all: $(TARGET).bin

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.elf *.bin
