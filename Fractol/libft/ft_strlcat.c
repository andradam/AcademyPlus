/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:49:23 by anadam            #+#    #+#             */
/*   Updated: 2016/12/23 19:15:49 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len1;
	size_t len2;

	j = 0;
	len1 = ft_strlen(src);
	i = ft_strlen(dst);
	len2 = i;
	if (size < i)
		return (len1 + size);
	if (size == len2)
		return (len1 + len2);
	while (src[j] && j < size - len2 - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (len1 + len2);
}
