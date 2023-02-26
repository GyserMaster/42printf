/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:02 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:25:28 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_dig(long int n)
{
	int	i;

	i = 0;
	if ((unsigned long)n == 2147483648UL)
		return (11);
	if (n <= 0)
	{
		n = n * (-1);
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_n_in_str(char *buffer, int digits, long int m)
{
	buffer[digits] = '\0';
	while (--digits >= 0)
	{
		buffer[digits] = m % 10 + '0';
		m = m / 10;
	}
	if (buffer[0] == '0')
		buffer[0] = '-';
}

char	*ft_itoa(int n)
{
	long int	m;
	char		*buffer;
	int			digits;

	m = n;
	digits = ft_count_dig(n);
	buffer = malloc(sizeof(char) * (digits + 1));
	if (!(buffer))
		return (0);
	if ((unsigned long)m == 2147483648UL)
		return ("-2147483648");
	if (m == (0))
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	if (m < 0)
		m = m * (-1);
	ft_n_in_str(buffer, digits, m);
	return (buffer);
}
