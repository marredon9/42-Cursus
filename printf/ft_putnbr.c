/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:59:36 by marredon          #+#    #+#             */
/*   Updated: 2023/09/11 10:57:02 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		ret;
	char	c;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ret += ft_putnbr(n / 10);
	c = n % 10 + '0';
	ret += ft_putchar(c);
	return (ret);
}
