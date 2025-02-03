#ifndef LIBEFI_TABLE_HEADER_H
#define LIBEFI_TABLE_HEADER_H

#include <libefi/types.h>

typedef struct efi_table_header_s
{
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;
    uint32_t reserved;
} efi_table_header_t;

#endif // LIBEFI_TABLE_HEADER_H
