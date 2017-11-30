/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:50:37 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 18:55:19 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_fractal(t_param *data)
{
	data->max_iterations = 50;
	data->zoom = 200;
	if (!ft_strcmp(data->name, "mandelbrot"))
	{
		data->color = 4000;
		data->zoom = 280;
		data->x1 = -2.3;
		data->y1 = -1.3;
	}
	else if (!ft_strcmp(data->name, "julia"))
	{
		data->color = 265;
		data->x1 = -2.5;
		data->y1 = -1.9;
		data->movement = 1;
		data->p_r = 0.285;
		data->p_i = 0.01;
	}
	else
	{
		data->color = 1000000;
		data->x1 = -2.6;
		data->y1 = -2.2;
	}
	create_fractal(data);
}

void	create_mandelbrot(t_param *data)
{
	int		i;
	double	tmp;

	i = 0;
	data->z_r = 0;
	data->z_i = 0;
	data->p_r = data->x / data->zoom + data->x1;
	data->p_i = data->y / data->zoom + data->y1;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& i < data->max_iterations)
	{
		tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->p_r;
		data->z_i = 2 * data->z_i * data->z_r + data->p_i;
		data->z_r = tmp;
		i++;
	}
	if (i < data->max_iterations)
		put_pxl_to_img(data, data->x, data->y, (data->color * i));
	else
		put_pxl_to_img(data, data->x, data->y, 0x000000);
}

void	create_julia(t_param *data)
{
	int		i;
	double	tmp;

	i = 0;
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& i < data->max_iterations)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i - 0.7
			+ (data->p_r / WDTH);
		data->z_i = 2 * data->z_i * tmp + data->p_i / HGHT;
		i++;
	}
	if (i < data->max_iterations)
		put_pxl_to_img(data, data->x, data->y, (data->color * i));
	else
		put_pxl_to_img(data, data->x, data->y, 0x000000);
}

void	create_burningship(t_param *data)
{
	int		i;
	double	tmp;

	i = 0;
	data->z_r = 0;
	data->z_i = 0;
	data->p_r = data->x / data->zoom + data->x1;
	data->p_i = data->y / data->zoom + data->y1;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 &&
			i < data->max_iterations)
	{
		tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->p_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->p_i;
		data->z_r = tmp;
		i++;
	}
	if (i < data->max_iterations)
		put_pxl_to_img(data, data->x, data->y, (data->color * i));
	else
		put_pxl_to_img(data, data->x, data->y, 0x000000);
}
