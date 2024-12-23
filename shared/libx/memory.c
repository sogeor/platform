#include <libx/memory.h>

void mem_set(void *dst, const u8 value, umax count)
{
    while (count) ((u8 *) dst)[--count] = value;
}

r8 mem_copy(void *__restrict__ dst, const void *__restrict__ src, umax count)
{
    if (!count) return 0;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 1;
    while (count) ((u8 *) dst)[--count] = ((u8 *) src)[count];
    return 0;
}
