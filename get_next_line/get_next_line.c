/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:47:15 by marredon          #+#    #+#             */
/*   Updated: 2023/09/26 13:33:22 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_clean(char *storage)
{
	char	*clean;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!clean)
		return (NULL);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			i++;
		clean[j] = storage[i];
		i++;
		j++;
	}
	clean[j] = '\0';
	return (clean);
}

char	*get_newline(char *str)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	len = (ptr - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
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
			return (ft_free(&str));
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (ft_free(&str));
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
}

/*
int	main(void)
{
	char *storage = "Hello, world!\nThis is a test string.";

	printf("Original storage: %s\n", storage);

	char *new_storage = clean_storage(storage);

	printf("Cleaned storage: %s\n", new_storage);

	return 0;
}*/
