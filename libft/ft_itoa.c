/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:14:18 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/22 10:13:29 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isnegative(int n)
{
	int flag;

	flag = 1;
	if (n < 0)
		flag = 2;
	return (flag);
}

char			*ft_itoa(int n)
{
	int				len;
	int				flag;
	char			*str;
	unsigned int	num;

	num = n;
	flag = ft_isnegative(n);
	len = ft_intsize(n);
	if (n < 0)
		num = -num;
	str = (char*)malloc(sizeof(char) * (len + flag));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[len + flag - 1] = '\0';
	while (num)
	{
		str[len + flag - 2] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
