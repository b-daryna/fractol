/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:10 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:11 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	data_hash(t_arg *my)
{
	if ((!ft_strcmp(my->length, "h") || !ft_strcmp(my->length, "hh"))\
			&& (my->tp == 'o' || my->tp == 'O'))
		my->hash = 0;
	if (my->hash == '#')
	{
		if ((my->tp == 'o' || my->tp == 'O') && !my->prec)
		{
			my->cnt++;
			ft_putchar('0');
			my->width--;
		}
		else if ((my->tp == 'X' || my->tp == 'x') && my->result != 0)
		{
			if (my->tp == 'X')
				ft_putstr("0X");
			else
				ft_putstr("0x");
			my->cnt += 2;
			my->width -= 2;
		}
	}
}

void	prefix(t_arg *my, int base)
{
	if (my->prec)
		ft_put_zero(my, my->prec, ft_count(my->result, base));
	else if (my->zero == '0' && my->align != '-')
		ft_put_zero(my, 0, ft_count(my->result, base));
	if (my->result == (uintmax_t)NULL)
		my->result = 0;
}

void	ft_putprefix(t_arg *my, int base)
{
	ft_modif_size(my, base);
	ft_put_space(my);
	if (my->neg)
		ft_putchar('-');
	data_hash(my);
	if ((my->tp == 'd' || my->tp == 'i' || my->tp == 'D')\
			&& ft_strcmp(my->flag, "+") == 0)
	{
		if (!my->neg)
		{
			my->width--;
			ft_putchar('+');
			my->cnt++;
		}
		my->space = 0;
	}
	else if (my->tp == 'p')
	{
		ft_putstr("0x");
		my->cnt += 2;
		my->width -= 2;
	}
	prefix(my, base);
}
