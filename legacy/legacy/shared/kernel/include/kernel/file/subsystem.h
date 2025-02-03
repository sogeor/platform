#ifndef KERNEL_FILE_SUBSYSTEM_H
#define KERNEL_FILE_SUBSYSTEM_H

#include <libx/types.h>
#include <kernel/file/desc.h>
#include <kernel/file/info.h>
#include <kernel/file/path.h>

/*!
 * \brief Открывает файл по переданному \code path\endcode.
 * \details Если успешно, сохраняет дескриптор файла в \code desc\endcode.
 * \param path Путь к файлу.
 * \param desc Указатель на дескриптор файла.
 * \return \code 0\endcode — успешно; \code 1\endcode — \code path\endcode равен \code NULL\endcode; \code 2\endcode — \code desc\endcode равен \code NULL\endcode; \code 3\endcode — некорректный \code path\endcode; \code 4\endcode — некорректный \code desc\endcode; \code 5\endcode — недостаточно места.
 */
typedef r8_t (*file_subsystem_open_t)(file_path_t path, file_desc_t *desc);

typedef r8_t (*file_subsystem_close_t)(file_desc_t *desc);

typedef struct file_subsystem_s
{
    file_subsystem_open_t open;
    file_subsystem_close_t close;
} __attribute__((packed)) file_subsystem_t;

#endif // KERNEL_FILE_SUBSYSTEM_H
