#include "mmu.h"
#include "utils.h"
void start_mmu(void);
//32M
void set_up_mmu() {
    // 0x00000000 - 0x07FFFFFF: 32 MB SDRAM
    // 4KB一页 8192 页
    // 页表 = 8192/1024 = 8
    //页目录项 8
    //4GB 空间  4096 x 256 x 4096 = 2^12 x 2^8 x 2^12
    //
    //32 个内存页目录项
    //0-0x100000
    //0x100000-0x200000
    //0x200000-0x300000
    //0x300000-0x400000
    //0x500000-0x600000
    //0x700000-0x800000
    //0x900000-0xA00000
    //0xA00000-0xB00000
    //0xB00000-0xC00000
    //....
    //0x1f00000-0x2000000

    //页目录表放在 0x20000 128KB位置
    unsigned int *ppci = (unsigned int *) PG_CONTENT_ADDR;
    unsigned int *ppti = (unsigned int *) PG_TABLE_ADDR;
    unsigned int page_base = 0;
    for (int i = 0; i < 1320; ++i) {

        *ppci = PAGE_CONTENT_ITEM((unsigned int)ppti);

        for (int j = 0; j < 256; j++) {
           *ppti = PAGE_TABLE_ITEM(page_base);
            ppti++;
            page_base += PAGE_SIZE;
        }
        ppci++;
    }

    start_mmu();
}

void start_mmu(void) {
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

void data_abort() {
    printk("%s\n","data_abort");
}

void prefetch_abort() {
    printk("%s\n","prefetch_abort");
}