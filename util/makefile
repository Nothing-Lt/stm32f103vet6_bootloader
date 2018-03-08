CC=arm-none-eabi-gcc

CCFLAGS = -Wall -mcpu=cortex-m3 -mthumb -g -mfloat-abi=soft -march=armv7-m -nostdlib

util:
	$(CC) $(CCFLAGS) -c *.c
	mv *.o ../ 