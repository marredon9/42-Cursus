/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:08:51 by marredon          #+#    #+#             */
/*   Updated: 2023/09/14 12:43:46 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_hexa_pointer(va_arg(list, unsigned long)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_hexa(va_arg(list, unsigned int), 1));
	else if (c == 'X')
		return (ft_hexa(va_arg(list, unsigned int), 2));
	else //if (c == '%')
		return (ft_putchar('%'));
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
		{
			e = ft_percent (str [i + 1], list);
			i += 2;
		}
		else
			e = ft_putchar(str[i++]);
		if (e == -1)
			return (-1);
		c += e;
	}
	return (c);
}
