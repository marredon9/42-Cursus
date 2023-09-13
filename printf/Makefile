# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marredon <marredon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:11:01 by marredon          #+#    #+#              #
#    Updated: 2023/09/13 12:05:57 by marredon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c\
ft_hexa_mayus.c ft_hexa_minus.c ft_hexa_pointer.c


INCLUDE = ft_printf.h

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

all:  ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %c ${INCLUDE}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: 
	${RM} ${OBJS}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re