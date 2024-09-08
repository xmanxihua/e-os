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
    ldr pc, _vector_reset
    ldr pc, _vector_undefined
    ldr pc, _vector_swi
    ldr pc, _vector_prefetch_abort
    ldr pc, _vector_data_abort
    ldr pc, _vector_reserved
    ldr pc, _vector_irq
    ldr pc, _vector_fiq
_vectors_end:

.align 4
    _vector_reset: .word _vector_reset
    _vector_undefined: .word _vector_undefined
    _vector_swi: .word _vector_swi
    _vector_prefetch_abort: .word _vector_prefetch_abort
    _vector_data_abort: .word _vector_data_abort
    _vector_reserved: .word _vector_reserved
    _vector_irq: .word _vector_irq
    _vector_fiq: .word _vector_fiq
