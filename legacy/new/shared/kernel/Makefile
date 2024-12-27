SHARED ?= ..
SHARED_KERNEL ?= $(SHARED)/kernel
SHARED_LIBX ?= $(SHARED)/libx

CFLAGS ?=
CFLAGS += -I "$(SHARED_KERNEL)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(SHARED_KERNEL)/*.nasm) $(wildcard $(SHARED_KERNEL)/*.c))

include $(SHARED_LIBX)/Makefile
