#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>

# define WIDTH 400
# define HEIGHT 400
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100
# define MAX_ITERATIONS 100
# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*buff;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		x;
	int		y;
	int 	ac;
	double	reel_c;
	double	imag_c;
	int		color;
	char	*name;
	double r_min;
	double r_max;
	double i_min;
	double i_max;
}			t_fractal;

void	draw_mandelbrot(t_fractal *fract);
void	draw_julia(t_fractal *fract);
void	init_fractal(t_fractal *fract, char **str);
void	init_mlx(t_fractal *fract);
int	key_hook(int key_code, t_fractal *fract);
int	mouse_hook(int button, int x, int y, void *param);
void	calculate_julia(t_fractal *fract, double reel_z, double imag_z);
void	calculate_mandelbrot(t_fractal *fractal, double reel_c, double imag_c);
int	draw_fractal(t_fractal *fract);
void	fill_buff_w_color(t_fractal *fract, int x, int y, int color);
int	free_fractal(t_fractal *fract);
void arg_error(void);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(char *str);

#endif