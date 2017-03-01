#ifndef _FRACTOL_H
# define _FRACTOL_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void *mlx;
	void *win;
	char *name;
	int type;
	float zoom;
}		t_data;

int	ft_error(int e);
int	ft_type(t_data *data, char *av);
int	key_hook(int keyhook, t_data *data);
void	ft_initialize_env(t_data *data);
void	ft_mandelbrot(t_data *data);
#endif
