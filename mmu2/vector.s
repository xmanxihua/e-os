.global _vector_undefined
.global _vector_swi
.global _vector_prefetch_abort
.global _vector_data_abort
.global _vector_reserved
.global _vector_irq
.global _vector_fiq
.extern common_irq_handler

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
    sub r14, r14, #4
    stmfd r13!,{r0-r3,r14}
    bl common_irq_handler
    ldmfd r13!,{r0-r3,pc}^
_vector_fiq:
    nop
