#ifndef LIBX_X86_CPU_CR0_H
#define LIBX_X86_CPU_CR0_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_CPU_CR0_PE 1
#define X86_CPU_CR0_MP (1 << 1)
#define X86_CPU_CR0_EM (1 << 2)
#define X86_CPU_CR0_TS (1 << 3)
#define X86_CPU_CR0_ET (1 << 4)
#define X86_CPU_CR0_NE (1 << 5)
#define X86_CPU_CR0_WP (1 << 16)
#define X86_CPU_CR0_AM (1 << 18)
#define X86_CPU_CR0_NW (1 << 29)
#define X86_CPU_CR0_CD (1 << 30)
#define X86_CPU_CR0_PG (1 << 31)

u32 x86_cpu_cr0();
void x86_cpu_cr0_set(u32 value);

#endif // LIBX_X86_CPU_CR0_H
