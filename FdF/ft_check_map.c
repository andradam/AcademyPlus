/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:57:38 by anadam            #+#    #+#             */
/*   Updated: 2017/02/24 16:39:23 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_color(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ',')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_signdigit(char digit)
{
	if ((digit >= 48 && digit <= 57) || digit == '-' || digit == '+')
		return (1);
	return (0);
}

int	ft_check_len(char *map)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (map[i])
	{
		if (ft_signdigit(map[i]) && (map[i + 1] == ' ' || map[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

int	ft_check_digit(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_signdigit(map[i][j])) && map[i][j] != 32)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, t_data *data)
{
	int i;
	int len;

	i = 1;
	len = ft_check_len(map[0]);
	data->cols = len;
	if (ft_check_color(map) == 1)
		return (0);
	if (ft_check_digit(map) != 0)
		return (1);
	while (map[i])
	{
		if (ft_check_len(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}
