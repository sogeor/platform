#ifndef KERNEL_MEMORY_H
#define KERNEL_MEMORY_H

#include <libx/defs.h>

struct memory_subsystem;
TYPEDEF_PTR(struct memory_subsystem, memory_subsystem_ptr);
TYPEDEF_PTRC(struct memory_subsystem, memory_subsystem_ptrc);
TYPEDEF_CPTR(struct memory_subsystem, memory_subsystem_cptr);
TYPEDEF_CPTRC(struct memory_subsystem, memory_subsystem_cptrc);

#include <libx/types.h>

struct memory_subsystem
{
    ptr (*const allocate_aligned)(u64 alignment, u64 size);
    ptr (*const allocate_unaligned)(u64 size);
    ptr (*const allocate_reallocate)(ptr memory, u64 size);
    void (*const free)(ptr memory);
};

#endif // KERNEL_MEMORY_H
