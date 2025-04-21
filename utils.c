/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:37 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 18:35:55 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_buff_w_color(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->buff;
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
	exit(0);
	return (0);
}
/*
void free_fract(t_fractal *fract)
{
	if (fract)
	{
		if (fract->img)
			mlx_destroy_image(fract->mlx, fract->img);
		if (fract->win)
			mlx_destroy_window(fract->mlx, fract->win);
		if (fract->mlx)
		{
			//mlx_destroy_display(fract->mlx);
			free(fract->mlx);
		}
		free(fract);
	}
}

int	exit_succ_fract(t_fractal *fract)
{
	if (fract)
		free_fract(fract);
	exit(EXIT_SUCCESS);
	return (0);
}

int exit_fail_fract(t_fractal *fract)
{
	if (fract)
		free_fract(fract);
	exit(EXIT_FAILURE);
	return (0);
}
	*/

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	ft_skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	is_neg = 1;
	nb = 0;
	div = 0.1;
	i = ft_skip(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
		nb = (nb * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb += (str[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		write(1, "Invalid value\n", 14);
	return (nb * is_neg);
}

void arg_error(void)
{
	write(1, "Mandelbrot From: ./fractol mandel\n", 34);
	write(1, "Julia From: ./fractol julia <reel_c> <imag_c>\n", 46);
	write(1, "Possible Julia Values:\n", 23);
	write(1, "<-0.745429> <0.05>\n", 19);
	write(1, "<-0.70176> <0.3842>\n", 20);
	write(1, "<0.285> <0.01>\n", 15);
	// 0.45 -0.1428

}