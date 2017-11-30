/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:50:52 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 18:58:04 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*fractal(void *fractal)
{
	double		tmp;
	t_param		*data;

	data = (t_param *)fractal;
	data->x = 0;
	tmp = data->y;
	while (data->x++ < WDTH)
	{
		data->y = tmp;
		while (data->y < data->max_y)
		{
			if (!ft_strcmp(data->name, "julia"))
				create_julia(data);
			else if (!ft_strcmp(data->name, "mandelbrot"))
				create_mandelbrot(data);
			else
				create_burningship(data);
			data->y++;
		}
	}
	return (fractal);
}

void	create_fractal(t_param *data)
{
	int			i;
	t_param		param[8];
	pthread_t	thread[8];

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&param[i], (void*)data, sizeof(t_param));
		param[i].y = 100 * i;
		param[i].max_y = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_create(&thread[i], NULL, fractal, &param[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	put_pxl_to_img(t_param *data, int x, int y, int color)
{
	int i;

	color = mlx_get_color_value(data->mlx, color);
	i = (x * 4) + (y * data->size_line);
	data->img_addr[i] = color;
	data->img_addr[++i] = color >> 8;
	data->img_addr[++i] = color >> 16;
}
