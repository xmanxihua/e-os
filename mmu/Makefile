CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

kernel.bin:kernel
	$(OBJCOPY) -O binary $< $@
kernel:startup.o kernel.ld main.o init.o vector.o mmu.o
	$(LD) -T kernel.ld startup.o init.o main.o vector.o mmu.o -o $@
startup.o:startup.s
	$(AS)  $< -o $@
init.o:init.s
	$(AS)  $< -o $@
vector.o:vector.s
	$(AS) $< -o $@
mmu.o:mmu.c mmu.h
	$(CC) -g -c mmu.c -o $@
main.o:main.c
	$(CC) -g -c $< -o $@
clean:
	rm -f *.o kernel.bin kernel