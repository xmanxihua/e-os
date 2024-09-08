.section .startup,"ax"
.code 32
.align 0
.global _start
.global _vectors_start
.global _vectors_end
.extern _vector_reset
.extern _vector_undefined
.extern _vector_swi
.extern _vector_prefetch_abort
.extern _vector_data_abort
.extern _vector_reserved
.extern _vector_fiq
.extern _vector_irq

_start:
_vectors_start:
    ldr pc, vector_reset
    ldr pc, vector_undefined
    ldr pc, vector_swi
    ldr pc, vector_prefetch_abort
    ldr pc, vector_data_abort
    ldr pc, vector_reserved
    ldr pc, vector_irq
    ldr pc, vector_fiq

 vector_reset: .word _vector_reset
 vector_undefined: .word _vector_undefined
 vector_swi: .word _vector_swi
 vector_prefetch_abort: .word _vector_prefetch_abort
 vector_data_abort: .word _vector_data_abort
 vector_reserved: .word _vector_reserved
 vector_irq: .word _vector_irq
 vector_fiq: .word _vector_fiq
_vectors_end:


