#ifndef LIBX_DEFS_H
#define LIBX_DEFS_H

#define NULL (void*) 0

#ifdef BITS128
#define BITS_SWITCH(value32, value64, value128) value128
#else
#ifdef BITS64
#define BITS_SWITCH(value32, value64, value128) value64
#else
#ifdef BITS32
#define BITS_SWITCH(value32, value64, value128) value32
#else
#error "BITS128 or BITS64 or BITS32 must be defined"
#endif
#endif
#endif

#endif // LIBX_DEFS_H
