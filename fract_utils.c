/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:17:13 by gdemirci          #+#    #+#             */
/*   Updated: 2025/04/21 21:17:16 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fractol.h"
#include <unistd.h>

void	fill_buff_w_color(t_fractal *fract, int x, int y, int color)
{
	int	*buffer;

	buffer = fract->buff;
	buffer[(y * WIDTH) + x] = color;
}

int	free_fractal(t_fractal *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

void	arg_error(void)
{
	write(1, "Error:\n", 7);
	write(1, "Mandelbrot From: ./fractol mandel\n", 34);
	write(1, "Julia From: ./fractol julia <reel_c> <imag_c>\n", 46);
	write(1, "Possible Julia Values:\n", 23);
	write(1, "<-0.745429> <0.05>\n", 19);
	write(1, "<-0.70176> <0.3842>\n", 20);
	write(1, "<0.45> <-0.1428>\n", 17);
	write(1, "<0.285> <0.01>\n", 15);
}

void	check_err(void)
{
	write(1, "Error:\n", 7);
	exit(EXIT_FAILURE);
}
