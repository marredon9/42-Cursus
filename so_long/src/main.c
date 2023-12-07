/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:41:06 by marredon          #+#    #+#             */
/*   Updated: 2023/12/05 12:04:26 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	(void)mlx;
	(void)mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void)mlx_win;

	mlx_loop(mlx);
}