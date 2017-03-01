/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:07:29 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 18:12:14 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(int c)
{
	int len;

	len = 0;
	if (c == 0)
		return (len + 1);
	while (c > 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

static	char	*ft_mod(char *str, int n, int len)
{
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		n = n * sign;
		len = ft_len(n) + 1;
	}
	else
		len = ft_len(n);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (sign == -1)
		str[0] = '-';
	str[len] = '\0';
	ft_mod(str, n, len);
	return (str);
}
