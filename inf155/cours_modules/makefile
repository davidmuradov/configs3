# Makefile for compiling main.c with multiple header files and their respective .c files

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iheader

# Directories
SRC_DIR = ./
HEADER_DIR = header
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Header files and corresponding source files
HEADERS = $(wildcard $(HEADER_DIR)/*.h)
HEADER_SRCS = $(wildcard $(HEADER_DIR)/*.c)
HEADER_OBJS = $(patsubst $(HEADER_DIR)/%.c, $(BUILD_DIR)/%.o, $(HEADER_SRCS))

# Output executable
TARGET = program

# Rule to build the executable
$(TARGET): $(OBJ_FILES) $(HEADER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile header source files
$(BUILD_DIR)/%.o: $(HEADER_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(shell mkdir -p $(BUILD_DIR))

# Phony target to clean the project
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
