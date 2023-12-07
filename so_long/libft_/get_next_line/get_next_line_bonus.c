/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:47:15 by marredon          #+#    #+#             */
/*   Updated: 2023/10/03 11:41:10 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_newline(char *str)
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

char	*get_read(int fd, char *str)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&str));
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free (buf);
			return (ft_free(&str));
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (ft_free(&str));
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	return (str);
}

char	*keep_str(char *str)
{
	char	*keep;
	char	*ret;

	keep = ft_strchr(str, '\n');
	ret = ft_substr(keep, 1, ft_strlen(keep));
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	ret = get_newline(str[fd]);
	str[fd] = keep_str(str[fd]);
	if (!str[fd] && !ret)
	{
		free (ret);
		return (NULL);
	}
	return (ret);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}*/
