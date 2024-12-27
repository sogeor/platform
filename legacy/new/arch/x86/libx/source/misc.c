#include <libx/x86/misc.h>

inline u8 farpeekb(u16 selector, ptr offset)
{
    u8 value;
    ASM("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2), %0\n\t"
        "pop %%fs" : "=r"(value) : "g"(selector), "r"(offset));
    return value;
}

inline u16 farpeekw(u16 selector, ptr offset)
{
    u16 value;
    ASM("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2), %0\n\t"
        "pop %%fs" : "=r"(value) : "g"(selector), "r"(offset));
    return value;
}

inline u32 farpeekl(u16 selector, ptr offset)
{
    u32 value;
    ASM("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2), %0\n\t"
        "pop %%fs" : "=r"(value) : "g"(selector), "r"(offset));
    return value;
}

inline void farpokeb(u16 selector, ptr offset, u8 value)
{
    ASM("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs" : : "g"(selector), "r"(offset), "r"(value));
}

inline void farpokew(u16 selector, ptr offset, u16 value)
{
    ASM("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movw %2, %%fs:(%1)\n\t"
        "pop %%fs" : : "g"(selector), "r"(offset), "r"(value));
}

inline void farpokel(u16 selector, ptr offset, u32 value)
{
    ASM("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movl %2, %%fs:(%1)\n\t"
        "pop %%fs" : : "g"(selector), "r"(offset), "r"(value));
}

inline u8 inb(u16 port)
{
    u8 value;
    ASM VOLATILE("inb %w1, %b0" : "=a"(value) : "Nd"(port) : "memory");
    return value;
}

inline u16 inw(u16 port)
{
    u16 value;
    ASM VOLATILE("inw %w1, %b0" : "=a"(value) : "Nd"(port) : "memory");
    return value;
}

inline u32 inl(u16 port)
{
    u32 value;
    ASM VOLATILE("inl %w1, %b0" : "=a"(value) : "Nd"(port) : "memory");
    return value;
}

inline void outb(u16 port, u8 value)
{
    ASM VOLATILE("outb %b0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

inline void outw(u16 port, u16 value)
{
    ASM VOLATILE("outw %b0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

inline void outl(u16 port, u32 value)
{
    ASM VOLATILE("outl %b0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

inline void io_wait(void)
{
    outb(0x80, 0);
}
