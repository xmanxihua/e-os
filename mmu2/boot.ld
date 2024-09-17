ENTRY(_start)
SECTIONS
{
    . = 0x00010000;
    .text : {
        *(.startup)
        *(.text)
    }
    . = ALIGN(32);
    .data :{
        *(.data)
    }
}