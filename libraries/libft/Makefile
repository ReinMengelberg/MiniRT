NAME = libft.a                     # The name of the library you're creating
CC = cc                            # The compiler
CFLAGS = -Wall -Wextra -Werror -I. # Compilation flags
SRC = $(wildcard *.c)              # Use wildcard to include all .c files in the directory
OBJ = $(SRC:.c=.o)                 # Convert all .c files to their respective .o files

# Rule to create the library from the object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)       # Create static library from object files

# Default rule to build the library
all: $(NAME)

# Rule to clean up object files
clean:
	rm -f $(OBJ)

# Rule to clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (clean + all)
re: fclean all

# Phony targets (these don't correspond to actual files)
.PHONY: all clean fclean re