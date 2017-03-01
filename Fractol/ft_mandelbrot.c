
#include "fractol.h"

void	ft_mandelbrot(t_data *data)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double tmp;
	int	max;
	int 	color[1000];
	int 	iter;
	int 	i;
	int 	j;

	i = 0;
	max = 1000;
	mlx_clear_window(data->mlx, data->win);
	while (i < max)
	{
		color[i] =  (i % 256 * i);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
		c_re = (j - WIDTH/2.0) * 4.0/WIDTH;
		c_im = (i - HEIGHT/2.0) * 4.0/ WIDTH;
		x = 0;
		y = 0;
		iter = 0;
		while (x*x + y*y <= 4 && iter < max)
		{
			tmp = x*x - y*y + c_re;
			y = 2*x*y + c_im;
			x = tmp;
			iter++;
		}
		if (iter < max)
		mlx_pixel_put(data->mlx,data->win, j, i, color[iter]);
			else
		mlx_pixel_put(data->mlx,data->win, j, i, 0x000000);

		j++;
		}
	i++;
	}
}
