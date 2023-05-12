/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:13:44 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 14:16:31 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	palette(t_data *v_ars, int color, double x, double y)
{
	if (color == 0)
		my_mlx_pixel_put(&v_ars->img, x, y, rgb(0, 0, 0));
	else if (color < 40)
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 10, \
				color * v_ars->img.zoom * 15));
	else
		my_mlx_pixel_put(&v_ars->img, x, y, \
			rgb(42, color * v_ars->img.zoom * 42, \
				color * v_ars->img.zoom * 15));
}
