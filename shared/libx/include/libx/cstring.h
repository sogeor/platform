#ifndef LIBX_CSTRING_H
#define LIBX_CSTRING_H

#include <libx/types.h>

/*!
 * \brief Представляет собой строку, состоящую из однобайтовых символов и завершающуюся \code \0\endcode.
 */
typedef const c8 *cstring_t;

/*!
 * \brief Вычисляет длину исходной \code cstring_t\endcode и сохраняет её по \code length\endcode.
 * \param[in] source Указатель на исходную \code cstring_t\endcode.
 * \param[out] length Указатель на длину исходной \code cstring_t\endcode.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code cstring\endcode равен \code NULL\endcode; \code 2\endcode — \code length\endcode равен \code NULL\endcode.
 */
r8 cstring_length(cstring_t source, umax *length);

// /*!
//  * \brief Декодирует символ в \code str\endcode по \code ndx\endcode.
//  * \param[in] src Исходная строка.
//  * \param[in] ndx Индекс символа, который необходимо декодировать.
//  * \param[out] chr Указатель на символ, который необходимо декодировать.
//  * \return \code 0\endcode — успешно; \code 1\endcode — \code src\endcode равна \code NULL\endcode; \code 2\endcode — \code chr\endcode равен \code NULL\endcode; \code 3\endcode — \code ndx\endcode равен или больше длины \code src\endcode; \code 4\endcode — некорректный символ.
//  */
// r8 string_decode(cstring src, umax ndx, c32 *chr);
//
// /*!
//  * \brief Вычисляет длину \code str\endcode.
//  * \param[in] src Исходная строка.
//  * \param[out] len Указатель на длину \code src\endcode.
//  * \return \code 0\endcode — успешно; \code 1\endcode — \code src\endcode равна \code NULL\endcode; \code 2\endcode — \code len\endcode равен \code NULL\endcode; \code 3\endcode — некорректная \code str\endcode.
//  */
// r8 string_length(cstring src, umax *len);

// /*!
//  * \brief Вычисляет длину \code str\endcode.
//  * \param[in] str Строка.
//  * \return \code 0\endcode — некорректная \code str\endcode; \code ?\endcode — длина \code str\endcode.
//  */
// umax str32_length(str32_t str);
//
// /*!
//  * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
//  * \param[out] dst Целевая строка.
//  * \param[in] value Значение, на которое заменяется каждый символ.
//  * \param[in] offset Количество символов, которые необходимо пропустить.
//  * \param[in] count Количество символов, которое необходимо заменить.
//  * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
//  */
// r8 str32_set(str16_t dst, c32 value, umax offset, umax count);
//
// /*!
//  * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
//  * \param[out] dst Целевая строка.
//  * \param[in] src Исходная строка.
//  * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
//  * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
//  * \param[in] count Количество символов, которое необходимо скопировать.
//  * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
//  */
// r8 str32_copy(str32_t dst, str32_t src, umax dst_offset, umax src_offset, umax count);


#endif // LIBX_CSTRING_H
