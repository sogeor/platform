#include <libx/x86/cpu/idtr.h>

inline void x86_cpu_idtr_set(ptr address)
{
    ASM VOLATILE("lidt %0" : : "m"(address));
}
