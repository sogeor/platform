X86_64 ?= ..
X86_64_LIBX ?= $(X86_64)/libx

SHARED ?= ../../../shared
SHARED_LIBX ?= $(SHARED)/libx

CFLAGS ?=
CFLAGS += -D BITS32 -I "$(X86_64_LIBX)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(X86_64_LIBX)/*.nasm) $(wildcard $(X86_64_LIBX)/*.c))

include $(SHARED_LIBX)/Makefile
