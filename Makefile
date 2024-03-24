# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Name of the output library
NAME = libftprintf.a

# Explicitly list all C source files
SRCS = 

# Object files based on the source files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rule for creating the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to prevent unnecessary relinks
.PHONY: all clean fclean re

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean everything (object files + library)
fclean: clean
	rm -f $(NAME)

# Rule to re-make everything
re: fclean all