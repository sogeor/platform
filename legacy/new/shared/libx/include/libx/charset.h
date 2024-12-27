#ifndef LIBX_CHARSET_H
#define LIBX_CHARSET_H

#include <libx/types.h>

/*!
 * \brief Представляет собой кодировку символов.
 */
typedef struct charset_s
{
    /*!
     * \brief Декодирует символ, используя исходные данные.
     * \param[in] data Указатель на исходные данные.
     * \param[in] limit Максимальный предел длины использованных исходных данных.
     * \param[out] length Указатель на длину использованных исходных данных.
     * \param[out] symbol Указатель на символ, который необходимо декодировать.
     * \return \code 0\endcode — успешно; \code 1\endcode — \code data\endcode равен \code NULL\endcode; \code 2\endcode — \code length\endcode равен \code NULL\endcode; \code 3\endcode — \code symbol\endcode равен \code NULL\endcode; \code 4\endcode — \code limit\endcode слишком мал; \code 5\endcode — некорректные исходные данные.
     */
    r8 (*decode)(const u8 *data, umax limit, umax *length, c32 *symbol);

    /*!
     * \brief Кодирует символ, преобразуя его в целевые данные.
     * \param[out] data Указатель на целевые данные.
     * \param[in] limit Максимальный предел длины целевых данных.
     * \param[out] length Указатель на длину целевых данных.
     * \param[in] symbol Символ, который необходимо кодировать.
     * \return \code 0\endcode — успешно; \code 1\endcode — \code data\endcode равен \code NULL\endcode; \code 2\endcode — \code length\endcode равен \code NULL\endcode; \code 3\endcode — \code limit\endcode слишком мал; \code 4\endcode — некорректный \code symbol\endcode.
     */
    r8 (*encode)(u8 *data, umax limit, umax *length, c32 symbol);
} charset_t;

/*!
 * \brief Представляет собой указатель на \code charset_t\endcode по умолчанию.
 */
extern const charset_t *charset_default;

#endif // LIBX_CHARSET_H
