#ifndef KERNEL_USER_GROUP_SUBSYSTEM_H
#define KERNEL_USER_GROUP_SUBSYSTEM_H

#include <libx/types.h>

typedef r8_t (*user_group_subsystem_close_t)(file_desc_t *desc);

typedef struct user_group_subsystem_s
{
} __attribute__((packed)) user_group_subsystem_t;

#endif // KERNEL_USER_GROUP_SUBSYSTEM_H
