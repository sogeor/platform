#include "string.h"
#include <libx/memory.h>

r8 string_create_default(const string_t **string, const u8 *data, const umax length)
{
    return string_create(string, data, length, charset_default);
}

r8 string_create(const string_t **string, const u8 *data, umax length, const charset_t *charset)
{
    if (string == NULL) return 1;
    if (data == NULL) return 2;
    if (charset == NULL) return 3;

    string_t *tmp = NULL;
    if (MEMORY_ALLOCATE_UNALIGNED(&tmp, sizeof(string_t) + length)) return 4;
    tmp->length = length;
    tmp->charset = charset;

    umax diff = 0;
    c32 symbol = 0;
    do
    {
        if (charset->decode(data, length, &diff, &symbol)) return 5;
        data += diff;
        length -= diff;
    } while (length);

    *string = tmp;
    return 0;
}

r8 string_create_default_from_cstring(const string_t **string, const cstring_t data)
{
    return string_create_from_cstring(string, data, charset_default);
}

r8 string_create_from_cstring(const string_t **string, const cstring_t data, const charset_t *charset)
{
    if (string == NULL) return 1;
    if (data == NULL) return 2;
    if (charset == NULL) return 3;

    umax length = 0;
    cstring_length(data, &length);
    string_t *tmp = NULL;
    if (MEMORY_ALLOCATE_UNALIGNED(&tmp, sizeof(string_t) + length)) return 4;
    tmp->length = length;
    tmp->charset = charset;
    memory_copy_unbuffered(tmp->data, data, length);
    return 0;
}

r8 string_destroy(const string_t **string)
{
    return MEMORY_FREE(string);
}

r8 string_at(const string_t *string, c32* symbol)
{
    if (string == NULL) return 1;
    if (symbol == NULL) return 2;
    // string->data
}
