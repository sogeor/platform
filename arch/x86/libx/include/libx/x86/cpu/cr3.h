#ifndef LIBX_X86_CPU_CR3_H
#define LIBX_X86_CPU_CR3_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_CPU_CR3_PWT (1 << 3)
#define X86_CPU_CR3_PCD (1 << 4)
#define X86_CPU_CR3_PDBR (0xFFFFF << 12)

u32 x86_cpu_cr3();
void x86_cpu_cr3_set(u32 value);

#endif // LIBX_X86_CPU_CR3_H
