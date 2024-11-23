#include <kernel/x86/driver.h>
#include <kernel/x86/memory.h>
#include <kernel/x86/system.h>

const struct system x86_system = {
    &x86_driver, &x86_memory
};
