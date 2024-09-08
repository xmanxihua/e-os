.global _vector_undefined
.global _vector_swi
.global _vector_prefetch_abort
.global _vector_data_abort
.global _vector_reserved
.global _vector_irq
.global _vector_fiq

.text
.code 32

_vector_undefined:
    nop
_vector_swi:
    nop
_vector_prefetch_abort:
    nop
_vector_data_abort:
    nop
_vector_reserved:
    nop
_vector_irq:
    nop
_vector_fiq:
    nop
