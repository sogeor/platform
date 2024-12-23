#include <libx/memory.h>
#include <libx/strings.h>

// str8

umax str8_length(const str8_t str)
{
    if (str == NULL) return 0;
    umax length = 0;
    while (str[length]) ++length;
    return length;
}

r8 str8_set(const str8_t dst, const c8 value, const umax offset, const umax count)
{
    if (offset + count > str8_length(dst)) return 1;
    mem_set(dst + offset, value, count);
    return 0;
}

r8 str8_copy(const str8_t dst, const str8_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > str8_length(src)) return 2;
    if (dst_offset + count > str8_length(dst)) return 3;
    return mem_copy(dst + dst_offset, src + src_offset, count);
}

// str16

umax str16_length(const str16_t str)
{
    if (str == NULL) return 0;
    umax length = 0;
    while (str[length]) ++length;
    return ++length;
}

r8 str16_set(str16_t dst, const c16 value, const umax offset, umax count)
{
    if (offset + count > str16_length(dst)) return 1;
    dst += offset;
    while (count) dst[--count] = value;
    return 0;
}

r8 str16_copy(const str16_t dst, const str16_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > str16_length(src)) return 2;
    if (dst_offset + count > str16_length(dst)) return 3;
    return mem_copy(dst + dst_offset, src + src_offset, count * sizeof(c16));
}

// str32

umax str32_length(const str32_t str)
{
    if (str == NULL) return 0;
    umax length = 0;
    while (str[length]) ++length;
    return ++length;
}

r8 str32_set(str32_t dst, const c32 value, const umax offset, umax count)
{
    if (offset + count > str32_length(dst)) return 1;
    dst += offset;
    while (count) dst[--count] = value;
    return 0;
}

r8 str32_copy(const str32_t dst, const str32_t src, const umax dst_offset, const umax src_offset, const umax count)
{
    if (src_offset + count > str32_length(src)) return 2;
    if (dst_offset + count > str32_length(dst)) return 3;
    return mem_copy(dst + dst_offset, src + src_offset, count * sizeof(c32));
}
