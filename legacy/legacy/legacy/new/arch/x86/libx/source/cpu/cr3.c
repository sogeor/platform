#include <libx/x86/cpu/cr3.h>

inline u32 x86_cpu_cr3()
{
    u32 value;
    ASM VOLATILE("mov %%cr3, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_cr3_set(u32 value)
{
    ASM VOLATILE("mov %0, %%cr3" : : "r"(value));
}
