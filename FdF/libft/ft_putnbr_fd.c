/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:41:06 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 17:41:29 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long len;

	len = n;
	if (len < 0)
	{
		len = -len;
		ft_putchar_fd('-', fd);
	}
	if (len < 10)
		ft_putchar_fd(len % 10 + 48, fd);
	else
	{
		ft_putnbr_fd(len / 10, fd);
		ft_putchar_fd(len % 10 + 48, fd);
	}
}
