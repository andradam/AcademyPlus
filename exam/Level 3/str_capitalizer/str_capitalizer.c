/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:06:49 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 14:08:01 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	cap(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] >='a' && str[i] <= 'z')
		str[i] -= 32;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] = str[i + 1] - 32;
		i++;
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int x;

	if (argc < 2)
	{
		write(1,"\n", 1);
		return (0);
	}
	x = 1;
	while (x <= argc - 1)
	{
		cap(argv[x]);
		ft_putstr(argv[x]);
		x++;
	}
	return (0);
}
