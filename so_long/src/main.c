/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:41:06 by marredon          #+#    #+#             */
/*   Updated: 2023/12/07 15:43:33 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	check(&data);
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
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "ah");
	mlx_hook(data.mlx, 27, 1, close_game, &data);
	mlx_loop(data.mlx); 
}

