/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:55 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:56 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t c, t_arg *my)
{
	if (c <= 0x7F)
	{
		ft_putchar(c);
		my->cnt++;
	}
	else
		ft_putwchar_big(c, my);
	my->width--;
}

void	ft_putwchar_big(wchar_t c, t_arg *my)
{
	if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
		my->cnt += 2;
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		my->cnt += 3;
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		my->cnt += 4;
	}
}

void	ft_putwstr(wchar_t *str, t_arg *my)
{
	int i;

	i = 0;
	while (str[i])
		ft_putwchar(str[i++], my);
}
