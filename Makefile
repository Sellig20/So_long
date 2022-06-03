# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:35:34 by jecolmou          #+#    #+#              #
#    Updated: 2022/06/03 19:08:51 by jecolmou         ###   ########.fr        #
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

LIBFT = ./libft/libft.a

NAME = so_long

MLX = ./mlx/libmlx.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

FL_MLX	=	 -ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(FL_MLX) $(OBJ) -o $(NAME)  $(LIBFT) $(MLX) -g

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	# $(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
