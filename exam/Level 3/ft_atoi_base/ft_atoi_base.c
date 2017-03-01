/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:08:56 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 16:39:29 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	int nr;
	int j;
	int k;
	int l;
	int c;

	nr = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	l = 1;
	while (i >=0 && str[i] != '-')
	{
		j = 1;
		k = 0;
		while (k < l -1)
		{
			j = j *str_base;
			k++;
		}
		l++;
		if (str[i] == 'a' || str[i] == 'A')
			c = 10;
		else
			if (str[i] == 'b' || str[i] == 'B')
				c = 11;
			else
				if (str[i] == 'c' || str[i] == 'C')
					c = 12;
				else
					if (str[i] == 'd' || str[i] == 'D')
						c = 13;
					else
						if (str[i] == 'e' || str[i] == 'E')
							c = 14;
						else
							if (str[i] == 'f' || str[i] == 'F')
								c = 15;
							else 
								c = str[i] - '0';
		nr = nr + c * j;
		i--;
	}
	if (str[0] == '-')
	{
		nr = -nr;
		if (str[1] == '-')
			nr = 0;
	}
	return(nr);
}

