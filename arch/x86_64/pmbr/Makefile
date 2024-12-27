INPUT := pmbr.nasm
OUTPUT := pmbr.bin

NASMC := nasm
NASMFLAGS := -f bin

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
