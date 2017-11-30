/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:19 by dbessmer          #+#    #+#             */
/*   Updated: 2017/04/11 16:38:21 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_address(void *nbr, t_arg *my)
{
	char *str_base;

	str_base = "0123456789abcdef";
	if ((size_t)nbr >= 16)
	{
		ft_put_address((void*)((size_t)nbr / 16), my);
		ft_put_address((void*)((size_t)nbr % 16), my);
	}
	else if (!my->flag_for_0)
	{
		ft_putchar(str_base[(size_t)nbr]);
		my->width--;
		my->cnt++;
	}
}

void	ft_putnbr_base(uintmax_t nbr, int base, t_arg *my)
{
	char	*str_base;

	if (my->tp == 'X')
		str_base = "0123456789ABCDEF";
	else
		str_base = "0123456789abcdef";
	if (nbr >= (unsigned int)base)
	{
		ft_putnbr_base(nbr / base, base, my);
		ft_putnbr_base(nbr % base, base, my);
	}
	else if (!my->flag_for_0)
	{
		ft_putchar(str_base[nbr]);
		my->width--;
		my->cnt++;
	}
}

void	ft_putnbr_double_f_string(double nbr, t_arg *my, char *str, int i)
{
	int j;

	j = 0;
	if (my->db > 1)
	{
		my->db--;
		str[i] = ((uintmax_t)nbr % 10) + '0';
		i++;
		ft_putnbr_double_f_string(nbr / 10, my, str, i);
	}
	else
	{
		str[i] = '\0';
		while (--i >= 0)
		{
			my->d_str[j++] = str[i];
			my->cnt++;
			my->width--;
		}
		my->d_str[j] = '\0';
		ft_putstr(my->d_str);
	}
}

void	ft_putnbr_double_e(uintmax_t nbr, t_arg *my)
{
	if (nbr >= 10)
	{
		my->db--;
		ft_putnbr_double_e(nbr / 10, my);
		ft_putnbr_double_e(nbr % 10, my);
	}
	else if (my->db > 0)
	{
		if (my->db == 1)
			my->ind++;
		if (my->ind > 1)
		{
			ft_putchar(nbr + 48);
			my->width--;
			my->cnt++;
		}
	}
}

void	ft_double(double nbr, t_arg *my)
{
	char	*str;
	int		i;

	my->db++;
	i = 0;
	if ((int)my->db < (my->prec + 1))
		ft_double(nbr * 10, my);
	else if (my->tp == 'f' || my->tp == 'F')
	{
		str = (char*)malloc(sizeof(char) * (my->db + my->neg + 1));
		my->d_str = (char*)malloc(sizeof(char) * (my->db + my->neg + 1));
		ft_putnbr_double_f_string(nbr, my, str, i);
		free(str);
		free(my->d_str);
	}
	else if (my->tp == 'e' || my->tp == 'E')
		ft_putnbr_double_e(ft_round(nbr), my);
}
