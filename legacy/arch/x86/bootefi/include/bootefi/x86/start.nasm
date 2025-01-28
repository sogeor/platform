section .start
bits 32

extern _start
_start:
    hlt
    jmp _start
