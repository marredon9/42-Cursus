/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:59:36 by marredon          #+#    #+#             */
/*   Updated: 2023/09/14 11:30:00 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int u)
{
	int		ret;
	char	c;

	ret = 0;
	if (u > 9)
		ret += ft_putnbr(u / 10);
	c = u % 10 + '0';
	ret += ft_putchar(c);
	return (ret);
}
