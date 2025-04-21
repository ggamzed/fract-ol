/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:46:11 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 16:02:22 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


# define WIDTH 300
# define HEIGHT 300
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100
# define MAX_ITERATIONS 50

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*buff;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		x;
	int		y;
	int 	ac;

	double	reel_c;
	double	imag_c;

	int		color;
	
	char	*name;

	double r_min;
	double r_max;
	double i_min;
	double i_max;
}			t_fractal;

// utils.c
void		fill_buff_w_color(t_fractal *fractal, int x, int y, int colour);
int			free_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

// init.c
void		init_fractal(t_fractal *fractal, char **str);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal, double reel_c, double imag_c);

// julia.c
void		calculate_julia(t_fractal *fractal, double reel_c, double imag_c);

// burning_ship.c
void		calculate_burning_ship(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal);

// mouse_and_keys.c
int			key_hook(int key_code, t_fractal *fractal);
int	mouse_hook(int button, int x, int y, void *param);

// draw.c
void		*draw_mandelbrot(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(char *str);
void arg_error(void);
#endif