#include <kernel/x86/memory.h>

ptr allocate_aligned(u64 alignment, u64 size)
{
    // TODO: do it
    return PTR_NULL;
}

ptr allocate_unaligned(u64 size)
{
    // TODO: do it
    return PTR_NULL;
}

ptr allocate_reallocate(ptr memory, u64 size)
{
    // TODO: do it
    return PTR_NULL;
}

void free(ptr memory)
{
    // TODO: do it
}

const struct memory_subsystem x86_memory = {
    .allocate_aligned = &allocate_aligned, .allocate_unaligned = &allocate_unaligned, .allocate_reallocate = &allocate_reallocate, .free = &free
};
