#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>

#include <fcntl.h>


#define HOST "127.0.0.1"
#define PORT 2121

int main(int argc, char *argv[])
{
    struct sockaddr_in server, client;
    int socket_fd = 0, accept_fd = 0, request, new_socket;
    socklen_t clientSize = 0;
    char buffer[1024];
    char *message;
    char line[100];
    int output_file;



    // INIT SERVER
    server.sin_family = AF_INET;
    inet_pton(AF_INET, HOST, &server.sin_addr);
    server.sin_port = htons(PORT);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socket_fd, (struct sockaddr*)&server, sizeof(server));
    listen(socket_fd, 10);

    printf("_SERVER - start : server launched, waiting for client\n");


    // CONNECTION
    clientSize = sizeof(client);
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&client, (socklen_t*)&clientSize))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        // REQUEST
        request = read(new_socket, buffer, 1024);
        printf("_SERVER - command received : %s\n", buffer);

        if(strstr(buffer, "ls"))
        {
            printf("_SERVER : LS COMMAND\n");

            system("ls > server_output.txt");
            output_file = open("server_output.txt", O_RDONLY);

            read(output_file, line, 100);
            printf("%s\n", line);
            printf("%lu\n", sizeof(line));

            //write(new_socket, output_file, sizeof(output_file));

            message = "test";

            write(new_socket, message, sizeof(output_file));


            exit(0);
        }
    }




}

