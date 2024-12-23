#ifndef LIBX_TYPES_H
#define LIBX_TYPES_H

#include <libx/defs.h>

// signed integers

typedef signed char i8;
typedef signed short int i16;
typedef signed long int i32;
typedef signed long long int i64;
typedef BITS_SWITCH(i32, i64) imax;

#define I8_MIN -128i8
#define I8_MAX 127i8
#define I16_MIN -32768i16
#define I16_MAX 32767i16
#define I32_MIN -2147483648i32
#define I32_MAX 2147483647i32
#define I64_MIN -9223372036854775808i64
#define I64_MAX 9223372036854775807i64

// unsigned integers

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef BITS_SWITCH(u32, u64) umax;

#define U8_MAX 255ui8
#define U16_MAX 65535ui16
#define U32_MAX 4294967295ui32
#define U64_MAX 18446744073709551615ui64

// chars

typedef u8 c8;
typedef u16 c16;
typedef u32 c32;

#define C_CR 0x0D
#define C_LF 0x0A

// ptrs

typedef void *ptr;
typedef const void *ptrc;
typedef void *RESTRICT rptr;
typedef const void *RESTRICT rptrc;

#define NULL_PTR ((ptr) 0)
#define NULL_PTRC ((ptrc) 0)
#define NULL_RPTR ((rptr) 0)
#define NULL_RPTRC ((rptrc) 0)

// results

typedef u8 r8;
typedef u16 r16;
typedef u32 r32;
typedef u64 r64;

#endif // LIBX_TYPES_H
