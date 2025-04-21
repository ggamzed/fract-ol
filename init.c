/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:17:33 by gdemirci          #+#    #+#             */
/*   Updated: 2025/04/21 21:17:35 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fractol.h"

void	check_args(t_fractal *fract, char **str)
{
	fract->name = str[1];
	if (fract->ac == 4 && ft_strncmp(fract->name, "Julia", 6) == 0)
	{
		fract->reel_c = ft_atof(str[2]);
		fract->imag_c = ft_atof(str[3]);
	}
	else if (fract->ac == 2 && ft_strncmp(fract->name, "Mandelbrot", 11) == 0)
	{
		fract->reel_c = 0.0;
		fract->imag_c = 0.0;
	}
	else
	{
		arg_error();
		exit(EXIT_FAILURE);
	}
}

void	init_fractal(t_fractal *fract)
{
	fract->color = 0x1E90FF;
	fract->x = 0;
	fract->y = 0;
	fract->r_min = -2.0;
	fract->r_max = 2.0;
	fract->i_min = -2.0;
	fract->i_max = 2.0;
	fract->win = NULL;
	fract->img = NULL;
	fract->mlx = NULL;
}

void	init_mlx(t_fractal *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "fractol");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->buff = mlx_get_data_addr(fract->img, &fract->pixel_bits,
			&fract->line_bytes, &fract->endian);
}
