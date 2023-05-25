/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:36 by marredon          #+#    #+#             */
/*   Updated: 2023/05/03 10:32:40 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		a;
	const char	*string;

	a = 0;
	string = s;
	if (n == 0)
		return (NULL);
	while (a < n)
	{
		if ((unsigned char)string[a] == (unsigned char)c)
		{
			return ((char *)(string + a));
		}
		a++;
	}
	if (c == '\0' && ((char *)s)[a] == '\0')
		return (((char *)s) + a);
	return (NULL);
}
