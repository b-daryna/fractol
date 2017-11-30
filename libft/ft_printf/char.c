/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:25:35 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:25:38 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_char_for_zero_and_space(t_arg *my)
{
	if (my->zero)
		ft_put_zero(my, 0, my->size);
	ft_put_space(my);
}

void	call_func_char(va_list *ap, t_arg *my)
{
	wchar_t		c;
	char		c1;

	my->space = 0;
	check_all_data(ap, my);
	my->size = my->width - 1;
	check_char_for_zero_and_space(my);
	if (ft_strcmp(my->length, "l") == 0)
		my->tp = 'C';
	if (my->tp == 'c')
	{
		c1 = va_arg(*ap, int);
		c1 = c1 == (int)NULL ? 0 : c1;
		ft_putchar(c1);
		my->cnt++;
		my->width--;
	}
	else
	{
		c = va_arg(*ap, wchar_t);
		c = c == (int)NULL ? 0 : c;
		ft_putwchar(c, my);
	}
	my->size = my->width;
	final_space_and_clear_all(my);
}

void	call_func_str(va_list *ap, t_arg *my, int n)
{
	my->space = 0;
	check_all_data(ap, my);
	if (ft_strcmp(my->length, "l") == 0)
	{
		call_func_wstr(ap, my, 0);
		return ;
	}
	my->st = va_arg(*ap, char*);
	my->st = my->st == NULL ? "(null)" : my->st;
	if (my->prec != 0 && my->prec < (int)ft_strlen(my->st))
		my->cnt = my->prec < 0 ? my->cnt + 0 : my->cnt + my->prec;
	else
		my->cnt += (int)ft_strlen(my->st);
	if (my->prec < 0)
		my->st = "";
	n = my->prec <= 0 ? 0 : my->prec;
	my->size = (n && n < (int)ft_strlen(my->st)) ? my->width - n :\
				my->width - (int)ft_strlen(my->st);
	check_char_for_zero_and_space(my);
	check_prec_for_str(my, n);
	my->size = (n && (int)ft_strlen(my->st)) ? my->width - n : \
				my->width - (int)ft_strlen(my->st);
	final_space_and_clear_all(my);
}

void	call_func_wstr(va_list *ap, t_arg *my, int n)
{
	my->cnt--;
	my->space = 0;
	check_all_data(ap, my);
	n = my->prec < 0 ? 0 : my->prec;
	my->str = va_arg(*ap, wchar_t*);
	my->s = "(null)";
	my->str = (my->str == (int*)NULL) ? (int*)my->s : my->str;
	my->size = my->prec ? my->width - n : \
				my->width - (int)ft_strlen((char*)my->str);
	my->cnt += (int)ft_strlen((char*)my->str);
	check_char_for_zero_and_space(my);
	if (my->prec)
		putstr_with_prec(my, n, 2);
	else if (my->str == (int*)my->s)
		ft_putstr(my->s);
	else
		ft_putwstr(my->str, my);
	my->size = my->width - (int)ft_strlen((char*)my->str);
	final_space_and_clear_all(my);
}

void	call_func_pointer(va_list *ap, t_arg *my)
{
	my->space = 0;
	if (my->prec)
		my->zero = 0;
	check_all_data(ap, my);
	my->result = va_arg(*ap, uintmax_t);
	ft_putprefix(my, 16);
	ft_put_address((void*)my->result, my);
	my->size = my->width;
	final_space_and_clear_all(my);
}
