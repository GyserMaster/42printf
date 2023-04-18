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

#include	"ft_printf.h"
#include	<stdarg.h>
#include	"ft_putchar_fd.c"
#include	"ft_putstr_fd.c"
#include	"ft_putpointer.c"
#include	"ft_putx.c"
#include	"ft_putdi.c"
#include	"ft_putul.c"

int	check_wildcard(char wdc, va_list valist)
{
	int	i;

	i = 0;
	if (wdc == '%')
		i += ft_putchar_fd('%', 1);
	else if (wdc == 'c')
		i += ft_putchar_fd(va_arg(valist, int), 1);
	else if (wdc == 's')
		i += ft_putstr_fd(va_arg(valist, char *), 1);
	else if (wdc == 'd' || wdc == 'i')
		i += ft_putdi(va_arg(valist, int));
	else if (wdc == 'u')
		i += ft_putul(va_arg(valist, unsigned int));
	else if (wdc == 'p')
		i += ft_putpointer(va_arg(valist, unsigned long));
	else if (wdc == 'x' || wdc == 'X')
		i += ft_putx(va_arg(valist, unsigned int), wdc);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	valist;
	int		i;

	i = 0;
	va_start(valist, str);
	while (*str)
	{
		if (*str != '%')
			i += ft_putchar_fd(*str, 1);
		else
		{
			i += check_wildcard(str[1], valist);
			str++;
		}
		str++;
	}
	va_end(valist);
	ft_putstr_fd((char *)str, 1);
	return (i);
}
/*
int	main(void)
{
	char	*name = NULL;
	int		age = 29;
	char	sex = 'M';
	int		year = 93;
	char	*hexa = "HEXADECIMAL";
	int		printoutput = 0;

	printoutput = ft_printf("Name: %s\nAge: %d\nSex: %c\nScore: %i\nHexa: %p\nxXxX: %X", 
	name, age, sex, year, hexa, -123);
	printf("\nprintoutput = %d", printoutput);

	printoutput = printf("\nName: %s \nAge: %d\nSex: %c\nScore: %i\nHexa: %p\nxXxX: %X", 
	name, age, sex, year, hexa, -123);
	printf("\nprintoutput = %d", printoutput);
	printf("\n-----\n");
	printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}*/