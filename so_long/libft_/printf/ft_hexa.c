/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:02 by marredon          #+#    #+#             */
/*   Updated: 2023/09/18 11:41:04 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long n, int loworup)
{
	char	c;
	int		count;
	char	*str;

	count = 0;
	if (loworup == 1)
	str = "0123456789abcdef";
	else
	str = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_hexa(n / 16, loworup);
	c = str[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
