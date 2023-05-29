/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:21:02 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 14:17:01 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handles(int key, t_data *vars)
{
	if (key == XK_Left)
	{
		vars->img.offs_x -= 10;
		render_fractal(vars, vars->fractal);
	}
	if (key == XK_Right)
	{
		vars->img.offs_x += 10;
		render_fractal(vars, vars->fractal);
	}
	if (key == XK_Down)
	{
		vars->img.offs_y += 10;
		render_fractal(vars, vars->fractal);
	}
	if (key == XK_Up)
	{
		vars->img.offs_y -= 10;
		render_fractal(vars, vars->fractal);
	}
	if (key == XK_Escape)
		destroy_all(vars);
	if (key == XK_m)
		vars->max_iter += 10;
	return (0);
}
