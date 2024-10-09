ARMGNU ?= aarch64-linux-gnu

CFLAGS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -Iinclude/peripherals
ASMOPS = -Iinclude

BUILD_DIR = build
SRC_DIR = src

all: kernel8.img

clean:
	rm -rf $(BUILD_DIR) *.img *.elf

# Rule for compiling C files
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(CFLAGS) -MMD -c $< -o $@

# Rule for compiling assembly files
$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	$(ARMGNU)-gcc $(ASMOPS) -MMD -c $< -o $@

# Wildcard pattern matching for source files
C_FILES = $(wildcard $(SRC_DIR)/kernel.c $(SRC_DIR)/uart.c)  # Specify the source files here
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)

# Object files derived from the source files
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

# Dependency files
DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

# Linking the kernel ELF
$(BUILD_DIR)/kernel8.elf: $(OBJ_FILES) $(SRC_DIR)/linker.ld
	$(ARMGNU)-ld -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf $(OBJ_FILES)

# Creating the kernel image
kernel8.img: $(BUILD_DIR)/kernel8.elf
	$(ARMGNU)-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
