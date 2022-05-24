# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:58:35 by jecolmou          #+#    #+#              #
#    Updated: 2022/05/24 14:04:41 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_split.c \
				ft_strncmp.c \
				ft_strnstr.c \

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

HEADER		= libft.h

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar -rcs	${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} libft.a

re:			fclean all

bonus:		${OBJS}
			ar -rcs ${NAME} ${OBJS}

.PHONY:		all bonus clean fclean re
