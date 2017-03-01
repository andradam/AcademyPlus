/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:01:23 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 19:02:01 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			ret = s + i;
		i++;
	}
	if (s[i] == (const char)c)
		return ((char*)s + i);
	return ((char*)ret);
}
