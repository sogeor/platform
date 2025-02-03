ENTRY(_start)

SECTIONS {
    . = 0x500;
    _stack_start = .;
    . = 0x7c00;
    _stack_end = .;

    _mbr_start = .;
    .boot :
    {
        *(.boot .boot.*)
    }
    .text :
    {
        *(.text .text.*)
    }
    .rodata :
    {
        *(.rodata .rodata.*)
    }
    .data :
    {
        *(.rodata .rodata.*)
        *(.data .data.*)
        *(.got .got.*)
    }
    _mbr_end = .;

    . = 0x7c00 + 446;
    _partition_table = .;
    .partition_table :
    {
        QUAD(0)
        QUAD(0)
        QUAD(0)
        QUAD(0)
        QUAD(0)
        QUAD(0)
        QUAD(0)
        QUAD(0)
    }

    . = 0x7c00 + 510;

    .magic_number :
    {
        SHORT(0xaa55)
    }

    _second_stage_start = .;
}
