#ifndef LIBX_MEMORY_H
#define LIBX_MEMORY_H

#include <libx/defs.h>
#include <libx/types.h>

/*!
 * \brief Заменяет \code count\endcode байт в \code src\endcode на \code value\endcode.
 * \code
 * u8 buffer[1024];
 * mem_set(buffer, 0, 1024);
 * \endcode
 * \param[out] src Исходная область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт.
 * \param[in] count Количество байт, которое необходимо заменить.
 */
void mem_set(void *RESTRICT src, u8 value, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode в \code dst\endcode.
 * \code
 * u8 src[1024];
 * u8 dst[1024];
 * mem_copy(src, dst, 1024);
 * \endcode
 * \param[in] src Исходная область памяти.
 * \param[out] dst Целевая область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code src\endcode и \code dst\endcode пересекаются.
 */
r8 mem_copy(const void *RESTRICT src, void *RESTRICT dst, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode в \code dst\endcode и заменяет \code count\endcode байт в \code src\endcode на \code value\endcode.
 * \code
 * u8 src[1024];
 * u8 dst[1024];
 * mem_move(src, dst, 0, 1024);
 * \endcode
 * \param[in,out] src Исходная область памяти.
 * \param[out] dst Целевая область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт в \code src\endcode.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code src\endcode и \code dst\endcode пересекаются.
 */
r8 mem_move(void *RESTRICT src, void *RESTRICT dst, u8 value, umax count);

#endif // LIBX_MEMORY_H
