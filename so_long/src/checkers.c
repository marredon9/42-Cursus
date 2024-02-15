
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

void	check_square(t_sl *data)
{
	//int		*len;
	int		i;

	i = 0;	
	while (data->map[i] && ft_strlen(data->map[i]) == ft_strlen(data->map[0]))
	{
		i++;
	}
	if (data->map [i] == NULL)
		printf("%s\n", "ta bien simetrico");
	else
		printf("%s\n", "ta mal simetrico");
}

int	check_walls(t_sl *data)
{
	//primera línea
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][i])
	{
		if(data->map[0][i] != '1')
			return(0);
		i++;
	}
	//ultima línea
	i = 0;
	while (data->map[j] != NULL)
		j++;
	while (data->map[j - 1][i])
	{
		if(data->map[j - 1][i] != '1')
			return(0);
		i++;
	}
	//primera columna
	j = 0;
	while (data->map[j])
	{
		if (data->map[j][0] != '1')
			return (0);
		j++;
	}
	//última columna
	j = 0;
	i = ft_strlen(data->map[0]);
	while (data->map[j])
	{
		if (data->map[j][i - 1] != '1')
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
	if (data->exit != 1 && data->player != 1)
		return (0);
	if (data->coins <= 0)
		return (0);
	return (1);
}

void	check(t_sl *data)
{
	check_square(data);
	if (check_walls(data) == 0)
		printf("%s\n", "ta mal paredes");
	else
		printf("%s\n", "ta bien paredes");
	if (check_valid_chars(data) == 0)
		printf("%s\n", "ta mal chars");
	else
		printf("%s\n", "ta bien chars");
	if (check_count(data) == 0)
		write (1, "Error\ninvalid amount of chars\n", 31);
	else 
		write (1, "ta bien conteo\n", 15);
}