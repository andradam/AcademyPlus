/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:26:25 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 18:27:29 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*str1;
	char	*str2;
	int		len;
	int		i;

	i = 0;
	str1 = (char*)src;
	str2 = (char*)dest;
	len = ft_strlen(src);
	while (i < len)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
