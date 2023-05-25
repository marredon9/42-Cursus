/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:59:36 by marredon          #+#    #+#             */
/*   Updated: 2023/05/24 15:15:04 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(char digit, int fd)
{
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == 0)
		ft_putdigit('0', fd);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		digit = '0' + (n % 10);
		ft_putdigit(digit, fd);
	}
}
