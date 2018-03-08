
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CP = arm-none-eabi-objcopy
DMP = arm-none-eabi-objdump

CCFLAGS = -Wall -mcpu=cortex-m3 -mthumb -g -mfloat-abi=soft -march=armv7-m -nostdlib
LDFLAGS = -Tlink.lds -g
CPFLAGS = -Oihex

all:
	cd util && make util
	cd debug && make debug
	$(CC) $(CCFLAGS) -c *.c *.s
	$(LD) $(LDFLAGS) *.o -o main.elf
	$(CP) $(CPFLAGS) main.elf main.hex
	$(DMP) -d main.elf > main.txt
	if [ ! -x "output" ]; then mkdir output; fi
	mv main.elf output
	mv main.hex output
	mv main.txt output
	rm *.o
