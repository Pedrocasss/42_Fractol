/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:09 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:07:41 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "unistd.h"

static void	norm_init(t_data *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "Fract-ol");
	vars->img.img = mlx_new_image(vars->mlx_ptr, WINDOW_WIDTH, \
		WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, \
			&vars->img.line_length, &vars->img.endian);
	vars->img.zoom = 3.5;
	mlx_key_hook(vars->win_ptr, &julia_keys, vars);
	mlx_mouse_hook(vars->win_ptr, &zoom_fract, vars);
}

static void	norm_parse(char **argv, t_data *vars)
{
	if (ft_strncmp(argv[1], "m", 1) == 0)
	{
		vars->fractal = 'm';
		render_fractal(vars, vars->fractal);
	}
	else if (ft_strncmp(argv[1], "j", 1) == 0)
	{
		vars->fractal = 'j';
		render_fractal(vars, vars->fractal);
	}
	else if (ft_strncmp(argv[1], "b", 1) == 0)
	{
		vars->fractal = 'b';
		render_fractal(vars, vars->fractal);
	}
}

static void	print_args(void)
{
	write(1, "============================\n", 29);
	write(1, " ./fractol m ->mandelbrot set!\n", 31);
	write(1, "============================\n", 29);
	write(1, " ./fractol j ->julia set!\n", 26);
	write(1, "============================\n", 29);
	write(1, " ./fractol b ->burnship set!\n", 29);
	write(1, "============================\n", 29);
	write(1, "Have fun (:\n", 12);
	exit(0);
}

static void	norm(int argc, char **argv)
{
	if (!verify_input(argc, argv))
	{
		print_args();
		exit(0);
	}
	if (ft_strlen(argv[1]) != 1)
	{
		print_args();
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*vars;

	vars = NULL;
	if (argc != 2)
		print_args();
	norm(argc, argv);
	if (1)
	{
		vars = malloc(sizeof(t_data));
		init_struct(vars);
		norm_init(vars);
		norm_parse(argv, vars);
	}
	if (vars != NULL)
	{
		mlx_hook(vars->win_ptr, DestroyNotify, 0, &destroy_all, vars);
		mlx_loop(vars->mlx_ptr);
		destroy_all(vars);
	}
}
