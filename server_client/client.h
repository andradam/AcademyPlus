#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#define BUFFER_SIZE 2048

int fd_scocket(int s, char *arg1, char *arg2);
int fd_connect(int s);
void fd_get(int s);

#endif
