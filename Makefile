# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11
CFLAGS += -Wno-deprecated-declarations

# Path to the static libraries and header files
LIB_DIR1 = data-structures
LIB_NAME1 = libdata_structures.a
LIB_PATH1 = $(LIB_DIR1)/$(LIB_NAME1)

LIB_DIR2 = ray-marching-lib
LIB_NAME2 = libdata_ray_marching.a
LIB_PATH2 = $(LIB_DIR2)/$(LIB_NAME2)

INCLUDE_DIRS = -I$(LIB_DIR1) -I$(LIB_DIR2)

# Source and object files
SRC = ray_marching.c
OBJ = $(SRC:.c=.o)

# Executable name
TARGET = program

# Default rule: Build the executable
all: $(TARGET)

# Build the static libraries in both directories
$(LIB_PATH1):
	@echo "Building static library in $(LIB_DIR1)..."
	@$(MAKE) -C $(LIB_DIR1)

$(LIB_PATH2):
	@echo "Building static library in $(LIB_DIR2)..."
	@$(MAKE) -C $(LIB_DIR2)

# Link object files and static libraries to create the executable
$(TARGET): $(OBJ) $(LIB_PATH1) $(LIB_PATH2)
	@echo "Linking object files and static libraries..."
	@$(CC) $(OBJ) -L$(LIB_DIR1) -ldata_structures -L$(LIB_DIR2) -ldata_ray_marching -o $(TARGET)

# Compile the ray_marching.c file into an object file
%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Clean up generated files
clean:
	@echo "Cleaning up..."
	@$(MAKE) -C $(LIB_DIR1) clean
	@$(MAKE) -C $(LIB_DIR2) clean
	@del /Q $(OBJ) 2> NUL
	@del /Q $(TARGET) 2> NUL
	@del program.exe

# Phony targets to avoid conflicts with files named "all" or "clean"
.PHONY: all clean