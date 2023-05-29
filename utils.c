/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:46:24 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:29:20 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

double	map(double x, double i_max, double z_min, double z_max)
{
	return ((x * (z_max - z_min) / i_max) + z_min);
}

double	coords(double x, double zoom, int option)
{
	if (option == 1)
		return (map(x, WINDOW_WIDTH - 1, -zoom, zoom));
	return (map(x, WINDOW_HEIGHT - 1, -zoom, zoom));
}

void	render_fractal(t_data *vars, char fractal)
{
	if (fractal == 'm')
		render_mandel(vars);
	if (fractal == 'j')
		render_julia(vars);
	if (fractal == 'b')
		render_burn(vars);
	mlx_do_sync(vars->mlx_ptr);
}

int	destroy_all(t_data *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	vars->win_ptr = NULL;
	mlx_destroy_image(vars->mlx_ptr, vars->img.img);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free(vars);
	exit(0);
	return (0);
}
