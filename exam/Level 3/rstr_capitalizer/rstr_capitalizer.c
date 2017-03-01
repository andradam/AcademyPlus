#include <unistd.h>

void    ft_putchar(char c)
{
	        write(1, &c, 1);
}

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	 while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_islower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int		ft_isupper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		ft_putchar('\n');
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (ft_isupper(argv[i][j]) == 1)
					argv[i][j] = argv[i][j] + 32;
				if ((argv[i][j + 1] == '\0' || ft_isspace(argv[i][j + 1]) == 1) && ft_islower(argv[i][j]) == 1)
					argv[i][j] = argv[i][j] - 32;
				ft_putchar(argv[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;			
		}
	}
	return (0);
}
