#include "minilibx/mlx.h"
#include "fractol.h"

int	draw_fractal(t_fractal *fract)
{
	if (ft_strncmp(fract->name, "Mandelbrot", 11) == 0)
		draw_mandelbrot(fract);
	else if (ft_strncmp(fract->name, "Julia", 6) == 0)
		draw_julia(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	fract.ac = argc;
	check_args(&fract, argv);
	init_fractal(&fract);
	init_mlx(&fract);
	mlx_key_hook(fract.win, key_hook, &fract);
	mlx_mouse_hook(fract.win, mouse_hook, &fract);
	mlx_hook(fract.win, 17, 0L, free_fractal, &fract);
	draw_fractal(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
