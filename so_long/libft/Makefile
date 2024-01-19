# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marredon <marredon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:47:28 by marredon          #+#    #+#              #
#    Updated: 2023/05/24 15:31:14 by marredon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

UTILS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c \
ft_strlen.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strncmp.c \
ft_strchr.c ft_strrchr.c ft_memchr.c ft_strnstr.c ft_memmove.c \
ft_atoi.c ft_calloc.c  ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_memcmp.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_split.c 

OBJS = $(UTILS:.c=.o)		
		
all : $(NAME)

$(NAME): $(OBJS)
		 ar rcs $(NAME) $(OBJS)

clean: 
		 $(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY: all clean fclean re  bonus