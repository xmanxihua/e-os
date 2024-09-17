.section .startup,"ax"
.code 32
.align 0
.global _start

.extern set_up_mmu
.extern copy_image

_start:
    ldr sp,=0x20000-4
    bl set_up_mmu
    bl copy_image
    ldr pc, =0xC0200000


