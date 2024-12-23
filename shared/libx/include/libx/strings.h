#ifndef LIBX_STRINGS_H
#define LIBX_STRINGS_H

#include <libx/types.h>

/*!
 * \brief Строка, которая состоит из 1-байтовых символов.
 */
typedef c8 *str8_t;

/*!
 * \brief Вычисляет длину \code str\endcode.
 * \param[in] str Строка.
 * \return \code 0\endcode — некорректная \code str\endcode; \code ?\endcode — длина \code str\endcode.
 */
umax str8_length(str8_t str);

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str8_set(str8_t dst, c8 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str8_copy(str8_t dst, str8_t src, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Строка, которая состоит из 2-байтовых символов.
 */
typedef c16 *str16_t;

/*!
 * \brief Вычисляет длину \code str\endcode.
 * \param[in] str Строка.
 * \return \code 0\endcode — некорректная \code str\endcode; \code ?\endcode — длина \code str\endcode.
 */
umax str16_length(str16_t str);

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str16_set(str16_t dst, c16 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str16_copy(str16_t dst, str16_t src, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Строка, которая состоит из 4-байтовых символов.
 */
typedef c32 *str32_t;

/*!
 * \brief Вычисляет длину \code str\endcode.
 * \param[in] str Строка.
 * \return \code 0\endcode — некорректная \code str\endcode; \code ?\endcode — длина \code str\endcode.
 */
umax str32_length(str32_t str);

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str32_set(str16_t dst, c32 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str32_copy(str32_t dst, str32_t src, umax dst_offset, umax src_offset, umax count);

#endif // LIBX_STRINGS_H
