#include <libx/x86/cpu/msr.h>

inline u64 x86_cpu_msr(u32 msr)
{
    u32 value;
    ASM VOLATILE("mov %%cr0, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_msr_set(u32 msr, u64 value)
{
    ASM VOLATILE("mov %0, %%cr0" : : "r"(value));
}
