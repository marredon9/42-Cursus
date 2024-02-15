
#include "../inc/so_long.h"

int close_game(t_sl *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    free(data->mlx);
    exit(0);
}