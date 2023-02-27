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
#include	"ft_putchar_fd.c"
#include	"ft_putstr_fd.c"

int	ft_check_wildcard(char c, char *buffer)
{
	ft_putstr_fd(buffer, 1);
	
	return (0);
}

int	ft_printf(char const *str, ...)
{
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
		}
		else
		{
			ft_check_wildcard(*str, "XXX");
			str++;
		}
		
		str++;
	}
	
	ft_putstr_fd((char*)str, 1);
	return (0);
}

int	main(void)
{
	char	*dashb = "Name: %s\nAge: %d\nSex: %c";
	char	*name = "spetrov";
	int		age = 29;
	char	sex = 'M';

	
	ft_printf(dashb, name, age, sex);
	printf("\n>> Hey! Main ft_printf.c");
	return (0);
}