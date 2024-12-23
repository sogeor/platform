#include <libx/memory.h>
#include <libx/strings.h>

r8 str8_set(const str8_t dst, const c8 value, const umax offset, const umax count)
{
    if (offset + count > dst.length) return 1;
    mem_set((c8 *) dst.data + offset, value, count);
    return 0;
}

r8 str8_copy(const str8_t dst, const str8_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_copy((c8 *) dst.data + dst_offset, (c8 *) src.data + src_offset, count);
}

r8 str8_move(const str8_t dst, const str8_t src, const c8 value, const umax dst_offset, const umax src_offset,
             const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_move((c8 *) dst.data + dst_offset, (c8 *) src.data + src_offset, value, count);
}

r8 str16_set(const str16_t dst, const c16 value, const umax offset, umax count)
{
    if (offset + count > dst.length) return 1;
    if (!count) return 0;
    do
    {
        --count;
        ((c16 *) dst.data + offset)[count] = value;
    } while (count);
    return 0;
}

r8 str16_copy(const str16_t dst, const str16_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_copy((c16 *) dst.data + dst_offset, (c16 *) src.data + src_offset, count * sizeof(c16));
}

r8 str16_move(const str16_t dst, const str16_t src, const c16 value, const umax dst_offset, const umax src_offset,
              const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_move((c16 *) dst.data + dst_offset, (c16 *) src.data + src_offset, value, count * sizeof(c16));
}

r8 str32_set(const str32_t dst, const c32 value, const umax offset, umax count)
{
    if (offset + count > dst.length) return 1;
    if (!count) return 0;
    do
    {
        --count;
        ((c32 *) dst.data + offset)[count] = value;
    } while (count);
    return 0;
}

r8 str32_copy(const str32_t dst, const str32_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_copy((c32 *) dst.data + dst_offset, (c32 *) src.data + src_offset, count * sizeof(c32));
}

r8 str32_move(const str32_t dst, const str32_t src, const c32 value, const umax dst_offset, const umax src_offset,
              const umax count)
{
    if (src_offset + count > src.length) return 2;
    if (dst_offset + count > dst.length) return 3;
    return mem_move((c32 *) dst.data + dst_offset, (c32 *) src.data + src_offset, value, count * sizeof(c32));
}
