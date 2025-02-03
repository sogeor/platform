#include <libx/x86/cpu/tsc.h>

inline u64 x86_cpu_tsc()
{
    u64 value;
    ASM VOLATILE("rdtsc" : "=A"(value));
    return value;
}
