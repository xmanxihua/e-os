//
// Created by xihua on 24-9-17.
//

#include "head.h"

void __attribute__((section(".startup"))) copy_image() {
    unsigned int *src = 0x10400;
    unsigned int *src_end = 102400 + src;
    unsigned int *dst = 0xC0200000;

    while (src < src_end) {
        *dst = *src;
        src++;
        dst++;
    }
}
