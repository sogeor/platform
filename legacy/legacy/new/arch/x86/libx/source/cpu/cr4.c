#include <libx/x86/cpu/cr4.h>

inline u32 x86_cpu_cr4()
{
    u32 value;
    ASM VOLATILE("mov %%cr4, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_cr4_set(u32 value)
{
    ASM VOLATILE("mov %0, %%cr4" : : "r"(value));
}
