/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:15:24 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/09 19:31:58 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intsize(int n)
{
	int				size;
	unsigned int	num;

	size = 0;
	num = n;
	if (n < 0)
		num = -num;
	if (n == 0)
		size = 1;
	while (num)
	{
		num = num / 10;
		size++;
	}
	return (size);
}
