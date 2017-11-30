/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:51:07 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 18:58:49 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_printf("Usage: ./fractol " RED
			"[mandelbrot, julia, burningship]\n" RESET);
	ft_exit();
}

void	ft_exit(void)
{
	exit(1);
}

int		close_win(void)
{
	ft_exit();
	return (0);
}
