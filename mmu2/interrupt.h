//
// Created by xihua on 24-9-7.
//

#ifndef INTERRUPT_INTERRUPT_H
#define INTERRUPT_INTERRUPT_H
#include "mmu.h"
#define VIC_BASE_ADDR (0x10140000+PA_OFFSET)
#define VIC_IRQ_STATUS (*((volatile uint32_t *)(VIC_BASE_ADDR + 0x0)))
#define VIC_INTENABLE (*((volatile uint32_t *)(VIC_BASE_ADDR + 0x010)))

void enable_irq();
void enable_intr(unsigned int offset);

void uart0_init();

#endif //INTERRUPT_INTERRUPT_H
