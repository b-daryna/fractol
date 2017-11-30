/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:28 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:29 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clear_data(t_arg *my)
{
	my->flag = "";
	my->prec = 0;
	my->align = 0;
	my->neg = 0;
	my->flag_for_0 = 0;
	my->size = 0;
	my->zero = 0;
	my->space = 0;
	my->width = 0;
	my->length = "";
	my->wd_cnt = 0;
	my->wildcard = 0;
	my->prec_wildcard = 0;
	my->db = 0;
	my->ind = 0;
	my->double_size = 0;
	my->st = 0;
	my->str = 0;
	my->ptr = 0;
}

void	get_prec_width(t_arg *my, int base)
{
	if (my->prec < 0 && my->result == 0)
		my->flag_for_0 = 1;
	my->prec = my->prec < 0 ? 0 : my->prec;
	if (my->tp == 'p' && my->prec && my->prec < \
			(int)ft_count(my->result, base))
		my->prec = 0;
	my->prec_wid = my->width - my->prec;
	if (my->tp == 'd' || my->tp == 'D' || my->tp == 'i'\
			|| my->tp == 'o' || my->tp == 'O' || \
			my->tp == 'x' || my->tp == 'X' || my->tp == 'u')
	{
		if ((int)ft_count(my->result, base) >= my->prec)
			my->prec_wid = my->width - (int)ft_count(my->result, base);
		else
			my->space = 0;
	}
}

void	ft_modif_size(t_arg *my, int base)
{
	size_t	no_prec_wid;
	int		num;
	int		index;

	index = base == 16 ? 2 : 1;
	no_prec_wid = my->width - ft_count(my->result, base);
	if (my->space == ' ' && !my->prec)
		no_prec_wid--;
	get_prec_width(my, base);
	if (my->prec && my->tp == 'o' && my->hash == '#')
		my->hash = 0;
	if (base == 10)
		num = ft_strcmp(my->flag, "+");
	else
		num = my->hash == '#' ? 0 : 1;
	if (my->tp == 'p' || my->neg)
		num = 0;
	if (num == 0)
		my->size = my->prec ? my->prec_wid - index : no_prec_wid - index;
	else
		my->size = my->prec ? my->prec_wid : no_prec_wid;
}

void	ft_put_zero(t_arg *my, int i, size_t size)
{
	size_t j;
	size_t tmp;

	tmp = my->size;
	if (i == 0)
	{
		while ((int)tmp-- > 0)
		{
			ft_putchar('0');
			my->width--;
			my->cnt++;
		}
	}
	else
	{
		j = my->prec - size;
		if ((my->tp == 'o' || my->tp == 'O') && my->hash == '#')
			j++;
		while ((int)j-- > 0)
		{
			ft_putchar('0');
			my->width--;
			my->cnt++;
		}
	}
}

void	ft_put_space(t_arg *my)
{
	size_t size;

	size = my->size;
	if ((my->tp == 'f' || my->tp == 'F' || \
			my->tp == 'e' || my->tp == 'E') && my->space)
	{
		if ((int)my->size < 0)
			size = 1;
		else
			size++;
	}
	else if (my->space && my->tp != '%')
		size = 1;
	else if (my->align || my->zero)
		size = 0;
	while ((int)size-- > 0)
	{
		my->cnt++;
		ft_putchar(' ');
		my->width--;
	}
}
