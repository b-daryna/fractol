/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:53:42 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 16:48:27 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!little[i])
		return ((char*)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i] && i < len)
		{
			j++;
			i++;
			if (little[j] == '\0')
				return ((char*)big + i - j);
		}
		i = i - j + 1;
	}
	return (0);
}
