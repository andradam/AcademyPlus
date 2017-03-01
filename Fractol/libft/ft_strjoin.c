/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:44:47 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 18:47:53 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str1 = (char*)malloc(sizeof(*str1) *
					((ft_strlen(s1) + (ft_strlen(s2) + 1))))))
		return (NULL);
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str1[i + j] = s2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}
