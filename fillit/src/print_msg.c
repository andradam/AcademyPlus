/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:03:05 by anadam            #+#    #+#             */
/*   Updated: 2017/01/08 11:16:53 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

void	display_fillit(char **tetris)
{
	int i;

	i = 0;
	while (tetris[i])
	{
		ft_putendl(tetris[i]);
		i++;
	}
}

int		validate_around(char **tetris, int i, int j)
{
	if ((j + 1) >= 0 && tetris[i][j + 1] == '#')
		if (((j + 1) % 4) == 0)
			return (0);
	return (((j - 1) >= 0 && tetris[i][j - 1] == '#')
			+ ((j - 4) >= 0 && tetris[i][j - 4] == '#')
			+ ((j + 1) <= 15 && tetris[i][j + 1] == '#')
			+ ((j + 4) <= 15 && tetris[i][j + 4] == '#'));
}

int		ft_sqrt(int len)
{
	int	size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}
