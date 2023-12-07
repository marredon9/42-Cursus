/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:42:44 by marredon          #+#    #+#             */
/*   Updated: 2023/05/25 15:41:52 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	*malloc_error(char **result, int err_idx)
{
	while (err_idx--)
	{
		free (result[err_idx]);
	}
	free (result);
	return (NULL);
}

static int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	const char	*start;
	char		**result;
	int			i;

	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(char *), (ft_countwords(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i++])
				return (malloc_error(result, i - 1));
		}
		else
			s++;
	}
	return (result);
}
/*
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("salut les cons", ' ');
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
*/