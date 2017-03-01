/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:41:48 by anadam            #+#    #+#             */
/*   Updated: 2017/01/14 14:59:06 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	k;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		k = str[i];
		str[i] = str[len];
		str[len] = k;
		i++;
		len--;
	}
	return (str);
}
