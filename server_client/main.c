#include "client.h"

void	ft_menu()
{
	printf("\n1. Conectare la server\n");
	printf("2. Deconectare de la server\n");
	printf("3. Rulare comanda GET / HTTP/1.0\\r\\r\\n \n");
	printf("4. Iesire din aplicatie\n");
	printf("Introduceti optiunea dorita: ");
}

int		get_opt()
{
	int key;
	int key1;
	int i;

	i = 0;
	do
	{
		key = getchar();
		if (i == 0)
			key1 = key;
		++i;
	}
	while (key != '\n');
	return (key1);
}

void do_opt(int opt, char *str1, char *str2)
{
	static int s; //socket
	int c; //connect
	int *ok;

	ok = malloc(sizeof(*ok));
	switch(opt)
	{
		case '1':
			s = fd_socket(s, str1, str2); //make a socket
			c = fd_connect(s); //connect
			*ok = 2;
			break ;
		case '2':
			if ((*ok > 1) || (*ok < -200))
			{
			shutdown(s, SHUT_RDWR);
			close (s);
			printf("Shutdown succesfull!\n");
			break ;
			}
			else
			break ;
		case '3':
			fd_get(s);
			break ;
		case '4':
			exit (0);
			break ;
		default:
			printf("Not a valid\n");
	}
}

int     main(int argc, char **argv)
{
	int key;

	if (argc != 3)
	{
		printf("You need to have 2 arg(DNS/IP and Protocol)\n");
		return (0);
	}
	do
	{
		ft_menu();
		key = get_opt();
		do_opt(key,argv[1],argv[2]);
	}
	while(key != '4');
	return (0);
}
