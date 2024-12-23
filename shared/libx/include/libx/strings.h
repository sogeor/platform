#ifndef LIBX_STRINGS_H
#define LIBX_STRINGS_H

#include <libx/defs.h>
#include <libx/types.h>

/*!
 * \brief Строка, которая состоит из 1-байтовых символов.
 */
typedef struct str8
{
    /*!
     * \brief Длина строки.
     */
    umax length;

    /*!
     * \brief Область данных, в которой содержатся символы строки.
     */
    c8 data[];
}
    ATTRIBUTE_PACKED str8;

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \code
 * str8 dst = {1024, {}};
 * str8_set(dst, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str8_set(str8 dst, c8 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \code
 * str8 dst = {1024, {}};
 * str8 src = {1024, {}};
 * str8_copy(dst, src, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str8_copy(str8 dst, str8 src, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode и заменяет, начиная с \code src_offset\endcode, \code count\endcode символов в \code src\endcode на \code value\endcode.
 * \code
 * str8 dst = {1024, {}};
 * str8 src = {1024, {}};
 * str8_move(dst, src, 0, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] value Значение, на которое заменяется каждый символ в \code src\endcode.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str8_move(str8 dst, str8 src, c8 value, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Строка, которая состоит из 2-байтовых символов.
 */
typedef struct str16
{
    /*!
     * \brief Длина строки.
     */
    umax length;

    /*!
     * \brief Область данных, в которой содержатся символы строки.
     */
    c16 data[];
}
    ATTRIBUTE_PACKED str16;

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \code
 * str16 dst = {1024, {}};
 * str16_set(dst, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str16_set(str16 dst, c16 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \code
 * str16 dst = {1024, {}};
 * str16 src = {1024, {}};
 * str16_copy(dst, src, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str16_copy(str16 dst, str16 src, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode и заменяет, начиная с \code src_offset\endcode, \code count\endcode символов в \code src\endcode на \code value\endcode.
 * \code
 * str16 dst = {1024, {}};
 * str16 src = {1024, {}};
 * str16_move(dst, src, 0, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] value Значение, на которое заменяется каждый символ в \code src\endcode.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str16_move(str16 dst, str16 src, c16 value, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Строка, которая состоит из 4-байтовых символов.
 */
typedef struct str32
{
    /*!
     * \brief Длина строки.
     */
    umax length;

    /*!
     * \brief Область данных, в которой содержатся символы строки.
     */
    c32 data[];
}
    ATTRIBUTE_PACKED str32;

/*!
 * \brief Заменяет, начиная с \code offset\endcode, \code count\endcode символов в \code dst\endcode на \code value\endcode.
 * \code
 * str32 dst = {1024, {}};
 * str32_set(dst, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] value Значение, на которое заменяется каждый символ.
 * \param[in] offset Количество символов, которые необходимо пропустить.
 * \param[in] count Количество символов, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — сумма \code offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str32_set(str16 dst, c32 value, umax offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode.
 * \code
 * str32 dst = {1024, {}};
 * str32 src = {1024, {}};
 * str32_copy(dst, src, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str32_copy(str32 dst, str32 src, umax dst_offset, umax src_offset, umax count);

/*!
 * \brief Копирует, начиная с \code src_offset\endcode и \code dst_offset\endcode, \code count\endcode символов из \code src\endcode в \code dst\endcode и заменяет, начиная с \code src_offset\endcode, \code count\endcode символов в \code src\endcode на \code value\endcode.
 * \code
 * str32 dst = {1024, {}};
 * str32 src = {1024, {}};
 * str32_move(dst, src, 0, 0, 0, 1024);
 * \endcode
 * \param[out] dst Целевая строка.
 * \param[in] src Исходная строка.
 * \param[in] value Значение, на которое заменяется каждый символ в \code src\endcode.
 * \param[in] dst_offset Количество символов, которые необходимо пропустить в \code dst\endcode.
 * \param[in] src_offset Количество символов, которые необходимо пропустить в \code src\endcode.
 * \param[in] count Количество символов, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — области данных \code dst\endcode и \code src\endcode пересекаются; \code 2\endcode — сумма \code src_offset\endcode и \code count\endcode больше длины \code src\endcode; \code 3\endcode — сумма \code dst_offset\endcode и \code count\endcode больше длины \code dst\endcode.
 */
r8 str32_move(str32 dst, str32 src, c32 value, umax dst_offset, umax src_offset, umax count);

#endif // LIBX_STRINGS_H
