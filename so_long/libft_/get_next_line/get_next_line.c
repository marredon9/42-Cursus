/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:47:15 by marredon          #+#    #+#             */
/*   Updated: 2023/10/05 12:20:50 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(char *str)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*get_read(int fd, char *buf)
{
	char	*str;
	int		ret;

	str = ft_strdup(buf);
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n'))
		return (str);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			buf[0] = '\0';
			return (ft_free(&str));
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (ft_free(&str));
		if (ft_strchr(buf, '\n'))
			ret = 0;
	}
	return (str);
}

static char	*get_newline(char *str)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	len = (ptr - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line || !*line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

static void	keep_str(char *buf)
{
	char	*keep;
	size_t	i;

	keep = ft_strchr(buf, '\n');
	i = 0;
	if (keep)
	{
		keep++;
		while (i < BUFFER_SIZE && keep[i] != '\0')
		{
			buf[i] = keep[i];
			i++;
		}
	}
	buf[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	char		*ret;

	if (fd < 0)
		return (NULL);
	str = get_read(fd, buf);
	if (!str)
		return (NULL);
	ret = get_newline(str);
	keep_str(buf);
	free(str);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	struct timeval start, end;

// 	gettimeofday(&start, NULL);
// 	fd = open("giant_line_nl.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	gettimeofday(&end, NULL);
// 	//system("leaks a.out");
// 	return (0);
// }
