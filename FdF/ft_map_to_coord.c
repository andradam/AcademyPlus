/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:58:05 by anadam            #+#    #+#             */
/*   Updated: 2017/02/22 11:19:59 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**maptoco(char **map, t_data *data, t_coord **coord, int i)
{
	int j;
	int jj;

	coord = (t_coord **)malloc(sizeof(t_coord) * data->rows);
	while (map[i])
	{
		j = 0;
		jj = 0;
		coord[i] = (t_coord *)malloc(sizeof(t_coord) * data->cols);
		while (map[i][j])
		{
			if (ft_signdigit(map[i][j]) != 0 &&
					(map[i][j - 1] == ' ' || j == 0))
			{
				coord[i][jj].x = jj;
				coord[i][jj].y = i;
				coord[i][jj].z = ft_atoi(map[i] + j);
				jj++;
			}
			j++;
		}
		i++;
	}
	return (coord);
}
