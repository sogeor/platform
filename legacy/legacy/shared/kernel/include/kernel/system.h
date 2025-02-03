#ifndef KERNEL_SYSTEM_H
#define KERNEL_SYSTEM_H

#include <kernel/file/subsystem.h>
#include <kernel/user/subsystem.h>

typedef struct system_s
{
    const file_subsystem_t *file;
    const user_subsystem_t *user;
} __attribute__((packed)) system_t;

inline void test(const system_t *system)
{
}

#endif // KERNEL_SYSTEM_H
