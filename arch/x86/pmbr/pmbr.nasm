bits 16
org 0x7C00

; TODO: rewrite it completely

struc partition_s
.status: resb 1
.base_chs: resb 3
.type: resb 1
.end_chs: resb 3
.base_lba: resd 1
.number_of_sectors: resd 1
endstruc

jmp 0:_die
_die:
    mov si, msg
    lodsb
    mov cl, al
    xor ch, ch
    mov ah, 0xE
.print:
    mov bx, 0
    lodsb
    int 10h
    loop .print
    cli

_hlt:
    hlt
    jmp _hlt

times 218 - ($ - $$) db 0

dw 0 ; reserved
db 0x80 ; the original physical drive
db 0
db 0
db 0

msg: db 46, "MBR isn't supported, so booting isn't possible"

times 440 - ($ - $$) db 0

dd 0 ; the disk signature
dw 0 ; the read-write state of the drive

struc partition_s
.status: resb 1
.base_chs: resb 3
.type: resb 1
.end_chs: resb 3
.base_lba: resd 1
.number_of_sectors: resd 1
endstruc

partition_1:
istruc partition_s
at partition_s.status, db 0
at partition_s.base_chs, db 0, 2, 0
at partition_s.type, db 0xEE
at partition_s.end_chs, db 0xFF, 0xFF, 0xFF
at partition_s.base_lba, dd 1
at partition_s.number_of_sectors, dd 0xFFFFFFFF
iend

partition_2:
istruc partition_s
at partition_s.status, db 0
at partition_s.base_chs, db 0, 0, 0
at partition_s.type, db 0
at partition_s.end_chs, db 0, 0, 0
at partition_s.base_lba, dd 0
at partition_s.number_of_sectors, dd 0
iend

partition_3:
istruc partition_s
at partition_s.status, db 0
at partition_s.base_chs, db 0, 0, 0
at partition_s.type, db 0
at partition_s.end_chs, db 0, 0, 0
at partition_s.base_lba, dd 0
at partition_s.number_of_sectors, dd 0
iend

partition_4:
istruc partition_s
at partition_s.status, db 0
at partition_s.base_chs, db 0, 0, 0
at partition_s.type, db 0
at partition_s.end_chs, db 0, 0, 0
at partition_s.base_lba, dd 0
at partition_s.number_of_sectors, dd 0
iend

dw 0xAA55
