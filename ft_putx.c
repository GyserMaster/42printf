/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:00:37 by spetrov           #+#    #+#             */
/*   Updated: 2023/04/02 22:33:12 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_tolower.c"
#include "ft_toupper.c"

int	ft_putx(char *s)
{
	int i;

	i = 0;
	while (*s)
		i += ft_putchar_fd(*s++, 1);
	return (i);
}
