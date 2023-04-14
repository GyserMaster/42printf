/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:27:00 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/14 13:48:53 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int ft_ulrecur(unsigned long long int n)
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

int	ft_putul(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putstr_fd("0", 1));	
	if (n == 9223372036854775807L)
		return (ft_putstr_fd("4294967295", 1));
	i += ft_ulrecur(n);
	return (i);
}
