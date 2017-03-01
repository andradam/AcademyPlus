/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:53:10 by anadam            #+#    #+#             */
/*   Updated: 2017/01/11 10:12:28 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putchar(nb / 10);
		ft_putchar('0' + (nb % 10));
}

int		main(int argc, char **argv)
{
	(void)argv;
	int nr;
	nr = argc - 1;
	if (argc < 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_putnbr(nr);
	write(1, "\n", 1);
	return (0);
}
