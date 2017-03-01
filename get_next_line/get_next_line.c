/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:22:19 by anadam            #+#    #+#             */
/*   Updated: 2017/01/31 12:32:23 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	is_newline(char **tab, char **line, int len)
{
	*line = ft_strsub(*tab, 0, len);
	*tab = ft_strsub(*tab, len + 1, ft_strlen(*tab) - len);
	return (1);
}

static int	read_file(int fd, char **line, char **tab)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		len;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		*tab = ft_strjoin(*tab, buff);
		len = find_new(*tab);
		if (len > -1)
		{
			is_newline(tab, line, len);
			return (1);
		}
	}
	return (-5);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tab;
	int				new;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (tab == NULL)
		tab = ft_strnew(0);
	if (find_new(tab) > -1)
		return (is_newline(&tab, line, find_new(tab)));
	if ((new = read_file(fd, line, &tab)) && new != -5)
		return (new);
	if (find_new(tab) == -1 && ft_strlen(tab) > 0)
	{
		*line = ft_strsub(tab, 0, ft_strlen(tab));
		tab = ft_strdup("");
		return (1);
	}
	return (0);
}
