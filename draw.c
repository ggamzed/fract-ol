#include "fractol.h"

void	draw_mandelbrot(t_fractal *fract)
{
	double	real_c;
	double	imag_c;

	fract->x = 0;
	fract->y = 0;
	while (fract->x < WIDTH)
	{
		while (fract->y < HEIGHT)
		{
			real_c = ((fract->r_max - fract->r_min) / WIDTH)
				* fract->x + fract->r_min;
			imag_c = ((fract->i_min - fract->i_max) / HEIGHT)
				* fract->y + fract->i_max;
			calculate_mandelbrot(fract, real_c, imag_c);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
}

void	draw_julia(t_fractal *fract)
{
	double	real_z;
	double	imag_z;

	fract->x = 0;
	fract->y = 0;
	while (fract->x < WIDTH)
	{
		while (fract->y < HEIGHT)
		{
			real_z = ((fract->r_max - fract->r_min) / WIDTH)
				* fract->x + fract->r_min;
			imag_z = ((fract->i_min - fract->i_max) / HEIGHT)
				* fract->y + fract->i_max;
			calculate_julia(fract, real_z, imag_z);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
}
