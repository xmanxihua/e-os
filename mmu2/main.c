//
// Created by xihua on 24-9-1.
//
#include "mmu.h"
#include "utils.h"
#include "interrupt.h"
#include "timer.h"

typedef void (*init_func)(void);

typedef unsigned int uint32_t;

void copy_vectors() {
    asm (
            "mrc p15, 0, r0, c1, c0, 0    // 读取 CP15 控制寄存器到 r0\n"
            "orr r0, r0, #(1 << 13)       //设置 V 位（bit 13），即将 V=1\n"
            "mcr p15, 0, r0, c1, c0, 0    //写回 CP15 控制寄存器，启用高地址中断向量表\n"
            :: :"r0"
            );
    extern uint32_t _vectors_start;
    extern uint32_t _vectors_end;
    int i = 0;
    uint32_t *vectors_src = &_vectors_start;
    uint32_t *vectors_dst = (uint32_t *) 0xFFFF0000;

    while (vectors_src < &_vectors_end) {
        *vectors_dst = *vectors_src;
        ++vectors_src;
        ++vectors_dst;
    }


}


void helloworld(void) {
    char *p = "helloworld\n";
    printk("%s", p);
}

static init_func init[] = {
        copy_vectors,
        helloworld,
        uart0_init,
        timer_init,
        enable_irq,

};

void plat_boot(void) {
    int i;
    for (i = 0; i < sizeof(init) / sizeof(init_func); i++) {
        init[i]();
    }
    volatile unsigned int *p = 0x0FFFF000;
    *p = 1;
    printk("read p= %d\n", *p);
    while (1);
}
