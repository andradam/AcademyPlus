/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:26:56 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 10:38:34 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar('m' - (str[i] - 'n'));
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar('M' - (str[i] - 'N'));
		else
			ft_putchar(str[i]);
		i++;
	}
		write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_mirror(argv[1]);
	return (0);
}
