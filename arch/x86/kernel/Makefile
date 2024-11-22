X86 ?= ..
X86_KERNEL ?= $(X86)/kernel
X86_LIBX ?= $(X86)/libx

SHARED ?= ../../../shared
SHARED_KERNEL ?= $(SHARED)/kernel

CFLAGS ?=
CFLAGS += -I "$(X86_KERNEL)/include"

OBJECTS ?=
OBJECTS += $(addsuffix .o,$(wildcard $(X86_KERNEL)/*.nasm) $(wildcard $(X86_KERNEL)/*.c))

include $(X86_LIBX)/Makefile

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
