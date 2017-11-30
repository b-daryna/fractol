/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:12:10 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 18:07:33 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0' || !to_find[j])
		return ((char*)str);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			if (to_find[++j] == '\0')
				return ((char*)str + (i + 1) - j);
			if (str[++i] == '\0')
				return (0);
			if (str[i] != to_find[j])
			{
				i = i - j + 1;
				j = 0;
			}
		}
		i++;
	}
	return (0);
}
