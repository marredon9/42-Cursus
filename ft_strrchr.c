/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:19:17 by marredon          #+#    #+#             */
/*   Updated: 2023/05/02 11:41:42 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	x;

	x = ft_strlen(s) +1;
	while (x--)
	{
		if (s[x] == (char)c)
		{
			return ((char *)&s[x]);
		}
	}
	return (NULL);
}
