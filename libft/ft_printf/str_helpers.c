/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:46 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:48 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_with_prec(t_arg *my, int n, int str_type)
{
	if (str_type == 1)
	{
		my->pt = (char*)malloc(sizeof(char) * n);
		ft_strncpy(my->pt, my->st, n);
		ft_putstr(my->pt);
		free(my->pt);
	}
	else
	{
		my->ptr = (wchar_t*)malloc(sizeof(wchar_t) * n);
		ft_strncpy((char*)my->ptr, (char*)my->str, n);
		ft_putwstr(my->ptr, my);
		free(my->ptr);
	}
}

void	check_prec_for_str(t_arg *my, int n)
{
	if (my->prec)
		putstr_with_prec(my, n, 1);
	else
		ft_putstr(my->st);
}
