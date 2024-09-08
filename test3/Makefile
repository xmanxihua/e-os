CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

kernel.bin:kernel
	$(OBJCOPY) -O binary $< $@
kernel:startup.o kernel.ld main.o init.o abnormal.o
	$(LD) -T kernel.ld startup.o init.o main.o abnormal.o -o $@
startup.o:startup.s
	$(AS)  $< -o $@
init.o:init.s
	$(AS)  $< -o $@
abnormal.o:abnormal.s
	$(AS) $< -o $@
main.o:main.c
	$(CC) -g -c $< -o $@
clean:
	rm -f startup.o init.o kernel.bin kernel abnormal.o main.o