/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:57:58 by anadam            #+#    #+#             */
/*   Updated: 2017/02/22 11:25:28 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int err, char *str)
{
	if (err == 1)
	{
		write(1, str, ft_strlen(str));
		return (0);
	}
	else if (err == 2)
	{
		write(1, str, ft_strlen(str));
		exit(0);
	}
	return (0);
}
