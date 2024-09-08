//
// Created by xihua on 24-9-1.
//
#include "mmu.h"
#include "utils.h"
#include "interrupt.h"

typedef void (*init_func)(void);

#define UFCON0  ((volatile unsigned int *)(0x101f1000))
typedef unsigned int uint32_t;

void copy_vectors() {
    extern uint32_t _vectors_start;
    extern uint32_t _vectors_end;
    int i = 0;
    uint32_t *vectors_src = &_vectors_start;
    uint32_t *vectors_dst = (uint32_t *) 0;

    while (vectors_src < &_vectors_end)
        *vectors_dst++ = *vectors_src++;
}


void helloworld(void) {
    char *p = "helloworld\n";
    printk("%s", p);
}

static init_func init[] = {
        copy_vectors,
        set_up_mmu,
        helloworld,
        enable_irq,
        uart0_init,

};

void plat_boot(void) {
    int i;
    for (i = 0; i < sizeof(init) / sizeof(init_func); i++) {
        init[i]();
    }
    while (1);
}
