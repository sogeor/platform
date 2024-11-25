#include <libx/x86/cpu/cr0.h>

inline u32 x86_cpu_cr0()
{
    u32 value;
    ASM VOLATILE("mov %%cr0, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_cr0_set(u32 value)
{
    ASM VOLATILE("mov %0, %%cr0" : : "r"(value));
}
