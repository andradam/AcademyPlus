
#include "fractol.h"

int	ft_type(t_data *data, char *av)
{
	if (ft_atoi(av) == 1)
	{
		data->type = ft_atoi(av);
		data->name = "Mandelbrot";
	return (1);
	}
	if (ft_atoi(av) == 2)
	{
		data->type = ft_atoi(av);
		data->name = "Julia";
	return (1);
	}
	if (ft_atoi(av) == 3)
	{
	data->type = ft_atoi(av);
	data->name = "Other";
	return (1);
	}
	if (ft_atoi(av) < 1 && ft_atoi(av) > 3)
	{
	write(1,"Incorect parameter!\n", 20);
	write(1,"Available: 1.Mandelbrot 2.Julia 3.Other\n",40);
	return (0);
	}	
	write(1,"Incorect parameter!\n", 20);
	write(1,"Available: 1.Mandelbrot 2.Julia 3.Other\n",40);
return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		return (ft_error(1));
	data = (t_data *)malloc(sizeof(t_data));
	if (ft_type(data, argv[1]) == 1)
	{
	ft_initialize_env(data);
	if (data->type == 1)
	ft_mandelbrot(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	}
	else
		return (0);
return (0);
}
