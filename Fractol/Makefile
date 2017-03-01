# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 10:43:58 by anadam            #+#    #+#              #
#    Updated: 2017/02/21 16:30:53 by anadam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c key_hook.c ft_mandelbrot.c ft_initialize_env.c ft_error.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc -Wall -Werror -Wextra -I libft/includes/ -c $(SRCS)
	@gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a

re: fclean all
