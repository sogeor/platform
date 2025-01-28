#ifndef LIBEFI_PROTOCOL_SIMPLE_TEXT_OUTPUT_H
#define LIBEFI_PROTOCOL_SIMPLE_TEXT_OUTPUT_H

#include <libefi/defs.h>
#include <libefi/types.h>

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2,0x69c7,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct efi_simple_text_output_protocol_s efi_simple_text_output_protocol_t;
//
// typedef efi_status_t (EFIAPI *efi_input_reset_t)(IN efi_simple_text_input_protocol_t *this,
//                                                  IN boolean_t extended_verification);
// typedef efi_status_t (EFIAPI *
//     efi_input_read_key_t)(IN efi_simple_text_input_protocol_t *this, OUT efi_input_key_t *key);

typedef struct efi_simple_text_output_protocol_s
{
    // efi_input_reset_t reset;
    // efi_input_read_key_t read_key_stroke;
    // efi_event_t wait_for_key;
} efi_simple_text_output_protocol_t;

#endif // LIBEFI_PROTOCOL_SIMPLE_TEXT_OUTPUT_H
