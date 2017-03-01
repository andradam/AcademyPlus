/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:26:23 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 17:28:28 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dest;
	if (!(tmp = (unsigned char*)malloc(sizeof(*tmp) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		tmp[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		str2[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str2);
}
