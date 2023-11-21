/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:02:34 by marredon          #+#    #+#             */
/*   Updated: 2023/04/28 13:41:09 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destiny;
	const char	*source;
	size_t		x;

	destiny = dst;
	source = src;
	if (!dst && !src)
		return (0);
	x = 0;
	while (x < n)
	{
		destiny[x] = source[x];
		x++;
	}
	return (dst);
}
