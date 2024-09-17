ENTRY(_vectors_start)
SECTIONS
{
    . = 0xC0200000;
    .text : {
        *(.vectors)
        *(.text)
    }
    . = ALIGN(32);
    .data :{
        *(.data)
    }
    . = ALIGN(32);
    __bss_start__ = .;
    .bss :{
        *(.bss)
    }
    __bss_end__ =.;
}