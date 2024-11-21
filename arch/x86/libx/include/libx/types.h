#ifndef X86_LIBX_TYPES_H
#define X86_LIBX_TYPES_H

#include <stdint.h>

// signed integers
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define I8_MIN -128i8
#define I8_MAX 127i8
#define I16_MIN -32768i16
#define I16_MAX 32767i16
#define I32_MIN -2147483648i32
#define I32_MAX 2147483647i32
#define I64_MIN -9223372036854775808i64
#define I64_MAX 9223372036854775807i64

// unsigned integers
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define U8_MAX 255ui8
#define U16_MAX 65535ui16
#define U32_MAX 4294967295ui32
#define U64_MAX 18446744073709551615ui64

// chars
typedef u8 c8;
typedef u16 c16;
typedef u32 c32;
typedef u64 c64;

// others
typedef void* ptr;
typedef u8 bl;

#endif // X86_LIBX_TYPES_H
