/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:08:51 by marredon          #+#    #+#             */
/*   Updated: 2023/09/13 15:53:50 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char c, va_list list)
{
	if ()

	
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		e;
	int		c;

	i = 0;
	c = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
			e = ft_percent
	}
}
