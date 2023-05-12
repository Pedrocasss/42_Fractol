/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:26 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:18:24 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_mandel(t_data *data, t_fractal *mandel)
{
	int		n;
	double	aa;
	double	bb;

	n = -1;
	aa = 0;
	bb = 0;
	while (++n < data->max_iter)
	{
		aa = pow(mandel->real, 2) - pow(mandel->imaginary, 2);
		bb = 2.0 * mandel->real * mandel->imaginary;
		if (fabs(aa) > 16)
			break ;
		mandel->real = aa + mandel->c_a;
		mandel->imaginary = bb + mandel->c_b;
	}
	return (n);
}

int	render_mandel(t_data *v_ars)
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
			color = picasso_mandel(v_ars, i + v_ars->img.offs_x, \
					j + v_ars->img.offs_y, 100);
			palette(v_ars, color, i, j);
		}
		j = 0;
	}
	mlx_put_image_to_window(v_ars->mlx_ptr, v_ars->win_ptr, \
			v_ars->img.img, 0, 0);
	return (0);
}

int	picasso_mandel(t_data *data, double x, double y, int iter)
{
	int			j;
	int			color;
	t_fractal	mandel;

	mandel.imaginary = coords(y, data->img.zoom, 0);
	mandel.c_b = mandel.imaginary;
	mandel.real = coords(x, data->img.zoom, 1);
	mandel.c_a = mandel.real;
	j = iterations_mandel(data, &mandel);
	color = map(iter, j, 0, 1);
	color = map(1, sqrt(color), 0, 1000);
	if (j == iter)
		color = 0;
	return (color);
}
