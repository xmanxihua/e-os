CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

test.bin:test
	$(OBJCOPY) -O binary $< $@
test:test.o test.ld helloworld.o
	$(LD) -T test.ld test.o helloworld.o -o $@
test.o:test.s
	$(AS)  $< -o $@
helloworld.o:helloworld.c
	$(CC) -g -c $< -o $@
clean:
	rm -f test.o test test.bin helloworld.o