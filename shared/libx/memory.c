#include <libx/memory.h>

void mem_set(const ptr dst, const u8 value, umax count)
{
    if (!count) return;
    do
    {
        --count;
        ((u8 *) dst)[count] = value;
    } while (count);
}

r8 mem_copy(const ptr dst, const ptrc src, umax count)
{
    if (!count) return 0;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 1;
    do
    {
        --count;
        ((u8 *) dst)[count] = ((u8 *) src)[count];
    } while (count);
    return 0;
}

r8 mem_move(const ptr dst, const ptr src, const u8 value, umax count)
{
    if (!count) return 0;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 1;
    do
    {
        --count;
        ((u8 *) dst)[count] = ((u8 *) src)[count];
        ((u8 *) src)[count] = value;
    } while (count);
    return 0;
}
