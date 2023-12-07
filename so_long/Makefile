NAME		= 	so_long

CC			= 	gcc
RM			= 	rm -rf
SRC			= 	src/so_long
CFLAGS		= 	-g -Wall -Wextra -Werror
UNAME		= 	$(shell uname -s)

CFILES		=	src/main.c

OBJS		= 	$(CFILES:.c=.o)

LIBS		= 	lib

ifeq ($(UNAME), Darwin)
MLX			= 	./$(LIBS)/mlx_darwin
MLXFLAGS	= 	-03 -L $(MLX) -lmlx -framework OpenGL -framework Appkit
MLXLIB		= 	$(MLX)/libmlx.a
else
MLX			= 	./$(LIBS)/mlx_linux
MLXFLAGS	= 	-L $(MLX) -lmlx -lXext -lX11 -lm
MLXLIB		= 	$(MLX)/libmlx_Linux.a
endif

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(MLXLIB) $(MLX)
				$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(MLXLIB)	:
				make -C $(MLX)

objs/%.o	: 	src/%.c 
				mkdir -p objs
				$(CC) $(CFLAGS) -c $< -o $@

clean		: 	$(RM) $(OBJS)

fclean		:	make -C$(MLX) clean

re			:	fclean all

.PHONY		:	all clean fclean re 