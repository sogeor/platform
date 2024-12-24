#ifndef LIBX_MEMORY_H
#define LIBX_MEMORY_H

#include <libx/types.h>

/*!
 * \brief Выделяет \code count\endcode байт — целевую область памяти.
 * \param[out] dst Указатель на целевую область памяти.
 * \param[in] count Количество байт, которое необходимо выделить.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — недостаточно свободной области памяти.
 */
r8 memory_allocate_unaligned(void **dst, umax count);

#define MEMORY_ALLOCATE_UNALIGNED(dst, count) memory_allocate_unaligned((void**) dst, count)

/*!
 * \brief Выделяет \code count\endcode байт, выровненных по \code aligment\endcode, — целевую область памяти.
 * \param[out] dst Указатель на целевую область памяти.
 * \param[in] count Количество байт, которое необходимо выделить.
 * \param[in] alignment Количество байт, по которым необходимо выровнять.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — \code alignment\endcode не является степенью двойки; \code 3\endcode — недостаточно свободной области памяти.
 */
r8 memory_allocate_aligned(void **dst, umax count, umax alignment);

#define MEMORY_ALLOCATE_ALIGNED(dst, count) memory_allocate_aligned((void**) dst, count)

/*!
 * \brief Выделяет, или освобождает, или перемещает целевую область памяти, чтобы её размер был равен \code count\endcode байт.
 * \param[out] dst Указатель на целевую область памяти.
 * \param[in] count Количество байт, которому должен быть равен размер целевой области памяти.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — некорректная целевая область памяти; \code 3\endcode — недостаточно свободной области памяти.
 */
r8 memory_reallocate(void **dst, umax count);

#define MEMORY_REALLOCATE(dst, count) memory_reallocate((void**) dst, count)

/*!
 * \brief Освобождает целевую область памяти.
 * \param[in,out] dst Указатель на целевую область памяти.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — некорректная целевая область памяти.
 */
r8 memory_free(void **dst);

#define MEMORY_FREE(dst) memory_free((void**) dst)

/*!
 * \brief Заменяет \code count\endcode байт в \code dst\endcode на \code value\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] value Значение, на которое заменяется каждый байт.
 * \param[in] count Количество байт, которое необходимо заменить.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode.
 */
r8 memory_set(void *dst, u8 value, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode либо напрямую в \code dst\endcode, либо, если \code dst\endcode и \code src\endcode перекрываются, сначала во временную область памяти, а потом из неё в \code dst\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] src Исходная область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — \code src\endcode равен \code NULL\endcode; \code 3\endcode — недостаточно свободной области памяти; \code 4\endcode — некорректная временная область памяти.
 */
r8 memory_copy(void *dst, const void *src, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode напрямую в \code dst\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] src Исходная область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — \code src\endcode равен \code NULL\endcode; \code 3\endcode — \code dst\endcode и \code src\endcode перекрываются.
 */
r8 memory_copy_unbuffered(void *__restrict__ dst, const void *__restrict__ src, umax count);

/*!
 * \brief Копирует \code count\endcode байт из \code src\endcode сначала во временную область памяти, а потом из неё в \code dst\endcode.
 * \param[out] dst Целевая область памяти.
 * \param[in] src Исходная область памяти.
 * \param[in] count Количество байт, которое необходимо скопировать.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code dst\endcode равен \code NULL\endcode; \code 2\endcode — \code src\endcode равен \code NULL\endcode; \code 3\endcode — недостаточно свободной области памяти; \code 4\endcode — некорректная временная область памяти.
 */
r8 memory_copy_buffered(void *dst, const void *src, umax count);

#endif // LIBX_MEMORY_H
