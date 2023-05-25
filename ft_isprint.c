/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:08 by marredon          #+#    #+#             */
/*   Updated: 2023/04/21 11:52:10 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
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

	c = 85;
	write (1, &c, 1);
	write (1, "\n", 1);
	result = ft_isprint(c);
	printf("%d\n", result);
	result2 = isprint(c);
	printf("%d\n", result2);
	return (0);
}
*/