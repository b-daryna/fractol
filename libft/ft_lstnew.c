/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:15:36 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 17:32:47 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *p;

	p = (t_list*)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	if (content)
	{
		p->content = malloc(sizeof(content) * content_size);
		p->content = ft_memmove(p->content, content, content_size);
		p->content_size = content_size;
	}
	else
	{
		p->content = NULL;
		p->content_size = 0;
	}
	p->next = NULL;
	return (p);
}
