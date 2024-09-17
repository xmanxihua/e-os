CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

# 将 .c 和 .s 文件映射为相应的 .o 文件
OBJS := init.o mmu.o main.o timer.o utils.o interrupt.o vector.o

#   DEPFLAGS = -MMD -MP：用于让 gcc 生成 .d 文件，这些文件包含 .o 文件的依赖项。
#  -include $(OBJS:.o=.d)：包含所有生成的 .d 文件，自动跟踪 .h 文件的依赖。
#  .d 文件：存储 .o 文件与 .h 文件之间的依赖关系。

DEPFLAGS = -MMD -MP

kernel.img:kernel.bin boot.bin
	dd if=/dev/zero bs=1024 count=1 of=kernel.img
	dd if=boot.bin bs=1024 count=1 of=kernel.img conv=notrunc
	cat kernel.bin >> kernel.img

boot.bin:boot
	$(OBJCOPY) -O binary $< $@

boot:startup.o mmu.o head.o
	$(CC) -T boot.ld startup.o mmu.o head.o -o $@ -nostartfiles -nostdlib -lgcc

kernel.bin:kernel
	$(OBJCOPY) -O binary $< $@

kernel:$(OBJS) kernel.ld
	$(CC) -T kernel.ld $(OBJS) -o $@ -nostartfiles -nostdlib -lgcc

%.o:%.s
	$(AS) -g $< -o $@

%.o:%.c
	$(CC) -g $(DEPFLAGS) -c $< -o $@
clean:
	rm -f *.o *.d kernel.img kernel.bin kernel boot boot.bin

# 包含自动生成的依赖文件
-include $(OBJS:.o=.d)