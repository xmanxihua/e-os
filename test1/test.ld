ENTRY(helloworld)
SECTIONS
{
    . = 0x00010000;
    .text :{
        *(.text)
    }
    . = ALIGN(32);
    .data :{
        *(.data)
    }
    . = ALIGN(32);
    .bss :{
        *(.bss)
    }
}