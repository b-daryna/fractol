/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:37:38 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:37:40 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count(size_t num, int base)
{
	size_t cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / base;
		cnt++;
	}
	return (cnt);
}

void	print_chars(const char *format, t_arg *my)
{
	while (format[my->i] != '%' && format[my->i] != '\0')
	{
		ft_putchar(format[my->i++]);
		my->cnt++;
	}
	if (format[my->i] == '%')
		my->i++;
}

double	ft_round(double nbr)
{
	if ((int)(nbr * 10) % 10 < 5)
		return ((int)nbr);
	else
		return ((int)nbr + 1);
}

void	final_space_and_clear_all(t_arg *my)
{
	my->align = 0;
	ft_put_space(my);
	ft_clear_data(my);
}
