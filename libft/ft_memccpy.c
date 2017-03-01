/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:15:24 by anadam            #+#    #+#             */
/*   Updated: 2016/12/23 13:01:37 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dest;
	while (i < n)
	{
		str2[i] = str1[i];
		if (str2[i] == (unsigned char)c)
		{
			return (str2 + i + 1);
		}
		i++;
	}
	return (NULL);
}
