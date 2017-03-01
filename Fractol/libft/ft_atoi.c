/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:56:44 by anadam            #+#    #+#             */
/*   Updated: 2016/12/23 11:50:41 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_atoi(const char *nptr)
{
	int rez;
	int sign;
	int i;

	sign = 1;
	rez = 0;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] == '+')
	{
		sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rez = rez * 10 + nptr[i] - '0';
		i++;
	}
	return (rez * sign);
}
