#include "client.h"

struct addrinfo hints, *res;

int	fd_socket(int s,char *arg1, char *arg2)
{
	//loadup adress structs with getaddrinfo() and set hints to 0;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; //coonection for IPV4
	hints.ai_socktype = SOCK_STREAM; //TCP socketype

	getaddrinfo(arg1, arg2, &hints, &res);

	s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (s == -1)
	{
		puts("Error at socket!");
		return (0);
	}
	printf("Socket descriptor is: %d\n", s);
	return (s);
}

int	fd_connect(int s)
{
	int c;

	c = connect(s, res->ai_addr, res->ai_addrlen);
	if (c == -1)
	{
		puts("Error at connect!");
		return (0);
	}
	printf("Connection successfull: %d\n", c);
	return (c);
}

void	fd_get(int s)
{
	char request[] = "GET / HTTP/1.0\r\n\r\n"; //storing request
	char buffer[BUFFER_SIZE];
	FILE *f;

	//write in file request through the handle s
	write(s, request, strlen(request));
	//writes 0 in the buffer
	bzero(buffer, BUFFER_SIZE);
	puts("Read in progress..\n");
	//opens the file to write
	f = fopen("index.html", "w");
	if (f == NULL)
	{
		puts("Error opening the file!\n");
		return ;
	}
	//makes reading in the buffer and prints
	while (read(s, buffer, BUFFER_SIZE - 1) != 0)
	{
		fprintf(stdout, "%s", buffer);
		fprintf(f, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}
	//close reading/writing data/recivinf data, wait until recieve a 0 size data and then close
//	shutdown(s, SHUT_RDWR);
//	close(s);
}
