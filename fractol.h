/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:10:27 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/16 19:13:42 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>

# define HGHT	800
# define WDTH	1000
# define RED	"\x1b[31;1m"
# define RESET	"\x1b[0m"

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	char		*name;
	double		p_r;
	double		p_i;
	double		z_r;
	double		z_i;
	double		x;
	double		y;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		zoom;
	double		max_iterations;
	double		max_y;
	int			bits;
	int			size_line;
	int			endian;
	int			color;
	int			movement;
}				t_param;

void			usage(void);
int				check_argument_validity(int argc, char **argv);
void			ft_exit(void);

void			get_fractal(t_param *data);
void			create_fractal(t_param *data);
void			create_mandelbrot(t_param *data);
void			create_julia(t_param *data);
void			create_burningship(t_param *data);
void			*fractal(void *tab);
void			put_pxl_to_img(t_param *data, int x, int y, int color);

int				key_hook(int keycode, t_param *data);
void			color_hook(int keycode, t_param *data);
void			zoom_hook(int keycode, t_param *data);
void			change_fractal_hook(int keycode, t_param *data);
int				mouse_hook(int mousecode, int x, int y, t_param *data);
int				movement_hook(int x, int y, t_param *data);
int				close_win(void);

#endif
