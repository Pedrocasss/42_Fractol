/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:21:23 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 14:21:55 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_julia(t_data *data, t_fractal *julia)
{
	int		n;
	double	aa;
	double	bb;

	n = -1;
	aa = 0;
	bb = 0;
	while (++n < data->max_iter)
	{
		aa = pow(julia->c_a, 2) - pow(julia->c_b, 2);
		bb = 2.0 * julia->c_a * julia->c_b;
		if (fabs(aa) > 16)
			break ;
		julia->c_a = aa + julia->c_aa;
		julia->c_b = bb + julia->c_bb;
	}
	return (n);
}

void	render_julia(t_data *vars)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
		{
			color = picasso_julia(vars, x + vars->img.offs_x, y
					+ vars->img.offs_y, 100);
			palette_julia(vars, color / 255, x, y);
		}
		y = 0;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
}

int	picasso_julia(t_data *data, double x, double y, int iter)
{
	int			j;
	double		color;
	t_fractal	*mandel;

	mandel = &(data->frac);
	mandel->imaginary = coords(y, data->img.zoom, 0);
	mandel->c_b = mandel->imaginary;
	mandel->real = coords(x, data->img.zoom, 1);
	mandel->c_a = mandel->real;
	j = iterations_julia(data, mandel);
	color = map(iter, j, 0, 1);
	color = map(j, sqrt(color), 0, 1000000);
	if (j == iter)
		color = 0;
	return (color);
}

int	julia_keys(int key, t_data *vars)
{
	key_handles(key, vars);
	if (key == XK_a)
	{
		vars->frac.c_aa -= 0.005;
	}
	if (key == XK_d)
	{
		vars->frac.c_aa += 0.005;
	}
	if (key == XK_s)
		vars->frac.c_bb -= 0.005;
	if (key == XK_w)
		vars->frac.c_bb += 0.005;
	render_fractal(vars, vars->fractal);
	return (0);
}

void	palette_julia(t_data *v_ars, int color, double x, double y)
{
	if (color == 0)
		my_mlx_pixel_put(&v_ars->img, x, y, rgb(0, 0, 0));
	else if (color <= 500)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 15, \
				color * v_ars->img.zoom * 12));
	else if (color < 300)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 50, \
				color * v_ars->img.zoom * 13));
	else if (color < 3000)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 10, \
				color * v_ars->img.zoom * 15));
	else
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 42, \
				color * v_ars->img.zoom * 15));
}
