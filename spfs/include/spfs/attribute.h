#ifndef SPFS_ATTRIBUTE_H
#define SPFS_ATTRIBUTE_H

#include <libb/types.h>

// Представляет собой список атрибутов элемента. Если элемент ссылается на атрибуты с одинаковым типом, который не
// поддерживает дубликаты, то используется только первый действительный атрибут.
typedef struct spfs_attribute_list_s {
    u64_t size; // Содержит количество атрибутов, на которые ссылается элемент.
    u64_t refs[]; // Содержит `LBA` каждого атрибута, на который ссылается элемент.
} __attribute((packed)) spfs_attribute_list_t;

// Представляет собой атрибут одного или нескольких элементов. Этот атрибут считается недействительным, если его тип, то
// есть `type`, равен `0`. Привязка аттрибута к элементу сопровождается увеличением `refs` на 1. Отвязка аттрибута от
// элемента сопровождается уменьшением `refs` на 1. Если `refs` равен 0, то память, выделенная под атрибут, может быть
// освобождена.
typedef struct spfs_attribute_s {
    u64_t type; // Содержит тип этого атрибута.
    u64_t refs; // Содержит количество элементов, которые ссылаются на этот атрибут.
} __attribute((packed)) spfs_attribute_t;

// Представляет собой атрибут, определяющий имя одного или нескольких элементов. Тип этого атрибута, то есть
// `attr.type`, всегда должен быть равен `0x1`. Также тип этого этого атрибута не поддерживает дубликаты, то есть
// элемент может иметь только одно имя. Если размер имени, то есть `size`, равен `0` или само имя некорректно
// закодировано в `UTF-8`, то этот атрибут считается недействительным.
typedef struct spfs_attribute_name_s {
    spfs_attribute_t attr; // Содержит фундаментальную информацию об этом атрибуте.
    u64_t size; // Содержит размер имени в байтах.
    u8_t data[]; // Содержит имя элемента, закодированное в `UTF-8`.
} __attribute((packed)) spfs_attribute_name_t;

#endif // SPFS_ATTRIBUTE_H
