/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:57:25 by anadam            #+#    #+#             */
/*   Updated: 2017/02/21 16:36:58 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_lines(t_data *data, t_coord **iso)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (j < data->cols - 1)
				ft_draw_line(data, iso[i][j], iso[i][j + 1],
						data->color);
			if (i < data->rows - 1)
				ft_draw_line(data, iso[i][j], iso[i + 1][j],
						data->color);
			j++;
		}
		i++;
	}
}

void	ft_draw_isop(t_data *data, t_coord **iso)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			mlx_pixel_put(data->mlx, data->win,
					iso[i][j].x, iso[i][j].y, 0xffe4);
			j++;
		}
		i++;
	}
}

t_coord	**ft_proj_iso(t_data *data)
{
	t_coord	**map;
	int		i;
	int		j;

	i = 0;
	map = (t_coord**)malloc(sizeof(t_coord) * data->rows);
	while (i < data->rows)
	{
		map[i] = (t_coord*)malloc(sizeof(t_coord) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			map[i][j].x = WIDTH / 2 + data->map[i][j].x
				* data->space * cos(DEG30) - data->map[i][j].y
				* data->space * cos(DEG30);
			map[i][j].y = HEIGHT / 2 + data->map[i][j].x
				* data->space * sin(DEG30) + data->map[i][j].y * data->space
				* sin(DEG30) - data->map[i][j].z * data->space;
			map[i][j].z = data->map[i][j].z;
			j++;
		}
		i++;
	}
	return (map);
}

t_coord	**ft_proj_paralel(t_data *data)
{
	t_coord **map;
	int		i;
	int		j;

	i = 0;
	map = (t_coord**)malloc(sizeof(t_coord) * data->rows);
	while (i < data->rows)
	{
		map[i] = (t_coord*)malloc(sizeof(t_coord) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			map[i][j].x = WIDTH / 2 + data->map[i][j].x
				* data->space * cos(M_PI / 60) - data->map[i][j].y
				* data->space * cos(M_PI / 60);
			map[i][j].y = HEIGHT / 2 + data->map[i][j].x
				* data->space * sin(M_PI / 60) + data->map[i][j].y * data->space
				* sin(M_PI / 60) - data->map[i][j].z * data->space;
			map[i][j].z = data->map[i][j].z;
			j++;
		}
		i++;
	}
	return (map);
}

int		expose_hook(t_data *data)
{
	t_coord **iso;

	if (data->proj == 1)
		iso = ft_proj_iso(data);
	if (data->proj == 2)
		iso = ft_proj_paralel(data);
	mlx_clear_window(data->mlx, data->win);
	ft_draw_isop(data, iso);
	ft_draw_lines(data, iso);
	return (0);
}
