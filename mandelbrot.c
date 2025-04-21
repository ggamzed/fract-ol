
#include "fractol.h"

void	calculate_mandelbrot(t_fractal *fractal, double reel_c, double imag_c)
{
	int iter;
	double reel_z;
	double imag_z;
	double tmp;

	reel_z = 0;
	imag_z = 0;
	iter = 0;
	while(++iter < MAX_ITERATIONS)
	{
		tmp = 2 * reel_z * imag_z + imag_c;
		reel_z = reel_z * reel_z - imag_z * imag_z + reel_c;
		imag_z = tmp;
		if ((reel_z * reel_z + imag_z * imag_z) > 4.0)
			break;
	}
	if (iter == MAX_ITERATIONS)
		fill_buff_w_color(fractal, fractal->x, fractal->y, 0x000000);
	else
		fill_buff_w_color(fractal, fractal->x, fractal->y, (fractal->color * iter));
}