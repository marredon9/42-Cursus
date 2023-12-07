/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:01:21 by marredon          #+#    #+#             */
/*   Updated: 2023/05/08 12:15:48 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				meringue;

	meringue = 0;
	ft_memset(s, meringue, n);
}
/*Se llama ft_meringue, si me lo niegas te mato ja ja */