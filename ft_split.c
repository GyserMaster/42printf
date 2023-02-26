/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:04 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:51:03 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static void	free_array(char **array, size_t	i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

static char	**split_strs(char const *s, char c, char **array, size_t size)
{
	size_t	i;
	size_t	split;

	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		split = 0;
		while (s[split] && s[split] != c)
			split++;
		array[i] = (char *)malloc(sizeof(char) * (split + 1));
		if (!array[i])
		{
			free_array(array, i);
			return (NULL);
		}
		ft_strlcpy(array[i], s, split + 1);
		s += split;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	size = count_strs(s, c);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	array = split_strs(s, c, array, size);
	if (!array)
		return (NULL);
	array[size] = NULL;
	return (array);
}
