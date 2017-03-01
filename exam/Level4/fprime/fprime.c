/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:09:37 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 14:13:42 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	f_prime(char *str)
{
	int n;
	int div;

	div = 2;
	n = atoi(str);
	if (n <= 1)
	{
		printf("%d\n", n);
		return ;
	}
	while (n != 1)
	{
		while(n % div == 0)
		{
			printf("%d", div);
			if (div != n)
				printf("*");
			n = n / div;
		}
		div++;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("\n");
		return (0);
	}
	f_prime(argv[1]);
	return (0);
}
