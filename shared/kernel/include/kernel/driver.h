#ifndef KERNEL_DRIVER_H
#define KERNEL_DRIVER_H

#include <libx/defs.h>

struct driver_subsystem;
TYPEDEF_PTR(struct driver_subsystem, driver_subsystem_ptr);
TYPEDEF_PTRC(struct driver_subsystem, driver_subsystem_ptrc);
TYPEDEF_CPTR(struct driver_subsystem, driver_subsystem_cptr);
TYPEDEF_CPTRC(struct driver_subsystem, driver_subsystem_cptrc);

struct driver;
TYPEDEF_PTR(struct driver, driver_ptr);
TYPEDEF_PTRC(struct driver, driver_ptrc);
TYPEDEF_CPTR(struct driver, driver_cptr);
TYPEDEF_CPTRC(struct driver, driver_cptrc);

#include <kernel/stream.h>
#include <kernel/system.h>
#include <libx/types.h>

struct driver_subsystem
{
    // TODO: do it
};

struct driver
{
    i64 (*const initialize)(system_cptrc system);
    i64 (*const finalize)(system_cptrc system);
};

#endif // KERNEL_DRIVER_H
