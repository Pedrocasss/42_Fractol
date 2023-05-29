/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:20:19 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 14:06:40 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_burn(t_data *data, t_fractal *burn)
{
	double	aa;
	double	bb;
	int		n;

	n = -1;
	aa = 0;
	bb = 0;
	while (++n < data->max_iter)
	{
		aa = pow(burn->real, 2) - pow(burn->imaginary, 2);
		bb = 2.0 * fabs(burn->real * burn->imaginary);
		if (fabs(pow(aa, 2) + fabs(pow(bb, 2))) > 250)
			break ;
		burn->real = aa + burn->c_a;
		burn->imaginary = bb + burn->c_b;
	}
	return (n);
}

int	render_burn(t_data *vars)
{
	int	i;
	int	j;
	int	color;

	color = 0;
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		j = -1;
		while (++j < WINDOW_HEIGHT)
		{
			color = picasso_burn(vars, i + vars->img.offs_x, \
					j + vars->img.offs_y, 100);
			palette(vars, color, i, j);
		}
		j = 0;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
	return (0);
}

int	picasso_burn(t_data *data, double x, double y, int iter)
{
	int			j;
	int			color;
	t_fractal	burn;

	burn.imaginary = coords(y, data->img.zoom, 0);
	burn.c_b = burn.imaginary;
	burn.real = coords(x, data->img.zoom, 1);
	burn.c_a = burn.real;
	j = iterations_burn(data, &burn);
	color = map(iter, j, 0, 1);
	color = map(1, sqrt(color), 0, 1000);
	if (j == iter)
		color = 0;
	return (color);
}

void	palette_burn(t_data *v_ars, int color, double x, double y)
{
	if (color == 0)
		my_mlx_pixel_put(&v_ars->img, x, y, rgb(0, 0, 0));
	else if (color < 110)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 30, \
				color * v_ars->img.zoom * 12));
	else if (color < 200)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 50, \
				color * v_ars->img.zoom * 13));
	else if (color < 250)
		my_mlx_pixel_put(&v_ars->img, x, y, \
				rgb(42, color * v_ars->img.zoom * 10, \
					color * v_ars->img.zoom * 15));
	else
		my_mlx_pixel_put(&v_ars->img, x, y, \
				rgb(42, color * v_ars->img.zoom * 42, \
					color * v_ars->img.zoom * 15));
}
