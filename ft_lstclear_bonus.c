/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:25 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:29:37 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	if (*lst)
	{
		while (*lst)
		{
			buffer = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = buffer;
		}
		*lst = 0;
	}
}
