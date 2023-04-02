/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:43:52 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/02 22:35:14 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int	ft_nbr_to_hexa(unsigned long dir)
{
	int i;

	i = 0;
	while (dir > 0)
	{
		i += ft_putchar_fd("0123456789abcdef"[dir % 16], 1);
		dir = dir / 16;
	}
	return (i);
}

int	ft_putpointer(unsigned long dir)
{
	int i;

	i = 0;
	if (!(dir))
	{
		i += ft_putstr_fd("0x0" ,1);
	}
	else
	{
		i += ft_putstr_fd("0x" ,1);
		i += ft_nbr_to_hexa(dir);
	}
	return (i);
}