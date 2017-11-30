/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:36:47 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:36:52 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_arg
{
	int				i;
	int				ind;
	int				cnt;
	uintmax_t		db;
	uintmax_t		double_size;
	int				wd_cnt;
	int				neg;
	int				flag_for_0;
	char			zero;
	char			tp;
	char			align;
	char			space;
	char			hash;
	unsigned int	width;
	int				wildcard;
	int				prec;
	int				prec_wildcard;
	size_t			prec_wid;
	size_t			size;
	uintmax_t		result;
	wchar_t			*ptr;
	wchar_t			*str;
	char			*pt;
	char			*st;
	char			*s;
	char			*d_str;
	char			*flag;
	char			*spec;
	char			*flags;
	char			*length;
	char			*lengths;

}				t_arg;

int				ft_printf(const char *format, ...);
void			read_specificator(va_list *ap, const char *format, t_arg *my);
void			resolve_type(va_list *ap, t_arg *my);

void			check_specifier(const char *format, t_arg *my);
void			check_flags(const char *format, t_arg *my);
int				count_width(const char *format, t_arg *my, int help);
void			check_all_data(va_list *ap, t_arg *my);
int				parse_length(const char *format, t_arg *my);
uintmax_t		get_unsigned_length(t_arg *my, va_list *ap);
intmax_t		get_signed_length(t_arg *my, va_list *ap);
uintmax_t		get_long_length(t_arg *my, va_list *ap);

void			call_func_int(va_list *ap, t_arg *my, int base);
void			call_func_unsint(va_list *ap, t_arg *my, int base);
void			call_func_long(va_list *ap, t_arg *my, int base);
void			call_func_double_f(va_list *ap, t_arg *my);
void			call_func_double_e(va_list *ap, t_arg *my, int cnt);
void			call_func_char(va_list *ap, t_arg *my);
void			call_func_str(va_list *ap, t_arg *my, int n);
void			call_func_wstr(va_list *ap, t_arg *my, int n);
void			call_func_pointer(va_list *ap, t_arg *my);

void			ft_check_between(const char *format, t_arg *my);
void			wrong_format_output(const char *format, t_arg *my);
void			ft_modif_size(t_arg *my, int base);
void			get_prec_width(t_arg *my, int base);
void			ft_put_zero(t_arg *my, int i, size_t size);
void			ft_put_space(t_arg *my);
void			print_chars(const char *format, t_arg *my);
int				wrong_format(t_arg *my, const char *format);
void			ft_clear_data(t_arg *my);
void			final_space_and_clear_all(t_arg *my);
void			ft_putprefix(t_arg *my, int base);
void			prefix(t_arg *my, int base);
void			double_prefix(va_list *ap, t_arg *my, uintmax_t flags);
void			check_prec_for_str(t_arg *my, int n);

void			ft_putnbr_base(uintmax_t nbr, int base, t_arg *my);
void			ft_put_address(void *nbr, t_arg *my);
void			ft_putwchar(wchar_t chr, t_arg *my);
void			ft_putwchar_big(wchar_t c, t_arg *my);
void			ft_putwstr(wchar_t *str, t_arg *my);
void			putstr_with_prec(t_arg *my, int n, int str_type);
void			ft_double(double nbr, t_arg *my);
void			ft_putnbr_double_f_string(double nbr, t_arg *my, \
											char *str, int i);
void			ft_putnbr_double_e(uintmax_t nbr, t_arg *my);

void			data_hash(t_arg *my);
size_t			ft_count(size_t num, int base);
double			ft_round(double nbr);
double			negative_nbr(double nbr, t_arg *my);
int				ft_wstrlen(wchar_t *str);

#endif
