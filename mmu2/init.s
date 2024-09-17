.equ DISABLE_IRQ,       0x80
.equ DISABLE_FIQ,       0x40
.equ SYS_MOD,          0x1f
.equ IRQ_MOD,          0x12
.equ FIQ_MOD,          0x11
.equ SVC_MOD,          0x13
.equ ABT_MOD,          0x17
.equ UND_MOD,          0x1b

.equ MEM_SIZE,         0x10000
.equ TEXT_BASE,         0xC0400000
.equ _SVC_STACK,        (TEXT_BASE+MEM_SIZE-4)
.equ _IRQ_STACK,        (_SVC_STACK-0x400)
.equ _FIQ_STACK,        (_IRQ_STACK-0x400)
.equ _ABT_STACK,        (_FIQ_STACK-0x400)
.equ _UND_STACK,        (_ABT_STACK-0x400)
.equ _SYS_STACK,        (_UND_STACK-0x400)

.section .vectors,"ax"
.code 32
.align 0

.extern plat_boot
.extern __bss_start__
.extern __bss_end__

.global _vectors_start
.global _vectors_end

_vectors_start:
    ldr pc, =_vector_reset
    ldr pc, vector_undefined
    ldr pc, vector_swi
    ldr pc, vector_prefetch_abort
    ldr pc, vector_data_abort
    ldr pc, vector_reserved
    ldr pc, vector_irq
    ldr pc, vector_fiq

 vector_undefined: .word _vector_undefined
 vector_swi: .word _vector_swi
 vector_prefetch_abort: .word _vector_prefetch_abort
 vector_data_abort: .word _vector_data_abort
 vector_reserved: .word _vector_reserved
 vector_irq: .word _vector_irq
 vector_fiq: .word _vector_fiq
_vectors_end:

_vector_reset:

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|SVC_MOD)
    ldr sp,=_SVC_STACK

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|IRQ_MOD)
    ldr sp,=_IRQ_STACK

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|FIQ_MOD)
    ldr sp,=_FIQ_STACK

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|ABT_MOD)
    ldr sp,=_ABT_STACK

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|UND_MOD)
    ldr sp,=_UND_STACK

    msr cpsr_c, #(DISABLE_IRQ|DISABLE_FIQ|SYS_MOD)
    ldr sp,=_SYS_STACK

 _clear_bss:
    ldr r1, bss_start__
    ldr r3, bss_end__
    mov r2, #0x0

 1:
    cmp r1, r3
    beq _main
    str r2,[r1], #0x4
    b 1b
 _main:
    b plat_boot
    bx lr
 bss_start__:.word __bss_start__
 bss_end__:.word __bss_end__
 .end
