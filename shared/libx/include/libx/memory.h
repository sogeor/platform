#ifndef LIBX_MEMORY_H
#define LIBX_MEMORY_H

#include <libx/defs.h>
#include <libx/types.h>

/*!
 * \brief Заменяет \code count\endcode байт в \code dst\endcode на \code value\endcode.
 * \code
 * u8 dst[1024];
 * mem_set(dst, 0, 1024);
 * \endcode
 * \param[out] dst Целевая область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт.
 * \param[in] count Количество байт, которое необходимо заменить.
 */
void mem_set(ptr dst, u8 value, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode в \code dst\endcode.
 * \code
 * u8 dst[1024];
 * u8 src[1024];
 * mem_copy(dst, src, 1024);
 * \endcode
 * \param[out] dst Целевая область памяти.
 * \param[in] src Исходная область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode и \code src\endcode пересекаются.
 */
r8 mem_copy(ptr dst, ptrc src, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode в \code dst\endcode и заменяет \code count\endcode байт в \code src\endcode на \code value\endcode.
 * \code
 * u8 dst[1024];
 * u8 src[1024];
 * mem_move(dst, src, 0, 1024);
 * \endcode
 * \param[out] dst Целевая область памяти.
 * \param[in,out] src Исходная область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт в \code src\endcode.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode и \code src\endcode пересекаются.
 */
r8 mem_move(ptr dst, ptr src, u8 value, umax count);

#endif // LIBX_MEMORY_H
