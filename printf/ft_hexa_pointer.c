/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:04:45 by marredon          #+#    #+#             */
/*   Updated: 2023/09/13 12:03:50 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_pointer(void *hex)
{
	int		c;
	int		re_hex;

	c = (int)hex;
	if (write (1, "0x", 1) == -1)
		return (-1);
	re_hex = ft_hexa_minus(c);
	if (re_hex == -1)
		return (-1);
	return (re_hex + 2);
}

//-> void * 
// addres void *
// n = (int)addres
// re_hex = ft_hecxa_minus(n)
//  if (re_hex == -1)
//	return (-1);
// return (re_hex + 2)
