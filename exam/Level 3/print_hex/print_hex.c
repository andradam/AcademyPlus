/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:18:27 by anadam            #+#    #+#             */
/*   Updated: 2017/01/11 10:49:37 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char c;

	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int		ft_atoi(char *s)
{
	int total;
	int	i;

	total = 0;
	i = -1;
	while (s[++i] && s[i] != '\n')
		total = total * 10 + s[i] - '0';
	return (total);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char	base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int		converted_number[64];
	int		i;
	int 	value;
	int		base;
	
	i = 0;
	value = ft_atoi(argv[1]);
	base = 16;
	if (argv[1][0] == '0')
	{
		write(1, &base_digits[0], 1);
		write(1, "\n", 1);
		return (0);
	}
	while (value != 0)
	{
		converted_number[i] = value % base;
		value = value /base;
		++i;
	}
	--i;
	while (i >= 0)
	{
		write(1,  &base_digits[converted_number[i]], 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
