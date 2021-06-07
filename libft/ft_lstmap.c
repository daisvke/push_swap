/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:31:14 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/03/24 00:39:28 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elem;

	if (lst)
	{
		first = ft_lstnew((*f)(lst->content));
		if (!first)
			return (0);
		elem = first->next;
		lst = lst->next;
		while (lst)
		{
			elem = ft_lstnew((*f)(lst->content));
			if (!elem)
			{
				ft_lstclear(&first, del);
				return (0);
			}
			ft_lstadd_back(&first, elem);
			elem = elem->next;
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
