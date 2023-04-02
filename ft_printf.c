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

#include "libft.h"
#include <stdarg.h>
#include	"ft_putchar_fd.c"
#include	"ft_putstr_fd.c"
#include	"ft_putnbr_fd.c"
#include	"ft_putdouble_fd.c"

int	ft_check_wildcard(char c, char *buffer)
{
	ft_putstr_fd(buffer, 1);
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list valist;
	int i;

	va_start(valist, 0);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
		}
		else
		{
			if (str[1] == '%')
			{
				ft_putchar_fd('%', 1);
			}
			else if (str[1] == 's')
			{
				ft_putstr_fd(va_arg(valist, char*), 1);
			}
			else if (str[1] == 'd')
			{
				ft_putnbr_fd(va_arg(valist, int), 1);
			}
			else if (str[1] == 'c')
			{
				ft_putchar_fd(va_arg(valist, int), 1);
			}
			else if (str[1] == 'f')
			{
				//ft_putdouble_fd(va_arg(valist, double), 1);
			}
			else
			{
				//ft_putstr_fd(va_arg(valist, char*), 1);
				ft_putstr_fd("va_arg", 1);
				
			}
			str++;
		}
		str++;
	}
	va_end(valist);
	ft_putstr_fd((char*)str, 1);
	return (0);
}

int	main(void)
{
	char	*dashb = "Name: %s\nAge: %d\nSex: %c\nScore: %f";
	char	*name = "spetrov";
	int		age = 29;
	char	sex = 'M';
	double	score = 93.1;

	
	ft_printf("Name: %s\nAge: %d\nSex: %c\nScore: %f", name, age, sex, score);
	printf("\n>> Hey! Main ft_printf.c");
	return (0);
}