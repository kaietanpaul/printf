# Compiler settings
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Find the first C file in the directory
SRC := $(firstword $(wildcard *.c))

# The target executable name
TARGET := main

# Default rule to compile the first found C file
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
