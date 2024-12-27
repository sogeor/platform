#ifndef LIBX_X86_CPUID_H
#define LIBX_X86_CPUID_H

#include <libx/types.h>

void cpuid(int code, u32 *eax, u32 *edx);

#endif // LIBX_X86_CPUID_H
