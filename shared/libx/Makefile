include library.mk

include $(SHARED)/make/debug.mk
DEBUG_NAME := "shared/libx"

.PHONY: all clean
all: clean
clean:
	@echo $(DEBUG_PREFIX)$@
	@find $(SHARED_LIBX_INCLUDE) -type f -name $(PATTERN_NASM_OBJECT) -delete
	@find $(SHARED_LIBX_INCLUDE) -type f -name $(PATTERN_C_OBJECT) -delete
