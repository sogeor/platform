#ifndef LIBX_TYPES_H
#define LIBX_TYPES_H

#include <libx/defs.h>

typedef signed char i8_t;
typedef signed short int i16_t;
typedef signed long int i32_t;
typedef signed long long int i64_t;
typedef signed __int128 i128_t;
typedef BITS_SWITCH(i32_t, i64_t, i128_t) imax_t;

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;
typedef unsigned long long int u64_t;
typedef unsigned __int128 u128_t;
typedef BITS_SWITCH(u32_t, u64_t, u128_t) umax_t;

typedef u8_t r8_t;
typedef u16_t r16_t;
typedef u32_t r32_t;
typedef u64_t r64_t;
typedef u128_t r128_t;
typedef BITS_SWITCH(r32_t, r64_t, r128_t) rmax_t;

typedef u8_t bool_t;
#define FALSE 0
#define TRUE 1

typedef u8_t c8_t;
typedef u16_t c16_t;
typedef u32_t c32_t;

typedef u8_t* str_t;
typedef const u8_t* cstr_t;

#endif // LIBX_TYPES_H
