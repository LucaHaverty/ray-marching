# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Find all .c files in this directory and its subdirectories
SRC = $(wildcard */*.c) $(wildcard *.c)

# Convert .c files to .o files
OBJ = $(patsubst %.c,%.o,$(SRC))

# Library name
TARGET = libdata_ray_marching.a

# Default rule: Build the library
all: $(TARGET)

# Archive object files into a static library
$(TARGET): $(OBJ)
	@echo "Compiling ray marching lib..."
	@ar rcs $(TARGET) $(OBJ)

# Compile each .c file into .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	@echo "Cleaning up ray marching lib..."
	@del /Q $(TARGET) 2> NUL
	@for /d %%d in (*) do del /Q %%d\*.o 2> NUL
	@del /Q *.o 2> NUL

# Phony targets to avoid conflicts with files named "all" or "clean"
.PHONY: all clean