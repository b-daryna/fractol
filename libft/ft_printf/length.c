/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:37:51 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:37:53 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_length(const char *format, t_arg *my)
{
	if (format[my->i] == 'h' && format[my->i + 1] == 'h')
	{
		my->length = "hh";
		return (1);
	}
	else if (format[my->i] == 'l' && format[my->i + 1] == 'l')
	{
		my->length = "ll";
		return (1);
	}
	else if (format[my->i] == 'h')
		my->length = "h";
	else if (format[my->i] == 'l')
		my->length = "l";
	else if (format[my->i] == 'j')
		my->length = "j";
	else if (format[my->i] == 'z')
		my->length = "z";
	return (0);
}

intmax_t	get_signed_length(t_arg *my, va_list *ap)
{
	intmax_t result;

	result = va_arg(*ap, intmax_t);
	if (!ft_strcmp(my->length, "hh"))
		result = (char)result;
	else if (!ft_strcmp(my->length, "h"))
		result = (short int)result;
	else if (!ft_strcmp(my->length, "l"))
		result = (long int)result;
	else if (!ft_strcmp(my->length, "ll"))
		result = (long long int)result;
	else if (!ft_strcmp(my->length, "j"))
		result = (intmax_t)result;
	else if (!ft_strcmp(my->length, "z"))
		result = (size_t)result;
	else
		result = (int)result;
	return (result);
}

uintmax_t	get_unsigned_length(t_arg *my, va_list *ap)
{
	uintmax_t result;

	result = va_arg(*ap, uintmax_t);
	if (!ft_strcmp(my->length, "hh"))
		result = (unsigned char)result;
	else if (!ft_strcmp(my->length, "h"))
		result = (unsigned short int)result;
	else if (!ft_strcmp(my->length, "l"))
		result = (unsigned long int)result;
	else if (!ft_strcmp(my->length, "ll"))
		result = (unsigned long long int)result;
	else if (!ft_strcmp(my->length, "j"))
		result = (uintmax_t)result;
	else if (!ft_strcmp(my->length, "z"))
		result = (size_t)result;
	else
		result = (unsigned int)result;
	return (result);
}

uintmax_t	get_long_length(t_arg *my, va_list *ap)
{
	uintmax_t result;

	result = va_arg(*ap, uintmax_t);
	if (my->tp == 'D' && (intmax_t)result < 0)
	{
		ft_putchar('-');
		my->cnt++;
		my->flag = "";
		my->space = 0;
		result = -result;
	}
	result = (unsigned long long int)result;
	return (result);
}
