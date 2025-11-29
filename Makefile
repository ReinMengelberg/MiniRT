#this is the makefile

NAME	= miniRT
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g -pthread
RM		= rm -f
OBJ_DIR	= obj
INC_DIR = includes
CLANKER = includes/bigmoneyclanker.txt

SRCS	= \
		src/main.c \
		src/validate.c \
		src/parser/scene.c \
		src/creator/creator.c \
		src/debug/composition.c \
		src/debug/scene.c \
		src/debug/shapes.c \
		src/debug/utils.c \
		src/image/fast.c \
		src/image/utils.c \
		src/math/vector_complex.c \
		src/math/vector_simple.c \
		src/movement/move.c \
		src/movement/rotate.c \
		src/parser/ambient.c \
		src/parser/camera.c \
		src/parser/composition.c \
		src/parser/cylinder.c \
		src/parser/light.c \
		src/parser/plane.c \
		src/parser/sphere.c \
		src/parser/viewport.c \
		src/parser/utils/ft_atod.c \
		src/parser/utils/ft_atof.c \
		src/parser/utils/light_utils.c \
		src/parser/utils/objecs_utils.c \
		src/parser/utils/objects.c \
		src/parser/utils/objects_free.c \
		src/parser/utils/plane_utils.c \
		src/parser/utils/sphere_utils.c \
		src/parser/utils/tokens.c \
		src/tracer/color_utils.c \
		src/tracer/intersect.c \
		src/tracer/intersect_cylinder.c \
		src/tracer/intersect_plane.c \
		src/tracer/intersect_sphere.c \
		src/tracer/lighting.c \
		src/tracer/shadowing.c \
		src/tracer/tracer.c \
		src/tracer/try_intersection.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

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
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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

.PHONY: all clean fclean re bonus