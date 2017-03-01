
NAME = client

SRC = client.c main.c client.h

OBJ = client.o main.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f client.h.gch
