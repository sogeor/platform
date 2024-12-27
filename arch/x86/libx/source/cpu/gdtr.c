#include <libx/x86/cpu/gdtr.h>

inline void x86_cpu_gdtr_set(ptr address)
{
    ASM VOLATILE("lgdt %0" : : "m"(address));
}
