include library.mk

include $(SHARED)/make/debug.mk
DEBUG_NAME := "shared/libefi"

.PHONY: all clean
all: clean
clean:
	@echo $(DEBUG_PREFIX)$@
	@$(MAKE) $(DEBUG_FLAGS) -C $(SHARED_LIBX) clean
	@find $(SHARED_LIBEFI_INCLUDE) -type f -name $(PATTERN_NASM_OBJECT) -delete
	@find $(SHARED_LIBEFI_INCLUDE) -type f -name $(PATTERN_C_OBJECT) -delete
