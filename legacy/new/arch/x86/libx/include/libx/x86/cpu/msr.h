#ifndef LIBX_X86_CPU_MSR_H
#define LIBX_X86_CPU_MSR_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_CPU_MSR_FS_BASE 0xC0000100
#define X86_CPU_MSR_GS_BASE 0xC0000101
#define X86_CPU_MSR_KERNEL_GS_BASE 0xC0000102

u64 x86_cpu_msr(u32 msr);
void x86_cpu_msr_set(u32 msr, u64 value);

#endif // LIBX_X86_CPU_MSR_H
