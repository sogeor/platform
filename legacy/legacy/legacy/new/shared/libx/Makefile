SHARED ?= ..
SHARED_LIBX ?= $(SHARED)/libx
SHARED_LIBX_INCLUDE ?= $(SHARED_LIBX)/include

CFLAGS ?=
CFLAGS += -I $(SHARED_LIBX_INCLUDE)

OBJECTS ?=
#OBJECTS += $(addsuffix .o,$(wildcard $(SHARED_LIBX)/*.nasm) $(wildcard $(SHARED_LIBX)/*.c))
OBJECTS += $(addsuffix .o,$(shell find $(SHARED_LIBX_INCLUDE) -type f -iname '*.nasm') $(shell find $(SHARED_LIBX_INCLUDE) -type f -iname '*.c'))
