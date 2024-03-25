# Compiler settings
CC = clang
CFLAGS = -Wall -Wextra -Werror

# Find the most recently modified .c file
LATEST_C := $(shell ls -t *.c | head -n1)
# Derive the executable name
TARGET := $(LATEST_C:.c=)

# Default rule to compile and run the latest file
.PHONY: run
run:
	$(CC) $(CFLAGS) $(LATEST_C) -o $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
