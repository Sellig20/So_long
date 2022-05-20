# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:35:34 by jecolmou          #+#    #+#              #
#    Updated: 2022/05/20 16:04:45 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME					=	so_long

SRCS					=	so_long.c \
							parsing.c \
							get_next_line/get_next_line.c \
							get_next_line/get_next_line.h \
							get_next_line/get_next_line_utils.c \
							libft/ft_strnstr.c \

OBJS					=	${SRCS:.c=.o}

CC						=	clang

CFLAGS					=	-Wall -Wextra -Werror

RM						=	rm -rf

all		:	${NAME}

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.c
		$(CC) $(CFLAGS)	-c	$<	-o	$@

clean	:
		${RM}	${OBJS}

fclean	:	clean
		${RM}	${NAME}

re:	fclean	all

.PHONY:	all	clean	fclean	re
