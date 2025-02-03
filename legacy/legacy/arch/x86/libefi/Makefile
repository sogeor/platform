include library.mk

include $(SHARED)/make/debug.mk
DEBUG_NAME := "x86/libk"

.PHONY: all clean
all: clean
clean:
	@echo $(DEBUG_PREFIX)$@
	@$(MAKE) $(DEBUG_FLAGS) -C $(X86_LIBX) clean
	@$(MAKE) $(DEBUG_FLAGS) -C $(SHARED_LIBK) clean
	@find $(X86_LIBX_INCLUDE) -type f -name $(PATTERN_NASM_OBJECT) -delete
	@find $(X86_LIBX_INCLUDE) -type f -name $(PATTERN_C_OBJECT) -delete
