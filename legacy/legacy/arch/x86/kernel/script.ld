ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)

SECTIONS {
    . = 0;

    .text : {
		*(.start)
		*(.text)
    }

    .rodata : {
		*(.rodata)
    }

    .data : {
		*(.data)
    }

    .bss : {
		*(.bss)
    }
}
