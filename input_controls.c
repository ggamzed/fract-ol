/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:17:45 by gdemirci          #+#    #+#             */
/*   Updated: 2025/04/21 21:17:47 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, double zoom_factor)
{
	double	range_real;
	double	range_imag;
	double	center_real;
	double	center_imag;

	range_real = f->r_max - f->r_min;
	range_imag = f->i_max - f->i_min;
	center_real = f->r_min + range_real / 2;
	center_imag = f->i_min + range_imag / 2;
	range_real *= zoom_factor;
	range_imag *= zoom_factor;
	f->r_min = center_real - range_real / 2;
	f->r_max = center_real + range_real / 2;
	f->i_min = center_imag - range_imag / 2;
	f->i_max = center_imag + range_imag / 2;
}

int	key_hook(int key_code, t_fractal *fract)
{
	if (key_code == ESC)
		free_fractal(fract);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *fract)
{
	(void)x;
	(void)y;
	if (!fract)
		return (1);
	if (button == SCROLL_UP)
		zoom(fract, 0.75);
	else if (button == SCROLL_DOWN)
		zoom(fract, 1.25);
	draw_fractal(fract);
	return (0);
}
