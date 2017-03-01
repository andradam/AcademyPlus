
NAME = fillit

SRCS = src/main.c src/checking.c src/fillit.c src/squares.c \
	   src/validate.c src/print_msg.c

OBJ = main.o checking.o fillit.o squares.o validate.o \
	  print_msg.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
