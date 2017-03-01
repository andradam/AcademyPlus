
#include "fractol.h"

void	ft_initialize_env(t_data *data)
{
	data->zoom = 4.0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
}
