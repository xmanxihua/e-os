AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

test.bin:test
	$(OBJCOPY) -O binary $< $@
test:test.o test.ld
	$(LD) -T test.ld test.o -o $@
test.o:test.s
	$(AS)  $< -o $@
clean:
	rm test.o test test.bin