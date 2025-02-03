#ifndef LIBB_TYPES_H
#define LIBB_TYPES_H

#include <libb/defs.h>

typedef signed char i8_t;
typedef signed short int i16_t;
typedef signed long int i32_t;
typedef signed long long i64_t;
typedef BITS_SWITCH(i32_t, i64_t) imax_t;
typedef imax_t isize_t;

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;
typedef unsigned long long u64_t;
typedef BITS_SWITCH(u32_t, u64_t) umax_t;
typedef umax_t usize_t;

typedef u8_t bool_t;

#endif // LIBB_TYPES_H
