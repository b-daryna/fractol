/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:35 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:37 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_between(const char *format, t_arg *my)
{
	int i;

	i = my->i;
	while (format[i] != '%' && format[i] != '\0')
	{
		if (wrong_format(my, format) && my->space)
			my->space = 0;
		else if (!wrong_format(my, format) && my->space)
			my->space = ' ';
		i++;
	}
}

void	check_all_data(va_list *ap, t_arg *my)
{
	my->result = 0;
	if (my->wildcard)
	{
		while (my->wd_cnt-- > 0)
			my->wildcard = va_arg(*ap, int);
		if (my->wildcard < 0)
		{
			my->wildcard = -my->wildcard;
			my->align = '-';
		}
		my->width = my->width == 0 ? my->wildcard : my->width;
	}
	if (my->prec_wildcard == 1)
	{
		my->prec_wildcard = va_arg(*ap, int);
		my->prec = my->prec_wildcard;
		if (my->prec < 0)
			my->prec = 0;
		else if (my->prec == 0 || my->prec == -0)
			my->prec = -1;
	}
}

void	check_specifier(const char *format, t_arg *my)
{
	check_flags(format, my);
	my->i += parse_length(format, my);
	if ((format[my->i] > 48 && format[my->i] <= 57) \
			|| format[my->i] == '*')
		my->width = (unsigned int)count_width(format, my, 0);
	if (format[my->i] == '.')
	{
		my->i++;
		if ((my->prec = count_width(format, my, 1)) < 0)
			my->i--;
	}
}

void	check_flags(const char *format, t_arg *my)
{
	char c;

	c = format[my->i];
	if (c == ' ' && ft_strcmp(my->flag, "+"))
		my->space = ' ';
	else if (c == '+')
	{
		my->flag = "+";
		my->space = 0;
	}
	else if (c == '-')
	{
		my->align = '-';
		my->zero = 0;
	}
	else if (c == '#')
		my->hash = '#';
	else if (c == '0' && !my->align)
		my->zero = '0';
}

int		count_width(const char *format, t_arg *my, int help)
{
	int size;

	if (format[my->i] == '*' && help == 0)
	{
		my->wildcard = 1;
		my->wd_cnt++;
	}
	if (format[my->i] == '*' && help == 1)
	{
		my->prec_wildcard = 1;
		return (0);
	}
	if ((!ft_isdigit(format[my->i]) || (format[my->i] == '0' && \
			!ft_atoi(&format[my->i + 1]))) && help == 1)
		return (-1);
	size = ft_atoi(&format[my->i]);
	my->i += ft_intsize(size) - 1;
	return (size);
}
