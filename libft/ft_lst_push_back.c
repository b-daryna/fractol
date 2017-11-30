/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:38:48 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 17:36:16 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **list, t_list *new)
{
	t_list	*p;

	if (new == NULL)
		return ;
	if (!*list)
		*list = new;
	else
	{
		p = *list;
		while (p->next != NULL)
			p = p->next;
		p->next = new;
	}
}
