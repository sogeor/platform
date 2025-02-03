#ifndef SPFS_ELEMENT_H
#define SPFS_ELEMENT_H

#include <spfs/attribute.h>

// Представляет собой элемент — фундаментальную единицу `SPFS`.
// Каждый элемент обладает списком атрибутов, но он может быть пустым, из-за чего некоторые элементы становятся
// недействительными.
typedef struct spfs_element_s {
    spfs_attribute_list_t attr; // Содержит список атрибутов этого элемента.
} __attribute((packed)) spfs_element_t;

#endif // SPFS_ELEMENT_H
