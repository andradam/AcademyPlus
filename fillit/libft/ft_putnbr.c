/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:39:38 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 17:40:54 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long len;

	len = n;
	if (len < 0)
	{
		ft_putchar('-');
		len = -len;
	}
	if (len < 10)
	{
		ft_putchar(len % 10 + 48);
	}
	else
	{
		ft_putnbr(len / 10);
		ft_putchar(len % 10 + 48);
	}
}
