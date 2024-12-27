#ifndef LIBX_X86_CPU_CR4_H
#define LIBX_X86_CPU_CR4_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_CPU_CR4_VME 1
#define X86_CPU_CR4_PVI (1 << 1)
#define X86_CPU_CR4_TSD (1 << 2)
#define X86_CPU_CR4_DE (1 << 3)
#define X86_CPU_CR4_PSE (1 << 4)
#define X86_CPU_CR4_PAE (1 << 5)
#define X86_CPU_CR4_MCE (1 << 6)
#define X86_CPU_CR4_PGE (1 << 7)
#define X86_CPU_CR4_PCE (1 << 8)
#define X86_CPU_CR4_OSFXSR (1 << 9)
#define X86_CPU_CR4_OSXMMEXCPT (1 << 10)
#define X86_CPU_CR4_UMIP (1 << 11)
#define X86_CPU_CR4_VMXE (1 << 13)
#define X86_CPU_CR4_SMXE (1 << 14)
#define X86_CPU_CR4_FSGSBASE (1 << 16)
#define X86_CPU_CR4_PCIDE (1 << 17)
#define X86_CPU_CR4_OSXSAVE (1 << 18)
#define X86_CPU_CR4_SMEP (1 << 20)
#define X86_CPU_CR4_SMAP (1 << 21)
#define X86_CPU_CR4_PKE (1 << 22)
#define X86_CPU_CR4_CET (1 << 23)
#define X86_CPU_CR4_PKS (1 << 24)

u32 x86_cpu_cr4();
void x86_cpu_cr4_set(u32 value);

#endif // LIBX_X86_CPU_CR4_H
