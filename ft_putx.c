/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:00:37 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/03 22:14:46 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putx(unsigned int dir, char c)
{
	int	i;

	i = 0;
	if (dir > 0 && c == 'x')
	{
		ft_putx((dir / 16), c);
		i += ft_putchar_fd("0123456789abcdef"[dir % 16], 1);
	}
	else if (dir > 0 && c == 'X')
	{
		ft_putx((dir / 16), c);
		i += ft_putchar_fd("0123456789ABCDEF"[dir % 16], 1);
	}
	return (i);
}
