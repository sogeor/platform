#ifndef LIBX_MEMORY_H
#define LIBX_MEMORY_H

#include <libx/types.h>

/*!
 * \brief Заменяет \code count\endcode байт в \code dst\endcode на \code value\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт.
 * \param[in] count Количество байт, которое необходимо заменить.
 */
void mem_set(void *dst, u8 value, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode в \code dst\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] src Исходная область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode и \code src\endcode пересекаются.
 */
r8 mem_copy(void *__restrict__ dst, const void *__restrict__ src, umax count);

#endif // LIBX_MEMORY_H
