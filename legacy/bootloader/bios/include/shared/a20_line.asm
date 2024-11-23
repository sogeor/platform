extern halt
extern println

global a20_line_prepare
global a20_line_check
global a20_line_enable_using_bios
global a20_line_enable_using_ps2_controller
global a20_line_enable_using_fast_gate

section .a20_line
bits 16

a20_line_prepare:
    mov si, A20_LINE_PREPARE
    call println
    call a20_line_check
    cmp ax, 0
    jz .free
    call a20_line_enable_using_bios
    call a20_line_check
    cmp ax, 0
    jz .free
    call a20_line_enable_using_ps2_controller
    call a20_line_check
    cmp ax, 0
    jz .free
    call a20_line_enable_using_fast_gate
    call a20_line_check
    cmp ax, 0
    jz .free
    jmp halt
.free:
    ret

a20_line_check:
    mov si, A20_LINE_CHECK
    call println
    cli
    push ds
    push es
    push di
    push si
    xor ax, ax
    mov es, ax
    not ax
    mov ds, ax
    mov di, 0x500
    mov si, 0x510
    mov dl, byte [es:di]
    push dx
    mov dl, byte [ds:si]
    push dx
    mov byte [es:di], 0
    mov byte [ds:si], 0xFF
    cmp byte [es:di], 0xFF
    jz .disabled
.enabled:
    mov ax, 0
    jmp .free
.disabled:
    mov ax, 1
.free:
    pop dx
    mov byte [ds:si], dl
    pop dx
    mov byte [es:di], dl
    pop si
    pop di
    pop es
    pop ds
    sti
    ret

a20_line_enable_using_bios:
    mov si, A20_LINE_ENABLE_USING_BIOS
    call println
    mov ax, 0x2403
    int 0x15
    jb .not_supported
    cmp ah, 0
    jnz .not_supported
    mov ax, 0x2402
    int 0x15
    jb .could_not_get_status
    cmp ah, 0
    jnz .could_not_get_status
    cmp al, 1
    jz .already_enabled
    mov ax, 0x2401
    int 0x15
    jb .could_not_enable
    cmp ah, 0
    jnz .could_not_enable
.enabled:
    mov ax, 0
    ret
.not_supported:
    mov ax, 1
    ret
.could_not_get_status:
    mov ax, 2
    ret
.already_enabled:
    mov ax, 3
    ret
.could_not_enable:
    mov ax, 4
    ret

a20_line_enable_using_ps2_controller:
    mov si, A20_LINE_ENABLE_USING_PS2_CONTROLLER
    call println
    cli
    call .wait_1
    mov al, 0xAD
    out 0x64, al
    call .wait_1
    mov al, 0xD0
    out 0x64, al
    call .wait_2
    in al, 0x60
    push eax
    call .wait_1
    mov al, 0xD1
    out 0x64, al
    call .wait_1
    pop eax
    or al, 2
    out 0x60, al
    call .wait_1
    mov al, 0xAE
    out 0x64, al
    call .wait_1
    sti
    ret
.wait_1:
    in al, 0x64
    test al, 2
    jnz .wait_1
    ret
.wait_2:
    in al, 0x64
    test al, 1
    jz .wait_2
    ret

a20_line_enable_using_fast_gate:
    mov si, A20_LINE_ENABLE_USING_FAST_GATE
    call println
    in al, 0x92
    test al, 2
    jnz .free
    or al, 2
    and al, 0xFE
    out 0x92, al
.free:
    ret

A20_LINE_PREPARE: db 'Preparing the A20 line...', 0
A20_LINE_CHECK: db 'Checking the A20 line...', 0
A20_LINE_ENABLE_USING_BIOS: db 'Trying to enable the A20 line using the BIOS...', 0
A20_LINE_ENABLE_USING_PS2_CONTROLLER: db 'Trying to enable the A20 line using the PS/2 controller...', 0
A20_LINE_ENABLE_USING_FAST_GATE: db 'Trying to enable the A20 line using fast gate...', 0