/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:28:02 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:51:30 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		m = (unsigned int)(n * (-1));
		ft_putchar_fd('-', fd);
	}
	else
		m = (unsigned int)n;
	if (m >= 10)
		ft_putnbr_fd((int)(m / 10), fd);
	ft_putchar_fd((char)(m % 10 + '0'), fd);
}
