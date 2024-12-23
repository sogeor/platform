#ifndef KERNEL_MEMORY_H
#define KERNEL_MEMORY_H

#include <libx/types.h>

/*!
 * \brief Выделяет целевую область памяти — количество \code count\endcode байт.
 * \code
 * ptr dst = memory_allocate_unaligned(1024);
 * \endcode
 * \param[in] count Количество байт, которое необходимо выделить.
 * \return \code NULL_RPTR\endcode — недостаточно свободной области памяти; \code ?\endcode — целевая область памяти.
 */
rptr memory_allocate_unaligned(umax count);

/*!
 * \brief Выделяет целевую область памяти — выровненное по \code aligment\endcode количество \code count\endcode байт.
 * \code
 * ptr dst = memory_allocate_aligned(1024, 4096);
 * \endcode
 * \param[in] count Количество байт, которое необходимо выделить.
 * \param[in] alignment Количество байт, по которым необходимо выровнять.
 * \return \code NULL_RPTR\endcode — недостаточно свободной области памяти; \code ?\endcode — целевая область памяти.
 */
rptr memory_allocate_aligned(umax count, umax alignment);

/*!
 * \brief Освобождает \code dst\endcode.
 * \code
 * ptr dst;
 * memory_free(dst);
 * \endcode
 * \param[in] dst Целевая область памяти.
 * \return \code 0\endcode — успешно; \code 1\endcode — некорректная целевая область памяти.
 */
r8 memory_free(ptr dst);

#endif // KERNEL_MEMORY_H
