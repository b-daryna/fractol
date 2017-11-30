/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:51:52 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 19:08:58 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int mousecode, int x, int y, t_param *data)
{
	double dz;

	dz = data->zoom;
	if (mousecode == 5)
	{
		data->x2 = x;
		data->y2 = y;
		data->x1 = (data->x2 / dz + data->x1) - ((dz * 1.3) / 2);
		data->x1 += ((dz * 1.3) / 2) - (data->x2 / (dz * 1.3));
		data->y1 = (data->y2 / dz + data->y1) - ((dz * 1.3) / 2);
		data->y1 += ((dz * 1.3) / 2) - (data->y2 / (dz * 1.3));
		data->zoom *= 1.3;
		data->max_iterations += 2;
	}
	else if (mousecode == 4)
	{
		data->x1 = (data->x2 / dz + data->x1) - ((dz / 1.3) / 2);
		data->x1 += ((dz / 1.3) / 2) - (data->x2 / (dz / 1.3));
		data->y1 = (data->y2 / dz + data->y1) - ((dz / 1.3) / 2);
		data->y1 += ((dz / 1.3) / 2) - (data->y2 / (dz / 1.3));
		data->zoom /= 1.3;
		data->max_iterations -= 2;
	}
	create_fractal(data);
	return (0);
}

int		movement_hook(int x, int y, t_param *data)
{
	if (!ft_strcmp(data->name, "julia") && data->movement == 1)
	{
		data->p_r = x * 2;
		data->p_i = y * 2 - 800;
		create_fractal(data);
	}
	return (0);
}
