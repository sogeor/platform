org 0x7C00
bits 16

%if BOOT_SIZE > 43
%error "not enough space in low memory under header sector"
%endif

jmp 0:l0
l0:
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov fs, ax
    mov gs, ax
    mov bp, 0x24FF
    mov sp, bp
    mov ah, 0x42
    mov si, dap
    int 13h
    jc .die
    test ah, ah
    je 0x2500
.die:
    mov ah, 0xE
    mov bx, 0
    mov cx, 29
    mov si, .m
.lp:
    lodsb
    int 10h
    loop .lp
.h:
    hlt
    jmp .h
.m: db "Failed to read rstage sectors"

dap:
dap_size: db 16
dap_reserved: db 0
%if BOOT_SIZE > 127
dap_number: dw 127
%else
dap_number: dw BOOT_SIZE
%endif
dap_offset: dw 0x2500
dap_segment: dw 0
dap_lba_low: dd 1
dap_lba_up: dw 0
dap_lba_extra: dw 0

times 440 - ($ - $$) db 0
times 6 db 0

p1: times 16 db 0
p2: times 16 db 0
p3: times 16 db 0
p4: times 16 db 0

dw 0xAA55
