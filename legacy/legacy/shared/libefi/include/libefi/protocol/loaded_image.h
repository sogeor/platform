#ifndef LIBEFI_PROTOCOL_LOADED_IMAGE_H
#define LIBEFI_PROTOCOL_LOADED_IMAGE_H

#include <libefi/system_table.h>

#define EFI_LOADED_IMAGE_PROTOCOL_GUID {0x5B1B31A1,0x9562,0x11d2,{0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}
#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef struct
{
    u32_t Revision;
    efi_handle_t ParentHandle;
    efi_system_table_t *SystemTable;
    efi_handle_t DeviceHandle;
    //EFI_DEVICE_PATH_PROTOCOL *FilePath;
    void *Reserved;
    // Image’s load options
    u32_t LoadOptionsSize;
    void *LoadOptions;
    // Location where image was loaded
    void *ImageBase;
    u64_t ImageSize;
    //EFI_MEMORY_TYPE ImageCodeType;
    //EFI_MEMORY_TYPE ImageDataType;
    //EFI_IMAGE_UNLOAD Unload;
} EFI_LOADED_IMAGE_PROTOCOL;

#endif // LIBEFI_PROTOCOL_LOADED_IMAGE_H
