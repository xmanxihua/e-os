#include "mmu.h"
#include "utils.h"

void start_mmu(void);

void __attribute__((section(".startup"))) set_up_mmu() {

    unsigned int *ppci = ((unsigned int *) PG_CONTENT_ADDR) + 3072;
    unsigned int *ppti = (unsigned int *) PG_TABLE_ADDR;
    unsigned int page_base = 0;
    //1G
    for (int i = 0; i < 1024; ++i) {

        *ppci = PAGE_CONTENT_ITEM((unsigned int) ppti);

        if (i==1023) {
            page_base = 0;
        }
        for (int j = 0; j < 256; j++) {
            *ppti = PAGE_TABLE_ITEM(page_base);
            ppti++;
            page_base += PAGE_SIZE;
        }
        ppci++;
    }

    //0xFFFF0000

    ppci = (unsigned int *) PG_CONTENT_ADDR;
    page_base = 0;
    //1M
    for (int i = 0; i < 10; ++i) {

        *ppci = PAGE_CONTENT_ITEM((unsigned int) ppti);

        for (int j = 0; j < 256; j++) {
            *ppti = PAGE_TABLE_ITEM(page_base);
            ppti++;
            page_base += PAGE_SIZE;
        }
        ppci++;
    }

    start_mmu();
}

void __attribute__((section(".startup"))) start_mmu(void) {
    unsigned int ttb = PG_CONTENT_ADDR;
    asm(
            "mcr p15,0,%0,c2,c0,0\n"
            "mvn r0,#0b10\n"
            "mcr p15,0,r0,c3,c0,0\n"
            "mov r0,#0x1\n"
            "mcr p15,0,r0,c1,c0,0\n"
            "mov r0,r0\n"
            "mov r0,r0\n"
            "mov r0,r0\n"
            :
            : "r" (ttb)
            :"r0"
            );
}
