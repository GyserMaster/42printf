/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:27:00 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/22 18:20:59 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static	int	ft_ulrecur(unsigned int n)
{
	int	i;

	i = 0;
	if (n)
	{
		i += ft_ulrecur(n / 10);
		i += ft_putchar_fd((n % 10) + '0', 1);
	}
	return (i);
}

int	ft_putul(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0 || n == (unsigned int)LONG_MIN)
		return (ft_putstr_fd("0", 1));
	if (n == (unsigned int)ULONG_MAX)
		return (ft_putstr_fd("4294967295", 1));
	i += ft_ulrecur(n);
	return (i);
}
