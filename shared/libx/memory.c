#include <libx/memory.h>

void mem_set(void *RESTRICT dst, const u8 value, umax count)
{
    if (count == 0) return;
    do
    {
        --count;
        ((u8 *) dst)[count] = value;
    } while (count);
}

r8 mem_copy(void *RESTRICT dst, const void *RESTRICT src, umax count)
{
    if (count == 0) return 0;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 1;
    do
    {
        --count;
        ((u8 *) dst)[count] = ((u8 *) src)[count];
    } while (count);
    return 0;
}

r8 mem_move(void *RESTRICT dst, void *RESTRICT src, const u8 value, umax count)
{
    if (count == 0) return 0;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 1;
    do
    {
        --count;
        ((u8 *) dst)[count] = ((u8 *) src)[count];
        ((u8 *) src)[count] = value;
    } while (count);
    return 0;
}
