UNAME=	$(shell uname)
MLX=lib/mlx_$(UNAME).a
NAME=so_long
CC=gcc
CCFLAGS=-Wall -Wextra -Werror
MLXFlAG :=

$(NAME): $(MLX)
ifeq ($(UNAME), Darwin)
	$(eval MLXFlAG := -framework OpenGL -framework AppKit)
else
	ifeq ($(UNAME), Linux)
		$(eval MLXFlAG := -L.. -L%%/../lib -lXext -lX11 -lm -lbsd)
	endif
endif
	$(CC) $(CCFLAGS) $(MLXFlAG) src/main.c $(MLX) -o $(NAME)

$(MLX):
	mkdir -p lib
ifeq ($(UNAME), Darwin)
	@echo Compiling mlx Darwin
	$(eval MLXFlAG := -framework OpenGL -framework AppKit)
	make -C mlx_darwin
else
	ifeq ($(UNAME), Linux)
		@echo Compiling mlx Linux
		$(eval MLXFlAG := -L.. -L%%/../lib -lXext -lX11 -lm -lbsd)
		make -C mlx_linux
	else
		@echo Your OS is not compatible
	endif
endif


