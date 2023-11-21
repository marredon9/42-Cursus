/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:08:51 by marredon          #+#    #+#             */
/*   Updated: 2023/09/18 11:50:25 by marredon         ###   ########.fr       */
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
<<<<<<< HEAD
	else 
=======
	else
>>>>>>> refs/remotes/origin/main
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

<<<<<<< HEAD
/*void	test_simple(void)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: simple string -----------\n\n");
	printf("Testing: (\"\\tHello!\\n\")\n");
	x += printf("  Or\t:\tHello!\n");
	y += ft_printf("  Ft\t:\tHello!\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_all(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: ALL -----------\n\n");
	printf("Testing: (\"\\tThe int is %%i or %%d, the char is %%c, the string is \\\"%%s\\\", the hex is %%x or %%X, the unsigned is %%u and the percent is %%%%.\\n\", 42, -42, 's', \"Hello\", 42, 42, 242)\n");
	x += printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	y += ft_printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int	main(void)
{
	printf("\n\n========== MANDATORY TESTS ========\n\n");
	test_simple();
	test_all();
	return (0);
*/
=======
/* int	main(void)
{
	int	nombre;

	nombre = 1;
	printf(" caracter: %c\n string: %s\n puntero: %p\n entero: %d %i\
		\n unsigned:%u\n mayus: %X\n minus: %x\n porcentaje: %%\n\n", 'a',
		"la palabra", &nombre, 6, -13, 5, 60, 60);
	ft_printf(" caracter: %c\n string: %s\n puntero: %p\n entero: %d %i\
		\n unsigned: %u\n mayus: %X\n minus: %x\n porcentaje: %%\n",
		'a', "la palabra", &nombre, 6, -13, 5, 60, 60);
} */
>>>>>>> refs/remotes/origin/main
