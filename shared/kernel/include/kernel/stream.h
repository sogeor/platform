#ifndef KERNEL_STREAM_H
#define KERNEL_STREAM_H

#include <libx/types.h>

/*!
 * \brief Поток.
 */
typedef struct stream
{
    /*!
     * \brief Дескриптор потока.
     */
    const umax desc;

    /*!
     * \brief Флаги потока.
     * \details Бит \code 0\endcode — поток открыт для записи; бит \code 1\endcode — поток открыт для чтения.
     */
    u8 flags;

    /*!
     * \brief Записывает \code value\endcode в поток.
     * \param[in] value Значение, которое необходимо записать в поток.
     * \return \code 0\endcode — успешно; \code 1\endcode — поток закрыт для записи.
     */
    r8 (*write)(u8 value);

    /*!
     * \brief Записывает \code count\endcode байт из \code buffer\endcode в поток.
     * \param[in] buffer Буфер данных, который необходимо записать в поток.
     * \param[in] count Количество байт, которые необходимо записать в поток.
     * \return \code 0\endcode — успешно; \code 1\endcode — поток закрыт для записи.
     */
    r8 (*write_buffer)(const u8 *buffer, umax count);

    /*!
     * \brief Считывает из потока в \code value\endcode.
     * \param[out] value Значение, которое необходимо считать из потока.
     * \return \code 0\endcode — успешно; \code 1\endcode — поток закрыт для считывания.
     */
    r8 (*read)(u8 *value);

    /*!
     * \brief Считывает \code count\endcode байт из потока в \code buffer\endcode.
     * \param[out] buffer Буфер данных, в который необходимо считать.
     * \param[in] count Количество байт, которые необходимо считать.
     * \return \code 0\endcode — успешно; \code 1\endcode — поток закрыт для чтения.
     */
    r8 (*read_buffer)(u8 *buffer, umax count);
} stream_t;

/*!
 * \brief Открывает поток с уникальным дескриптором.
 * \return \code NULL\endcode — недостаточно свободной области памяти; \code ?\endcode — успешно.
 */
stream_t *stream_open();

/*!
 * \brief Закрывает \code stream\endcode.
 * \param[in] stream Поток, который необходимо закрыть.
 * \return \code 0\endcode — успешно; \code 1\endcode — некорректный поток; \code 2\endcode — поток уже закрыт.
 */
r8 stream_close(stream_t *stream);

/*!
 * \brief Возвращает количество открытых потоков.
 * \return Количество открытых потоков.
 */
umax stream_count();

#endif // KERNEL_STREAM_H
