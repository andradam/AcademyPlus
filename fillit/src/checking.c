/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:02:38 by anadam            #+#    #+#             */
/*   Updated: 2017/01/08 11:13:45 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		get_dots(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}

int		ft_div(int n)
{
	int count;

	count = 0;
	while (n >= 4)
	{
		n = n - 4;
		count++;
	}
	return (count);
}

int		check(char **map, char *tetris, int i, int j)
{
	int	k;
	int	dots;
	int	size;

	dots = get_dots(tetris);
	size = ft_lines(map);
	k = dots - 1;
	while (tetris[++k] != '\0')
		if (tetris[k] != '.')
		{
			if ((j + ft_div(k) - ft_div(dots)) >= size
				|| (i + ((k % 4) - (dots % 4))) >= size
				|| map[j + ft_div(k) - ft_div(dots)]
				[i + ((k % 4) - (dots % 4))] != '.')
				return (1);
		}
	return (0);
}
