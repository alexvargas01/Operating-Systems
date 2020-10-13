//Alex Vargas A00824525
//Cesar Martinez A00517067

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
    addr.sin_port = htons(2001);
    inet_pton(AF_INET, "18.214.37.173", &addr.sin_addr);
    //Connect to the address
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    //Read and Write from the socket
    char *buffer = (char *)malloc(50000);
    strcpy(buffer, "turtle2");

    write(sock, buffer, strlen(buffer) + 1);
    read(sock, buffer, 50000);
    printf("%s\n", buffer);

    strcpy(buffer, "-la");

    write(sock, buffer, strlen(buffer) + 1);
    read(sock, buffer, 50000);
    printf("%s\n", buffer);
    //Close the socket
    close(sock);
    free(buffer);

    return 0;
}
