/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:36:23 by marredon          #+#    #+#             */
/*   Updated: 2023/05/03 10:53:43 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
	{
		return ((char *)haystack);
	}
	while (*haystack && len--)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			if (!needle[++i])
			{
				return ((char *)haystack);
			}
			if (i > len)
			{
				return (0);
			}
		}
		haystack++;
	}
	return (0);
}
