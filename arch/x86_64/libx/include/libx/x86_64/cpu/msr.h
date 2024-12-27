#ifndef LIBX_X86_64_CPU_MSR_H
#define LIBX_X86_64_CPU_MSR_H

#include <libx/defs.h>
#include <libx/types.h>

#define X86_64_CPU_MSR_IA32_EFER 0xC0000080
#define X86_64_CPU_MSR_IA32_EFER_SCE 1
#define X86_64_CPU_MSR_IA32_EFER_LME (1 << 8)
#define X86_64_CPU_MSR_IA32_EFER_LMA (1 << 10)
#define X86_64_CPU_MSR_IA32_EFER_NXE (1 << 11)
#define X86_64_CPU_MSR_IA32_EFER_SVME (1 << 12)
#define X86_64_CPU_MSR_IA32_EFER_LMSLE (1 << 13)
#define X86_64_CPU_MSR_IA32_EFER_FFXSR (1 << 14)
#define X86_64_CPU_MSR_IA32_EFER_TCE (1 << 15)

#endif // LIBX_X86_64_CPU_MSR_H
