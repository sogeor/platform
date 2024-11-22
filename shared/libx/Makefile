SHARED ?= ..
SHARED_LIBX ?= $(SHARED)/libx

CFLAGS ?=
CFLAGS += -I "$(SHARED_LIBX)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(SHARED_LIBX)/*.nasm) $(wildcard $(SHARED_LIBX)/*.c))
