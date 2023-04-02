/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:53:56 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/26 19:34:27 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include	"ft_putchar_fd.c"
#include	"ft_putstr_fd.c"
#include	"ft_itoa.c"
#include	"ft_putpointer.c"
#include	"ft_putx.c"

int	ft_printf(char const *str, ...)
{
	va_list valist;
	int i;

	va_start(valist, 0);
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1);
		else
		{
			if (str[1] == '%')
				i += ft_putchar_fd('%', 1);
			else if (str[1] == 'c')
				i += ft_putchar_fd(va_arg(valist, int), 1);
			else if (str[1] == 's')
				i += ft_putstr_fd(va_arg(valist, char*), 1);
			else if (str[1] == 'd' || str[1] == 'i')
				i += ft_itoa(va_arg(valist, int));
			else if (str[1] == 'p') // HEXA
				i += ft_putpointer(va_arg(valist, unsigned long));
			else if (str[1] == 'x' || str[1] == 'X')
				i += ft_putx(va_arg(valist, char*));
			str++;
		}
		str++;
	}
	va_end(valist);
	ft_putstr_fd((char*)str, 1);
	return (i);
}

int	main(void)
{
	char	*name = "spetrov";
	int		age = 29;
	char	sex = 'M';
	int		year = 93;
	char	*hexa = "HEXADECIMAL";

	
	ft_printf("Name: %s\nAge: %d\nSex: %c\nScore: %i\nHexa: %p", name, age, sex, year, hexa);
	printf("\nName: %s\nAge: %d\nSex: %c\nScore: %i\nHexa: %p", name, age, sex, year, hexa);
	return (0);
}