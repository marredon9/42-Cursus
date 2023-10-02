/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:47:15 by marredon          #+#    #+#             */
/*   Updated: 2023/10/02 13:37:41 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read(fd, str);
	if (!str)
		return (NULL);
	ret = get_newline(str);
	str = keep_str(str);
	if (!str && !ret)
	{
		free (ret);
		return (NULL);
	}
	return (ret);
}

/*int	main(void)
{
	int		fd;
	//char	*line;
	//int i = 0;

	//fd = open("test.txt", O_RDONLY);
	//line = get_next_line(fd);
	//// printf("line: %s fd: %d\n", line, fd);
//	//printf("%d", *line);
	//while (i++ < 3)
	//{
	//	printf("%s", line);
	//	free (line);
	//	line = get_next_line(fd);
	//}
	//close(fd);
	//system("leaks a.out");

	fd = open("42_with_nl", O_RDWR);
	printf("[%s]\n",get_next_line(fd));
	char c = 0; read(fd, &c, 1);
	printf("[%c]\n",c);
	//printf("[%s]\n",get_next_line(fd));	
	return (0);
}*/
