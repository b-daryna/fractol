/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:06:56 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 17:27:58 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	i = 0;
	j = 0;
	if (s == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[j] != '\0')
		str[i++] = s[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
