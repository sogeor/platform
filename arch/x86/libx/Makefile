X86 ?= ../
X86_LIBX ?= $(X86)/libx

CFLAGS ?=
CFLAGS += -I "$(X86_LIBX)/include"
OBJECTS ?=

x86_libx_cpuid ?= excluded
ifeq ($(x86_libx_cpuid), included)
CFLAGS += -I "$(X86_LIBX)/cpuid/include"
OBJECTS += $(wildcard $(X86_LIBX)/cpuid/*.c)
endif
