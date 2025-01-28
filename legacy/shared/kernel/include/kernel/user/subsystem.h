#ifndef KERNEL_USER_SUBSYSTEM_H
#define KERNEL_USER_SUBSYSTEM_H

#include <libx/types.h>
#include <kernel/user/info.h>
#include <kernel/user/group/subsystem.h>

typedef r8_t (*user_subsystem_close_t)(file_desc_t *desc);

typedef struct user_subsystem_s
{
    user_group_subsystem_t group;
} __attribute__((packed)) user_subsystem_t;

#endif // KERNEL_USER_SUBSYSTEM_H
