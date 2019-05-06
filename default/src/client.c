#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>


#define SERVER_HOST "127.0.0.1"
#define SERVER_PORT 2121


int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    int socket_fd = 0, response;
    char *command;
    char buffer[1024];


    // INIT CLIENT
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_HOST, &server.sin_addr);

    printf("_CLIENT - start : client ready for connection\n");


    // CONNECTION
    if( connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("\n Error : Connection failed \n");
        return 1;
    }
    printf("_CLIENT : connection ready\n");


    // REQUEST : ls
    command  = "ls";
    write(socket_fd, command, sizeof(command));
    printf("_CLIENT : request sent\n");


    // RESPONSE
    printf("_CLIENT : REPONSE???\n");
    response = read(socket_fd , buffer, 1024);

    printf("%s\n", buffer);
    printf("%lu\n", sizeof(buffer));

    return 0;

}