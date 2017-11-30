/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:37:45 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 17:39:20 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	call_func_int(va_list *ap, t_arg *my, int base)
{
	intmax_t nbr;

	check_all_data(ap, my);
	if (my->prec)
		my->zero = 0;
	nbr = get_signed_length(my, ap);
	if (nbr < 0)
	{
		my->neg = 1;
		my->space = 0;
		my->cnt++;
	}
	my->result = nbr < 0 ? -nbr : nbr;
	ft_putprefix(my, base);
	if (my->neg)
		my->width--;
	ft_putnbr_base(my->result, base, my);
	my->size = my->width;
	my->align = 0;
	my->space = 0;
	ft_put_space(my);
	ft_clear_data(my);
}

void	call_func_unsint(va_list *ap, t_arg *my, int base)
{
	my->space = 0;
	check_all_data(ap, my);
	if (my->prec)
		my->zero = 0;
	my->result = get_unsigned_length(my, ap);
	if (my->result == 0 && base == 8 && !my->prec)
		my->hash = 0;
	ft_putprefix(my, base);
	ft_putnbr_base(my->result, base, my);
	my->size = my->width;
	my->align = 0;
	my->space = 0;
	ft_put_space(my);
	ft_clear_data(my);
}

void	call_func_long(va_list *ap, t_arg *my, int base)
{
	if (my->tp != 'D')
		my->space = 0;
	check_all_data(ap, my);
	my->result = get_long_length(my, ap);
	if (my->result == 0 && !my->prec)
		my->hash = 0;
	ft_putprefix(my, base);
	ft_putnbr_base(my->result, base, my);
	my->size = my->width;
	my->align = 0;
	my->space = 0;
	ft_put_space(my);
	ft_clear_data(my);
}
