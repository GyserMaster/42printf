/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:00:37 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/22 18:21:15 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_putx_rec(unsigned int dir, char c)
{
	int	i;

	i = 0;
	if (dir > 0 && c == 'x')
	{
		i += ft_putx_rec((dir / 16), c);
		i += ft_putchar_fd("0123456789abcdef"[dir % 16], 1);
	}
	else if (dir > 0 && c == 'X')
	{
		i += ft_putx_rec((dir / 16), c);
		i += ft_putchar_fd("0123456789ABCDEF"[dir % 16], 1);
	}
	return (i);
}

int	ft_putx(unsigned int dir, char c)
{
	int	i;

	i = 0;
	if (dir == (unsigned int)0)
		i += ft_putstr_fd("0", 1);
	else
		i += ft_putx_rec(dir, c);
	return (i);
}
