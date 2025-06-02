# Target name
TARGET = usb_stack

# Toolchain
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# MCU & flags (STM32L433RC - Cortex-M4)
MCU = cortex-m4
CFLAGS = -mcpu=$(MCU) -mthumb -O0 -g -Wall -ffreestanding -nostdlib
LDFLAGS = -Tlinker.ld -nostdlib
ASFLAGS = -mcpu=$(MCU) -mthumb

# Paths
SRC = src
INC = inc
STARTUP = startup
DEVICE = device

# Files
C_SOURCES = $(wildcard $(SRC)/*.c)
ASM_SOURCES = $(STARTUP)/startup_stm32l433rc.S
OBJS = $(C_SOURCES:.c=.o) $(ASM_SOURCES:.S=.o)

# Default target
all: $(TARGET).bin $(TARGET).hex

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I$(DEVICE) -c $< -o $@

# Compile assembly files
%.o: %.S
	$(CC) $(ASFLAGS) -c $< -o $@

# Linking
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@

# Binary output
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Intel HEX output
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# Clean
clean:
	rm -f $(SRC)/*.o
	rm -f $(STARTUP)/*.o
	rm -f *.elf *.bin *.hex

.PHONY: all clean
