# Cross-compiler prefix for ARM GNU toolchain
ARMGNU ?= aarch64-linux-gnu

# Compiler flags
CFLAGS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -Iinclude/peripherals
ASMOPS = -Iinclude

# Directories for build and source files
BUILD_DIR = build
SRC_DIR = src

# Target for the final kernel image
all: kernel8.img

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) *.img *.elf

# Rule for compiling C files
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(CFLAGS) -MMD -c $< -o $@

# Rule for compiling assembly files
$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(ASMOPS) -MMD -c $< -o $@

# Source files (including the boot.S file with your startup code)
C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/boot.S)

# Object files generated from the source files
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

# Dependency files for each object file
DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

# Linking the kernel ELF file
$(BUILD_DIR)/kernel8.elf: $(OBJ_FILES) $(SRC_DIR)/linker.ld
	$(ARMGNU)-ld -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf $(OBJ_FILES)

# Creating the final kernel image in binary format
kernel8.img: $(BUILD_DIR)/kernel8.elf
	$(ARMGNU)-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
