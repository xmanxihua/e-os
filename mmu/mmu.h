#ifndef __MMU_H__
#define __MMU_H__

//页目录表的地址
#define PG_CONTENT_ADDR 0x40000
//页表起始地址
#define PG_TABLE_ADDR (PG_CONTENT_ADDR+(1<<14))

//虚拟地址和物理地址便宜量
#define PA_OFFSET 0x00000000

#define PAGE_SIZE 4096


void set_up_mmu();
//页目录项结构
//typedef struct page_content_item {
//    unsigned int valid:1;
//    unsigned int type:1;
//    unsigned int domain:3;
//    unsigned int zero:4;
//    //no-secure
//    unsigned int ns:1;
//    //页表基地址
//    unsigned int page_table_base:22;
//} page_content_item;

#define FIRST_LARGE_TAG 0b01
#define _4 1<<4
#define DOMAIN (0<<5)
#define PAGE_TABLE_BASE(x) ((x) & 0xFFFFFC00)
#define PAGE_CONTENT_ITEM(x) PAGE_TABLE_BASE(x) | DOMAIN | _4 | FIRST_LARGE_TAG

////页表项结构
//typedef struct page_table_item {
//    //必须为1 表示是有效的小页项
//    unsigned int valid:1;
//    //B位 是否可以缓冲
//    unsigned int b:1;
//    //C位，是否可以缓存
//    unsigned int c:1;
//    //AP 位访问权限位
//    unsigned int ap:3;
//    //必须为0
//    unsigned int zero:1;
//    //nG,指示该小页是否为非全局页表项
//    //S 指示该小页是否是共享内存
//    unsigned int s:1;
//    //XN 指示该小页是否禁止执行
//    unsigned int xn:1;
//    //APX位，扩展访问权限
//    unsigned int apx:2;
//    //页基地址
//    unsigned int page_base:20;
//} page_table_item;

#define SECOND_SMALL_TAG 0b10
#define BUFFER 0
#define CACHE 0
#define AP 0
#define S 0
#define XN 0
#define APX 0
#define PAGE_BASE(x) ((x) & 0xFFFFF000)

#define PAGE_TABLE_ITEM(x) PAGE_BASE(x) | CACHE | BUFFER | SECOND_SMALL_TAG

#endif //__MMU_H__