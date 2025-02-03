#include <memory.h>

r8 memory_set(void *dst, const u8 value, umax count)
{
    if (dst == NULL) return 1;
    while (count) ((u8 *) dst)[--count] = value;
    return 0;
}

r8 memory_copy(void *dst, const void *src, const umax count)
{
    const r8 rslt = memory_copy_unbuffered(dst, src, count);
    return rslt == 3 ? memory_copy_buffered(dst, src, count) : rslt;
}

r8 memory_copy_unbuffered(void *__restrict__ dst, const void *__restrict__ src, umax count)
{
    if (dst == NULL) return 1;
    if (src == NULL) return 2;
    if (src <= dst && src + count > dst || src >= dst && src < dst + count) return 3;
    while (count) ((u8 *) dst)[--count] = ((u8 *) src)[count];
    return 0;
}

r8 memory_copy_buffered(void *dst, const void *src, const umax count)
{
    if (dst == NULL) return 1;
    if (src == NULL) return 2;
    if (!count) return 0;
    u8 *tmp;
    if (MEMORY_ALLOCATE_UNALIGNED(&tmp, count)) return 3;
    umax i = count;
    while (i) tmp[--i] = ((u8 *) src)[i];
    i = count;
    while (i) ((u8 *) dst)[--i] = tmp[i];
    return MEMORY_FREE(&tmp) ? 4 : 0;
}
