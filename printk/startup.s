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
.extern _vector_irq
.extern _vector_fiq

_start:
_vectors_start:
    ldr pc, =_vector_reset
    ldr pc, =_vector_undefined
    ldr pc, =_vector_swi
    ldr pc, =_vector_prefetch_abort
    ldr pc, =_vector_data_abort
    ldr pc, =_vector_reserved
    ldr pc, =_vector_irq
    ldr pc, =_vector_fiq
_vectors_end:


