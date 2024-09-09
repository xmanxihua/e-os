//
// Created by xmanxihua on 9/9/24.
//

#include "timer.h"
#include "interrupt.h"
#include "utils.h"

static unsigned int timer_count = 0;

void timer_init() {
    //120MHZ
    TIMER0_BG_LOAD  = 1000000;
//    TIMER0_LOAD  = 1000000;
    //timer0启用 设置周期模式 开启中断 1分之1 32位
    TIMER0_CONTROL |= 0b11100010;
    //开启时钟中断
    enable_intr(4);
}

void timer_handler() {
    //清除中断状态
    TIMER0_INT_CLEAR = 0 ;
    printk("%s: %d\n", "timer interrupt", ++timer_count);

}
