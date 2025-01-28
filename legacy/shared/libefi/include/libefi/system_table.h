#ifndef LIBEFI_SYSTEM_TABLE_H
#define LIBEFI_SYSTEM_TABLE_H

#include <libefi/table_header.h>
#include <libefi/protocol/simple_text_input.h>
#include <libefi/protocol/simple_text_output.h>

typedef struct efi_system_table_s
{
    efi_table_header_t hdr;
    c16_t *firmware_vendor;
    u32_t firmware_revision;
    efi_handle_t console_in_handle;
    efi_simple_text_input_protocol_t *con_in;
    efi_handle_t console_out_handle;
    efi_simple_text_output_protocol_t *con_out;
    efi_handle_t standard_error_handle;
    efi_simple_text_output_protocol_t *std_err;
    void *runtime_services; // TODO: EFI_RUNTIME_SERVICES
    void *boot_services; // TODO: EFI_BOOT_SERVICES
    umax_t number_of_table_entries;
    void *configuration_table; // TODO: EFI_CONFIGURATION_TABLE
} efi_system_table_t;

#endif // LIBEFI_SYSTEM_TABLE_H
