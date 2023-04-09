/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:42:38 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/09 22:22:06 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int ft_direcur(int n)
{
	int	i;

	i = 0;
	if (n)
	{
		i += ft_direcur(n / 10);
		i += ft_putchar_fd((n % 10) + '0', 1);
	}
	return (i);
}

int	ft_putdi(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	if (n == 0)
		return (ft_putstr_fd("0", 1));
	if (n < 0)
	{
		n = n * (-1);
		i += ft_putstr_fd("-", 1);
	}
	i += ft_direcur(n);
	return (i);
}
