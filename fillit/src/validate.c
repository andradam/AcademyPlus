/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:03:10 by anadam            #+#    #+#             */
/*   Updated: 2017/01/08 11:15:18 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		count_tetriminos(char *str, int i, int j, int k)
{
	while (str[++i] != '\0')
	{
		j++;
		if (j == 4)
		{
			if (str[i] == '\n')
				i++;
			else
				return (0);
			j = 0;
			k++;
		}
		if (k == 4)
		{
			if (str[i] == '\n' || str[i] == '\0')
				i++;
			else
				return (0);
			k = 0;
		}
	}
	if (j != 0 || k != 0)
		return (0);
	return (i / 21);
}

char	**get_in_matrix(char *array, int count, int i, int j)
{
	char	**matrix;

	if (!(matrix = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	matrix[count] = NULL;
	while (i < count)
	{
		if (!(matrix[i++] = (char*)malloc(sizeof(char) * 17)))
			return (NULL);
		matrix[i - 1][16] = '\0';
	}
	count = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] != '\n')
			matrix[j][count++] = array[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

void	validate_pieces(char **tetris, int i, int j, int hash)
{
	int	center;
	int	ok;

	while (tetris[++i] != NULL)
	{
		center = 0;
		while ((tetris[i][++j] != '\0') && (tetris[i][j] == '.' ||
				tetris[i][j] == '\n' || tetris[i][j] == '#'))
			if (tetris[i][j] == '#')
			{
				if ((ok = validate_around(tetris, i, j)) > 0)
				{
					++hash;
					if (ok > 1)
						center = ok;
				}
				else
					ft_error();
			}
		if (center <= 1 || hash != 4 || tetris[i][j] != '\0')
			ft_error();
		hash = 0;
		j = -1;
	}
}

void	convert_hash(char **tetris, int i, int j)
{
	char c;

	c = 'A';
	while (tetris[i] != '\0')
	{
		while (tetris[i][j] != '\0')
		{
			if (tetris[i][j] == '#')
				tetris[i][j] = c;
			j++;
		}
		j = 0;
		c++;
		i++;
	}
	if (c > 'Z' + 1)
		ft_error();
}

char	**validate(int fd, char **tetris)
{
	char	*buf;
	int		bytes;
	int		count;

	if (!(buf = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	bytes = read(fd, buf, BUFF_SIZE + 1);
	buf[bytes] = '\0';
	if ((buf[bytes - 1] == '\n') && (buf[bytes - 2] == '\n'))
		ft_error();
	count = count_tetriminos(buf, 0, 0, 0);
	if (count == 0)
		ft_error();
	tetris = get_in_matrix(buf, count, 0, 0);
	free(buf);
	validate_pieces(tetris, -1, -1, 0);
	convert_hash(tetris, 0, 0);
	return (tetris);
}
