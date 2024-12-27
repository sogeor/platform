bits 16
org 0x600

struc prt
.status: resb 1
.start_chs: resb 3
.type: resb 1
.end_chs: resb 3
.lba: resd 1
.sectors: resd 1
endstruc

p1:
%if P1_STATUS == "bootable"
    db 0x80
%else
    db 0
%endif
    db 0, 0, 0
%if P1_TYPE == "bootable"
    db 0x80
%else
    db 0
%endif

istruc prt
at prt.status, db P1_STATUS
at prt.base_chs, db 0, 0, 0
at prt.type, db 0
at prt.end_chs, db 0, 0, 0
at prt.base_lba, dd 0
at prt.number_of_sectors, dd 0
iend

dw 0xAA55
