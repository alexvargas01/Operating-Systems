#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{

    //Create a socket, obtaining the flie descriptor
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //Setup the address that we want to connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(11809);
    addr.sin_addr.s_addr=INADDR_ANY;
   
    //Bind the socket to the address
    bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    //Listen for conections
    listen(sock, 1);
    //Accept the conections
    int conn = accept(sock, NULL, NULL);
    //Read and write
    char *buffer=(char*)malloc(1000);
    read (conn, buffer, 1000);
    printf("%s\n", buffer);
    write(conn, "ok", strlen("ok")+1);
    //Close the socket
    close(conn);
    close(sock);

    return 0;
}