#ifndef SPFS_FILE_H
#define SPFS_FILE_H

#include <libb/types.h>
#include <spfs/attribute.h>
#include <spfs/element.h>

typedef struct spfs_file_s {
    spfs_element_t lmnt; // Содержит фундаментальную информацию об этом элементе.
} __attribute((packed)) spfs_file_t;

u32_t spfs_file_attribute_link(spfs_file_t file, spfs_attribute_t attr);
u32_t spfs_file_attribute_unlink(spfs_file_t file, spfs_attribute_t attr);

#endif // SPFS_FILE_H
