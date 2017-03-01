/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:02:46 by anadam            #+#    #+#             */
/*   Updated: 2017/01/06 13:05:46 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	char	**tetris;
	int		count;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	tetris = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	tetris = validate(fd, tetris);
	close(fd);
	count = ft_lines(tetris);
	ft_fillit(tetris, count);
	count = 0;
	while (tetris[count])
	{
		free(tetris[count]);
		count++;
	}
	free(tetris);
	return (0);
}
