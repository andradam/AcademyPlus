/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:12:15 by anadam            #+#    #+#             */
/*   Updated: 2016/12/22 17:13:52 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!size)
		return (NULL);
	if (!(str = malloc(sizeof(*str) * size)))
		return (NULL);
	str = ft_memset(str, 0, size);
	return (str);
}
