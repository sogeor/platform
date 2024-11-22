#ifndef LIBX_DEFS_H
#define LIBX_DEFS_H

#define ASM __asm__
#define VOLATILE __volatile__
#define INLINE __inline__
#define GOTO goto

#define TYPEDEF_PTR(target, name) typedef target *name
#define TYPEDEF_PTRC(target, name) typedef const target *name
#define TYPEDEF_CPTR(target, name) typedef target *const name
#define TYPEDEF_CPTRC(target, name) typedef const target *const name

#endif // LIBX_DEFS_H
