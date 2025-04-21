/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:55:52 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 15:42:56 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	calculate_julia(t_fractal *fract, double reel_z, double imag_z)
{
	int iter;
	double tmp;

	iter = 0;
	while(++iter < MAX_ITERATIONS)
	{	
		tmp = 2 * reel_z * imag_z + fract->imag_c;
		reel_z = reel_z * reel_z - imag_z * imag_z + fract->reel_c;
		imag_z = tmp;
		if ((reel_z * reel_z + imag_z * imag_z) > 4.0)
			break;
	}
	if (iter == MAX_ITERATIONS)
		fill_buff_w_color(fract, fract->x, fract->y, 0x000000);
	else
		fill_buff_w_color(fract, fract->x, fract->y, (fract->color * iter));
}