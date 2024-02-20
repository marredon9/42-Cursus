NAME		= 	so_long

CC			= 	gcc
RM			= 	rm -rf
SRC			= 	src/so_long
CFLAGS		= 	-Wall -Wextra -Werror
UNAME		= 	$(shell uname -s)

CFILES		=	src/main.c src/start_close.c src/checkers.c

OBJS		= 	$(CFILES:.c=.o)

LIBS		= 	lib

LIBFT_PATH	=	libft/
LIBFT		=	libft.a

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

$(NAME)		:	$(LIBFT_PATH)$(LIBFT) $(OBJS) $(MLXLIB) $(MLX)
				$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT_PATH)$(LIBFT) -o $(NAME)

$(LIBFT_PATH)$(LIBFT) :
				make -C$(LIBFT_PATH)

$(MLXLIB)	:
				make -C $(MLX)

objs/%.o	: 	src/%.c 
				mkdir -p objs
				$(CC) $(CFLAGS) -c $< -o $@

clean		: 	
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re 