#ifndef LIBX_X86_CPU_CR8_H
#define LIBX_X86_CPU_CR8_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_CPU_CR8_TPL 0xF

u32 x86_cpu_cr8();
void x86_cpu_cr8_set(u32 value);

#endif // LIBX_X86_CPU_CR8_H
