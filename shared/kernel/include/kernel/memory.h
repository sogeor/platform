#ifndef KERNEL_MEMORY_H
#define KERNEL_MEMORY_H

#include <libx/types.h>

/*!
 * \brief Выделяет целевую область памяти — количество \code count\endcode байт.
 * \param[in] count Количество байт, которое необходимо выделить.
 * \return \code NULL\endcode — недостаточно свободной области памяти; \code ?\endcode — целевая область памяти.
 */
void *memory_allocate_unaligned(umax count);

/*!
 * \brief Выделяет целевую область памяти — выровненное по \code aligment\endcode количество \code count\endcode байт.
 * \param[in] count Количество байт, которое необходимо выделить.
 * \param[in] alignment Количество байт, по которым необходимо выровнять.
 * \return \code NULL\endcode — недостаточно свободной области памяти; \code ?\endcode — целевая область памяти.
 */
void *memory_allocate_aligned(umax count, umax alignment);

/*!
 * \brief Освобождает \code ptr\endcode.
 * \param[in] ptr Исходную область памяти.
 * \return \code 0\endcode — успешно; \code 1\endcode — некорректная \code ptr\endcode.
 */
r8 memory_free(void *ptr);

#endif // KERNEL_MEMORY_H
