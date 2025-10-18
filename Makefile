# --- Variables ---
CC = gcc

# 1. Compiler Flags
# -MMD -MP: tells GCC to generate .d (dependency) files for each .c file.
CFLAGS = -Wall -g -Iinclude -MMD -MP

# 2. Linker Flags
LDFLAGS = -lreadline

# 3. Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# 4. Final Executable Name
TARGET = $(BINDIR)/mar1bash

# --- Automatic File Discovery ---

# Find all .c files in src/ and its subfolders
SOURCES = $(shell find $(SRCDIR) -name '*.c')

# Create a list of all .o (object) files that will live in obj/
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Create a list of all .d (dependency) files that will live in obj/
DEPS = $(OBJECTS:.o=.d)

# --- Rules ---

# Default rule
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	@echo "Build complete! Run with: $(TARGET)"

# Rule to compile .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# "Phony" target to clean up build files
clean:
	@rm -rf $(OBJDIR) $(BINDIR)
	@echo "Cleanup complete."

.PHONY: all clean

# --- Dependency Magic ---
# Include all the .d files.
# make will now read these files and learn about
# all the .h dependencies.
# The '-' means "don't complain if the file doesn't exist yet."
-include $(DEPS)