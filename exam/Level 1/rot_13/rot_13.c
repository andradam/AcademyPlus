/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:12:04 by anadam            #+#    #+#             */
/*   Updated: 2017/01/11 10:38:39 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rot(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 64 && str[i] < 91)
		{
			if ((str[i] + 13) > 90)
				str[i] = 13 - (91 - str[i]) + 65;
			else
				str[i] = str[i] + 13;
		}
		if (str[i] > 96 && str[i] < 123)
		{
			if ((str[i] + 13) > 122)
				str[i] = 13 - (123 - str[i]) + 97;
			else
				str[i] = str[i] + 13;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rot(argv[1]);
	return (0);
}
