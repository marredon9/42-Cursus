/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:04:29 by marredon          #+#    #+#             */
/*   Updated: 2023/04/21 11:46:55 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
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

	c = '8';
	write (1, &c, 1);
	write (1, "\n", 1);
	result = ft_isdigit(c);
	printf("%d\n", result);
	result2 = isdigit(c);
	printf("%d\n", result2);
	return (0);
}
*/