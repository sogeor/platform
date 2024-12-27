#include <libx/x86/cpu/cr8.h>

inline u32 x86_cpu_cr8()
{
    u32 value;
    ASM VOLATILE("mov %%cr8, %0" : "=r"(value));
    return value;
}

inline void x86_cpu_cr8_set(u32 value)
{
    ASM VOLATILE("mov %0, %%cr8" : : "r"(value));
}
