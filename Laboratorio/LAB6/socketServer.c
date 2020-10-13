//Alex Vargas A00824525
//Cesar Martinez A00517067

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main()
{
    //Create a socket, obtaining the flie descriptor
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    //Setup the address that we want to connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2001);
    addr.sin_addr.s_addr = INADDR_ANY;

    //Set reutilize
    int allowReuse = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &allowReuse, sizeof(allowReuse));

    //Bind the socket to the address
    bind(sock, (struct sockaddr *)&addr, sizeof(addr));

    //Listen for conections
    listen(sock, 1);

    //Accept the conections
    int conn = accept(sock, NULL, NULL);

    //Read and write
    char *buffer = (char *)malloc(50000);
    read(conn, buffer, 50000);

    write(conn, "ok", strlen("ok") + 1);

    //Comparing the strings
    int res = strncmp(buffer, "turtle", 5);

    read(conn, buffer, 50000);

    if (res == 0)
    { //They are the same string
        int option = atoi(&buffer[6]);
        int fileDescriptors[2];
        pipe(fileDescriptors);
        pid_t child = fork();

        if (option == 1)
        {
            if (child == 0)
            {
                close(fileDescriptors[READ]);
                dup2(fileDescriptors[WRITE], STDOUT_FILENO);
                close(fileDescriptors[WRITE]);
                execlp("ps", "ps", buffer, NULL);
            }
            else
            {
                wait(NULL);
                close(fileDescriptors[WRITE]);
                read(fileDescriptors[READ], buffer, 50000);
                close(fileDescriptors[READ]);
            }
        }
        else if (option == 2)
        {
            if (child == 0)
            {
                close(fileDescriptors[READ]);
                dup2(fileDescriptors[WRITE], STDOUT_FILENO);
                close(fileDescriptors[WRITE]);
                execlp("ls", "ls", buffer, NULL);
            }
            else
            {
                wait(NULL);
                close(fileDescriptors[WRITE]);
                read(fileDescriptors[READ], buffer, 50000);
                close(fileDescriptors[READ]);
            }
        }

        write(conn, buffer, strlen(buffer));
    }
    else
    { //they are different strings
        printf("Different strings. Terminating connection\n");
        close(conn);
        close(sock);
    }

    //Close the socket
    close(conn);
    close(sock);

    return 0;
}
