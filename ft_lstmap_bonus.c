/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:32:19 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/25 20:29:27 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buffer;

	if (!lst || !f)
		return (NULL);
	buffer = ft_lstnew(f(lst->content));
	if (!buffer)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new = buffer;
	lst = lst->next;
	while (lst)
	{
		buffer = ft_lstnew(f(lst->content));
		if (!buffer)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, buffer);
		lst = lst->next;
	}
	return (new);
}
