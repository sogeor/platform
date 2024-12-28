#ifndef LIBX_CHARSET_ASCII_H
#define LIBX_CHARSET_ASCII_H

#include <libx/charset.h>

/*!
 * \brief Декодирует символ, используя исходные данные, согласно \code ASCII\endcode.
 * \param[in] data Указатель на исходные данные.
 * \param[in] limit Максимальный предел длины использованных исходных данных.
 * \param[out] length Указатель на длину использованных исходных данных.
 * \param[out] symbol Указатель на символ, который необходимо декодировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code data\endcode равен \code NULL\endcode; \code 2\endcode — \code length\endcode равен \code NULL\endcode; \code 3\endcode — \code symbol\endcode равен \code NULL\endcode; \code 4\endcode — \code limit\endcode слишком мал; \code 5\endcode — некорректные исходные данные.
 */
r8 charset_ascii_decode(const u8 *data, umax limit, umax *length, c32 *symbol);

/*!
 * \brief Кодирует символ, преобразуя его в целевые данные, согласно \code ASCII\endcode.
 * \param[out] data Указатель на целевые данные.
 * \param[in] limit Максимальный предел длины целевых данных.
 * \param[out] length Указатель на длину целевых данных.
 * \param[in] symbol Символ, который необходимо кодировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code data\endcode равен \code NULL\endcode; \code 2\endcode — \code length\endcode равен \code NULL\endcode; \code 3\endcode — \code limit\endcode слишком мал; \code 4\endcode — некорректный \code symbol\endcode.
 */
r8 charset_ascii_encode(u8 *data, umax limit, umax *length, c32 symbol);

/*!
 * \brief Представляет собой \code ASCII\endcode.
 */
extern const charset_t charset_ascii;

#endif // LIBX_CHARSET_ASCII_H