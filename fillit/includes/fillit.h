/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:03:35 by anadam            #+#    #+#             */
/*   Updated: 2017/01/06 12:53:29 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# include "fillit.h"
# define BUFF_SIZE 2048

void	ft_error(void);
void	validate_pieces(char **tetris, int i, int j, int hash);
void	convert_hash(char **tetris, int i, int j);
void	display_fillit(char **tetris);
void	free_map(char **map);
void	ft_fillit(char **tetris, int count);
int		check(char **map, char *tetris, int i, int j);
int		count_tetriminos(char *str, int i, int j, int k);
int		validate_around(char **tetris, int i, int j);
int		ft_sqrt(int len);
int		get_dots(char *str);
int		ft_div(int n);
int		ft_lines(char **map);
char	**get_in_matrix(char *array, int count, int i, int j);
char	**validate(int fd, char **tetris);
char	**create_map(int size);

#endif
