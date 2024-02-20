

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_sl	data;
	//int		i;
	//int		j;
	//char	*str = "ANIMALITO";

	(void)argc;
	data.path = argv[1];
	initializer(&data);
	read_map(&data);
	if (check(&data) == 0)
		return (0);
	/*i = 0;
	while (data.map[i] != 0)
	{
		j = 0;
		while (data.map[i][j] != 0)
		{
			if (data.map[i][j] == '1')
				printf("%c", 'X');
			else if (data.map[i][j] == '0')
				printf("%c", 'X');
			else
				printf("%c",data.map[i][j]);
			
			j++;

		}
		printf("\n");
		i++;
	}*/
	
	//printf("%c\n", str[3]);
 	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.cols * 64, data.rows * 64, "ah");
	mlx_hook(data.mlx_win, 17, 0, close_game, &data);
	mlx_loop(data.mlx); 
}

