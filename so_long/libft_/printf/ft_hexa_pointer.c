/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:45 by marredon          #+#    #+#             */
/*   Updated: 2023/09/18 11:52:39 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_pointer(unsigned long hex)
{
	int		re_hex;

	re_hex = 2;
	if (write (1, "0x", 2) == -1)
		return (-1);
	re_hex += ft_hexa(hex, 1);
	return (re_hex);
}
