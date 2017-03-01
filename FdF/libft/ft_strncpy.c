/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:56:00 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 18:58:23 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char*)src;
	str2 = (char*)dest;
	while (src[i] && i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	while (i < n)
	{
		str2[i] = '\0';
		i++;
	}
	return (str2);
}
