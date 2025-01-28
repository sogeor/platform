#ifndef KERNEL_DRIVER_H
#define KERNEL_DRIVER_H

#include <libx/defs.h>

struct driver;

#include <kernel/stream.h>
#include <libx/types.h>

struct driver
{
    umax (*const initialize)();
    umax (*const finalize)();
};

#endif // KERNEL_DRIVER_H
