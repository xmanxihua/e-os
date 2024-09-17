//
// Created by xihua on 24-9-7.
//

#include <stdint.h>
#include "interrupt.h"
#include "utils.h"
#include "timer.h"
#include "mmu.h"

#define UART0_BASE_ADDR (0x101f1000 + PA_OFFSET)
#define UART0_DR (*((volatile uint32_t *)(UART0_BASE_ADDR + 0x000)))
#define UART0_IMSC (*((volatile uint32_t *)(UART0_BASE_ADDR + 0x038)))

void enable_irq() {
    asm volatile (
            "mrs r4, cpsr\n\t"
            "bic r4,r4, #0x80\n\t"
            "msr cpsr,r4\n\t"
            :::"r4"
            );
}

void enable_intr(unsigned int offset) {
    VIC_INTENABLE = (1 << offset);
}

void common_irq_handler() {
    uint32_t irq_number = VIC_IRQ_STATUS;
//    printk("%s:%u\n", "common_irq_handler",irq_number);
    if (irq_number & 1<<12) {
        printk("%s\n", "uart interrupt");
        UART0_DR = UART0_DR;
    }else if (irq_number & 1<<4) {
        timer_handler();
    }
}

void uart0_init() {
    enable_intr(12);
    /* enable RXIM interrupt */
    UART0_IMSC = 1<<4;
}


void data_abort() {
    printk("%s\n", "data_abort");
}

void prefetch_abort() {
    printk("%s\n", "prefetch_abort");
}
