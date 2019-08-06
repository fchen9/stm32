
TOOLCHAIN_PATH = 

CC = $(TOOLCHAIN_PATH)/arm-none-eabi-gcc
OBJCPY = $(TOOLCHAIN_PATH)/arm-none-eabi-objcopy
GDB = $(TOOLCHAIN_PATH)/arm-none-eabi-gdb

C_CPU_FLAGS = -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mabi=aapcs
C_DEBUG_FLAGS = -g
C_OTHER_FLAGS = -ffunction-sections -fdata-sections
C_OPTIMIZATION_FLAGS = -O0
C_LANGUAGE_FLAGS = -std=c11

CFLAGS = $(C_CPU_FLAGS) $(C_DEBUG_FLAGS) $(C_OTHER_FLAGS) $(C_OPTIMIZATION_FLAGS)
LD_FLAGS = -T cortex_m4.ld -Wl,-Map=project.map -Wl,--gc-sections -nostartfiles

SOURCES = vector_table.c interrupt.c application.c
OBJECTS = $(SOURCES:.c=.o)

all: project.hex project.bin

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS)
 
project.elf: $(OBJECTS)
	$(CC) -o $@ $(C_CPU_FLAGS) $(LD_FLAGS) $^
 
project.bin: project.elf
	$(OBJCPY) -O binary $^ $@
 
project.hex: project.elf
	$(OBJCPY) -O ihex $^ $@
 
clean:
rm -rf *.o *.elf *.bin *.hex *.map