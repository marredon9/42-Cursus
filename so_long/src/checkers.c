
#include "../inc/so_long.h"


void	initializer(t_sl *data)
{
	data->coins = 0;
	data->exit = 0;
	data->player = 0;
}

void	read_map(t_sl *data)
{
	int		fd;
	char	*miau;

	miau = ft_calloc(5000000, sizeof(char));
	fd = open(data->path, O_RDONLY);
	read(fd, miau, 5000000);
	data->map = ft_split(miau, '\n');
	
}

int	check_square(t_sl *data)
{
	int		i;

	i = 0;	
	while (data->map[i] && ft_strlen(data->map[i]) == ft_strlen(data->map[0]))
		i++;
	if (data->map [i] == NULL)
		return (1);
	return (0);
}

int	check_walls(t_sl *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
		j++;
	while (data->map[0][i])
	{
		if(data->map[0][i] != '1')
			return(0);
		if(data->map[j - 1][i] != '1')
			return(0);
		i++;
	}
	j = 0;
	while (data->map[j])
	{
		if (data->map[j][0] != '1')
			return (0);
		if (data->map[j][ft_strlen(data->map[0]) - 1] != '1')
			return(0);
		j++;
	}
	return(1);
}

int	check_valid_chars(t_sl *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0' \
				&& data->map[i][j] != 'P' && data->map[i][j] != 'E' \
				&& data->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	data->cols = ft_strlen(data->map[0]);
	data->rows = i;
	return (1);
}

int	check_count(t_sl *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->coins++;
			if (data->map[i][j] == 'P')
				data->player++;
			if (data->map[i][j] == 'E')
				data->exit++;
			j++;
		}
		i++;
	}
	if (data->exit != 1 || data->player != 1)
		return (0);
	if (data->coins <= 0)
		return (0);
	return (1);
}



int	check(t_sl *data)
{
	if (check_square(data) == 0)
		return (printf("%s\n", "no es simetrico"), 0);
	if (check_walls(data) == 0)
		return (printf("%s\n", "ta mal paredes"), 0);
	if (check_valid_chars(data) == 0)
		return (printf("%s\n", "ta mal chars"), 0);
	if (check_count(data) == 0)
		return (printf("Error\ninvalid amount of chars\n"), 0);
	return (1);
}
