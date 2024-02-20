#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# if defined(__APPLE__)
#  include "../lib/mlx_darwin/mlx.h"
# elif defined(__linux__)
#  include "../lib/mlx_linux/mlx.h"
# endif

typedef struct sl
{
    void    *mlx;
    void    *mlx_win;
    char    *path;
    char    **map;
    int     rows;
    int     cols;
    int     coins;
    int     player;
    int     exit;
}               t_sl;

/*checks*/

void	initializer(t_sl *data);
void	read_map(t_sl *data);
int 	check_square(t_sl *data);
int     check_walls(t_sl *data);
int	    check_valid_chars(t_sl *data);
int	    check_count(t_sl *data);
int 	check(t_sl *data);

/*start and close game*/

int close_game(t_sl *data);

#endif