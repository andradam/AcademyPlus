/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:40:17 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 13:03:53 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	wd_match(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str2[j])
	{
		if (str1[i] && str2[j] && str1[i] == str2[j])
			i++;
			j++;
	}
		if (!str1[i])
			write(1, str1, ft_strlen(str1));
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	wd_match(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
