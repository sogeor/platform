#ifndef LIBX_X86_MISC_H
#define LIBX_X86_MISC_H

#include <libx/defs.h>
#include <libx/types.h>

u8 farpeekb(u16 selector, ptr offset);
u16 farpeekw(u16 selector, ptr offset);
u32 farpeekl(u16 selector, ptr offset);

void farpokeb(u16 selector, ptr offset, u8 value);
void farpokew(u16 selector, ptr offset, u16 value);
void farpokel(u16 selector, ptr offset, u32 value);

u8 inb(u16 port);
u16 inw(u16 port);
u32 inl(u16 port);

void outb(u16 port, u8 value);
void outw(u16 port, u16 value);
void outl(u16 port, u32 value);

void io_wait(void);

#endif // LIBX_X86_MISC_H
