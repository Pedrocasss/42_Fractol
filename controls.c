/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:21:25 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 14:13:31 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_more(t_data *vars, int x, int y)
{
	vars->img.zoom /= 1.1;
	vars->img.offs_x *= 1.1;
	vars->img.offs_y *= 1.1;
	vars->img.offs_x += ((x - WINDOW_WIDTH / 2) * 0.1);
	vars->img.offs_y += ((y - WINDOW_HEIGHT / 2) * 0.1);
	vars->max_iter += 10;
	render_fractal(vars, vars->fractal);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
}

void	zoom_less(t_data *vars, int x, int y)
{
	vars->img.zoom *= 1.1;
	vars->img.offs_x /= 1.1;
	vars->img.offs_y /= 1.1;
	vars->img.offs_x -= ((x - WINDOW_WIDTH / 2) * 0.1);
	vars->img.offs_y -= ((y - WINDOW_HEIGHT / 2) * 0.1);
	vars->max_iter -= 10;
	render_fractal(vars, vars->fractal);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
}

int	zoom_fract(int button, int x, int y, t_data *vars)
{
	if (button == 5)
		zoom_less(vars, x, y);
	if (button == 4)
		zoom_more(vars, x, y);
	return (0);
}
