/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:51:31 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 19:02:55 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_param *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		data->x1 = data->x1 - 40 / data->zoom;
	else if (keycode == 124)
		data->x1 = data->x1 + 40 / data->zoom;
	else if (keycode == 125)
		data->y1 = data->y1 + 40 / data->zoom;
	else if (keycode == 126)
		data->y1 = data->y1 - 40 / data->zoom;
	else if (keycode == 36)
		get_fractal(data);
	else if (keycode == 69)
		data->max_iterations += 2;
	else if (keycode == 78)
		data->max_iterations -= 2;
	else if (keycode == 35)
		data->movement = !data->movement;
	change_fractal_hook(keycode, data);
	zoom_hook(keycode, data);
	color_hook(keycode, data);
	create_fractal(data);
	return (0);
}

void	color_hook(int keycode, t_param *data)
{
	if (keycode == 18)
		data->color = 1677216;
	else if (keycode == 19)
		data->color = 2050;
	else if (keycode == 20)
		data->color = -3000;
	else if (keycode == 21)
	{
		if (!ft_strcmp(data->name, "mandelbrot"))
			data->color = 4000;
		else if (!ft_strcmp(data->name, "julia"))
			data->color = 265;
		else
			data->color = 1000000;
	}
}

void	change_fractal_hook(int keycode, t_param *data)
{
	if (keycode == 46)
	{
		data->name = "mandelbrot";
		get_fractal(data);
	}
	else if (keycode == 11)
	{
		data->name = "burningship";
		get_fractal(data);
	}
	else if (keycode == 38)
	{
		data->name = "julia";
		get_fractal(data);
	}
}

void	zoom_hook(int keycode, t_param *data)
{
	double dz;

	dz = data->zoom;
	if (keycode == 24)
	{
		data->x2 = data->x;
		data->y2 = data->y;
		data->x1 = (data->x2 / dz + data->x1) - ((dz * 1.2) / 2);
		data->x1 += ((dz * 1.2) / 2) - (data->x2 / (dz * 1.2));
		data->y1 = (data->y2 / dz + data->y1) - ((dz * 1.2) / 2);
		data->y1 += ((dz * 1.2) / 2) - (data->y2 / (dz * 1.2));
		data->zoom *= 1.2;
		data->max_iterations += 2;
	}
	else if (keycode == 27)
	{
		data->x1 = (data->x2 / dz + data->x1) - ((dz / 1.2) / 2);
		data->x1 += ((dz / 1.2) / 2) - (data->x2 / (dz / 1.2));
		data->y1 = (data->y2 / dz + data->y1) - ((dz / 1.2) / 2);
		data->y1 += ((dz / 1.2) / 2) - (data->y2 / (dz / 1.2));
		data->zoom /= 1.2;
		data->max_iterations -= 2;
	}
}
