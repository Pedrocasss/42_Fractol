/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:25:53 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:46:40 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_data *v_ars)
{
	v_ars->img.zoom = 1.1;
	v_ars->img.offs_y = 0;
	v_ars->mlx_ptr = 0;
	v_ars->img.offs_x = 0;
	v_ars->frac.c_aa = 0.0;
	v_ars->frac.c_bb = 0.0;
	v_ars->max_iter = 500;
}
