/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:23:41 by marredon          #+#    #+#             */
/*   Updated: 2023/05/09 11:01:25 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destiny;
	const char	*origin;
	size_t		x;

	destiny = dst;
	origin = src;
	if (dst > src)
	{
		x = len;
		while (x--)
		{
			destiny[x] = origin[x];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (destiny);
}
