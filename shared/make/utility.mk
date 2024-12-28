utility_remove_duplicates = $(if $1,$(firstword $1) $(call utility_remove_duplicates,$(filter-out $(firstword $1),$1)))
utility_recursive_wildcard = $(foreach path,$1,$(wildcard $(path)$2) $(call utility_recursive_wildcard,$(wildcard $(path)*/),$2))
utility_find_tool = $(shell which $1)
