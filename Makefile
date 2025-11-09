#this is the makefile

NAME	= RenderClanker
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g -pthread
RM		= rm -f
OBJ_DIR	= obj
INC_DIR = includes
DEP_DIR	= $(OBJ_DIR)
CLANKER = includes/bigmoneyclanker.txt

SRCS	= \
$(wildcard *.c) \
$(wildcard src/*.c) \
$(wildcard src/*/*.c) \
$(wildcard src/*/*/*.c)

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Libraries
LIBFT_DIR	= libraries/libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= libraries/minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a

# Includes
INCLUDES	= -Iincludes -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		= -lm -lX11 -lXext -pthread

all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)
	@cat $(CLANKER) 2>/dev/null || true

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS)
	@echo "\033[0;32m✓ miniRT compiled successfully!\033[0m"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

-include $(DEPS)

.PHONY: all clean fclean re bonus