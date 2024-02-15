#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# if defined(__APPLE__)
#  include "../lib/mlx_darwin/mlx.h"
# elif defined(__linux__)
#  include "../lib/mlx_linux/mlx.h"
# endif

typedef struct sl
{
    char    *path;
    char    **map;
    int     total_rows;
    int     total_cols;
    int     coins;
    int     player;
    int     exit;
}               t_sl;

#endif