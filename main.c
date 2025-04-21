/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 16:03:52 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fract)
{
	if (fract->ac == 2 && ft_strncmp(fract->name, "mandel", 7) == 0)
		draw_mandelbrot(fract);
	else if (fract->ac == 4 && ft_strncmp(fract->name, "julia", 6) == 0)
	{
		draw_julia(fract);
	}
	else
	{
		arg_error();
		free_fractal(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	return (0);
}


int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (!(argc == 2 || argc == 4))
	{
		arg_error();
		return (0);
	}
	fract.ac = argc;
	init_fractal(&fract, argv);
	init_mlx(&fract);
	mlx_key_hook(fract.win, key_hook, &fract);
	mlx_mouse_hook(fract.win, mouse_hook, &fract);
	mlx_hook(fract.win, 17, 0L, free_fractal, &fract);
	draw_fractal(&fract);
	mlx_loop(fract.mlx);

	return (0);
}