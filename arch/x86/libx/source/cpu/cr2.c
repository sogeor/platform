#include <libx/x86/cpu/cr2.h>

inline u32 x86_cpu_cr2()
{
    u32 value;
    ASM VOLATILE("mov %%cr2, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_cr2_set(u32 value)
{
    ASM VOLATILE("mov %0, %%cr2" : : "r"(value));
}
