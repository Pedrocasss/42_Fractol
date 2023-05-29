/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:22 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:42:20 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	zoom;
	double	offs_x;
	double	offs_y;
}				t_img;

typedef struct s_render {
	int	x;
	int	y;
	int	height;
	int	width;
	int	color;
}				t_render;

typedef struct s_fractal
{
	double	imaginary;
	double	real;
	double	c_a;
	double	c_b;
	double	c_aa;
	double	c_bb;
	void	*fractal;
	t_img	img;
}				t_fractal;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fractal	frac;
	int			max_iter;
	char		fractal;
}				t_data;

typedef struct s_all_in
{
	t_img		img;
	t_data		data;
	t_render	render;
	t_fractal	fractal;
}				t_all_in;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	map(double x, double i_max, double z_min, double z_max);
double	coords(double x, double zoom, int option);
int		iterations_mandel(t_data *data, t_fractal *mandel);
int		picasso_mandel(t_data *data, double x, double y, int iter);
int		render_mandel(t_data *img);
int		rgb(int r, int g, int b);
void	palette(t_data *v_ars, int color, double x, double y);
void	init_struct(t_data *v_ars);
int		iterations_julia(t_data *data, t_fractal *burn);
void	render_julia(t_data *vars);
int		picasso_julia(t_data *data, double x, double y, int iter);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		zoom_fract(int button, int x, int y, t_data *vars);
void	zoom_more(t_data *v_ars, int x, int y);
void	zoom_less(t_data *v_ars, int x, int y);
int		key_handles(int key, t_data *vars);
void	render_fractal(t_data *vars, char fractal);
int		destroy_all(t_data *vars);
int		julia_keys(int key, t_data *julia);
int		iterations_burn(t_data *data, t_fractal *burn);
int		render_burn(t_data *vars);
int		picasso_burn(t_data *data, double x, double y, int iter);
void	palette_burn(t_data *v_ars, int color, double x, double y);
void	palette_julia(t_data *v_ars, int color, double x, double y);
int		is_digit(char *s);
int		is_double(char *s);
int		verify_input(int argc, char **argv);
int		ft_strlen(char *str);

#endif