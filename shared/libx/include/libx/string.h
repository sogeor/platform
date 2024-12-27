#ifndef LIBX_STRING_H
#define LIBX_STRING_H

#include <libx/charset.h>
#include <libx/cstring.h>
#include <libx/types.h>

/*!
 * \brief Представляет собой строку с поддержкой \code charset_t\endcode.
 */
typedef struct string_s
{
    /*!
     * \brief Содержит количество символов строки.
     */
    umax length;

    /*!
     * \brief Содержит указатель на \code charset_t\endcode символов строки.
     */
    const charset_t *charset;

    /*!
     * \brief Содержит cимволы строки.
     */
    c32 data[];
} string_t;

/*!
 * \brief TODO
 */
r8 string_create_default(string_t **string, const u8 *data, umax length);

/*!
 * \brief TODO
 */
r8 string_create(string_t **string, const u8 *data, umax length, const charset_t *charset);

/*!
 * \brief TODO
 */
r8 string_create_default_from_cstring(string_t **string, cstring_t data);

/*!
 * \brief TODO
 */
r8 string_create_from_cstring(string_t **string, cstring_t data, const charset_t *charset);

/*!
 * \brief TODO
 */
r8 string_destroy(string_t **string);

/*!
 * \brief TODO
 */
r8 string_at(const string_t *string, c32* symbol);

string_t d = {0, charset_default, "Hello, world!"};

#endif // LIBX_STRING_H
