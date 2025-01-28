global __vbe_get_controller_info__
global __vbe_get_mode_info__
global __vbe_set_mode__
extern __vbe_controller_info
extern __vbe_mode_info
extern __vbe_mode_brief

section .vbe
bits 16

__vbe_get_controller_info__:
    push di
    push es
    xor ax, ax
    mov es, ax
    mov ax, 0x4F00
    mov di, __vbe_controller_info
    int 0x10
    pop es
    pop di
    ret

__vbe_get_mode_info__:
    push di
    push es
    xor ax, ax
    mov es, ax
    mov ax, 0x4F01
    mov di, __vbe_mode_info
    int 0x10
    pop es
    pop di
    ret

__vbe_set_mode__:
    push di
    push es
    xor ax, ax
    mov es, ax
    mov ax, 0x4F02
    mov di, __vbe_mode_info
    int 0x10
    pop es
    pop di
    ret