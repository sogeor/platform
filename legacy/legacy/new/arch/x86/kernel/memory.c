#include <kernel/memory.h>
#include <libx/x86/mmu.h>

// TODO: Написать менеджер памяти.
// TODO: Удалить заглушки.

#include <libx/charset/utf8.h>

void *memory_allocate_unaligned(umax count)
{
    return NULL;
}

void *memory_allocate_aligned(umax count, umax alignment)
{
    return NULL;
}

r8 memory_free(void *ptr)
{
    return 1;
}
