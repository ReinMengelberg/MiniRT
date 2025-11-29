NAME = libft.a                     # The name of the library you're creating
CC = cc                            # The compiler
CFLAGS = -Wall -Wextra -Werror -I. # Compilation flags

# Source files
SRC = $(wildcard *.c)              # All .c files in the current directory
SRC += $(wildcard gnl/*.c)         # All .c files in the gnl directory
SRC += $(wildcard printf/*.c)       # All .c files in the print directory

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