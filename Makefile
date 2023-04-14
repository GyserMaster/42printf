# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 12:27:30 by spetrov           #+#    #+#              #
#    Updated: 2023/02/25 20:12:45 by spetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putpointer.c \
		ft_putx.c \
		ft_putdi.c \
		ft_putul.c \
		ft_printf.c \

OBJ	= ${SRC:%.c=%.o}

NAME	= libftprintf.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

$(NAME):	${OBJ}
			${CC} ${FLAGS} -c ${SRC}
			ar rc ${NAME} ${OBJ} ft_printf.h

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
