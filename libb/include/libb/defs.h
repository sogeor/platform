#ifndef LIBB_DEFS_H
#define LIBB_DEFS_H

#define NULL (void *)0

#ifdef BITS64
#define BITS_SWITCH(value32, value64) value64
#else
#ifdef BITS32
#define BITS_SWITCH(value32, value64) value32
#else
#error "BITS64 or BITS32 must be defined"
#endif
#endif

#endif // LIBB_DEFS_H
