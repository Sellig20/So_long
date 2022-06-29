# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:35:34 by jecolmou          #+#    #+#              #
#    Updated: 2022/06/28 13:36:36 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME					=	so_long

SRC					=	so_long.c \
							parsing/parsing.c \
							parsing/open_map.c \
							parsing/parse_p.c \
							parsing/parse_e.c \
							parsing/parse_c.c \
							parsing/wall.c \
							get_next_line/get_next_line.c \
							get_next_line/get_next_line_utils.c \
							linked_lists/ft_add_back.c \
							linked_lists/ft_lstsize.c \
							linked_lists/ft_lstclear.c \
							tools.c \
							mlx.c \
							get_images.c \
							keyboard.c \
							keyboard_annex.c \
							x_y.c \

LIBFT = ./libft/libft.a

NAME = so_long

MLX = ./mlx/libmlx.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

FL_MLX	=	 -ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(FL_MLX) $(OBJ) -o $(NAME) -Llibft -lft -Lmlx -lmlx

$(LIBFT) :
	$(MAKE) -C ./libft

$(MLX) :
	$(MAKE) -C ./mlx

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

malloc_test: $(OBJ) $(MLX) $(LIBFT)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} $(FL_MLX) -L. -lmallocator -Llibft -lft -Lmlx -lmlx

.PHONY: clean fclean re
