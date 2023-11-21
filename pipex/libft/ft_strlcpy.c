/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:45:54 by marredon          #+#    #+#             */
/*   Updated: 2023/04/28 14:09:13 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	x;

	x = 0;
	if (size > 0)
	{
		while (src[x] && x < size - 1)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = 0;
	}
	while (src[x])
	{
		x++;
	}
	return (x);
}
