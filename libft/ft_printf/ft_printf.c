/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:37:23 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:37:25 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wrong_format(t_arg *my, const char *format)
{
	if (format[my->i] == '%' || \
			(!ft_strchr(my->flags, format[my->i]) && \
			!ft_strchr(my->lengths, format[my->i]) && \
			!ft_isdigit(format[my->i]) && \
			format[my->i] != '*' && format[my->i] != '.'))
		return (1);
	return (0);
}

void	wrong_format_output(const char *format, t_arg *my)
{
	if (format[my->i] == '%')
	{
		my->cnt++;
		ft_putchar('%');
		if (my->width && my->align)
		{
			my->space = 0;
			my->align = 0;
			ft_put_space(my);
		}
	}
	else
	{
		print_chars(format, my);
		if (format[my->i] == '%' || format[my->i - 1] == '%')
			my->i -= 2;
	}
}

void	read_specificator(va_list *ap, const char *format, t_arg *my)
{
	while (!ft_strchr(my->spec, format[my->i]))
	{
		my->tp = format[my->i];
		if (wrong_format(my, format))
		{
			check_all_data(ap, my);
			my->size = my->width - 1;
			ft_check_between(format, my);
			if (my->zero == '0')
				ft_put_zero(my, 0, my->size);
			else
				ft_put_space(my);
			wrong_format_output(format, my);
			ft_clear_data(my);
			return ;
		}
		else
			check_specifier(format, my);
		my->i++;
	}
	my->tp = format[my->i];
	resolve_type(ap, my);
}

void	resolve_type(va_list *ap, t_arg *my)
{
	if (my->tp == 'd' || my->tp == 'i')
		call_func_int(ap, my, 10);
	else if (my->tp == 'u')
		call_func_unsint(ap, my, 10);
	else if (my->tp == 'D' || my->tp == 'U')
		call_func_long(ap, my, 10);
	else if (my->tp == 'o')
		call_func_unsint(ap, my, 8);
	else if (my->tp == 'O')
		call_func_long(ap, my, 8);
	else if (my->tp == 'x' || my->tp == 'X')
		call_func_unsint(ap, my, 16);
	else if (my->tp == 'c' || my->tp == 'C')
		call_func_char(ap, my);
	else if (my->tp == 's')
		call_func_str(ap, my, 0);
	else if (my->tp == 'S')
		call_func_wstr(ap, my, 0);
	else if (my->tp == 'p')
		call_func_pointer(ap, my);
	else if (my->tp == 'f' || my->tp == 'F')
		call_func_double_f(ap, my);
	else if (my->tp == 'e' || my->tp == 'E')
		call_func_double_e(ap, my, 0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	my;

	my.i = 0;
	my.cnt = 0;
	my.spec = "sSpdDioOuUxXcCeEfFgG";
	my.flags = "-+ #0";
	my.lengths = "lhjzL";
	va_start(ap, format);
	ft_clear_data(&my);
	while (format[my.i])
	{
		print_chars(format, &my);
		read_specificator(&ap, format, &my);
		if (format[my.i] == '\0')
			break ;
		my.i++;
	}
	va_end(ap);
	return (my.cnt);
}
