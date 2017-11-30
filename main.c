/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:51:43 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 19:05:36 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_argument_validity(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia") &&
			ft_strcmp(argv[1], "burningship"))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_param data;

	if (!check_argument_validity(argc, argv))
		usage();
	data.name = argv[1];
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WDTH, HGHT, argv[1]);
	data.img = mlx_new_image(data.mlx, WDTH, HGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bits,
			&data.size_line, &data.endian);
	get_fractal(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 6, 1L < 6, movement_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0L, close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
