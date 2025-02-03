include project.mk

include $(SHARED)/make/debug.mk
DEBUG_NAME := "x86/kernel"

.PHONY: all clean build
all: clean build
clean:
	@echo $(DEBUG_PREFIX)$@
	@$(MAKE) $(DEBUG_FLAGS) -C $(X86_LIBK) clean
	@$(MAKE) $(DEBUG_FLAGS) -C $(SHARED_KERNEL) clean
	@find $(X86_KERNEL_INCLUDE) -type f -name $(PATTERN_NASM_OBJECT) -delete
	@find $(X86_KERNEL_INCLUDE) -type f -name $(PATTERN_C_OBJECT) -delete
	@rm -f $(X86_KERNEL_IMAGE)
build: $(X86_KERNEL_LD_OBJECTS)
	@echo $(DEBUG_PREFIX)$@
	@$(X86_TOOLCHAIN_LD) $(X86_KERNEL_LD_FLAGS) -o $(X86_KERNEL_IMAGE) $^

%$(PATTERN_NASM_OBJECT_EXTENSION): %$(PATTERN_NASM_SOURCE_EXTENSION)
	@echo $(DEBUG_PREFIX)$@
	@$(X86_TOOLCHAIN_NASM) $(X86_KERNEL_NASM_FLAGS) -o $@ $^

%$(PATTERN_C_OBJECT_EXTENSION): %$(PATTERN_C_SOURCE_EXTENSION)
	@echo $(DEBUG_PREFIX)$@
	@$(X86_TOOLCHAIN_C) $(X86_KERNEL_GCC_FLAGS) -o $@ $^
