/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:27:12 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:51:16 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		i += ft_putstr_fd("(null)", fd);
	else
		while (*s)
			i += ft_putchar_fd(*s++, 1);
	return (i);
}
