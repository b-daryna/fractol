/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:37:04 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:37:08 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	negative_nbr(double nbr, t_arg *my)
{
	nbr = nbr == (int)NULL ? 0 : nbr;
	if (nbr < 0)
	{
		my->neg = 1;
		my->space = 0;
		my->cnt++;
		nbr = -nbr;
	}
	return (nbr);
}

void	double_prefix(va_list *ap, t_arg *my, uintmax_t flags)
{
	int	index;

	check_all_data(ap, my);
	if (!my->prec)
		my->prec = 6;
	index = my->space == 32 ? 1 : 0;
	my->size = my->width - my->prec - flags - index;
	ft_put_space(my);
	if (my->zero)
		ft_put_zero(my, 0, my->size);
	if (my->neg)
		ft_putchar('-');
}

void	call_func_double_f(va_list *ap, t_arg *my)
{
	double	nbr;

	nbr = va_arg(*ap, double);
	nbr = negative_nbr(nbr, my);
	my->double_size = (uintmax_t)ft_count(nbr, 10);
	double_prefix(ap, my, (1 + my->double_size));
	if (my->prec >= 0)
	{
		ft_putnbr_base(nbr, 10, my);
		ft_putchar('.');
		my->cnt++;
	}
	else
		ft_putnbr_base(ft_round(nbr), 10, my);
	ft_double(nbr, my);
	ft_clear_data(my);
}

void	call_func_double_e(va_list *ap, t_arg *my, int cnt)
{
	double	nbr;

	nbr = va_arg(*ap, double);
	nbr = negative_nbr(nbr, my);
	double_prefix(ap, my, 6);
	while (nbr >= 1)
	{
		nbr /= 10;
		cnt++;
	}
	nbr *= 10;
	ft_putchar(nbr + '0');
	if (my->prec >= 0)
	{
		ft_putchar('.');
		my->cnt++;
	}
	ft_double(nbr, my);
	my->tp == 'e' ? ft_putstr("e+") : ft_putstr("E+");
	if (cnt < 10)
		ft_putchar('0');
	ft_putnbr(cnt - 1);
	my->cnt += 5;
	ft_clear_data(my);
}
