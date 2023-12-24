# Makefile

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Linker flags
LDFLAGS =

# Source files
SOURCES = main.c grid.c boats.c playfonction.c

# Object files to build
OBJECTS = $(SOURCES:.c=.o)

# Name of the executable
EXECUTABLE = battleship

# Default target
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

# Target for rebuilding the project
rebuild: clean all

.PHONY: all clean rebuild
