X86_64 ?= ..
X86_64_KERNEL ?= $(X86_64)/kernel
X86_64_LIBX ?= $(X86_64)/libx

SHARED ?= ../../../shared
SHARED_KERNEL ?= $(SHARED)/kernel

CFLAGS ?=
CFLAGS += -D BITS64 -I "$(X86_64_KERNEL)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(X86_64_KERNEL)/*.nasm) $(wildcard $(X86_64_KERNEL)/*.c))

include $(X86_64_LIBX)/Makefile

include $(SHARED_KERNEL)/Makefile

# TODO: Makefile

.PHONY: all
all: build

.PHONY: clean
clean: .

.PHONY: build
build: $(OBJECTS)

%.nasm.o: %.nasm
	@$(NASM) $(NASMFLAGS) -o $@ $^

%.c.o: %.c
	@$(CC) $(CFLAGS) -o $@ $^
