#include "utf8.h"

r8 charset_utf8_decode(const u8 *data, const umax limit, umax *length, c32 *symbol)
{
    if (data == NULL) return 1;
    if (length == NULL) return 2;
    if (symbol == NULL) return 3;
    if (limit == 0) return 4;

    if (data[0] & u8(0b10000000)) goto next_0;
    // 0 — 127
    *length = 1;
    *symbol = c32(data[0]);
    return 0;

next_0:
    if (data[0] & u8(0b11100000) != u8(0b11000000)) goto next_1;
    // 128 — 2047
    if (limit < 2) return 4;
    if (data[1] & u8(0b11000000) != u8(0b10000000)) goto fail_with_1;
    *length = 2;
    *symbol = c32((data[0] & u8(0b00011111)) << 6) | c32(data[1] & u8(0b00111111));
    if (*symbol < 128) return 5;
    return 0;

next_1:
    if (data[0] & u8(0b11110000) != u8(0b11100000)) goto next_2;
    // 2048 — 55295 && 57344 — 65535
    if (limit < 3) return 4;
    if (data[1] & u8(0b11000000) != u8(0b10000000)) goto fail_with_1;
    if (data[2] & u8(0b11000000) != u8(0b10000000)) goto fail_with_2;
    *length = 3;
    *symbol = c32((data[0] & u8(0b00001111)) << 11) | c32((data[1] & u8(0b00011111)) << 6) | c32(
                  data[2] & u8(0b00111111));
    if (*symbol < 2048 || *symbol >= 55296 && *symbol <= 57343) return 5;
    return 0;

next_2:
    if (data[0] & u8(0b11111000) != u8(0b11110000)) goto fail_with_1;
    // 65536 — 1114111
    if (limit < 4) return 4;
    if (data[1] & u8(0b11000000) != u8(0b10000000)) goto fail_with_1;
    if (data[2] & u8(0b11000000) != u8(0b10000000)) goto fail_with_2;
    if (data[3] & u8(0b11000000) != u8(0b10000000))
    {
        *length = 3;
        return 5;
    }
    *length = 4;
    *symbol = c32((data[0] & u8(0b00000111)) << 16) | c32((data[1] & u8(0b00001111)) << 11) |
              c32((data[2] & u8(0b00011111)) << 6) | c32(data[3] & u8(0b00111111));
    if (*symbol < 65536) return 5;
    return 0;

fail_with_1:
    *length = 1;
    return 5;

fail_with_2:
    *length = 2;
    return 5;
}

r8 charset_utf8_encode(u8 *data, const umax limit, umax *length, const c32 symbol)
{
    if (data == NULL) return 1;
    if (length == NULL) return 2;
    if (limit == 0) return 3;

    if (symbol > 127) goto next_0;
    // 0 — 127
    data[0] = u8(symbol);
    *length = 1;
    return 0;

next_0:
    if (symbol > 2047) goto next_1;
    // 128 — 2047
    if (limit < 2) return 3;
    data[0] = u8((symbol & c32(0b00011111) << 6) >> 6) | u8(0b11000000);
    data[1] = u8(symbol & c32(0b00111111)) | u8(0b10000000);
    *length = 2;
    return 0;

next_1:
    if (symbol > 65535) goto next_2;
    // 2048 — 55295 && 57344 — 65535
    if (limit < 3) return 3;
    if (symbol >= 55296 && symbol <= 57343) return 4;
    data[0] = u8((symbol & c32(0b00001111) << 11) >> 11) | u8(0b11100000);
    data[1] = u8((symbol & c32(0b00011111) << 6) >> 6) | u8(0b11000000);
    data[2] = u8(symbol & c32(0b00111111)) | u8(0b10000000);
    *length = 3;
    return 0;

next_2:
    if (symbol > 1114111)
    {
        *length = 0;
        return 4;
    }
    // 65536 — 1114111
    if (limit < 4) return 3;
    data[0] = u8((symbol & c32(0b00000111) << 16) >> 16) | u8(0b11110000);
    data[1] = u8((symbol & c32(0b00001111) << 11) >> 11) | u8(0b11100000);
    data[2] = u8((symbol & c32(0b00011111) << 6) >> 6) | u8(0b11000000);
    data[3] = u8(symbol & c32(0b00111111)) | u8(0b10000000);
    *length = 3;
    return 0;
}

const charset_t charset_utf8 = {charset_utf8_decode, charset_utf8_encode};
