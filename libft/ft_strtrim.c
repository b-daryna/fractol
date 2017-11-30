/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:56:01 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 17:42:03 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	n = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j] != '\0')
		j++;
	if (j < n)
	{
		while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
			n--;
	}
	str = (char*)malloc(sizeof(char) * (n - j + 2));
	if (!str)
		return (NULL);
	while (j <= n)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
