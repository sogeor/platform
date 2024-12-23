#ifndef LIBX_DEFS_H
#define LIBX_DEFS_H

#define ASM __asm__
#define VOLATILE __volatile__
#define INLINE __inline__
#define GOTO goto
#define RESTRICT __restrict__
#define ATTRIBUTE __attribute__
#define ATTRIBUTE_ALIGNED(value) ATTRIBUTE((aligned(value)))
#define ATTRIBUTE_NO_RETURN ATTRIBUTE((noreturn))
#define ATTRIBUTE_PACKED ATTRIBUTE((packed))

#define TYPEDEF_PTR(target, name) typedef target *RESTRICT name
#define TYPEDEF_PTRC(target, name) typedef const target *RESTRICT name
#define TYPEDEF_CPTR(target, name) typedef target *const RESTRICT name
#define TYPEDEF_CPTRC(target, name) typedef const target *const RESTRICT name

#ifdef BITS64
#define BITS_SWITCH(value32, value64) value64
#else
#ifdef BITS32
#define BITS_SWITCH(value32, value64) value32
#else
#error "BITS64 or BITS32 must be defined"
#endif
#endif

#endif // LIBX_DEFS_H
