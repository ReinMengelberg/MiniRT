# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 11:33:36 by theyn             #+#    #+#              #
#    Updated: 2025/05/31 12:21:11 by jspannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME 		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror 
INCLUDES	= -I../headers
AR			= ar rcs
RM			= rm -f
OBJ_DIR		= ../obj

SRCS		= \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_free_array.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strjoinfree.c \
ft_strlcat.c \
ft_strcpy.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c 

GNL_DIR 	= ../get_next_line
GNL_SRCS 	= \
$(GNL_DIR)/get_next_line_bonus.c \
$(GNL_DIR)/get_next_line_utils_bonus.c

PRINTF_DIR 	= ../ft_printf
PRINTF_SRCS = \
$(PRINTF_DIR)/ft_printf.c \
$(PRINTF_DIR)/ft_helper_functions.c \
$(PRINTF_DIR)/ft_hexadecimals.c

# Object files
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
GNL_OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRCS:.c=.o)))
PRINTF_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_SRCS:.c=.o)))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@$(AR) $(NAME) $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	
fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re