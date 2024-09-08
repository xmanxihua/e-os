.global _start
.equ REG_FIFO, 0x101f1000
.text
.align 2
_start:
    LDR sp, =stack_top
    ldr r0, =REG_FIFO
    adr r1, .L0
    bl helloworld
.L1:
    b .L1
.align 2
.L0:
    .ascii "helloworld\n\0"