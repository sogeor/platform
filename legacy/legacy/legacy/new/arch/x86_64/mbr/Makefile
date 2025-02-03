SHELL = /bin/bash

p1_status ?= unknown
p1_type ?= unknown
p1_offset ?= unknown
p1_size ?= unknown

p2_status ?= unknown
p2_type ?= unknown
p2_offset ?= unknown
p2_size ?= unknown

p3_status ?= unknown
p3_type ?= unknown
p3_offset ?= unknown
p3_size ?= unknown

p4_status ?= unknown
p4_type ?= unknown
p4_offset ?= unknown
p4_size ?= unknown

INPUT := mbr.nasm
OUTPUT := mbr.bin

NASMC := nasm
NASMFLAGS := -f bin \
             -D P1_STATUS=$(p1_status) \
             -D P1_TYPE=$(p1_type) \
             -D P1_OFFSET=$(p1_offset) \
             -D P1_SIZE=$(p1_size) \
             -D P2_STATUS=$(p2_status) \
             -D P2_TYPE=$(p2_type) \
             -D P2_OFFSET=$(p2_offset) \
             -D P2_SIZE=$(p2_size) \
             -D P3_STATUS=$(p3_status) \
             -D P3_TYPE=$(p3_type) \
             -D P3_OFFSET=$(p3_offset) \
             -D P3_SIZE=$(p3_size) \
             -D P4_STATUS=$(p4_status) \
             -D P4_TYPE=$(p4_type) \
             -D P4_OFFSET=$(p4_offset) \
             -D P4_SIZE=$(p4_size)

QEMU := qemu-system-i386
QEMUFLAGS := -net none -drive format=raw,file=$(OUTPUT)

.PHONY: all
all: clean build emulate

.PHONY: clean
clean:
ifneq ($(wildcard $(OUTPUT)),)
	@echo "Deleting <$(OUTPUT)>"
	@rm -f "$(OUTPUT)"
endif

.PHONY: build
build:
	@echo "Compiling <$(INPUT)> to <$(OUTPUT)>"
	@$(NASMC) $(NASMFLAGS) -o $(OUTPUT) $(INPUT)

.PHONY: emulate
emulate: build
	@echo "Emulating <$(OUTPUT)> using <$(QEMU)>"
	@$(QEMU) $(QEMUFLAGS)
