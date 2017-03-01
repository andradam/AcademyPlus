/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:58:19 by anadam            #+#    #+#             */
/*   Updated: 2017/02/21 16:37:26 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj(t_data *data, int key)
{
	if (key == 20)
	{
		data->proj = 2;
		expose_hook(data);
	}
	if (key == 21)
	{
		data->proj = 1;
		expose_hook(data);
	}
}

void	ft_zoom(t_data *data, int key)
{
	if (key == 78)
	{
		data->space += 2;
		expose_hook(data);
	}
	if (key == 69)
	{
		data->space -= 1;
		expose_hook(data);
	}
}

void	ft_color(t_data *data, int c)
{
	if (c == 18)
	{
		data->color = COLO << 7;
		expose_hook(data);
	}
	if (c == 19)
	{
		data->color = COLO << 11;
		expose_hook(data);
	}
}

int		key_hook(int keyhook, t_data *data)
{
	data->name = "file";
	if (keyhook == ESC)
		exit(0);
	if (keyhook == ZOOMOUT)
		ft_zoom(data, 78);
	if (keyhook == ZOOMIN)
		ft_zoom(data, 69);
	if (keyhook == YELLOW)
		ft_color(data, 18);
	if (keyhook == RED)
		ft_color(data, 19);
	if (keyhook == PARA)
		ft_proj(data, 20);
	if (keyhook == ISO)
		ft_proj(data, 21);
	return (0);
}
