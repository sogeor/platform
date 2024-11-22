#include <kernel/x86/driver.h>
#include <kernel/x86/memory.h>
#include <kernel/x86/system.h>

const struct system x86_system = {
    .driver = &x86_driver, .memory = &x86_memory
};
