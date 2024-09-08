ENTRY(_start)
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
    . = . + 0x1000; /* 4kB of stack memory */
    stack_top = .;
}