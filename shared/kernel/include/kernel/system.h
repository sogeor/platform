#ifndef KERNEL_SYSTEM_H
#define KERNEL_SYSTEM_H

#include <libx/defs.h>

struct system;
TYPEDEF_PTR(struct system, system_ptr);
TYPEDEF_PTRC(struct system, system_ptrc);
TYPEDEF_CPTR(struct system, system_cptr);
TYPEDEF_CPTRC(struct system, system_cptrc);

#include <kernel/driver.h>
#include <kernel/memory.h>

struct system
{
    driver_subsystem_cptrc driver;
    memory_subsystem_cptrc memory;
};

#endif // KERNEL_SYSTEM_H
