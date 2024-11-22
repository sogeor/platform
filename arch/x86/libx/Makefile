X86 ?= ..
X86_LIBX ?= $(X86)/libx

SHARED ?= ../../../shared
SHARED_LIBX ?= $(SHARED)/libx

CFLAGS ?=
CFLAGS += -I "$(X86_LIBX)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(X86_LIBX)/*.nasm) $(wildcard $(X86_LIBX)/*.c))

include $(SHARED_LIBX)/Makefile
