X86_TOOLCHAIN_NASM_NAME := nasm
X86_TOOLCHAIN_C_NAME := i686-elf-gcc
X86_TOOLCHAIN_LD_NAME := i686-elf-ld

include $(SHARED)/make/utility.mk
ifndef CLION_PROJECT_IMPORT
X86_TOOLCHAIN_NASM := $(call utility_find_tool,$(X86_TOOLCHAIN_NASM_NAME))
X86_TOOLCHAIN_C := $(call utility_find_tool,$(X86_TOOLCHAIN_C_NAME))
X86_TOOLCHAIN_LD := $(call utility_find_tool,$(X86_TOOLCHAIN_LD_NAME))
else
X86_TOOLCHAIN_NASM := /home/linuxbrew/.linuxbrew/bin/nasm
X86_TOOLCHAIN_C := /home/linuxbrew/.linuxbrew/bin/i686-elf-gcc
X86_TOOLCHAIN_LD := /home/linuxbrew/.linuxbrew/bin/i686-elf-ld
endif
