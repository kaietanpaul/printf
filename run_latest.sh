#!/bin/bash

# Find the most recently modified .c file
latest_c_file=$(ls -t *.c | head -n1)

# Derive the executable name
executable=${latest_c_file%.c}

# Echo the executable name
echo -e "$executable:\n"

# Compile the latest .c file into an executable, suppress make output
make "$executable" > /dev/null 2>&1

# Run the executable
./"$executable"

# Clean up, suppress make clean output
make clean > /dev/null 2>&1
