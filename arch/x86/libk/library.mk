ROOT ?= ../../..
ARCH ?= $(ROOT)/arch
X86 ?= $(ARCH)/x86
SHARED ?= $(ROOT)/shared

X86_LIBX ?= $(X86)/libx
include $(X86_LIBX)/library.mk

SHARED_LIBK ?= $(SHARED)/libk
include $(SHARED_LIBK)/library.mk

include $(SHARED)/make/object.mk
X86_LIBX ?= $(X86)/libx
X86_LIBX_INCLUDE ?= $(X86_LIBX)/include
X86_LIBX_NASM_FLAGS ?= -i $(X86_LIBX_INCLUDE) $(X86_LIBX_NASM_FLAGS) $(SHARED_LIBK_NASM_FLAGS)
X86_LIBX_NASM_OBJECTS ?= $(call object_prepare_nasm,$(X86_LIBX_INCLUDE),$(X86_LIBX_NASM_OBJECTS) $(SHARED_LIBK_NASM_OBJECTS))
X86_LIBX_GCC_FLAGS ?= -I $(X86_LIBX_INCLUDE) $(X86_LIBX_GCC_FLAGS) $(SHARED_LIBK_GCC_FLAGS)
X86_LIBX_C_OBJECTS ?= $(call object_prepare_c,$(X86_LIBX_INCLUDE),$(X86_LIBX_C_OBJECTS) $(SHARED_LIBK_C_OBJECTS))
X86_LIBX_LD_FLAGS ?= $(X86_LIBX_LD_FLAGS) $(SHARED_LIBK_LD_FLAGS)