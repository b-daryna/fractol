/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:36:17 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/10 18:20:03 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *ptr;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = f(lst);
	node = ptr;
	while (lst->next != NULL)
	{
		lst = lst->next;
		node->next = f(lst);
		node = node->next;
	}
	return (ptr);
}
