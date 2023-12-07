/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:47:38 by marredon          #+#    #+#             */
/*   Updated: 2023/04/21 11:37:05 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ))
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

	c = '9';
	write (1, &c, 1);
	write (1, "\n", 1);
	result = ft_isalpha(c);
	printf("%d\n", result);
	result2 = isalpha(c);
	printf("%d\n", result2);
	return (0);
}
*/