/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:32:20 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 18:23:17 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_fractal *fract, char **str)
{
	fract->name = str[1];
	fract->color = 0x1E90FF;
	//fract->color = 0xFFC30B;
	fract->reel_c = 0.0;
	fract->imag_c = 0.0;
	//fract->reel_c = ft_atod(str[2]);
	//fract->imag_c = ft_atod(str[3]);
	fract->x = 0;
	fract->y = 0;
	fract->r_min = -2.0;
	fract->r_max = 2.0;
	fract->i_min = -2.0;
	fract->i_max = 2.0;
	if (fract->ac == 4 && ft_strncmp(fract->name, "julia", 6) == 0)
	{
		fract->reel_c = ft_atod(str[2]);
		fract->imag_c = ft_atod(str[3]);
	}
}

void	init_mlx(t_fractal *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fract-ol");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->buff = mlx_get_data_addr(fract->img, &fract->pixel_bits, &fract->line_bytes, &fract->endian);
}