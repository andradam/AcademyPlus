
#include "fractol.h"

int key_hook(int keyhook, t_data *data)
{
	if (keyhook == 53) //adica a
	{
	data->zoom *= 0.9;
	ft_mandelbrot(data);
	}
return (0);
}
