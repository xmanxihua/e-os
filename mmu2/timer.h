//
// Created by xmanxihua on 9/9/24.
//

#ifndef INTERRUPT_TIMER_H
#define INTERRUPT_TIMER_H
#include "mmu.h"

#define TIMER0_BASE (0x101E2000+PA_OFFSET)

//设置计数器值 寄存器，即时生效
#define TIMER0_LOAD (*((volatile unsigned int *)(TIMER0_BASE+0x00)))
//清除中断寄存器
#define TIMER0_INT_CLEAR (*((volatile unsigned int *)(TIMER0_BASE+0x0C)))
//设置计数器值 寄存器，不是即时生效
#define TIMER0_BG_LOAD (*((volatile unsigned int *)(TIMER0_BASE+0x18)))
//控制寄存器 设置 周期模式  开启中断 启用计时器
#define TIMER0_CONTROL (*((volatile unsigned int*)(TIMER0_BASE+0x08)))

void timer_init();
void timer_handler();
#endif //INTERRUPT_TIMER_H
