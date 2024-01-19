/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:26:29 by marredon          #+#    #+#             */
/*   Updated: 2023/05/08 11:13:43 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*str;

	str = NULL;
	printf("%d\n", ft_strlen(str));
	if (!str)
	{
		return (0);
	}
	printf("%lu\n", strlen(str));
	return (0);
}
*/
/*
	if (!str)
	{					si peta la funcion 
		return (0);
	}*/