include library.mk

include $(SHARED)/make/debug.mk
DEBUG_NAME := "shared/bootefi"

.PHONY: all clean
all: clean
clean:
	@echo $(DEBUG_PREFIX)$@
	@$(MAKE) $(DEBUG_FLAGS) -C $(SHARED_LIBEFI) clean
	@find $(SHARED_BOOTEFI_INCLUDE) -type f -name $(PATTERN_NASM_OBJECT) -delete
	@find $(SHARED_BOOTEFI_INCLUDE) -type f -name $(PATTERN_C_OBJECT) -delete
