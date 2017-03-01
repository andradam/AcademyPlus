
#include "fractol.h"

int	ft_error(int e)
{	
	if (e == 1)
	{
	write(1, "Wrong number of parameters\n", 27);
	}
return (0);
}
