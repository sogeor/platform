#include "cstring.h"

r8 cstring_length(const cstring_t source, umax *length)
{
    if (source == NULL) return 1;
    if (length == NULL) return 2;
    umax tmp = 0;
    while (source[tmp]) ++tmp;
    *length = tmp;
    return 0;
}

//r8 string_decode(cstring src, umax ndx, c32 *chr)
//{
//    if (src == NULL) return 1;
//    if (chr == NULL) return 2;
//    c32 tmp;
//    goto start;
//    do
//    {
//        --ndx;
//    start:
//        tmp = (c32) *src;
//        if (tmp < 0b10000000) continue;
//        if (tmp > 0b10111111) return 4;
//        tmp &= (c32) 0b00111111;
//        ++src;
//        if (*src >= 0b11000000 && *src <= 0b11011111)
//        {
//            tmp |= (c32) (*src & 0b00011111) << 6;
//            if (!tmp) return 4;
//            continue;
//        }
//        if (*src < 0b10000000 || *src > 0b10111111) return 4;
//        tmp |= (c32) (*src & 0b00111111) << 6;
//        ++src;
//        if (*src >= 0b11100000 && *src <= 0b11101111)
//        {
//            tmp |= (c32) (*src & 0b00001111) << 12;
//            if (!tmp) return 4;
//            continue;
//        }
//        if (*src < 0b10000000 || *src > 0b10111111) return 4;
//        tmp |= (c32) (*src & 0b00111111) << 12;
//        ++src;
//        if (*src < 0b11110000 || *src > 0b11110111) return 4;
//        tmp |= (c32) (*src & 0b00000111) << 18;
//        if (!tmp) return 4;
//    } while (tmp && ndx); // TODO: Переписать... Я перепутал последовательность байтов...
//    if (ndx) return 3;
//    *chr = tmp;
//    return 0;
//}
//
//r8 string_length(cstring src, umax *len)
//{
//    if (src == NULL) return 1;
//    if (len == NULL) return 2;
//    *len = 0;
//    c32 chr;
//    goto start;
//    do
//    {
//        ++*len;
//    start:
//        if (string_decode(src++, 0, &chr) == 4) return 3;
//    } while (chr);
//    return 0;
//}


//
// // str8
//
// umax str8_length(const str8_t str)
// {
//     if (str == NULL) return 0;
//     umax length = 0;
//     while (str[length]) ++length;
//     return length;
// }
//
// r8 str8_set(const str8_t dst, const c8 value, const umax offset, const umax count)
// {
//     if (offset + count > str8_length(dst)) return 1;
//     memory_set(dst + offset, value, count);
//     return 0;
// }
//
// r8 str8_copy(const str8_t dst, const str8_t src, const umax dst_offset, const umax src_offset, const umax count)
// {
//     if (src_offset + count > str8_length(src)) return 2;
//     if (dst_offset + count > str8_length(dst)) return 3;
//     return mem_copy(dst + dst_offset, src + src_offset, count);
// }
//
// // str16
//
// umax str16_length(const str16_t str)
// {
//     if (str == NULL) return 0;
//     umax length = 0;
//     while (str[length]) ++length;
//     return ++length;
// }
//
// r8 str16_set(str16_t dst, const c16 value, const umax offset, umax count)
// {
//     if (offset + count > str16_length(dst)) return 1;
//     dst += offset;
//     while (count) dst[--count] = value;
//     return 0;
// }
//
// r8 str16_copy(const str16_t dst, const str16_t src, const umax dst_offset, const umax src_offset, const umax count)
// {
//     if (src_offset + count > str16_length(src)) return 2;
//     if (dst_offset + count > str16_length(dst)) return 3;
//     return mem_copy(dst + dst_offset, src + src_offset, count * sizeof(c16));
// }
//
// // str32
//
// umax str32_length(const str32_t str)
// {
//     if (str == NULL) return 0;
//     umax length = 0;
//     while (str[length]) ++length;
//     return ++length;
// }
//
// r8 str32_set(str32_t dst, const c32 value, const umax offset, umax count)
// {
//     if (offset + count > str32_length(dst)) return 1;
//     dst += offset;
//     while (count) dst[--count] = value;
//     return 0;
// }
//
// r8 str32_copy(const str32_t dst, const str32_t src, const umax dst_offset, const umax src_offset, const umax count)
// {
//     if (src_offset + count > str32_length(src)) return 2;
//     if (dst_offset + count > str32_length(dst)) return 3;
//     return mem_copy(dst + dst_offset, src + src_offset, count * sizeof(c32));
// }
