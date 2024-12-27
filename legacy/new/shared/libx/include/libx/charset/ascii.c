#include "ascii.h"

r8 charset_ascii_decode(const u8 *data, const umax limit, umax *length, c32 *symbol)
{
    if (data == NULL) return 1;
    if (length == NULL) return 2;
    if (symbol == NULL) return 3;
    if (limit == 0) return 4;

    *length = 1;
    if (data[0] & u8(0b10000000)) return 5;
    // 0 — 127
    *symbol = c32(data[0]);
    return 0;
}

r8 charset_ascii_encode(u8 *data, const umax limit, umax *length, const c32 symbol)
{
    if (data == NULL) return 1;
    if (length == NULL) return 2;
    if (limit == 0) return 3;

    if (symbol > 127)
    {
        *length = 0;
        return 4;
    }
    // 0 — 127
    data[0] = u8(symbol);
    *length = 1;
    return 0;
}

const charset_t charset_ascii = {charset_ascii_decode, charset_ascii_encode};
