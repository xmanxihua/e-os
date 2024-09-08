#ARCH = arm
CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
#LIBDIR=/home/xihua/develop/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi/lib/gcc/arm-none-eabi/11.2.1
LIBDIR=
# 查找当前目录下所有的 .c 和 .s 文件
SRC_C = $(wildcard *.c)
SRC_S = init.s startup.o

# 将 .c 和 .s 文件映射为相应的 .o 文件
OBJS := vector.o $(patsubst %.c, %.o, $(SRC_C)) $(patsubst %.s, %.o, $(SRC_S))


#   DEPFLAGS = -MMD -MP：用于让 gcc 生成 .d 文件，这些文件包含 .o 文件的依赖项。
#  -include $(OBJS:.o=.d)：包含所有生成的 .d 文件，自动跟踪 .h 文件的依赖。
#  .d 文件：存储 .o 文件与 .h 文件之间的依赖关系。

DEPFLAGS = -MMD -MP

kernel.bin:kernel
	$(OBJCOPY) -O binary $< $@
kernel:$(OBJS) kernel.ld
	#$(LD) -T kernel.ld $(OBJS)  -lgcc -o $@
	$(CC) -T kernel.ld $(OBJS) -o $@ -nostartfiles -nostdlib -lgcc
%.o:%.s
	$(AS) -g $< -o $@
%.o:%.c
	$(CC) -g $(DEPFLAGS) -c $< -o $@
clean:
	rm -f *.o kernel.bin kernel

# 包含自动生成的依赖文件
-include $(OBJS:.o=.d)