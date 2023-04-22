/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:43:52 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/22 19:47:09 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_nbr_to_hexa(unsigned long dir)
{
	int	i;

	i = 0;
	if (dir > 0)
	{
		i += ft_nbr_to_hexa(dir / 16);
		i += ft_putchar_fd("0123456789abcdef"[dir % 16], 1);
	}
	return (i);
}

int	ft_putpointer(unsigned long dir)
{
	int	i;

	i = 0;
	if (!(dir))
		i += ft_putstr_fd("0x0", 1);
	else
	{
		i += ft_putstr_fd("0x", 1);
		i += ft_nbr_to_hexa(dir);
	}
	return (i);
}
