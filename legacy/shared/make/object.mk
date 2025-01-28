include $(SHARED)/make/pattern.mk
include $(SHARED)/make/utility.mk
object_find_nasm = $(patsubst %$(PATTERN_NASM_SOURCE_EXTENSION),%$(PATTERN_NASM_OBJECT_EXTENSION),$(call utility_recursive_wildcard,$1,$(PATTERN_NASM_SOURCE)))
object_find_c = $(patsubst %$(PATTERN_C_SOURCE_EXTENSION),%$(PATTERN_C_OBJECT_EXTENSION),$(call utility_recursive_wildcard,$1,$(PATTERN_C_SOURCE)))

include $(SHARED)/make/utility.mk
object_prepare_nasm = $(call utility_remove_duplicates,$(call object_find_nasm,$1) $2)
object_prepare_c = $(call utility_remove_duplicates,$(call object_find_c,$1) $2)
