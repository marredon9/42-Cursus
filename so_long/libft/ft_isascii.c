/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:16:14 by marredon          #+#    #+#             */
/*   Updated: 2023/04/21 11:37:57 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int	c;
	int	result;
	int	result2;

	c = 128;
	write (1, &c, 1);
	write (1, "\n", 1);
	result = ft_isascii(c);
	printf("%d\n", result);
	result2 = isascii(c);
	printf("%d\n", result2);
	return (0);
}
*/