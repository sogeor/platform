#include <libx/x86/cpu/ldtr.h>

inline void x86_cpu_ldtr_set(ptr address)
{
    ASM VOLATILE("lldt %0" : : "m"(address));
}
