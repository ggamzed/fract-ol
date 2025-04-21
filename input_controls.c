/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:11:08 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 15:41:25 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, double zoom_factor)
{
	double range_real = f->r_max - f->r_min;
	double range_imag = f->i_max - f->i_min;

	double center_real = f->r_min + range_real / 2;
	double center_imag = f->i_min + range_imag / 2;

	range_real *= zoom_factor;
	range_imag *= zoom_factor;

	f->r_min = center_real - range_real / 2;
	f->r_max = center_real + range_real / 2;
	f->i_min = center_imag - range_imag / 2;
	f->i_max = center_imag + range_imag / 2;
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}


int	key_hook(int key_code, t_fractal *fract)
{
	if (key_code == ESC)
	{
		free_fractal(fract); // bunu kullandığın yerde hata leak logları çıkıyor
		//exit_succ_fract(fract);
		exit(0);
	}
	//(void)fract;

	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractal *fractal = (t_fractal *)param;
	(void)x;
	(void)y;
	if (!fractal)
		return (1);

	if (button == SCROLL_UP)
		zoom(fractal, 0.75);
	else if (button == SCROLL_DOWN)
		zoom(fractal, 1.25);

	draw_fractal(fractal);
	return (0);
}