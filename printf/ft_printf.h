/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:11:04 by marredon          #+#    #+#             */
/*   Updated: 2023/09/13 11:58:35 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_putchar(int c);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_printf(const	char *str, ...);
int				ft_hexa_pointer(void *hex);
int				ft_strlen(char *s);
int				ft_hexa_minus(int num);
int				ft_hexa_mayus(int num);

#endif