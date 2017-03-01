/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:02:52 by anadam            #+#    #+#             */
/*   Updated: 2017/01/08 11:14:17 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	while (i < size)
	{
		if (!(map[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}

void	free_map(char **map)
{
	int i;
	int j;

	j = 0;
	i = ft_lines(map);
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
