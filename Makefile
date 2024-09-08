CC=arm-none-eabi-gcc
helloworld.bin: helloworld
	arm-none-eabi-objcopy -O binary $< $@
helloworld: helloworld.o
	arm-none-eabi-ld -e helloworld -Ttext 0x10000 $< -o $@
helloworld: helloworld.c
	arm-none-eabi-gcc -g -c $< -o $@
clean:
	rm -rf helloworld.o helloworld helloworld.bin
