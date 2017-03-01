/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:02:59 by anadam            #+#    #+#             */
/*   Updated: 2017/01/08 11:14:02 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	**place_tetris(char **map, char *tetris, int i, int j)
{
	int		k;
	int		dots;

	dots = get_dots(tetris);
	k = dots - 1;
	while (tetris[++k] != '\0')
		if (tetris[k] != '.')
		{
			map[j + ft_div(k) - ft_div(dots)]
				[i + ((k % 4) - (dots % 4))] = tetris[k];
		}
	return (map);
}

char	**remove_tetris(char **map, int i, int j, char *tetris)
{
	char	c;

	c = tetris[get_dots(tetris)];
	while (map[j] != NULL)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == c)
				map[j][i] = '.';
			++i;
		}
		i = 0;
		++j;
	}
	return (map);
}

int		recursive(char **tetris, char **map, int k)
{
	int		i;
	int		j;
	char	*new_tetris;

	if (!tetris[k])
		return (1);
	j = -1;
	new_tetris = tetris[k];
	while (j++ < ft_lines(map))
	{
		i = 0;
		while (i < ft_lines(map))
		{
			if (check(map, new_tetris, i, j) == 0)
			{
				map = place_tetris(map, new_tetris, i, j);
				if (recursive(tetris, map, k + 1) == 1)
					return (1);
				else
					remove_tetris(map, 0, 0, new_tetris);
			}
			i++;
		}
	}
	return (0);
}

void	ft_fillit(char **tetris, int count)
{
	char	**map;
	int		size;

	size = ft_sqrt(count * 4);
	map = create_map(size);
	while (recursive(tetris, map, 0) == 0)
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	display_fillit(map);
}
